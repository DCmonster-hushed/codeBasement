#pragma once
#include <iostream>
using namespace std;
class Chess
{
public:
	void setLocation();
	void initBoard();
	void showBoard();
	bool getEndGame();
	void setEndGame(bool);
private:
	int xLocation;
	int yLocation;
	char move(int);
	bool endGame = false;
};