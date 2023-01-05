#include"OpenGl.h"

extern vector<Graph> graphList;
extern GLfloat red, green, blue;
extern int GT_select;

void Refresh() {
	
	for (int i = graphList.size()-1; i >=0; i--)
	{
		int graphType = graphList[i].getType();
		if (i == GT_select)
		{
			continue;
		}
		switch (graphType)
		{
		case 1: {
			cout << "重绘矩形 " << endl;
			float c[3];
			graphList[i].getRGB(c);
			float Red = c[0];
			float Green = c[1];
			float Blue = c[2];
			vector<Point> ps = graphList[i].getPoints();
			glColor3f(Red, Green, Blue);
			drawRect(ps[0].getX(),ps[0].getY(),ps[1].getX(),ps[1].getY());
			cout<<"重绘结束" << endl;
		}break;
		case 2: {
			cout << "重绘三角形" << endl;
			float c[3];
			graphList[i].getRGB(c);
			float Red = c[0];
			float Green = c[1];
			float Blue = c[2];
			vector<Point> ps = graphList[i].getPoints();
			glColor3f(Red, Green, Blue);
			drawtri(ps[0].getX(), ps[0].getY(), ps[1].getX(), ps[1].getY());
			cout << "重绘结束" << endl;
		}break;
		case 3: {
			cout<<"重绘多边形" << endl;
			float c[3];
			graphList[i].getRGB(c);
			/*float Red = c[0];
			float Green = c[1];
			float Blue = c[2];*/
			vector<Point> ps = graphList[i].getPoints();
			drawPolygon(ps,c);
			cout << "重绘结束" << endl;
		}break;
		case 4: {
			cout << "重绘圆形 " << endl;
			float c[3];
			graphList[i].getRGB(c);
			float Red = c[0];
			float Green = c[1];
			float Blue = c[2];
			vector<Point> ps = graphList[i].getPoints();
			glColor3f(Red, Green, Blue);
			drawcric(hypot(abs(ps[0].getX() - ps[1].getX()), abs(ps[0].getY() - ps[1].getY())),ps[0].getX(),ps[0].getY());
			cout << "重绘结束" << endl;
		}break;
		case 5: {
			cout << "重绘直线 " << endl;
			float c[3];
			graphList[i].getRGB(c);
			float Red = c[0];
			float Green = c[1];
			float Blue = c[2];
			vector<Point> ps = graphList[i].getPoints();
			glColor3f(Red, Green, Blue);
			drawLine(ps[0].getX(), ps[0].getY(), ps[1].getX(), ps[1].getY());
			cout << "重绘结束" << endl;
		}break;
		case 6: {
			cout << "重绘Bezier曲线 " << endl;
			float c[3];
			graphList[i].getRGB(c);
			float Red = c[0];
			float Green = c[1];
			float Blue = c[2];
			vector<Point> ps = graphList[i].getPoints();
			drawBezier(ps);
			cout << "重绘结束" << endl;
		}break;
		case 7: {
			cout << "重绘B_spline曲线 " << endl;
			float c[3];
			graphList[i].getRGB(c);
			float Red = c[0];
			float Green = c[1];
			float Blue = c[2];
			vector<Point> ps = graphList[i].getPoints();
			drawB_spline(ps);
			cout << "重绘结束" << endl;
		}break;
		default:
			break;
		}
	}
}