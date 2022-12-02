#include "OpenGl.h"
int LBlineClip(double p,double q,double &umax,double &umin) {
	double u = 0.0;
	if (p < 0.0) {
		u = p / q;
		if (u>umin) {
			return 0;
		}
		else if (u>umax) {
			umax = u;
		}
	}
	else if(p>0.0)
	{
		u = p / q;
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

void Liang_Barsky(double xl, double xr,double yt,double yb,double x1,double y1,double x2,double y2) {
	double delta_X = x2 - x1, delta_Y = y2 - y1, umax = 0.0, umin = 1.0;
	if (LBlineClip(-delta_X,x1-xl,umax,umin))
	{
		if (LBlineClip(delta_X,xr-x1,umax,umin))
		{
			if (LBlineClip(-delta_Y, y1-yb,umax,umin))
			{
				if (LBlineClip(delta_Y,yt-y1,umax,umin))
				{
						x1 = int(x1+delta_X*umax);
						y1 = int(y1+delta_Y*umax);
						x2 = int(x2+delta_X*umin);
						x2 = int(y2+delta_Y*umin);
						Bresenham(x1,y1,x2,y2);
				}
			}
		}
	}
}