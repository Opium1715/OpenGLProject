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