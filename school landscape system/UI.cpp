#include "UI.h"

UI::UI()
{
	VertexData temp = { "0","��Է","��Էס������������Էʳ�ã�ѧ���������ĵ���ʩ" };
	map.insertVertex(temp);
	temp = {"1","��Է","��Էס����" };
	map.insertVertex(temp);
	temp = { "2","��Է","" };
	map.insertVertex(temp);
	temp = { "3","����","" };
	map.insertVertex(temp);
	temp = { "4","��ɽ","" };
	map.insertVertex(temp);
	temp = { "5","��ѧ","" };
	map.insertVertex(temp);
	temp = { "6","����̨","" };
	map.insertVertex(temp);
	temp = { "7","����","" };
	map.insertVertex(temp);
	temp = { "8","Уʷ��","" };
	map.insertVertex(temp);
	temp = { "9","ͼ���","" };
	map.insertVertex(temp);
	temp = { "10","�ֽ��ٳ�","" };
	map.insertVertex(temp);
	temp = { "11","�ֽ���ѧ¥","" };
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



void UI::CleanConsole(int x, int y)     //y��ָ��Ҫɾ����������x���Դ�0λ�ÿ�ʼѭ���滻���Ľ�ֹλ��
{
	COORD loc;
	loc.Y = y;    //�̶�����
	for (int i = 0; i < x; i++)     //x��ָ��λ�ÿ�ʼѭ�������滻
	{
		loc.X = i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
		cout << " " << endl;;
	}
}
void UI::CleanConsole(int y)     //y��ָ��Ҫɾ����������ֱ��ָ��x��0~50��λ�ý������
{
	COORD loc;
	loc.Y = y;    //�̶�����
	for (int i = 0; i < 50; i++)     //x��ָ��λ�ÿ�ʼѭ�������滻
	{
		loc.X = i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
		cout << " " << endl;;
	}
}

void UI::writeChar(int x, int y, string pchar, char color)
{
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;   //���ĺ��
	cci.bVisible = FALSE;    //��겻�ɼ�
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

	COORD loc = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	cout << pchar;
}

int UI::mainManu()
{
	string options[] = { "��ʾ��ͼ" , "���Ҳ˵�","���¾���","�˳�" };    //��������������Ϊ��ʹ��option��ֵ�ܺ�options���±��Ӧ������ˢ�����
	system("mode con cols=100 lines=50");
	writeChar(18, 10, "�Ͼ���ҵ��ѧ����", 7);
	writeChar(16, 12, "��", 10);
	for (int i = 0; i < 4; i++)
	{
		writeChar(18, 12 + i, options[i], 10);
	}
	char ch;
	int option = 0;    //Ĭ��ָ���������ѡ��
	while (true)
	{
		if (_kbhit())
		{
			ch = _getch();  //�����л���

			if (ch == 27)   //esc
			{
				return -1;
			}
			if (ch == 72 || ch == 80 || ch == '\r')  //ֻ������¼�+�س�ֱ�ӷ��ص�ǰ��optionֵ
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
				if (option < 0)    //��ֹԽ��
				{
					option = 0;
				}
				else if (option >= 4)    //һֱ����ָ�����һ��ѡ��
				{
					option--;
				}
				//�������¼�֮�����ʾ
				writeChar(16, 12 + option, "                        ", 0);
				Sleep(100);
				writeChar(16, 12 + option, "��", 10);
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
	string options[] = { "���Ҿ���","�������·��" };    //��������������Ϊ��ʹ��option��ֵ�ܺ�options���±��Ӧ������ˢ�����
	writeChar(18, 10, "�Ͼ���ҵ��ѧ", 10);
	writeChar(16, 12, "��", 10);
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
	int option = 0;    //Ĭ��ָ���������ѡ��
	while (true)
	{
		if (_kbhit())
		{
			ch = _getch();  //�����л���

			if (ch == 27)   //esc
			{
				return -1;
			}
			if (ch == 72 || ch == 80 || ch == '\r')  //ֻ������¼�+�س�ֱ�ӷ��ص�ǰ��optionֵ
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
				if (option < 0)    //��ֹԽ��
				{
					option = 0;
				}
				else if (option >= 2)    //һֱ����ָ�����һ��ѡ��
				{
					option--;
				}
				//�������¼�֮�����ʾ
				writeChar(16, 12 + option, "                        ", 0);
				Sleep(100);
				writeChar(16, 12 + option, "��", 10);
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
	string options[] = { "��Ӿ���","���¾���","ɾ������" };    //��������������Ϊ��ʹ��option��ֵ�ܺ�options���±��Ӧ������ˢ�����
	writeChar(18, 10, "�Ͼ���ҵ��ѧ", 10);
	writeChar(16, 12, "��", 10);
	for (int i = 0; i < 3; i++)
	{
		writeChar(18, 12 + i, options[i], 10);
	}
	char ch;
	int option = 0;    //Ĭ��ָ���������ѡ��
	while (true)
	{
		if (_kbhit())
		{
			ch = _getch();  //�����л���

			if (ch == 27)   //esc
			{
				return -1;
			}
			if (ch == 72 || ch == 80 || ch == '\r')  //ֻ������¼�+�س�ֱ�ӷ��ص�ǰ��optionֵ
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
				if (option < 0)    //��ֹԽ��
				{
					option = 0;
				}
				else if (option >= 3)    //һֱ����ָ�����һ��ѡ��
				{
					option--;
				}
				//�������¼�֮�����ʾ
				writeChar(16, 12 + option, "                        ", 0);
				Sleep(100);
				writeChar(16, 12 + option, "��", 10);
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
	cout << "���뾰���ţ�";
	cin >> code;
	cout << "���뾰�����ƣ�";
	cin >> name;
	cout << "���뾰��������";
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
	cout << "����Ҫ�޸ĵľ�����룺";
	cin >> code;
	s = map.serchVexByCode(code);
	cout << "�޸����ƣ�e������";
	cin >> name;
	if (name != "e") {
		s.location_name = name;
	}
	cout << "�޸�������e������";
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
	cout << "������Ҫ���ҵľ�������ֻ���룺";
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
	cout << "���������:";
	cin >> x;
	cout << "�����յ㣺";
	cin >> y;
	cout << "��̾���Ϊ��" << d[x][y] << endl;
	cout << "���·��Ϊ��";
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
	cout << "����Ҫɾ���ľ������ֻ��ţ�";
	cin >> s;
	system("cls");
	map.deleteVertex(s);
}

UI::~UI()
{
}