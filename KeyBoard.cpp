#include"OpenGl.h"

Point wpoint0(200, 100);
Point wpoint1(500, 200);

void ClipReshape(int w, int h) {
	//glViewport(0, 0, (GLsizei)w, (GLsizei)h);//改变显示区域，起始位置为客户端窗口左下角（非坐标原点）
	glViewport(wpoint0.getX(), wpoint0.getY(), wpoint1.getX(), wpoint1.getY());
	glMatrixMode(GL_PROJECTION);//修改投影矩阵
	glLoadIdentity();//导入单位阵
	gluOrtho2D(wpoint0.getX(), wpoint1.getX(), wpoint1.getY(), wpoint0.getY());
	//gluOrtho2D(0.0, 800.0, 600.0, 0.0);//反转y方向，使屏幕坐标系符合操作逻辑
}

void drawwindow(int x0,int y0, int x1, int y1) {
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 1.0, 0.1);
	glVertex2f(x0, y0);
	glVertex2f(x1, y0);
	glVertex2f(x1, y1);
	glVertex2f(x0, y1);
	glEnd();
}

void ClipSpecialKey(int key, int x, int y) {
	if (mode == Clip)
	{
		if (key == GLUT_KEY_UP)
		{
			cout << "up" << endl;
			/*wpoint0.setY(wpoint0.getY() - 1);
			wpoint1.setY(wpoint1.getY() - 1);*/
		}
		if (key == GLUT_KEY_DOWN)
		{
			cout << "down" << endl;
			/*wpoint0.setY(wpoint0.getY() + 1);
			wpoint1.setY(wpoint1.getY() + 1);*/
		}
		if (key == GLUT_KEY_LEFT)
		{
			cout << "left" << endl;
			/*wpoint0.setY(wpoint0.getX() - 1);
			wpoint1.setY(wpoint1.getX() - 1);*/
		}
		if (key == GLUT_KEY_RIGHT)
		{
			cout << "right" << endl;
			/*wpoint0.setY(wpoint0.getX() + 1);
			wpoint1.setY(wpoint1.getX() + 1);*/
		}
	}
	drawwindow(wpoint0.getX()-1, wpoint0.getY()-1, wpoint1.getX()-1, wpoint1.getY()-1);

	glutSwapBuffers();
}