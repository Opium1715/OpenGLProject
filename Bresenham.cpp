#include "OpenGL.h"
void Bresenham(int x0,int y0,int x1,int y1) {
	int x, y, dx, dy, e;

	if (x0 > x1) {
		int temp = x0;
		x0 = x1;
		x1 = temp;
		temp = y0;
		y0 = y1;
		y1 = temp;
	}

	dx = x1 - x0;
	dy = y1 - y0; 

	int uy = dy > 0 ? 1 : -1;

	/*int k = abs(dy) /abs( dx);*/
	if (abs(dx)>abs(dy)) {
		e = -dx;
		x = x0;
		y = y0;
		while (x <= x1)
		{
			putPixel(x, y);
			x++;
			e = e + abs(2 * dy);
			if (e > 0) {
				y += uy;
				e = e - abs(2 * dx);
			}
		}
	}
	else
	{
		e = -dy;
		x = x0;
		y = y0;
		while (y != y1)
		{
			putPixel(x, y);
			y += uy;
			e = e + abs(2 * dx);
			if (e > 0) {
				x ++;
				e = e - abs(2 * dy);
			}
		}
	}

}