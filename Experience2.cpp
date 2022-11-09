#include "OpenGl.h"
void Translate(float tx,float ty) {
	glColor3f(0.1f, 1.0f, 0.1f);
	glRecti(0.0, 0.0, 100.0, 100.0);//原始矩形大小
	glPushMatrix();
	glTranslatef(tx, ty, 0.0);
	glRotatef(45.0, 0.0, 0.0, 1.0);
	glColor3f(0.6f, 0.5f,0.0f);
	glRecti(0.0, 0.0, 100.0, 100.0);//目标平移后的矩形大小
	glPopMatrix();//将经过平移旋转计算的矩阵与上文定义的矩阵进行计算得出最终矩阵位置
}
void Display2() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	Translate(50.0, 42.5);
	glFlush();
}