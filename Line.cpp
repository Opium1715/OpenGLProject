#include"OpenGl.h"

extern int beginX, beginY, endX, endY;

void drawLine(int x0,int y0,int x1,int y1) {
	Bresenham(x0,y0,x1,y1);
}

void LineDisplay() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	Bresenham(beginX, beginY, endX, endY);

	Refresh();
	glutSwapBuffers();
}

void lineMotion(int x,int y) {
	if (mode == line)
	{
		cout << "�ƶ����굽" << " (" << x << " , " << y << ") " << endl;
		endX = x;
		endY = y;
		LineDisplay();
		glutPostRedisplay();
	}
}

void lineMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			if (mode == line)
			{
				cout << "ֱ�߻滭" << endl;
				beginX = x, beginY = y;
				endX = x, endY = y;
				cout << "��ʼ����=" << " (" << x << " , " << y << ") " << endl;
				glutMotionFunc(&lineMotion);
				glutDisplayFunc(&LineDisplay);
				LineDisplay();
			}
		}
		if (state == GLUT_UP)
		{
			cout << "�ָ���ʼ" << endl;
			mode = 0;
			vector<Point> p;
			p.push_back(Point(beginX, beginY));
			p.push_back(Point(endX, endY));
			graphList.push_back(Graph(p, line, red, green, blue));
		}
	}
}