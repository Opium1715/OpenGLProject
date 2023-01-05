#include "OpenGl.h"
extern GLfloat red = 1.0, green = 1.0, blue = 1.0;
extern int mode = 0;
extern vector<Graph> graphList;

float ct = 1;

void putPixel(int x, int y) {
	glPointSize(2);
	glBegin(GL_POINTS);
	//glColor3f(1.0f, 1.0f, 1.0f);
	glColor3f(red,green,blue);
	glVertex2i(x, y);
	glEnd();
}
void DDALine(int x0, int y0, int x1, int y1) {
	int dx, dy, epsl, k;
	float x, y, xIncre, yIncre;
	dx = x1 - x0;//算出dx
	dy = y1 - y0;//算出dy
	x = x0;//确定起始点
	y = y0;
	if (abs(dx) > abs(dy)) epsl = abs(dx);//如果dx更大，说明斜率<=1，e=dx
	else epsl = abs(dy);//如果dy更大，说明斜率>1，e=dy
	xIncre = (float)dx / (float)epsl;//增量计算
	yIncre = (float)dy / (float)epsl;
	for (k = 0; k <= epsl; k++) {
		putPixel(int(x + 0.5), int(y + 0.5));
		x += xIncre;
		y += yIncre;
	}
}




//实验一的调用显示内容
void myDisplay() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	MidBresenhamCircle(200);
	Bresenham(0, 0, 200, 200);
	Bresenham(-200, -200, 200, -200);
	DDALine(200, -200, 200, 200);
	Mid_Bresenham(200, 200, -200, 200);
	DDALine(-200, 200, -200, -200);
	Bresenham(-150, 200, 50, -100);
	Bresenham(-150, -100, 150, 200);
	/*Mid_Bresenham(-100, 120, 100, -150);*/
	glFlush();
}

void Display() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	//test Polygon
	cout<<"scale" << endl;
	glPushMatrix();
	
	int x0 = 100, y0 = 100, x1 = 200, y1 = 200;
	glColor3f(0.5, 0.5, 0.5);
	glRectd(x0, y0, x1, y1);
	glLoadIdentity();
	float m[16];
	glTranslatef(-100.0, -100.0, 0.0);
	glGetFloatv(GL_PROJECTION_MATRIX, m);
	x0 += m[12], y0 += m[13];
	x1 += m[12], y1 += m[13];
	glPopMatrix();
	//glPushMatrix();
	////
	//ct -= 0.01;
	//glTranslatef(150, 150.0, 0.0);
	//glScalef(ct, ct, 1.0);
	////glRotatef(ct++, 0.0, 0.0, 1.0);
	//glGetFloatv(GL_PROJECTION_MATRIX, m);
	//glColor3f(1.5,1.5,0.5);
	//glRectd(x0, y0, x1, y1);
	//glPopMatrix();
	//glGetFloatv(GL_PROJECTION_MATRIX, m);
	glutSwapBuffers();
	glutPostRedisplay();
}



void Reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);//改变显示区域，起始位置为客户端窗口左下角（非坐标原点）
	glMatrixMode(GL_PROJECTION);//修改投影矩阵
	glLoadIdentity();//导入单位阵
	gluOrtho2D(-400.0, 400.0, -300.0, 300.0);
}
int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Hello Opengl!");
	glutDisplayFunc(&Display);
	glutReshapeFunc(&Exp4Reshape);
	//glutKeyboardFunc(&keyboard);
	//glutSpecialFunc(&SpecialKey);
	//glutMouseFunc(&myMouse);
	
	myMenu();
	glutMainLoop();
	return 0;
}