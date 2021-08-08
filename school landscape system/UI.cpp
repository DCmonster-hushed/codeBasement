#include "UI.h"

UI::UI()
{
	VertexData temp = { "0","东苑","东苑住宿区，包含东苑食堂，学生服务中心等设施" };
	map.insertVertex(temp);
	temp = {"1","西苑","西苑住宿区" };
	map.insertVertex(temp);
	temp = { "2","南苑","" };
	map.insertVertex(temp);
	temp = { "3","镜湖","" };
	map.insertVertex(temp);
	temp = { "4","象山","" };
	map.insertVertex(temp);
	temp = { "5","厚学","" };
	map.insertVertex(temp);
	temp = { "6","音乐台","" };
	map.insertVertex(temp);
	temp = { "7","亚青","" };
	map.insertVertex(temp);
	temp = { "8","校史馆","" };
	map.insertVertex(temp);
	temp = { "9","图书馆","" };
	map.insertVertex(temp);
	temp = { "10","浦江操场","" };
	map.insertVertex(temp);
	temp = { "11","浦江教学楼","" };
	map.insertVertex(temp);
	map.setN(12);

	/*      N 0
*      NW 7    NE 1
*    W 6           E 2
*      SW 5     SE 3
		   S 4
*/
	EdgeData e = { true,300,0 };
	map.insertEdge(e, 0, 9);
	map.insertEdge(e, 9, 0);
	e = {true,300,7 };
	map.insertEdge(e, 0, 3);
	map.insertEdge(e, 3, 0);
	e = { true,500,2 };
	map.insertEdge(e, 0, 10);
	map.insertEdge(e, 10, 0);
	e = { true,500,3 };
	map.insertEdge(e, 0, 5);
	map.insertEdge(e, 5, 0);
	e = { true,300,4 };
	map.insertEdge(e, 0, 6);
	map.insertEdge(e, 6, 0);
	e = { true,100,6 };
	map.insertEdge(e, 0, 1);
	map.insertEdge(e, 1, 0);
	e = { true,200,4 };
	map.insertEdge(e, 1, 2);
	map.insertEdge(e, 2, 1);
	e = { true,100,3 };
	map.insertEdge(e, 2, 6);
	map.insertEdge(e, 6, 2);
	e = { true,300,7 };
	map.insertEdge(e, 3, 4);
	map.insertEdge(e, 4, 3);
	e = { true,200,6 };
	map.insertEdge(e, 4, 7);
	map.insertEdge(e, 7, 4);
	e = { true,150,6 };
	map.insertEdge(e, 5, 6);
	map.insertEdge(e, 6, 5);
	e = { true,500,1 };
	map.insertEdge(e, 5, 11);
	map.insertEdge(e, 11, 5);
	e = { true,600,0 };
	map.insertEdge(e, 3, 8);
	map.insertEdge(e, 8, 3);
	e = { true,100,5 };
	map.insertEdge(e, 10, 11);
	map.insertEdge(e, 11, 10);

	map.setE(14);
}



void UI::CleanConsole(int x, int y)     //y是指定要删除的行数，x可以从0位置开始循环替换到的截止位置
{
	COORD loc;
	loc.Y = y;    //固定行数
	for (int i = 0; i < x; i++)     //x从指定位置开始循环进行替换
	{
		loc.X = i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
		cout << " " << endl;;
	}
}
void UI::CleanConsole(int y)     //y是指定要删除的行数，直接指定x：0~50的位置进行清空
{
	COORD loc;
	loc.Y = y;    //固定行数
	for (int i = 0; i < 50; i++)     //x从指定位置开始循环进行替换
	{
		loc.X = i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
		cout << " " << endl;;
	}
}

void UI::writeChar(int x, int y, string pchar, char color)
{
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;   //光标的厚度
	cci.bVisible = FALSE;    //光标不可见
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

	COORD loc = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	cout << pchar;
}

