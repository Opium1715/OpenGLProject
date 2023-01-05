#include"OpenGl.h"

int GT_select = -1;
double Rangle = 0;//��ת�任�Ƕȣ���ʼֵ=0
int basic_GTX = 0, basic_GTY = 0;//���α任��ʼ��
int cur_GTX = 0, cur_GTY = 0;//���α任�յ�
float scaleRatio = 1.0;//����Ĭ�ϱ���

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
		glPushMatrix();//����ԭʼͶӰ����
		

		if (graphList.empty()) {
			cout << "�ڴ�����ͼ�У��볢�Ա�����ٲ�����" << endl;
			return;
		}
		Graph g = graphList[graphList.size() - 1];
		vector <Point> gPoint = g.getPoints();//ע��bug
		
		//glPushMatrix();

		//�Ƕȼ���
		Point* vector_a = new Point(x - basic_GTX, y - basic_GTY);
		//Point* vector_b = new Point(1, 0);
		Rangle = acos( (double)vector_a->getX() / hypot(vector_a->getX(), vector_a->getY()) );
		Rangle = Rangle * 180 / PI;
		cout<<"�Ƕ�=" << Rangle << endl;
		delete vector_a;

		//����ͼ�����ĵ�����
		//ֱ�Ӽ���ѡ���ĳ�ʼ����������ľ���
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

		//ͼ���ƻ�ԭ��
		for (int i = 0; i < gPoint.size(); i++)
		{
			int a[2];
			a[0] = gPoint[i].getX() - centerX;
			a[1] = gPoint[i].getY() - centerY;
			gPoint[i].setXY(a);
		}
		
		//��ת����
		glGetFloatv(GL_PROJECTION_MATRIX, m);
		//�õ�����ԭ��������ֵ
		

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
			glPopMatrix();//����ԭʼͶӰ����
			glutSwapBuffers();
		}
		else
		{
			glLoadIdentity();//���뵥λ����
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
			glPopMatrix();//����ԭʼͶӰ����
			glutPostRedisplay();
		}

		//vector<Point> newPoints;//�յ㼯��
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
		
		cout<<"��ת" << endl;
	}
	else if (mode == translate)
	{
		
		//ƽ��
		if (graphList.empty()) {
			cout<<"�ڴ�����ͼ�У��볢�Ա�����ٲ�����" << endl;
			return;
		}
		Graph g = graphList[graphList.size() - 1];
		vector <Point> gPoint = g.getPoints();
		//glPushMatrix();//���浱ǰͶӰ����
		//glLoadIdentity();//���뵥λ����
		//ƽ�ƾ������
		int tx = x - basic_GTX;
		int ty = y - basic_GTY;
		basic_GTX += tx;//�䶯�����׼��
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
		cout<<"ƽ��x= "<<tx<<"y= "<<ty<< endl;
		glutPostRedisplay();
	}
	else if (mode == scale)
	{
		//����
		if (graphList.empty()) {
			cout << "�ڴ�����ͼ�У��볢�Ա�����ٲ�����" << endl;
			return;
		}
		Graph g = graphList[graphList.size() - 1];
		vector <Point> gPoint = g.getPoints();

		//���ż���
		int tx = x - basic_GTX;
		basic_GTX = x;

		//�ж����ű��ʴ�С
		if (scaleRatio>1.0 && tx<0)
		{
			scaleRatio = 1.0;
			cout<<"reset" << endl;
		}
		else if (scaleRatio<1.0 && tx>0)
		{
			scaleRatio = 1.0;
		}

		//�ж�������Ϊ
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

		//�ƻ�ԭ��
		for (int i = 0; i < gPoint.size(); i++)
		{
			int gx = gPoint[i].getX(), gy = gPoint[i].getY();
			gx -= beginX;
			gy -= beginY;
			int a[2] = { gx, gy };
			gPoint[i].setXY(a);
		}

		//��ƽ�ƺ�����
		//����û��ʹ��OpenGL��API,���ǲ���ֱ�Ӹ��Ĺؼ�����Ĳ�����ʽ
		//��ʱ������û�б��ƶ��������ƶ�ͼ��
		//����Ӧ����������ƽ��
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
		cout<<"���ű���= "<<scaleRatio<<endl;
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
			cout << "���α任����" << endl;
			mode = 0;
			GT_select = -1;
			//vector<Point> p;
			//p.push_back(Point(endX, endY));
		}
	}
}