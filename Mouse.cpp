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
//				cout << "���λ滭����" << endl;
//				beginX = x, beginY = y;
//				endX = x, endY = y;
//				cout << "��ʼ����=" << " (" << x << " , " << y << ") " << endl;
//				glutMotionFunc(&Motion);
//				glutDisplayFunc(&RectDisplay);
//				drawRect(beginX, beginY, beginX, beginY);
//			}
//		}
//		if (state == GLUT_UP)
//		{
//			if (mode==1)
//			{
//				cout << "�ָ���ʼ" << endl;
//				mode = 0;
//			}
//		}
//	}
//}
//void Motion(int x,int y) {
//	if (mode == 1)
//	{
//		cout << "�ƶ�����" << " (" << x << " , " << y << ") " << endl;
//		endX = x;
//		endY = y;
//		drawRect(beginX, beginY, x, y);
//	}
//}