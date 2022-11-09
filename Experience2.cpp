#include "OpenGl.h"
void Translate(float tx,float ty) {
	glColor3f(0.1f, 1.0f, 0.1f);
	glRecti(0.0, 0.0, 100.0, 100.0);//原始矩形大小
	glPushMatrix();
	glTranslatef(tx, ty, 0.0);
	//glRotatef(45.0, 0.0, 0.0, 1.0);
	glColor3f(0.6f, 0.5f, 0.0f);
	glRecti(0.0, 0.0, 100.0, 100.0);//目标平移后的矩形大小
	glPopMatrix();//将经过平移旋转计算的矩阵与上文定义的矩阵进行计算得出最终矩阵位置
}
void Rotate(int angle) {
	glPushMatrix();
	glRotatef(angle, 0.0, 0.0, 1.0);//（角度，x轴向量，y轴向量，z轴向量），显然当前是绕着（0，0，1）向量方向旋转
	glColor3f(0.8f, 0.6f, 0.0f);
	glRecti(0.0, 0.0, 100.0, 100.0);//目标平移后的矩形大小,将变换矩阵与该矩形的规范化齐次坐标矩阵相乘转化
	glPopMatrix();
}
void Zoom(int x_ratio, int y_ratio) {

	glPushMatrix();
	glScalef(x_ratio, y_ratio, 1.0);//二维变换不涉及Z轴
	glColor3f(1.0f, 0.6f, 0.0f);
	glRecti(0.0, 0.0, 100.0, 100.0);//目标平移后的矩形大小
	glPopMatrix();
}
void Display2() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	Translate(50.0, 42.5);
	
	Rotate(35);
	
	Zoom(2.0, 1.1);
	
	glFlush();
}