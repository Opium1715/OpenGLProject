#include "OpenGl.h"
extern int mode;
extern vector<Graph> graphList;
extern GLfloat red, green, blue;

void MainMenuHandler(int option) {

	switch (option)
	{
	case 1: {
		cout << "�ü��߶�" << endl;
		glutSpecialFunc(&SpecialKey);
		glutDisplayFunc(&Display3);
		mode = Clip;
	}break;
	case 2: {
		cout << "���ͼ��" << endl;
		glutDisplayFunc(&Display);
		Display();
		graphList.clear();
	}break;
	case 3: {
		cout << "����ͼ��" << endl;
		TCHAR szFile[MAX_PATH] = { 0 };
		if (FileDialog(szFile, 1))
		{
			SaveToFile(TCHARToChar(szFile));
		}
		glutPostRedisplay();
		/*string filename = "C:/Users/ZhangQi/Desktop/41.txt";
		SaveToFile(filename);*/
	}break;
	case 4: {
		cout<<"���ļ�" << endl;
		TCHAR szFile[MAX_PATH] = { 0 };
		if (FileDialog(szFile, 0))
		{
			ReadFromFile(TCHARToChar(szFile));
		}
		glutPostRedisplay();
		/*string filename = "C:/Users/ZhangQi/Desktop/41.txt";
		ReadFromFile(filename);*/
	}break;
	case 5: {
		cout<<"�˳��������" << endl;
		exit(0);
	}break;
	case 6: {
		cout << "������һ��ͼ��" << endl;
		graphList.pop_back();
		glutPostRedisplay();
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
			glutMouseFunc(&RectMouse);
			mode = rect;
		}break;
		case 2: {
			cout << "������" << endl;
			glutMouseFunc(&TriMouse);
			mode = triangle;
		}break;
		case 3: {
			cout << "��������" << endl;
			glutMouseFunc(&PolyMouse);
			mode = polygon;
		}break;
		case 4: {
			cout << "Բ��" << endl;
			glutMouseFunc(&CircleMouse);
			mode = circular;
		}break;
		case 5: {
			cout << "ֱ��" << endl;
			glutMouseFunc(&lineMouse);
			mode = line;
		}break;
		case 6: {
			cout << "����������" << endl;
			glutMouseFunc(&myMouse);
			glutDisplayFunc(&Display4);
			mode = bezier;
		}break;
		case 7: {
			cout << "B��������" << endl;
			glutMouseFunc(&myMouse);
			glutDisplayFunc(&Display4);
			mode = b_spline;
		}break;
	
		default:
			break;
		}
}

void SubMenuHandler2(int option) {
	switch (option)
	{
	case 1: {
		cout << "��ת" << endl;
		glutMouseFunc(&GTMouse);
		mode = rotate;
	}break;
	case 2: {
		cout << "ƽ��" << endl;
		glutMouseFunc(&GTMouse);
		mode = translate;
	}break;
	case 3: {
		cout << "����" << endl;
		glutMouseFunc(&GTMouse);
		mode = scale;
	}break;
	default:
		break;
	}
}

void SubMenuHandler3(int option) {
	switch (option)
	{
	case 1: {
		cout << "��ɫ" << endl;
		red = 1.0;
		green = 1.0;
		blue = 0.0;
	}break;
	case 2: {
		cout << "��ɫ" << endl;
		red = 0.0;
		green = 0.5;
		blue = 0.0;
	}break;
	case 3: {
		cout << "��ɫ" << endl;
		red = 1.0;
		green = 0.0;
		blue = 0.0;
	}break;
	case 4: {
		cout << "��ɫ" << endl;
		red = 0.0;
		green = 0.0;
		blue = 1.0;
	}break;
	case 5: {
		cout << "��ɫ" << endl;
		red = 1.0;
		green = 1.0;
		blue = 1.0;
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
	glutAddMenuEntry("��ջ���",2);
	glutAddMenuEntry("����", 3);
	glutAddMenuEntry("���ļ�", 4);
	glutAddMenuEntry("����", 6);
	glutAddSubMenu("����ͼ��", submenu1);
	glutAddSubMenu("���α任ģʽ", submenu2);
	glutAddSubMenu("��ɫ�任", submenu3);
	glutAddMenuEntry("�˳�",5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

}