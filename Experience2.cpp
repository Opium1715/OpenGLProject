#include "OpenGl.h"
void Translate(float tx,float ty) {
	glColor3f(0.1f, 1.0f, 0.1f);
	glRecti(0.0, 0.0, 100.0, 100.0);//ԭʼ���δ�С
	glPushMatrix();
	glTranslatef(tx, ty, 0.0);
	//glRotatef(45.0, 0.0, 0.0, 1.0);
	glColor3f(0.6f, 0.5f, 0.0f);
	glRecti(0.0, 0.0, 100.0, 100.0);//Ŀ��ƽ�ƺ�ľ��δ�С
	glPopMatrix();//������ƽ����ת����ľ��������Ķ���ľ�����м���ó����վ���λ��
}
void Rotate(int angle) {
	glPushMatrix();
	glRotatef(angle, 0.0, 0.0, 1.0);//���Ƕȣ�x��������y��������z������������Ȼ��ǰ�����ţ�0��0��1������������ת
	glColor3f(0.8f, 0.6f, 0.0f);
	glRecti(0.0, 0.0, 100.0, 100.0);//Ŀ��ƽ�ƺ�ľ��δ�С,���任������þ��εĹ淶���������������ת��
	glPopMatrix();
}
void Zoom(int x_ratio, int y_ratio) {

	glPushMatrix();
	glScalef(x_ratio, y_ratio, 1.0);//��ά�任���漰Z��
	glColor3f(1.0f, 0.6f, 0.0f);
	glRecti(0.0, 0.0, 100.0, 100.0);//Ŀ��ƽ�ƺ�ľ��δ�С
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