#include"OpenGl.h"

extern vector<Point> points;
double computeB_basic(double t, double a, double b ,double c, double d) {
	return (pow(t, 3) * a + pow(t, 2) * b + t * c + d) * (1.0 / 6);
}

void B_spline() {
	double accurancy = 1.0 / 10000;
	for (int point = 0; point < points.size()-3; point++)
	{
		cout << point << endl;
		for (int i = 1; i < 1 / accurancy; i++)
		{
			double t = accurancy * i;
			double x = 0, y = 0;
			double Bratio[4];
			Bratio[0] = computeB_basic(t, -1.0, 3.0, -3.0, 1.0);
			Bratio[1] = computeB_basic(t, 3.0, -6.0, 0.0, 4.0);
			Bratio[2] = computeB_basic(t, -3.0, 3.0, 3.0, 1.0);
			Bratio[3] = computeB_basic(t, 1.0, 0.0, 0.0, 0.0);
			
			for (int j = point, num = 0; j < point + 4; j++,num++)
			{
				x += Bratio[num] * points[j].getX();
				y += Bratio[num] * points[j].getY();
			}
			putPixel(x, y);
		}
	}
}