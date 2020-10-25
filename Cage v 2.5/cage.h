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
	double cID;//����ID
	double cTotal = 3;//�ܸ�����
	double cMun = 9;//���ø�����
	string position;//λ��
	bool state_occupied;//�Ƿ�����
	int codeReply;//���������ȷ���ظ��Ӻţ�������󷵻�0
	vector <Case> cases;
	vector <expressman> expressmen;
	char strTime[100] = { 0 };
public:
	Cage(double);
	void setcID(double);//���ù���ID
	double getcID();//���ع���ID
	void deposit();//���
	void totalCheck();//����
	void pickUp();//ȡ��
	void code_in();//����
	void check_expired_total();//�����
	bool log_in();
	void checkcode(int, double);
	void addexpressman(expressman e);
	void addcase(Case c);
	void makeRecord(int, int);
};