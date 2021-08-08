#pragma once
#include "graph.h"
#include <Windows.h>
#include <conio.h>
#include <vector>
class UI
{
public:
	UI();
	~UI();
	void CleanConsole(int, int);
	void CleanConsole(int y);
	void writeChar(int x, int y, string pchar, char color);
	int mainManu();
	void mapPage();
	int searchPage();
	int renewPage();

	void addVertex();//添加一个新结点
	void renewVertex();//更新景点信息
	void searchLandscape();//查找景点
	void shortestPath_floid();//最短路径
	void getpath(int x, int y);
	void deletePage();
private:
	Graph map;
	int d[50][50];
	int p[50][50];

};

