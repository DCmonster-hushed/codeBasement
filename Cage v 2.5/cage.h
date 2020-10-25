#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <ctime>
#include"case.h"
#include"expressman.h"
#include"package.h"
#include <fstream>
using namespace std;

class Cage
{
private:
	double cID;//柜子ID
	double cTotal = 3;//总格子数
	double cMun = 9;//可用格子数
	string position;//位置
	bool state_occupied;//是否已满
	int codeReply;//如果密码正确返回格子号，密码错误返回0
	vector <Case> cases;
	vector <expressman> expressmen;
	char strTime[100] = { 0 };
public:
	Cage(double);
	void setcID(double);//设置柜子ID
	double getcID();//返回柜子ID
	void deposit();//存件
	void totalCheck();//查满
	void pickUp();//取件
	void code_in();//输码
	void check_expired_total();//查过期
	bool log_in();
	void checkcode(int, double);
	void addexpressman(expressman e);
	void addcase(Case c);
	void makeRecord(int, int);
};