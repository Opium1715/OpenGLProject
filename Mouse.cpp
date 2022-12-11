//#include"OpenGl.h"
//extern int beginX, beginY;
//extern int endX, endY;
//extern int mode;
//void Mouse(int button, int state, int x, int y) {
//	if (button == GLUT_LEFT_BUTTON)
//	{
//		if (state == GLUT_DOWN)
//		{
//			if (mode==1)
//			{
//				cout << "¾ØÐÎ»æ»­²âÊÔ" << endl;
//				beginX = x, beginY = y;
//				endX = x, endY = y;
//				cout << "ÆðÊ¼×ø±ê=" << " (" << x << " , " << y << ") " << endl;
//				glutMotionFunc(&Motion);
//				glutDisplayFunc(&RectDisplay);
//				drawRect(beginX, beginY, beginX, beginY);
//			}
//		}
//		if (state == GLUT_UP)
//		{
//			if (mode==1)
//			{
//				cout << "»Ö¸´³õÊ¼" << endl;
//				mode = 0;
//			}
//		}
//	}
//}
//void Motion(int x,int y) {
//	if (mode == 1)
//	{
//		cout << "ÒÆ¶¯×ø±ê" << " (" << x << " , " << y << ") " << endl;
//		endX = x;
//		endY = y;
//		drawRect(beginX, beginY, x, y);
//	}
//}