#include"OpenGl.h"

extern vector<Graph> graphList;
extern GLfloat red, green, blue;
const float* c;//�ػ���ɫ

void Refresh() {
	
	for (int i = 0; i < graphList.size(); i++)
	{
		int graphType = graphList[i].getType();
		switch (graphType)
		{
		case 1: {
			cout << "�ػ���� " << endl;
			c = graphList[i].getRGB();
			float Red = c[0];
			float Green = c[1];
			float Blue = c[2];
			vector<Point> ps = graphList[i].getPoints();
			glColor3f(Red, Green, Blue);
			drawRect(ps[0].getX(),ps[0].getY(),ps[1].getX(),ps[1].getY());
			cout<<"�ػ����" << endl;
		}break;
		case 2: {
			cout << "�ػ�������" << endl;
			c = graphList[i].getRGB();
			float Red = c[0];
			float Green = c[1];
			float Blue = c[2];
			vector<Point> ps = graphList[i].getPoints();
			glColor3f(Red, Green, Blue);
			drawtri(ps[0].getX(), ps[0].getY(), ps[1].getX(), ps[1].getY());
			cout << "�ػ����" << endl;
		}break;
		case 3: {
			cout<<"�ػ�����" << endl;
			c = graphList[i].getRGB();
			red = c[0];
			green = c[1];
			blue = c[2];
			vector<Point> ps = graphList[i].getPoints();
			drawtri(ps[0].getX(), ps[0].getY(), ps[1].getX(), ps[1].getY());
			cout << "�ػ����" << endl;
		}break;
		case 4: {
			cout << "�ػ���� " << endl;
			c = graphList[i].getRGB();
			float Red = c[0];
			float Green = c[1];
			float Blue = c[2];
			vector<Point> ps = graphList[i].getPoints();
			glColor3f(Red, Green, Blue);
			drawRect(ps[0].getX(), ps[0].getY(), ps[1].getX(), ps[1].getY());
			cout << "�ػ����" << endl;
		}break;
		case 5: {
			cout << "�ػ�ֱ�� " << endl;
			c = graphList[i].getRGB();
			float Red = c[0];
			float Green = c[1];
			float Blue = c[2];
			vector<Point> ps = graphList[i].getPoints();
			glColor3f(Red, Green, Blue);
			drawLine(ps[0].getX(), ps[0].getY(), ps[1].getX(), ps[1].getY());
			cout << "�ػ����" << endl;
		}break;
		case 6: {
			cout << "�ػ���� " << endl;
			c = graphList[i].getRGB();
			float Red = c[0];
			float Green = c[1];
			float Blue = c[2];
			vector<Point> ps = graphList[i].getPoints();
			glColor3f(Red, Green, Blue);
			drawRect(ps[0].getX(), ps[0].getY(), ps[1].getX(), ps[1].getY());
			cout << "�ػ����" << endl;
		}break;
		case 7: {
			cout << "�ػ���� " << endl;
			c = graphList[i].getRGB();
			float Red = c[0];
			float Green = c[1];
			float Blue = c[2];
			vector<Point> ps = graphList[i].getPoints();
			glColor3f(Red, Green, Blue);
			drawRect(ps[0].getX(), ps[0].getY(), ps[1].getX(), ps[1].getY());
			cout << "�ػ����" << endl;
		}break;
		default:
			break;
		}
	}
}