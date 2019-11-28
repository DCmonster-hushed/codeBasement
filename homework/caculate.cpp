#include <string>
#include <iostream>
#include "caculate.h"
#include <ctime>
using namespace std;

void caculate::reply(int resultCheck)
{
	int reply;
	string correct, wrong;
	srand(time(NULL));
	reply = rand() % 5;
	switch (reply)
	{
	case 1 :
		correct = "Very good";
		wrong = "No.Please try again.";
		break;
	case 2 :
		correct = "Excellent!";
		wrong = "Wrong.Try once more.";
		break;
	case 3 :
		correct = "Nice work!";
		wrong = "No.Don't give up.";
		break;
	case 4 :
		correct = "Keep up the good work.";
		wrong = "Not correct.Keep trying.";
		break;
	default:
		break;
    }
	if (resultCheck == 0)
		cout << correct << endl;
	else
		cout << wrong << endl;
}

void caculate::solve()
{
int number1, number2, result, caculateType, userResult, resultCheck;
srand(time(NULL));
number1 = rand() % 51;
number2 = rand() % 51;
caculateType = rand() % 2;
    switch (caculateType)
    {
	case 0 :
		result = number1 + number2;
		while (result>50)
		{
			number1 = rand() % 51;
			number2 = rand() % 51;
			result = number1 + number2;
		}
		judge(number1, number2, caculateType, result);
		break;
	case 1 :
		result = number1 - number2;
		while (result > 50||result < 0)
		{
			number1 = rand() % 51;
			number2 = rand() % 51;
			result = number1 - number2;
		}
		judge(number1, number2, caculateType, result);
    break;
    default:
	break;
    }



}

void caculate::getScore()
{
	cout << "Your score is " << score << ". Congratulation£¡" << endl;
}

void caculate::addToScore(int i)
{
	switch (i)
	{
	case 0 :
		score = score + 10;
		break;
	case 1 :
		score = score + 7;
		break;
	case 2 :
		score = score + 5;
		break;
	default:
		score = score;
		break;
	}
}

void caculate::judge(int number1, int number2, int caculateType, int result)
{
	int userResult, resultCheck, i = 0;
	string type;
	if (caculateType == 0)
		type = "+";
	else
		type = "-";
	cout << number1 << type << number2 << " = ";
	cin >> userResult;
	while (userResult != result && i <= 2)
	{
		resultCheck = 1;
		reply(resultCheck);
		cout << number1 << type << number2 << " = ";
		cin >> userResult;
		i++;
	}
	if (userResult == result)
	{
		resultCheck = 0;
		reply(resultCheck);
	}
	addToScore(i);
}