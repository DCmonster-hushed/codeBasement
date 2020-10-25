#include "Case.h"

Case::Case(string _nowpID, int _size)//初始化当前存放货物id
{
	setNowpID(_nowpID);
	setSize(_size);
}

void Case::setCode(double code_1)//设置取件码
{
	code = code_1;
}

double Case::getCode()//返回取件码
{
	return code;
}

void Case::setState(int _state)
{
	state = _state;
}

int Case::getState()
{
	return state;
}

void Case::setIntime(int _intime)
{
	intime = _intime;
}

int Case::getIntime()
{
	return intime;
}

void Case::setNowpID(string _nowpID)
{
	nowpID = _nowpID;
}

string Case::getNowpID()
{
	return nowpID;
}

void Case::setSize(int _size)
{
	size = _size;
}

int Case::getSize()
{
	return size;
}

void Case::make_code()
{
	srand((unsigned)time(NULL));
	code = double((rand() % 900000)) + 100000;//从100000到999999六位密码
}

int Case::expired()
{
	time_t present;
	time(&present);
	int short_time = present - intime;
	return short_time;
}
