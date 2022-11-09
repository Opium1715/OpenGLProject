#include "OpenGl.h"

void Mid_Bresenham(int x0,int y0,int x1,int y1) {
	int dx, dy, k, x, y, d;
	int upinc, keepinc;
	
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
	k = abs(dy) / abs(dx);
	if (k >= 0 && k <= 1) {
		upinc = 2 * dx - 2 * dy;
		keepinc = 2 * dy;
		x = x0;
		y = y0;
		d = dx - 2 * dy;
		while (x<=x1)
		{
			putPixel(x, y);
			if (d < 0) {
				x++;
				y++;
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
		upinc = 2 * dy - 2 * dx;
		keepinc = 2 * dx;
		x = x0;
		y = y0;
		d = dy - 2 * dx;
		while (y <= y1)
		{
			putPixel(x, y);
			if (d < 0) {
				x++;
				y++;
				d += upinc;
			}
			else
			{
				y++;
				d -= keepinc;
			}
		}
	}


}