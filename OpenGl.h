#pragma once
#include<GL/glut.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
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