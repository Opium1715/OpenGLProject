#include"OpenGl.h"

int R = 0;
int n = 3600;
int centerX = 0, centerY = 0;
int edgeX = 0, edgeY = 0;
void drawcric(int R,int centerX,int centerY) {
	glBegin(GL_POLYGON);
	for (int i = 0; i < n; i++)
	{
		glVertex2f(R * cos(2 * PI * i / n)+centerX, R * sin(2 * PI * i / n)+centerY);   //定义顶点
	}
	glEnd();
}

void CircleDisplay() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(red, green, blue);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 3600; i++)
	{
		glVertex2f(R * cos(2 * PI * i / n)+centerX, R * sin(2 * PI * i / n)+centerY);   //定义顶点
	}
	glEnd();
	
	Refresh();
	glutSwapBuffers();
}

void CircleMotion( int x, int y) {
	if (mode == circular)
	{
		cout << "移动坐标到" << " (" << x << " , " << y << ") " << endl;
		R = hypot(abs(x-centerX),abs(y - centerY));
		cout << R << endl;
		edgeX = x;
		edgeY = y;
		CircleDisplay();
		glutPostRedisplay();
	}
}

void CircleMouse(int button, int state, int x, int y) {
	if (mode == circular) {
		if (button == GLUT_LEFT_BUTTON)
		{
			if (state == GLUT_DOWN)
			{
				cout << "圆形绘画" << endl;
				centerX = x, centerY = y;
				cout << "圆心起始坐标=" << " (" << x << " , " << y << ") " << endl;
				glutMotionFunc(&CircleMotion);
				glutDisplayFunc(&CircleDisplay);
				CircleDisplay();
			}
			if (state == GLUT_UP)
			{
				cout << "恢复初始" << endl;
				mode = 0;
				vector<Point> p;
				p.push_back(Point(centerX, centerY));
				p.push_back(Point(edgeX, edgeY));
				graphList.push_back(Graph(p, circular, red, green, blue));
			}
		}
	}
}