#include "OpenGl.h"

void Mid_Bresenham(int x0,int y0,int x1,int y1) {
	int dx, dy, k, x, y, d;
	int upinc, keepinc;
	
	if (x0 > x1) {//保证线段从左往右绘制
		int temp = x0;
		x0 = x1;
		x1 = temp;
		temp = y0;
		y0 = y1;
		y1 = temp;
	}
	dx = x1 - x0;
	dy = y1 - y0;

	int y_inc = dy > 0 ?  1:-1;

	k = abs(dy) / abs(dx);
	if (k >= 0 && k <= 1) {
		upinc = abs(2 * dx) -abs( 2 * dy);
		keepinc =abs( 2 * dy);
		x = x0;
		y = y0;
		d = dx - abs(2 * dy);
		while (x<=x1)
		{
			putPixel(x, y);
			if (d < 0) {
				x++;
				y+=y_inc;
				d += upinc;
			}
			else
			{
				x++;
				d -= keepinc;
			}
		}
	}
	else
	{
		upinc = abs(2 * dy) -abs( 2 * dx);
		keepinc = abs(2 * dx);
		x = x0;
		y = y0;
		d = dy - abs(2 * dx);
		while (y <= y1)
		{
			putPixel(x, y);
			if (d < 0) {
				x++;
				y += y_inc;
				d += upinc;
			}
			else
			{
				y += y_inc;
				d -= keepinc;
			}
		}
	}
}