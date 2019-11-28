#include "crossChess.h"
#include <iostream>
#include <string>
using namespace std;
char chess[3][3];
int j;
void Chess::setLocation()
{
	int i = 0, a[2] = {0};
	    cout << "Set your xlocation: ";
	cin >> a[0];
	cout << "Set your ylocation: ";
	cin >> a[1];
	xLocation = a[0];
	yLocation = a[1];
}
void Chess::initBoard()
{
	char chess[3][3] = {  };
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "\t" "\t" << chess[0][0] << "\t" << "|" << "\t" << chess[0][1] << "\t" << "|" << "\t" << chess[0][2] << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "           ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª" << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "\t" "\t" << chess[1][0] << "\t" << "|" << "\t" << chess[1][1] << "\t" << "|" << "\t" << chess[1][2] << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "           ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª" << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "\t" "\t" << chess[2][0] << "\t" << "|" << "\t" << chess[2][1] << "\t" << "|" << "\t" << chess[2][2] << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
};
void Chess::showBoard()
{
	system("cls");
	bool endgame = false;
	char playerTurn;
	if (j % 2 == 0)
		playerTurn = 'X';
	else
		playerTurn = 'O';
	chess[xLocation][yLocation] = playerTurn;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "\t" "\t" << chess[0][0] << "\t" << "|" << "\t" << chess[0][1] << "\t" << "|" << "\t" << chess[0][2] << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "           ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª" << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "\t" "\t" << chess[1][0] << "\t" << "|" << "\t" << chess[1][1] << "\t" << "|" << "\t" << chess[1][2] << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "           ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª" << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "\t" "\t" << chess[2][0] << "\t" << "|" << "\t" << chess[2][1] << "\t" << "|" << "\t" << chess[2][2] << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	cout << "\t" << "\t" << "\t" << "|" << "\t" << " " << "\t" << "|" << "\t" << " " << endl;
	int winner = 0;
	for (int i = 0; i < 3; i++)
	{
		if (chess[i][0] == chess[i][1] && chess[i][0] == chess[i][2])
		{
			if (chess[i][0] == 'X')
			{
				winner = 1;
				endgame = true;
				break;
			}
			if (chess[i][0] == 'O')
			{
				winner = 2;
				endgame = true;
				break;
			}
		}
	} //ÅÐ¶ÏÐÐ
	for (int i = 0; i < 3; i++)
	{
		if (chess[0][i] == chess[1][i] && chess[0][i] == chess[2][i])
		{
			if (chess[0][i] == 'X')
			{
				winner = 1;
				endgame = true;
				break;
			}
			if (chess[0][i] == 'O')
			{
				winner = 2;
				endgame = true;
				break;
			}
		}
	}//ÅÐ¶ÏÁÐ
		if (chess[0][0] == chess[1][1] && chess[0][0] == chess[2][2])
		{
			if (chess[1][1] == 'X')
			{
				winner = 1;
				endgame = true;
			}
			if (chess[1][1] == 'O')
			{
				winner = 2;
				endgame = true;
			}
		}//ÅÐ¶ÏÐ±Ïò1
		if (chess[0][2] == chess[1][1] && chess[0][2] == chess[2][0])
		{
			if (chess[1][1] == 'X')
			{
				winner = 1;
				endgame = true;
			}
			if (chess[1][1] == 'O')
			{
				winner = 2;
				endgame = true;
			}
		}//ÅÐ¶ÏÐ±Ïò2
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (chess[i][j] == ' ')
					winner = 3;
					break;
			}
		}
		if (winner == 1)
			cout << "Player1 wins!\n";
		if (winner == 2)
			cout << "Player2 wins!\n";
		if (winner == 3)
			cout << "tied!\n";
		setEndGame(endgame);
	j++;
}
char Chess::move(int j)
{
	if (j % 2 == 0)
		return 'X';
	else
		return 'O';
}
bool Chess::getEndGame()
{
	return endGame;
}
void Chess::setEndGame(bool endgame)
{
	endGame = endgame;
}
