#include "OpenGl.h"

extern float* c;
 int beginX = 0, beginY = 0;
 int endX = 0, endY = 0;

void drawRect(int x0,int y0,int x1,int y1) {
	glRectd(x0, y0, x1, y1);
}

void RectDisplay() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(red,green,blue);
	drawRect(beginX, beginY, endX, endY);
	Refresh();
	glutSwapBuffers();
}

void RectMotion(int x, int y) {
	if (mode == rect)
	{
		cout << "�ƶ����굽" << " (" << x << " , " << y << ") " << endl;
		endX = x;
		endY = y;
		RectDisplay();
		glutPostRedisplay();
	}
}

void RectMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			if (mode == rect)
			{
				cout << "���λ滭" << endl;
				beginX = x, beginY = y;
				endX = x, endY = y;
				cout << "��ʼ����=" << " (" << x << " , " << y << ") " << endl;
				glutMotionFunc(&RectMotion);
				glutDisplayFunc(&RectDisplay);
				//drawRect(beginX, beginY, beginX, beginY);
				RectDisplay();
			}
		}
		if (state == GLUT_UP)
		{
				cout << "�ָ���ʼ" << endl;
				mode = 0;
				//��¼����ȷ���ĵ�
				vector<Point> p;
				p.push_back(Point(beginX, beginY));
				p.push_back(Point(endX, endY));
				graphList.push_back(Graph(p, rect, red, green, blue));
		}
	}
}