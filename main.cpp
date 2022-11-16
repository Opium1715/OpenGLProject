#include "OpenGl.h"

void putPixel(int x, int y) {
	glPointSize(2);
	glBegin(GL_POINTS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2i(x, y);
	glEnd();
}
void DDALine(int x0, int y0, int x1, int y1) {
	int dx, dy, epsl, k;
	float x, y, xIncre, yIncre;
	dx = x1 - x0;//���dx
	dy = y1 - y0;//���dy
	x = x0;//ȷ����ʼ��
	y = y0;
	if (abs(dx) > abs(dy)) epsl = abs(dx);//���dx����˵��б��<=1��e=dx
	else epsl = abs(dy);//���dy����˵��б��>1��e=dy
	xIncre = (float)dx / (float)epsl;//��������
	yIncre = (float)dy / (float)epsl;
	for (k = 0; k <= epsl; k++) {
		putPixel(int(x + 0.5), int(y + 0.5));
		x += xIncre;
		y += yIncre;
	}
}


//ʵ��һ�ĵ�����ʾ����
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

void Reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);//�ı���ʾ������ʼλ��Ϊ�ͻ��˴������½ǣ�������ԭ�㣩
	glMatrixMode(GL_PROJECTION);//�޸�ͶӰ����
	glLoadIdentity();//���뵥λ��
	gluOrtho2D(-400.0, 400.0, -300.0, 300.0);
}
int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Hello Opengl!");
	glutDisplayFunc(&Display2);
	glutReshapeFunc(&Reshape);
	glutMainLoop();
	return 0;
}