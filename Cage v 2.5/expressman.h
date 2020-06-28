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
	string eID;//快递员工号
	string key;//账号密码
	string eName;//快递员姓名
	string ePhone;//快递员手机号
};
#endif

