#include "OpenGl.h"
class Point
{
public:
	Point(int x,int y);
	int getX();
	int getY();
private:
	int x;
	int y;
};

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Point::getX()
{
	return this->x;
}

int Point::getY() {
	return this->y;
}

vector<Point> points;
void Display4() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glFlush();
}

double computeBezier(double t, double x, double y,double z, double w ) {
	return pow(t, 3) * x + pow(t, 2) * y + t * z + w;
}

void Bezier() {
	double accuracy = 1.0/500;
	for (int i = 1; i <= 1/accuracy; i++)
	{
		double t = accuracy*i;
		double Bratio[4];
		Bratio[0] = computeBezier(t, -1.0, 3.0, -3.0, 1.0);
		Bratio[1] = computeBezier(t, 3.0, -6.0, 3.0, 0.0);
		Bratio[2] = computeBezier(t, -3.0, 3.0, 0.0, 0.0);
		Bratio[3] = computeBezier(t, 1.0, 0.0, 0.0, 0.0);
		double x = 0, y = 0;
		for (int j = 0; j < 4; j++)
		{
			x += Bratio[j] * points[j].getX();
			y += Bratio[j] * points[j].getY();
		}
		putPixel(int(x+0.5), int(y+0.5));
	}
}



void myMouse(int button, int state, int x,int y) {
	if (button == GLUT_LEFT_BUTTON&&state == GLUT_DOWN&&points.size()<4)
	{
		cout << " (" << x << " , " << y << ") " << endl;
		putPixel(x, y);
		Point p(x, y);
		points.push_back(p);
		//�������
		glLineWidth(1);
		glColor3f(1.0, 1.0, 0.9);
		glBegin(GL_LINE_STRIP);
		for (int i = 0; i < points.size(); i++)
		{
			glVertex2d(points[i].getX(), points[i].getY());
		}
		glEnd();

		if (points.size()==4)
		{
			Bezier();
		}
		glFlush();
	}

	if (button == GLUT_RIGHT_BUTTON&&state==GLUT_DOWN)
	{
		cout << "��յ㼯�����»���" << endl;
		points.clear();
		Display4();
	}
}

void Exp4Reshape(int w,int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);//�ı���ʾ������ʼλ��Ϊ�ͻ��˴������½ǣ�������ԭ�㣩
	glMatrixMode(GL_PROJECTION);//�޸�ͶӰ����
	glLoadIdentity();//���뵥λ��
	gluOrtho2D(0.0, 800.0, 600.0, 0.0);//��תy����ʹ��Ļ����ϵ���ϲ����߼�
}