#include"OpenGl.h"

extern vector<Graph> graphList;
extern GLfloat red, green, blue;
void Refresh() {
	
	for (int i = 0; i < graphList.size(); i++)
	{
		int graphType = graphList[i].getType();
		switch (graphType)
		{
		case 1: {
			cout << "重绘矩形 " << endl;
			float* c = graphList[i].getRGB();
			red = c[0];
			green = c[1];
			blue = c[2];
			vector<Point> ps = graphList[i].getPoints();
			drawRect(ps[0].getX(),ps[0].getY(),ps[1].getX(),ps[1].getY());
			cout<<"重绘结束" << endl;
		}break;
		case 2: {
			cout << "重绘三角形" << endl;
			float* c = graphList[i].getRGB();
			red = c[0];
			green = c[1];
			blue = c[2];
			vector<Point> ps = graphList[i].getPoints();
			drawtri(ps[0].getX(), ps[0].getY(), ps[1].getX(), ps[1].getY());
			cout << "重绘结束" << endl;
		}break;
		case 3: {
			cout<<"重绘多边形" << endl;
			float* c = graphList[i].getRGB();
			red = c[0];
			green = c[1];
			blue = c[2];
			vector<Point> ps = graphList[i].getPoints();
			drawtri(ps[0].getX(), ps[0].getY(), ps[1].getX(), ps[1].getY());
			cout << "重绘结束" << endl;
		}break;
		default:
			break;
		}
	}
}