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

	void addVertex();//���һ���½��
	void renewVertex();//���¾�����Ϣ
	void searchLandscape();//���Ҿ���
	void shortestPath_floid();//���·��
	void getpath(int x, int y);
	void deletePage();
private:
	Graph map;
	int d[50][50];
	int p[50][50];

};

