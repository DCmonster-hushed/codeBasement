#include "Case.h"

Case::Case(string _nowpID, int _size)//��ʼ����ǰ��Ż���id
{
	setNowpID(_nowpID);
	setSize(_size);
}

void Case::setCode(double code_1)//����ȡ����
{
	code = code_1;
}

double Case::getCode()//����ȡ����
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
	code = double((rand() % 900000)) + 100000;//��100000��999999��λ����
}

int Case::expired()
{
	time_t present;
	time(&present);
	int short_time = present - intime;
	return short_time;
}
