#include "OpenGl.h"
int LBlineClip(double p,double q,double &umax,double &umin) {
	double u = 0.0;
	if (p < 0.0) {//计算umax,起点处比例
		u = q / p;
		if (u>umin) {
			return 0;
		}
		else if (u>umax) {
			umax = u;
		}
	}
	else if(p>0.0)
	{//计算umin,终点处比例
		u = q / p;
		if (u < umax) {
			return 0;
		}
		else if (u<umin) {
			umin = u;
		}
	}
	else if(q<0)	//p==0
	{
		return 0;
	}
	return 1;
}

void Liang_Barsky(double x1,double y1,double x2,double y2,  double yt, double yb, double xl, double xr) {
	double delta_X = x2 - x1, delta_Y = y2 - y1, umax = 0.0, umin = 1.0;
	double basic_X = x1, basic_Y = y1;
	if (LBlineClip(-delta_X,x1-xl, umax, umin))
	{
		if (LBlineClip(delta_X,xr-x1,umax,umin))
		{
			if (LBlineClip(-delta_Y, y1-yb,umax,umin))
			{
				if (LBlineClip(delta_Y,yt-y1,umax,umin))
				{
						x1 = int(basic_X+delta_X*umax+0.5);
						y1 = int(basic_Y+delta_Y*umax+0.5);
						x2 = int(basic_X+delta_X*umin+0.5);
						y2 = int(basic_Y+delta_Y*umin+0.5);	
						cout << "裁剪后坐标: (" << x1 << "," << y1 << ") ";
						cout << "裁剪后坐标: (" << x2 << "," << y2 << ")"<<endl;
						Bresenham(x1, y1, x2, y2);
				}
			}
		}
	}
}