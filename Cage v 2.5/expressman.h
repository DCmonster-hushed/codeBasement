#ifndef EXPRESSMAN_H
#define EXPRESSMAN_H
#include <string>
#include <iostream>
using namespace std;

class expressman
{
public:
	expressman(string, string, string, string);
	void seteID(string);
	string geteID() const;
	void setkey(string);
	string getkey() const;
	void seteName(string);
	string geteName() const;
	void setePhone(string);
	string getePhone() const;

private:
	string eID;//���Ա����
	string key;//�˺�����
	string eName;//���Ա����
	string ePhone;//���Ա�ֻ���
};
#endif

