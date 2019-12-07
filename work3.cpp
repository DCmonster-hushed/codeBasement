#include <stdio.h>
#include <iostream>
#include <ctime>
#include <Windows.h>
#include <iomanip>
#include <conio.h>
#include <string>
using namespace std;
	int A[6][6];
	int B[6][6];
CONSOLE_CURSOR_INFO	cci;
COORD pos;
enum MyEnum
{
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77,
	SHOW = 115,
	EDIT = 32,
};

int get_UserInPut(int x, int y)
{
	string board = "";
    int keyBoardTap;
	keyBoardTap = _getch();
	switch (keyBoardTap)
	{
	case UP:
		if (y > 0)
			return -1;
		else
		//	board = "At the top!";
		break;
	case DOWN:
		if (y + 1 < 6)
			return 1;
		else
			//board = "At the bottom!";
		break;
	case LEFT:
		if (x > 0)
			return -10;
		else
			//board = "At the left edge!";
		break;
	case RIGHT:
		if (x + 1 < 6)
			return 10;
		else
			//board = "At the right edge!";
		break;
	case SHOW:
		return SHOW;
		break;
	case EDIT:
		return EDIT;
		break;

	}
	return 0;
}

void initData()
{
	srand(time(NULL));
	for (int i = 0; i < 6; i++)//初始化A，B数组
		for (int j = 0; j < 6; j++)
		{
			A[i][j] = rand()%101;
			B[i][j] = rand()%101;
		}
}


int main()
{
	int locationAx = 0, locationAy = 0, change = 0;//初始位置
	int rep;
	initData();
	while (1)
	{
		cout << "\n\n\n\n\n\n\n" << "Press s to show all\nPress space to edit";
		rep = get_UserInPut(locationAx, locationAy);
		system("cls");
		switch (rep)
		{
		case -1 :
			locationAy -= 1;
			break;
		case 1 :
			locationAy += 1;
			break;
		case 10 :
			locationAx += 1;
			break;
		case -10 : 
			locationAx -= 1;
			break;
		}
		cout << A[locationAx][locationAy] << "\t" << A[locationAx + 1][locationAy] << endl << A[locationAx][locationAy + 1] << "\t" << A[locationAx + 1][locationAy + 1];
		if (rep == SHOW)
		{
			system("cls");
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					cout << A[j][i] << "\t";
				}
				for (int j = 0; j < 6; j++)
				{
					cout << B[j][i] << "\t";
				}
				cout << endl;
			}
		}
		if (rep == EDIT)
		{
			int xLocation, yLocation;
			cout << "\n\n\n\n\n\n\n\n" << "the number you want to edit \nthe xLocation(1`2): ";
			cin >> xLocation;
			cout << "the yLocation(1`2): ";
			cin >> yLocation;
			if (xLocation == 1 && yLocation == 1)
				cin >> A[locationAx][locationAy];
			if (xLocation == 1 && yLocation == 2)
				cin >> A[locationAx][locationAy + 1];
			if (xLocation == 2 && yLocation == 1)
				cin >> A[locationAx + 1][locationAy];
			if (xLocation == 2 && yLocation == 2)
				cin >> A[locationAx + 1][locationAy + 1];

		}
	}
return 0;
}//俩个数组的链接还是有点懵。。。
//就不美化了。。。。。