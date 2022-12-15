#pragma once
#include<GL/glut.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<algorithm>

#define PI acos(-1)
#define rect 1
#define triangle 2
#define polygon 3
#define circular 4
#define line 5
#define bezier 6
#define b_spline 7
#define Clip 8

using namespace std;

void Display();
void putPixel(int x, int y);
void Bresenham(int x0, int y0, int x1, int y1);
void Mid_Bresenham(int x0, int y0, int x1, int y1);
void MidBresenhamCircle(int r);
void Display2();
void Display3();
void Cohen_Sutherland(int x0, int y0, int x1, int y1, int yt, int yb, int xl, int xr);
void keyboard(unsigned char key, int x, int y);
void SpecialKey(int key, int x, int y);
void Liang_Barsky(double x1, double y1, double x2, double y2, double yt, double yb, double xl, double xr);
void Display4();
void myMouse(int button, int state, int x, int y);
void Exp4Reshape(int w, int h);
void B_spline();
void drawRect(int x0, int y0, int x1, int y1);
void RectDisplay();
void drawtri(int x0, int y0, int x1, int y1);
void drawLine(int x0, int y0, int x1, int y1);

void MainMenuHandler(int option);
void SubMenuHandler1(int option);
void SubMenuHandler2(int option);
void SubMenuHandler3(int option);
void myMenu();
//void Motion(int x, int y);
//void Mouse(int button, int state, int x, int y);
void RectMouse(int button, int state, int x, int y);
void TriMouse(int button, int state, int x, int y);
void PolyMouse(int button, int state, int x, int y);
void lineMouse(int button, int state, int x, int y);

void ClipSpecialKey(int key, int x, int y);

void Refresh();



class Point
{
public:
	Point(int x, int y);
	int getX();
	int getY();
	void setX(int newx);
	void setY(int newy);
private:
	int x;
	int y;
};

class Graph {
public:
	Graph(std::vector <Point>&  points, int type,int R,int G,int B);
	int getType() {
		return this->type;
	}
	void setType(int type) {
		this->type = type;
	}
	const float* getRGB() {
		float color[3];
		color[0] = this->R;
		color[1] = this->G;
		color[2] = this->B;
		return  color;
	}
	void setRGB(int R, int G, int B) {
		this->R = R;
		this->G = G;
		this->B = B;
	}
	vector<Point> getPoints() {
		return this->points;
	}

private:
	vector<Point> points;
	int type;
	int R;
	int G;
	int B;
};

extern vector<Graph> graphList;
extern GLfloat red , green, blue;//初始默认颜色
extern int mode;//初始模式