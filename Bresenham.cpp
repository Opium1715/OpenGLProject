#include "OpenGL.h"
void Bresenham(int x0,int y0,int x1,int y1) {
	int x, y, dx, dy, e;
	dx = x1 - x0;
	dy = y1 - y0; 
	int k = abs(dy) / abs(dx);
	if (k <= 1&& k>=0) {
		e = -dx;
		x = x0;
		y = y0;
		while (x <= x1)
		{
			putPixel(x, y);
			x++;
			e = e + 2 * dy;
			if (e > 0) {
				y++;
				e = e - 2 * dx;
			}
		}
	}
	else
	{
		e = -dy;
		x = x0;
		y = y0;
		while (y <= y1)
		{
			putPixel(x, y);
			y++;
			e = e + 2 * dx;
			if (e > 0) {
				x++;
				e = e - 2 * dy;
			}
		}
	}

}