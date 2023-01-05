#pragma once
#include<GL/glut.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include <tchar.h>


#define PI acos(-1)
#define rect 1
#define triangle 2
#define polygon 3
#define circular 4
#define line 5
#define bezier 6
#define b_spline 7
#define Clip 8

#define rotate 9
#define translate 10
#define scale 11

#define Save 12
#define Open 13

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
void drawcric(int R, int centerX, int centerY);


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
void CircleMouse(int button, int state, int x, int y);
void GTMouse(int button, int state, int x, int y);

void ClipSpecialKey(int key, int x, int y);

void Refresh();

char* TCHARToChar(TCHAR* pTchar);
int FileDialog(TCHAR* path, int option);
void SaveToFile(string filename);
string toString(int f);
void ReadFromFile(string filename);


class Point
{
public:
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int getX() {
		return this->x;
	}
	int getY() {
		return this->y;
	}
	void setXY(int* a) {
		this->x = a[0];
		this->y = a[1];
	}
private:
	int x;
	int y;
};
void drawBezier(std::vector <Point>& ps);
void drawB_spline(std::vector <Point>& ps);
void drawPolygon(std::vector <Point>& ps, float* c);

class Graph {
public:
	Graph(std::vector <Point>& points, int type, float R, float G, float B) {
		this->points = points;
		this->type = type;
		this->R = R;
		this->G = G;
		this->B = B;
	};
	int getType() {
		return this->type;
	}
	void setType(int type) {
		this->type = type;
	}
	void getRGB(float* color) {
		color[0] = this->R;
		color[1] = this->G;
		color[2] = this->B;
	}
	void setRGB(int R, int G, int B) {
		this->R = R;
		this->G = G;
		this->B = B;
	}
	vector<Point> getPoints() {
		return this->points;
	}
	void setPoints(std::vector <Point>& points) {
		this->points = points;
	}
private:
	vector<Point> points;
	int type;
	float R;
	float G;
	float B;
};

extern vector<Graph> graphList;
extern GLfloat red , green, blue;//初始默认颜色
extern int mode;//初始模式