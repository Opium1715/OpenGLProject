#include "OpenGl.h"

void MidBresenhamCircle(int r) {
	int x, y, d;
	x = 0;
	y = r;
	d = 1 - r;
	while (x<=y)
	{
		putPixel(x, y);
		putPixel(x, -y);
		putPixel(-x, y);
		putPixel(-x, -y);
		putPixel(y, x);
		putPixel(y, -x);
		putPixel(-y, x);
		putPixel(-y, -x);
		if (d < 0) {
			d += 2 * x + 3;
		}
		else
		{
			d += 2 * (x - y) + 5;
			y--;
		}
		x++;
	}
}