#include "OpenGl.h"
extern int mode;
void MainMenuHandler(int option) {

	switch (option)
	{
	case 1: {
		cout << "menu 1" << endl;
	}break;
	case 2: {
		cout << "menu 2" << endl;
	}break;
	case 3: {
		cout << "menu 3" << endl;
	}break;
	case 4: {
		cout << "menu 4" << endl;
	}break;
	case 5: {
		cout << "menu 5" << endl;
	}break;
	default:
		break;
	}

}

void SubMenuHandler1(int option) {
	switch (option)
	{
		case 1: {
			cout << "����" << endl;
			mode = 1;
		}break;
		case 2: {
			cout << "menu 2" << endl;
		}break;
		case 3: {
			cout << "menu 3" << endl;
		}break;
		case 4: {
			cout << "menu 4" << endl;
		}break;
		case 5: {
			cout << "menu 5" << endl;
		}break;
		default:
			break;
		}
}

void SubMenuHandler2(int option) {
	switch (option)
	{
	case 1: {
		cout << "menu 1" << endl;
	}break;
	case 2: {
		cout << "menu 2" << endl;
	}break;
	case 3: {
		cout << "menu 3" << endl;
	}break;
	case 4: {
		cout << "menu 4" << endl;
	}break;
	case 5: {
		cout << "menu 5" << endl;
	}break;
	default:
		break;
	}
}

void SubMenuHandler3(int option) {
	switch (option)
	{
	case 1: {
		cout << "menu 1" << endl;
	}break;
	case 2: {
		cout << "menu 2" << endl;
	}break;
	case 3: {
		cout << "menu 3" << endl;
	}break;
	case 4: {
		cout << "menu 4" << endl;
	}break;
	case 5: {
		cout << "menu 5" << endl;
	}break;
	default:
		break;
	}
}

void myMenu() {

	//�����Ӳ˵�
	int submenu1 = glutCreateMenu(SubMenuHandler1);
	glutAddMenuEntry("����", 1);
	glutAddMenuEntry("������", 2);
	glutAddMenuEntry("��������", 3);
	glutAddMenuEntry("Բ��", 4);
	glutAddMenuEntry("ֱ��", 5);
	glutAddMenuEntry("����������", 6);
	glutAddMenuEntry("B��������", 7);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	//�����Ӳ˵�
	int submenu2 = glutCreateMenu(SubMenuHandler2);
	glutAddMenuEntry("��ת", 1);
	glutAddMenuEntry("ƽ��", 2);
	glutAddMenuEntry("����", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	//�����Ӳ˵�
	int submenu3 = glutCreateMenu(SubMenuHandler3);
	glutAddMenuEntry("��ɫ", 1);
	glutAddMenuEntry("��ɫ", 2);
	glutAddMenuEntry("��ɫ", 3);
	glutAddMenuEntry("��ɫ", 4);
	glutAddMenuEntry("��ɫ", 5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	int mianmenu = glutCreateMenu(MainMenuHandler);
	//�����˵���
	glutAddMenuEntry("����", 1);
	glutAddSubMenu("����ͼ��", submenu1);
	glutAddSubMenu("���α任ģʽ", submenu2);
	glutAddSubMenu("��ɫ�任", submenu3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

}