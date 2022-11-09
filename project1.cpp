#include<GL/glut.h>
void mydisplay() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f); glVertex2f(0.0f, 1.0f);
	glColor3f(0.0f, 1.0f, 0.0f); glVertex2f(0.8f, -0.5f);
	glColor3f(0.0f, 0.0f, 1.0f); glVertex2f(-0.8f, -0.5f);
	glEnd();
	glPointSize(3);
	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.0f, 0.0f); glVertex2f(-0.4f, -0.4f);
	glColor3f(0.0f, 1.0f, 0.0f); glVertex2f(0.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f); glVertex2f(0.4f, 0.4f);
	glEnd();
	glFlush();
}
//int main(int argc, char* argv[])
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(400, 400);
//	glutCreateWindow("Hello Opengl!");
//	glutDisplayFunc(&mydisplay);
//	glutMainLoop();
//	return 0;
//}