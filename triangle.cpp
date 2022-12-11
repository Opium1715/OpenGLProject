#include"OpenGl.h"

extern int beginX, beginY;
extern int endX, endY;

//void drawtri(int x0, int y0, int x1, int y1) {
//	glColor3f(red, green, blue);
//	glRectd(x0, y0, x1, y1);
//	glutSwapBuffers();
//	glutPostRedisplay();
//}

void TriangleDisplay() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(red, green, blue);
	glBegin(GL_TRIANGLES);
	
	glVertex2d(beginX,beginY);
	glVertex2d(((double)endX + beginX) / 2, ((double)endX - beginX) * sin(60*PI/180));
	cout <<"���볤��=" << (double)endX - beginX << endl;
	cout << ((double)endX + beginX) / 2<<"," << ((double)endX - beginX) * sin(60 * PI / 180) << endl;
	cout << "��=" << ((double)endX - beginX) * sin(60 * PI / 180) << endl;
	glVertex2d(endX,endY);
	glEnd();

	glutSwapBuffers();
	glutPostRedisplay();
}

void TriMotion(int x, int y) {
	if (mode == triangle)
	{
		cout << "�ƶ����굽" << " (" << x << " , " << y << ") " << endl;
		endX = x;
		endY = y;
		TriangleDisplay();
	}
}

void TriMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			if (mode == triangle)
			{
				cout << "���λ滭" << endl;
				beginX = x, beginY = y;
				endX = x, endY = y;
				cout << "��ʼ����=" << " (" << x << " , " << y << ") " << endl;
				glutMotionFunc(&TriMotion);
				glutDisplayFunc(&TriangleDisplay);
				TriangleDisplay();
			}
		}
		if (state == GLUT_UP)
		{
			cout << "�ָ���ʼ" << endl;
			mode = 0;
		}
	}
}