int UI::mainManu()
{
	string options[] = { "显示地图" , "查找菜单","更新景点","退出" };    //这里这样定义是为了使得option的值能和options的下标对应，便于刷新输出
	system("mode con cols=100 lines=50");
	writeChar(18, 10, "南京工业大学景点", 7);
	writeChar(16, 12, "→", 10);
	for (int i = 0; i < 4; i++)
	{
		writeChar(18, 12 + i, options[i], 10);
	}
	char ch;
	int option = 0;    //默认指向最上面的选项
	while (true)
	{
		if (_kbhit())
		{
			ch = _getch();  //不进行回显

			if (ch == 27)   //esc
			{
				return -1;
			}
			if (ch == 72 || ch == 80 || ch == '\r')  //只检测上下键+回车直接返回当前的option值
			{

				if (ch == 72)	//UP
				{
					writeChar(16, 12 + option, "  ", 0);
					option--;
				}
				else if (ch == 80)	//DOWN
				{
					writeChar(16, 12 + option, "  ", 0);
					option++;
				}
				if (option < 0)    //防止越界
				{
					option = 0;
				}
				else if (option >= 4)    //一直让其指向租后一个选项
				{
					option--;
				}
				//处理按上下键之后的显示
				writeChar(16, 12 + option, "                        ", 0);
				Sleep(100);
				writeChar(16, 12 + option, "→", 10);
				writeChar(18, 12 + option, options[option], 10);

				if (ch == '\r')
				{
					return option;
				}
			}
		}
	}
}

void UI::mapPage()
{
	system("cls");
	map.print();
}

int UI::searchPage()
{
	system("cls");
	VertexData s;
	string options[] = { "查找景点","查找最短路径" };    //这里这样定义是为了使得option的值能和options的下标对应，便于刷新输出
	writeChar(18, 10, "南京工业大学", 10);
	writeChar(16, 12, "→", 10);
	for (int i = 0; i < map.getN(); i++) {
		s = map.getVexlist(i);
		if (s.code != "-1") {
			writeChar(0, 8 + i, s.code, 9);
			writeChar(6, 8 + i, s.location_name, 10);
		}
	}
	for (int i = 0; i < 2; i++)
	{
		writeChar(18, 12 + i, options[i], 10);
	}
	char ch;
	int option = 0;    //默认指向最上面的选项
	while (true)
	{
		if (_kbhit())
		{
			ch = _getch();  //不进行回显

			if (ch == 27)   //esc
			{
				return -1;
			}
			if (ch == 72 || ch == 80 || ch == '\r')  //只检测上下键+回车直接返回当前的option值
			{

				if (ch == 72)	//UP
				{
					writeChar(16, 12 + option, "  ", 0);
					option--;
				}
				else if (ch == 80)	//DOWN
				{
					writeChar(16, 12 + option, "  ", 0);
					option++;
				}
				if (option < 0)    //防止越界
				{
					option = 0;
				}
				else if (option >= 2)    //一直让其指向租后一个选项
				{
					option--;
				}
				//处理按上下键之后的显示
				writeChar(16, 12 + option, "                        ", 0);
				Sleep(100);
				writeChar(16, 12 + option, "→", 10);
				writeChar(18, 12 + option, options[option], 10);

				if (ch == '\r')
				{
					return option;
				}
			}
		}
	}

}

int UI::renewPage()
{
	VertexData s;
	system("cls");
	for (int i = 0; i < map.getN(); i++) {
		s = map.getVexlist(i);
		if (s.code != "-1") {
			writeChar(0, 8 + i, s.code, 9);
			writeChar(6, 8 + i, s.location_name, 10);
		}
	}
	string options[] = { "添加景点","更新景点","删除景点" };    //这里这样定义是为了使得option的值能和options的下标对应，便于刷新输出
	writeChar(18, 10, "南京工业大学", 10);
	writeChar(16, 12, "→", 10);
	for (int i = 0; i < 3; i++)
	{
		writeChar(18, 12 + i, options[i], 10);
	}
	char ch;
	int option = 0;    //默认指向最上面的选项
	while (true)
	{
		if (_kbhit())
		{
			ch = _getch();  //不进行回显

			if (ch == 27)   //esc
			{
				return -1;
			}
			if (ch == 72 || ch == 80 || ch == '\r')  //只检测上下键+回车直接返回当前的option值
			{

				if (ch == 72)	//UP
				{
					writeChar(16, 12 + option, "  ", 0);
					option--;
				}
				else if (ch == 80)	//DOWN
				{
					writeChar(16, 12 + option, "  ", 0);
					option++;
				}
				if (option < 0)    //防止越界
				{
					option = 0;
				}
				else if (option >= 3)    //一直让其指向租后一个选项
				{
					option--;
				}
				//处理按上下键之后的显示
				writeChar(16, 12 + option, "                        ", 0);
				Sleep(100);
				writeChar(16, 12 + option, "→", 10);
				writeChar(18, 12 + option, options[option], 10);

				if (ch == '\r')
				{
					return option;
				}
			}
		}
	}
}

