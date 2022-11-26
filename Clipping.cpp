#include "OpenGl.h"
unsigned char P1;
unsigned char P2;
vector<vector<int> > point0;
vector<vector<int> > point1;
void Display3() 
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 1.0, 0.1);
	glVertex2f(-200, -100);
	glVertex2f(200, - 100);
	glVertex2f(200, 100);
	glVertex2f(-200, 100);
	glEnd();
	
	glFlush();
}


unsigned int Encode(int x0, int y0, int yt, int yb, int xl, int xr) {
	/*window :
	* 0x09 | 0x08 | 0x0a
	* --------------------
	* 0x01 | 0x00 | 0x02
	* --------------------
	* 0x05 | 0x04 | 0x06
	*/
	unsigned int temp = 0x00;
	if (x0 < xl) {//窗口左侧
		if (y0 < yb) {//窗口左下侧
			temp = 0x05;
		}
		else if (y0 > yt) {//窗口左下侧
			temp = 0x09;
		}
		else
		{
			temp = 0x01;
		}
	}
	else if (x0 > xr) {
		if (y0 < yb) {
			temp = 0x06;
		}
		else if (y0 > yt) {
			temp = 0x0a;
		}
		else
		{
			temp = 0x02;
		}
	}
	else
	{
		if (y0 < yb) {
			temp = 0x04;
		}
		else if (y0 > yt) {
			temp = 0x08;
		}
	}
	return temp;
}

void Cohen_Sutherland(int x0,int y0,int x1,int y1,int yt,int yb,int xl,int xr ) 
{
	unsigned int P1Code = Encode(x0, y0, yt,  yb,  xl,  xr);
	unsigned int P2Code = Encode(x1, y1, yt, yb, xl, xr);

	double k = ((double)y1 - y0) / ((double)x1 - x0);
	int i = 1;
	while (true)
	{
		cout << "第" << i << "次裁剪操作" << endl;
		i++;
		if ((P1Code | P2Code) == 0)
		{	//简取
			Bresenham(x0, y0, x1, y1);
			break;
		}
		else if ((P1Code & P2Code)!=0) {
			break;
		}
		else if ((P1Code & P2Code) == 0) {
			if (P1Code == 0) {
				swap(P1Code, P2Code);
				swap(x0, x1);
				swap(y0, y1);
				cout << "exchange" << endl;
			}
			//先确定P1点是在左边还是右边
			if ((P1Code & 0x01) == 1) {
				//left
				int newy = int((y0 + k * ((double)xl -(double) x0))+0.5);
				cout<< "与左边界交点：" << newy << endl;
				unsigned int Scode = Encode(xl, newy, yt, yb, xl, xr);
				//判断求得的交点是否为实交点
				if(Scode != 0){//虚点
					if ((P1Code & 0x08) == 8) {
						//left top
						int newx = int((x0 + ((double)yt - y0) / k) + 0.5);
						cout<< "与上边界交点：" << newx << endl;
						P1Code = Encode(newx, yt, yt, yb, xl, xr);
						x0 = newx;
						y0 = yt;
					}
					else if ((P1Code & 0x04) == 4) {
						//left bottom
						int newx = int((x0 + ((double)yb - y0) / k) + 0.5);
						cout << "与下边界交点：" << newx << endl;
						P1Code = Encode(newx, yb, yt, yb, xl, xr);
						x0 = newx;
						y0 = yb;
					}
					else
					{
						break;
					}
				}
				else
				{
					P1Code = Scode;
					y0 = newy;
					x0 = xl;
				}
			}
			else if((P1Code & 0x02) == 2)
			{
				//right
				int newy = int((y0 + k * ((double)xr - x0)) + 0.5);
				cout << "与右边界交点：" << newy << endl;
				unsigned int Scode = Encode(xr, newy, yt, yb, xl, xr);
				//判断求得的交点是否为实交点
				if (Scode != 0) {
					if ((P1Code & 0x08) == 8) {
						//right top
						int newx = int((x0 + ((double)yt - y0) / k) + 0.5);
						cout << "与上边界交点：" << newx << endl;
						P1Code = Encode(newx, yt, yt, yb, xl, xr);
						x0 = newx;
						y0 = yt;
					}
					else if ((P1Code & 0x04) == 4) {
						//right bottom
						int newx = int((x0 + ((double)yb - y0) / k) + 0.5);
						cout << "与下边界交点：" << newx << endl;
						P1Code = Encode(newx, yb, yt, yb, xl, xr);
						x0 = newx;
						y0 = yb;
					}
					else
					{
						break;
					}
				}
				else
				{
					P1Code = Scode;
					y0 = newy;
					x0 = xr;
				}
			}
			else
			{
				//mid
				if ((P1Code & 0x08) == 8) {
					// top
					int newx = int((x0 + ((double)yt - y0) / k) + 0.5);
					cout << "与上边界交点：" << newx << endl;
					P1Code = Encode(newx, yt, yt, yb, xl, xr);
					x0 = newx;
					y0 = yt;
				}
				else if ((P1Code & 0x04) == 4) {
					// bottom
					int newx = int((x0 + ((double)yb - y0) / k) + 0.5);
					cout << "与下边界交点：" << newx << endl;
					P1Code = Encode(newx, yb, yt, yb, xl, xr);
					x0 = newx;
					y0 = yb;
				}
			}
		}
	}
}


void keyboard(unsigned char key,int x,int y)
{
	if (key == 'c') {
		cout << "cut" << endl;
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_LINE_LOOP);
		glColor3f(1.0, 1.0, 0.1);
		glVertex2f(-200, -100);
		glVertex2f(200, -100);
		glVertex2f(200, 100);
		glVertex2f(-200, 100);
		glEnd();
		for (int i = 0; i < point0.size(); i++)
		{
			Cohen_Sutherland(point0[i][0], point0[i][1], point1[i][0], point1[i][1], 100, -100, -200, 200);
		}
		glFlush();
	}

	if (key == 'r') {
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_LINE_LOOP);
		glColor3f(1.0, 1.0, 0.1);
		glVertex2f(-200, -100);
		glVertex2f(200, -100);
		glVertex2f(200, 100);
		glVertex2f(-200, 100);
		glEnd();
		for (int i = 0; i < point0.size(); i++)
		{
			Bresenham(point0[i][0], point0[i][1], point1[i][0], point1[i][1]);
		}
		glFlush();
	}
	if (key == 'p')
	{
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_LINE_LOOP);
		glColor3f(1.0, 1.0, 0.1);
		glVertex2f(-200, -100);
		glVertex2f(200, -100);
		glVertex2f(200, 100);
		glVertex2f(-200, 100);
		glEnd();
		point0.clear();
		point1.clear();
		glFlush();
	}
	if (key == 'd')
	{
		cout << "draw" << endl;
		int randomX1 = (rand() % 601) - 300;
		int randomY1 = (rand() % 401) - 200;
		int randomX0 = (rand() % 601) - 300;
		int randomY0 = (rand() % 401) - 200;
		vector<int> x0v;
		x0v.push_back(randomX0);
		x0v.push_back(randomY0);
		point0.push_back(x0v);
		vector<int> x1v;
		x1v.push_back(randomX1);
		x1v.push_back(randomY1);
		point1.push_back(x1v);
		cout << "(" << randomX0 << "," << randomY0 << ")"<<" ";
		cout << "(" << randomX1 << "," << randomY1 << ")"<<endl;
		Bresenham(randomX0, randomY0, randomX1, randomY1);
		glFlush();
	}
}
