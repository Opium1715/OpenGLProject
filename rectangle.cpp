#include "OpenGl.h"

 int beginX = 0, beginY = 0;
 int endX = 0, endY = 0;

void drawRect(int x0,int y0,int x1,int y1) {
	glColor3f(red, green, blue);
	glRectd(x0, y0, x1, y1);
	glutSwapBuffers();
	glutPostRedisplay();
}

void RectDisplay() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	drawRect(beginX, beginY, endX, endY);
}

void RectMotion(int x, int y) {
	if (mode == rect)
	{
		cout << "移动坐标到" << " (" << x << " , " << y << ") " << endl;
		endX = x;
		endY = y;
		drawRect(beginX, beginY, x, y);
	}
}

void RectMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			if (mode == rect)
			{
				cout << "矩形绘画" << endl;
				beginX = x, beginY = y;
				endX = x, endY = y;
				cout << "起始坐标=" << " (" << x << " , " << y << ") " << endl;
				glutMotionFunc(&RectMotion);
				glutDisplayFunc(&RectDisplay);
				drawRect(beginX, beginY, beginX, beginY);
			}
		}
		if (state == GLUT_UP)
		{
				cout << "恢复初始" << endl;
				mode = 0;
		}
	}
}