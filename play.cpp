#include <iostream>
#include "crossChess.h"
using namespace std;
int main()
{
	Chess chess;
	chess.initBoard();
	char reply = 'y';
	while (reply == 'y')
	{
		while (chess.getEndGame() == false)
		{
			chess.setLocation();
			chess.showBoard();
		}
	cout << "Would you replay or quit?\n";
	cout << "y to replay , n to quit\n";
	cin >> reply;
}
	return 0;
}