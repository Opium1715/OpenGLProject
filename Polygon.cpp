#include"OpenGl.h"

extern float* c;
vector<Point> polyPoints;//临时存储多边形信息
vector<Point> tempPoly;//新的存储多边形信息

void drawPoly(float R,float G,float B) {
	glBegin(GL_POLYGON);
	for (int i = 0; i < polyPoints.size(); i++)
	{
		glColor3f(R,G,B);
		//putPixel(polyPoints[i].getX(), polyPoints[i].getY());
		glVertex2d(polyPoints[i].getX(), polyPoints[i].getY());
	}
	glEnd();
}

void PolyDisplay() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	drawPoly(red,green,blue);
	Refresh();
	glutSwapBuffers();
}

void drawPolygon(std::vector <Point>& ps, float * c) {
	polyPoints = ps;
	drawPoly(c[0], c[1], c[2]);
	polyPoints.clear();
}

//void PolyMotion(int x, int y) {
//	/*if (mode == polygon)
//	{
//		cout << "移动坐标到" << " (" << x << " , " << y << ") " << endl;
//		
//		PolyDisplay();
//		glutPostRedisplay();
//	}*/
//}

void PolyMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			if (mode == polygon)
			{
				cout << "多边形绘画" << endl;
				cout << "坐标=" << " (" << x << " , " << y << ") " << endl;
				//glutMotionFunc(&PolyMotion);
				glutDisplayFunc(&PolyDisplay);
				//drawRect(beginX, beginY, beginX, beginY);
				tempPoly.push_back(Point(x, y));
				polyPoints = tempPoly;
				PolyDisplay();
			}
		}
	}
	if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN && mode == polygon)
	{
		cout<<"恢复正常，保存多边形" << endl;
		cout << "恢复初始" << endl;
		mode = 0;
		graphList.push_back(Graph(tempPoly, polygon, red, green, blue));
		polyPoints.clear();
		tempPoly.clear();
	}
}