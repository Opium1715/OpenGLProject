#include"OpenGl.h"

int GT_select = -1;
double Rangle = 0;//旋转变换角度，初始值=0
int basic_GTX = 0, basic_GTY = 0;//几何变换起始点
int cur_GTX = 0, cur_GTY = 0;//几何变换终点
float scaleRatio = 1.0;//缩放默认倍率

void GTDisplay() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	Refresh();
	glutSwapBuffers();
}

void GTMotion(int x, int y) {
	if (mode == rotate)
	{
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);

		float m[16];
		glGetFloatv(GL_PROJECTION_MATRIX, m);
		glPushMatrix();//保存原始投影矩阵
		

		if (graphList.empty()) {
			cout << "内存中无图行，请尝试保存后再操作！" << endl;
			return;
		}
		Graph g = graphList[graphList.size() - 1];
		vector <Point> gPoint = g.getPoints();//注意bug
		
		//glPushMatrix();

		//角度计算
		Point* vector_a = new Point(x - basic_GTX, y - basic_GTY);
		//Point* vector_b = new Point(1, 0);
		Rangle = acos( (double)vector_a->getX() / hypot(vector_a->getX(), vector_a->getY()) );
		Rangle = Rangle * 180 / PI;
		cout<<"角度=" << Rangle << endl;
		delete vector_a;

		//计算图形中心点坐标
		//直接计算选定的初始点与坐标轴的距离
		int centerX = 0, centerY = 0;
		/*for (int i = 0; i < gPoint.size(); i++)
		{
			centerX += gPoint[i].getX();
			centerY += gPoint[i].getY();
		}
		centerX /= gPoint.size();
		centerY /= gPoint.size();*/
		centerX = basic_GTX;
		centerY = basic_GTY;

		//图形移回原点
		for (int i = 0; i < gPoint.size(); i++)
		{
			int a[2];
			a[0] = gPoint[i].getX() - centerX;
			a[1] = gPoint[i].getY() - centerY;
			gPoint[i].setXY(a);
		}
		
		//旋转矩阵
		glGetFloatv(GL_PROJECTION_MATRIX, m);
		//得到返回原点后的坐标值
		

		if (g.getType()==rect || g.getType()==triangle)
		{
			GT_select = graphList.size() - 1;
			glTranslatef(centerX, centerY, 0);
			glRotatef(Rangle, 0.0, 0.0, 1.0);
			int type = g.getType();
			switch (type)
			{
			case 1: {
				glRectf(gPoint[0].getX(), gPoint[0].getY(), gPoint[1].getX(), gPoint[1].getY());
			}break;
			case 2: {
				drawtri(gPoint[0].getX(), gPoint[0].getY(), gPoint[1].getX(), gPoint[1].getY());
			}break;
			default:
				break;
			}
			glPopMatrix();//弹出原始投影矩阵
			glutSwapBuffers();
		}
		else
		{
			glLoadIdentity();//载入单位矩阵
			glTranslatef(centerX, centerY, 0);
			glRotatef(5.0, 0.0, 0.0, 1.0);
			glGetFloatv(GL_PROJECTION_MATRIX, m);
			for (int i = 0; i < gPoint.size(); i++)
			{
				int gx = gPoint[i].getX(), gy = gPoint[i].getY();
				int cx = gx * m[0] + gy * m[4] + m[12];
				int cy = gx * m[1] + gy * m[5] + m[13];
				int a[2] = { cx, cy };
				gPoint[i].setXY(a);
			}
			graphList[graphList.size() - 1].setPoints(gPoint);
			glPopMatrix();//弹出原始投影矩阵
			glutPostRedisplay();
		}

		//vector<Point> newPoints;//空点集合
		//for (int i = 0; i < g.getPoints().size(); i++)
		//{
		//	int gx = g.getPoints()[i].getX(), gy = g.getPoints()[i].getY();
		//	newPoints.push_back(Point(gx * m[0] + gy * m[4], gx * m[1] + gy * m[5]));
		//	//g.getPoints()[i].setXY(newxy);
		//	//g.getPoints()[i].setX(gx * m[0] + gy * m[4]);//bug
		//	//g.getPoints()[i].setY(gx * m[1] + gy * m[5]);
		//}
		//graphList[graphList.size() - 1].setPoints(newPoints);
		//g.setPoints(newPoints);
		
		cout<<"旋转" << endl;
	}
	else if (mode == translate)
	{
		
		//平移
		if (graphList.empty()) {
			cout<<"内存中无图行，请尝试保存后再操作！" << endl;
			return;
		}
		Graph g = graphList[graphList.size() - 1];
		vector <Point> gPoint = g.getPoints();
		//glPushMatrix();//保存当前投影矩阵
		//glLoadIdentity();//载入单位矩阵
		//平移距离计算
		int tx = x - basic_GTX;
		int ty = y - basic_GTY;
		basic_GTX += tx;//变动计算基准点
		basic_GTY += ty;
		for (int i = 0; i < gPoint.size(); i++)
		{
			int gx = gPoint[i].getX(), gy = gPoint[i].getY();
			gx += tx;
			gy += ty;
			int a[2] = { gx, gy };
			gPoint[i].setXY(a);
		}
		graphList[graphList.size() - 1].setPoints(gPoint);
		cout<<"平移x= "<<tx<<"y= "<<ty<< endl;
		glutPostRedisplay();
	}
	else if (mode == scale)
	{
		//缩放
		if (graphList.empty()) {
			cout << "内存中无图行，请尝试保存后再操作！" << endl;
			return;
		}
		Graph g = graphList[graphList.size() - 1];
		vector <Point> gPoint = g.getPoints();

		//缩放计算
		int tx = x - basic_GTX;
		basic_GTX = x;

		//判断缩放倍率大小
		if (scaleRatio>1.0 && tx<0)
		{
			scaleRatio = 1.0;
			cout<<"reset" << endl;
		}
		else if (scaleRatio<1.0 && tx>0)
		{
			scaleRatio = 1.0;
		}

		//判断缩放行为
		if (tx>0)
		{
			scaleRatio += 0.0008;
		}
		else if (tx<0)
		{
			scaleRatio -= 0.0008;
		}

		//scaleRatio = (tx > 0) ? scaleRatio + 0.001 : scaleRatio - 0.001;
		int beginX = gPoint[0].getX(), beginY = gPoint[0].getY();

		//移回原点
		for (int i = 0; i < gPoint.size(); i++)
		{
			int gx = gPoint[i].getX(), gy = gPoint[i].getY();
			gx -= beginX;
			gy -= beginY;
			int a[2] = { gx, gy };
			gPoint[i].setXY(a);
		}

		//先平移后缩放
		//由于没有使用OpenGL的API,而是采用直接更改关键坐标的操作方式
		//此时坐标轴没有被移动，而是移动图形
		//所以应当先缩放再平移
		for (int i = 0; i < gPoint.size(); i++)
		{
			int gx = gPoint[i].getX(), gy = gPoint[i].getY();
			gx = gx * scaleRatio;
			gx += beginX;
			gy = gy * scaleRatio;
			gy += beginY;
			int a[2] = { gx, gy };
			gPoint[i].setXY(a);
		}
		graphList[graphList.size() - 1].setPoints(gPoint);
		cout<<"缩放倍率= "<<scaleRatio<<endl;
		glutPostRedisplay();
	}
	
}

void GTMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON )
	{
		if (state == GLUT_DOWN)
		{
			glutDisplayFunc(&GTDisplay);
			glutMotionFunc(&GTMotion);
			
			if (mode == rotate)
			{
				basic_GTX = x;
				basic_GTY = y;

			}
			else if (mode == translate)
			{
				basic_GTX = x;
				basic_GTY = y;
			}
			else if (mode == scale)
			{
				basic_GTX = x;
				basic_GTY = y;
			}
		}
		else if (state == GLUT_UP)
		{
			cout << "几何变换结束" << endl;
			mode = 0;
			GT_select = -1;
			//vector<Point> p;
			//p.push_back(Point(endX, endY));
		}
	}
}