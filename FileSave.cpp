#include "OpenGl.h"


//	TCHAR 转 Char
char* TCHARToChar(TCHAR* pTchar)
{
	char* pChar = nullptr;
	int nLen = wcslen(pTchar) + 1;
	pChar = new char[nLen * 2];
	WideCharToMultiByte(CP_ACP, 0, pTchar, nLen, pChar, 2 * nLen, NULL, NULL);
	return pChar;
}

int openwindow() {
	OPENFILENAME ofn;									//	公共对话框结构
	TCHAR szFile[MAX_PATH];								//	保存获取文件名称的缓冲区
	ZeroMemory(&ofn, sizeof(OPENFILENAME));				//	初始化选择文件对话框
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = NULL;
	ofn.lpstrFile = szFile;
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = _T("All(*.*)\0*.*\0Text(*.txt)\0*.TXT\0\0");
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	return GetOpenFileName(&ofn);
}

//	打开文件窗口
int FileDialog(TCHAR* path, int option)
{
	OPENFILENAME ofn;
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);						//	结构大小
	ofn.lpstrFile = path;								//	路径
	ofn.nMaxFile = MAX_PATH;							//	路径大小
	ofn.lpstrFilter = _T("All\0*.*\0Text\0*.TXT\0");	//	文件类型
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	if (option == 0) {
		return GetOpenFileName(&ofn);
	}
	else {
		return GetSaveFileName(&ofn);
	}
}






string toString(int f)
{
	ostringstream oss;
	oss << f;
	return oss.str();
}

vector<string> splitStr(string liner, string flag)
{
	vector<string> token;
	auto split_pos = liner.find(flag);//先找到空格在的下标。
	while (split_pos < liner.length())
	{
		token.push_back(liner.substr(0, split_pos));
		liner.erase(0, split_pos + 1);
		split_pos = liner.find(flag);
	}
	return token;
}

void ReadFromFile(string filename) 
{
	ifstream file(filename);
	if (!file)
	{
		cout<<"Not Found!" << endl;
		exit(-1);
	}
	string s;
	while (!file.eof())
	{
		getline(file, s);//read a line
		vector<string> spilt = splitStr(s, " ");//按空格分开
		if (spilt.size()==0) break;
		int type = atoi(spilt[0].c_str());
		int R = atoi(spilt[1].c_str());
		int G = atoi(spilt[2].c_str());
		int B = atoi(spilt[3].c_str());
		int sizeofPoints = atoi(spilt[4].c_str());
		int next = 5;
		vector<Point> points;
		for (int i = 0; i <sizeofPoints ; i++)
		{
			int x = atoi(spilt[next].c_str());
			next++;
			int y = atoi(spilt[next].c_str());
			next++;
			points.push_back(Point(x, y));
		}
		Graph g(points,type,R,G,B);
		graphList.push_back(g);

	}
	file.close();
	cout<<"读取图形文件完成" << endl;
	glutPostRedisplay();
}

//保存文件
void SaveToFile(string filename)
{
	ofstream file(filename); 
	string space = " ";
	for (int i = 0; i != graphList.size(); i++)
	{
		string p = "";
		//RGB
		float color[3];
		graphList[i].getRGB(color);
		string co = toString(color[0]) + space + toString(color[1]) + space +
			toString(color[2]) + space;//最后一个空格
		//Points
		vector <Point> gPoint = graphList[i].getPoints();
		for (int j = 0; j < gPoint.size(); j++)
		{
			p = p + toString(gPoint[j].getX()) + space + toString(gPoint[j].getY()) + space;
		}
		string sizeofPoints = toString(gPoint.size());
		//type
		string s = toString(graphList[i].getType()) + space + co + sizeofPoints + space + p;
		file << s << endl;
	}
	file.close();
	cout<<"保存成功！" << endl;
}
