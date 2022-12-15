#include "OpenGl.h"
extern int mode;
extern vector<Graph> graphList;
extern GLfloat red, green, blue;

void MainMenuHandler(int option) {

	switch (option)
	{
	case 1: {
		cout << "裁剪线段" << endl;
		glutSpecialFunc(&ClipSpecialKey);
		mode = Clip;
	}break;
	case 2: {
		cout << "清空图形" << endl;
		glutDisplayFunc(&Display);
		Display();
		graphList.clear();
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
			cout << "矩形" << endl;
			glutMouseFunc(&RectMouse);
			mode = rect;
		}break;
		case 2: {
			cout << "三角形" << endl;
			glutMouseFunc(&TriMouse);
			mode = triangle;
		}break;
		case 3: {
			cout << "任意多边形" << endl;
			glutMouseFunc(&PolyMouse);
			mode = polygon;
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
		cout << "黄色" << endl;
		red = 1.0;
		green = 1.0;
		blue = 0.0;
	}break;
	case 2: {
		cout << "绿色" << endl;
		red = 0.0;
		green = 0.5;
		blue = 0.0;
	}break;
	case 3: {
		cout << "红色" << endl;
		red = 1.0;
		green = 0.0;
		blue = 0.0;
	}break;
	case 4: {
		cout << "蓝色" << endl;
		red = 0.0;
		green = 0.0;
		blue = 1.0;
	}break;
	case 5: {
		cout << "白色" << endl;
		red = 1.0;
		green = 1.0;
		blue = 1.0;
	}break;
	default:
		break;
	}
}

void myMenu() {

	//创建子菜单
	int submenu1 = glutCreateMenu(SubMenuHandler1);
	glutAddMenuEntry("矩形", 1);
	glutAddMenuEntry("三角形", 2);
	glutAddMenuEntry("任意多边形", 3);
	glutAddMenuEntry("圆形", 4);
	glutAddMenuEntry("直线", 5);
	glutAddMenuEntry("贝塞尔曲线", 6);
	glutAddMenuEntry("B样条曲线", 7);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	//创建子菜单
	int submenu2 = glutCreateMenu(SubMenuHandler2);
	glutAddMenuEntry("旋转", 1);
	glutAddMenuEntry("平移", 2);
	glutAddMenuEntry("缩放", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	//创建子菜单
	int submenu3 = glutCreateMenu(SubMenuHandler3);
	glutAddMenuEntry("黄色", 1);
	glutAddMenuEntry("绿色", 2);
	glutAddMenuEntry("红色", 3);
	glutAddMenuEntry("蓝色", 4);
	glutAddMenuEntry("白色", 5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	int mianmenu = glutCreateMenu(MainMenuHandler);
	//创建菜单项
	glutAddMenuEntry("裁切", 1);
	glutAddMenuEntry("清空画板",2);
	glutAddSubMenu("基础图形", submenu1);
	glutAddSubMenu("几何变换模式", submenu2);
	glutAddSubMenu("颜色变换", submenu3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

}