void UI::addVertex()
{	
	VertexData s;
    system("cls");
	for (int i = 0; i < map.getN(); i++) {
		s = map.getVexlist(i);
		if (s.code != "-1") {
			writeChar(0, 8 + i, s.code, 9);
			writeChar(6, 8 + i, s.location_name, 10);
		}
	}
	cout << endl;
	string code, name, discribe;
	cout << "输入景点编号：";
	cin >> code;
	cout << "输入景点名称：";
	cin >> name;
	cout << "输入景点描述：";
	cin >> discribe;
	map.insertVertex(s);
}

void UI::renewVertex()
{
	system("cls");
	VertexData s;
	for (int i = 0; i < map.getN(); i++) {
		s = map.getVexlist(i);
		if (s.code != "-1") {
			writeChar(0, 8 + i, s.code, 9);
			writeChar(6, 8 + i, s.location_name, 10);
		}
	}
	cout << endl;
	string code,name,discribe;
	cout << "输入要修改的景点编码：";
	cin >> code;
	s = map.serchVexByCode(code);
	cout << "修改名称（e跳过）";
	cin >> name;
	if (name != "e") {
		s.location_name = name;
	}
	cout << "修改描述（e跳过）";
	cin >> discribe;
	if (discribe != "e") {
		s.discribe = discribe;
	}
	map.renewVertex(code, s);
}

void UI::searchLandscape()
{
	VertexData result1, result2,s1;
	string s;
	system("cls");
	for (int i = 0; i < map.getN(); i++) {
		s1 = map.getVexlist(i);
		if (s1.code != "-1") {
			writeChar(0, 8 + i, s1.code, 9);
			writeChar(6, 8 + i, s1.location_name, 10);
		}
	}
	cout << endl;
	cout << "请输入要查找的景点的名字或编码：";
	getline(cin, s);
	result1 = map.serchVexByCode(s);
	if (result1.code == "-1")
	{
		result2 = map.serchVexByName(s);
		if (result2.code == "-1")
			cout << "no result by code or name:" << s << endl;
		else
		{
			cout << result2.location_name << endl;
			cout << result2.code << endl;
			cout << result2.discribe << endl;
		}
	}
	else
	{
		cout << result1.location_name << endl;
		cout << result1.code << endl;
		cout << result1.discribe << endl;

	}

}

void UI::shortestPath_floid()
{
	int x, y;
	int i, j,k;
	for (i = 1; i <= map.getN(); i++)
		for (j = 0; j <= map.getN(); j++)
			d[i][j] = INF;
	for (i = 0; i <= map.getN(); i++)
	{
		for (j = 0; j < map.getN(); j++)
		{
			d[i][j] = map.getEdgeDistance(i, j);
			p[i][j] = i;
		}
	}
	for (k = 0; k <= map.getN(); k++)
	{
		for (i = 0; i <= map.getN(); i++)
			for (j = 0; j <= map.getN(); j++)
			{
				if (d[i][j] > d[i][k] + d[k][j])
				{
					d[i][j] = d[i][k] + d[k][j];
					p[i][j] = k;
				}
			}
	}
	system("cls");
	VertexData s;
	for (int i = 0; i < map.getN(); i++) {
		s = map.getVexlist(i);
		if (s.code != "-1") {
			writeChar(0, 8 + i, s.code, 9);
			writeChar(6, 8 + i, s.location_name, 10);
		}
	}
	cout << endl;
	cout << "输入出发点:";
	cin >> x;
	cout << "输入终点：";
	cin >> y;
	cout << "最短距离为：" << d[x][y] << endl;
	cout << "最短路径为：";
	getpath(x, y);
	cout << map.getVertexName(y) << endl;
}

void UI::getpath(int x, int y)
{
	    if (p[x][y] == x)
    {
        cout << map.getVertexName(x) << "->";
        return;
    }
    getpath(x, p[x][y]);
    getpath(p[x][y], y);

}

void UI::deletePage()
{
	VertexData s1;
	system("cls");
	for (int i = 0; i < map.getN(); i++) {
		s1 = map.getVexlist(i);
		if (s1.code != "-1") {
			writeChar(0, 8 + i, s1.code, 9);
			writeChar(6, 8 + i, s1.location_name, 10);
		}
	}
	cout << endl;
	string s;
	cout << "输入要删除的景点名字或编号：";
	cin >> s;
	system("cls");
	map.deleteVertex(s);
}

UI::~UI()
{
}