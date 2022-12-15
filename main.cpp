#include "OpenGl.h"
extern GLfloat red = 1.0, green = 1.0, blue = 1.0;
extern int mode = 0;
extern vector<Graph> graphList;
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


Graph::Graph(std::vector <Point>&  points, int type, int R, int G, int B) {
	this->points = points;
	this->type = type;
	this->R = R;
	this->G = G;
	this->B = B;
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

void Display() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	

	////test color
	//glColor3f(red, green, blue);
	//glRectd(100, 100, 200, 200);

	//red = 1.0, green = 0.0, blue = 0.0;
	//glColor3f(red, green, blue);
	//glRecti(0, 0, 100, 100);


	//test Polygon
	
	glBegin(GL_POLYGON);
	glColor3f(255, 0, 0); glVertex3f(0.0f, 25.0f, 0.0f);
	glColor3f(0, 0, 255); glVertex3f(50.5f, 29.5f, 0.0f);
	glColor3f(0, 255, 0); glVertex3f(100.0f, 65.0f, 0.0f);
	glEnd();
	glutSwapBuffers();
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
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Hello Opengl!");
	glutDisplayFunc(&Display);
	glutReshapeFunc(&Exp4Reshape);
	//glutKeyboardFunc(&keyboard);
	//glutSpecialFunc(&SpecialKey);
	glutMouseFunc(&myMouse);
	
	myMenu();
	glutMainLoop();
	return 0;
}