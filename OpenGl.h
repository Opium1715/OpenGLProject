#pragma once
#include<GL/glut.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;
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

void MainMenuHandler(int option);
void SubMenuHandler1(int option);
void SubMenuHandler2(int option);
void SubMenuHandler3(int option);
void myMenu();
void Motion(int x, int y);
void Mouse(int button, int state, int x, int y);


class Point
{
public:
	Point(int x, int y);
	int getX();
	int getY();
private:
	int x;
	int y;
};


extern GLfloat red , green, blue;//初始默认颜色
extern int mode;//初始模式