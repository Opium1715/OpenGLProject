#include"OpenGl.h"

extern int beginX, beginY;
extern int endX, endY;
extern GLfloat red, green, blue;
extern float* c;

vector<Graph> graphList;
void drawtri(int x0, int y0, int x1, int y1) {
	//glColor3f(c[0], c[1], c[2]);
	glBegin(GL_TRIANGLES);
	glVertex2d(x0, y0);
	glVertex2d(((double)x1 + x0) / 2, (((double)y0 + y1) / 2) - (((double)x1 - x0) * sin(60 * PI / 180)));
	glVertex2d(x1, y1);
	glEnd();
}

void TriangleDisplay() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(red, green, blue);
	glBegin(GL_TRIANGLES);
	
	glVertex2d(beginX,beginY);
	glVertex2d(((double)endX + beginX) / 2, (((double)beginY+endY)/2) - (((double)endX - beginX) * sin(60*PI/180)));
	//cout <<"距离长度=" << (double)endX - beginX << endl;
	//cout << ((double)endX + beginX) / 2<<"," << (((double)beginY + endY) / 2) - (((double)endX - beginX) * sin(60 * PI / 180)) << endl;
	//cout << "高=" << ((double)endX - beginX) * sin(60 * PI / 180) << endl;
	glVertex2d(endX,endY);
	glEnd();

	Refresh();
	glutSwapBuffers();
}

void TriMotion(int x, int y) {
	if (mode == triangle)
	{
		cout << "移动坐标到" << " (" << x << " , " << y << ") " << endl;
		endX = x;
		endY = y;
		TriangleDisplay();
		glutPostRedisplay();
	}
}

void TriMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			if (mode == triangle)
			{
				cout << "矩形绘画" << endl;
				beginX = x, beginY = y;
				endX = x, endY = y;
				cout << "起始坐标=" << " (" << x << " , " << y << ") " << endl;
				glutMotionFunc(&TriMotion);
				glutDisplayFunc(&TriangleDisplay);
				TriangleDisplay();
			}
			else if (mode == rotate)
			{

			}
		}
		if (state == GLUT_UP && mode == triangle)
		{
			cout << "恢复初始" << endl;
			mode = 0;
			vector<Point> p;
			p.push_back(Point(beginX, beginY));
			p.push_back(Point(endX, endY));
			graphList.push_back(Graph(p, triangle, red, green, blue));
		}
	}
}