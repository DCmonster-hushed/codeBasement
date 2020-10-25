#ifndef PACKAGE_H
#define PACKAGE_H
#include <string>
#include <iostream>
#include <string>
using namespace std;


class package
{
public:
	package(string, string, string, string, string, string, string);

	void setpID(string);
	string getpID() const;

	void setSname(string);
	string getSname() const;

	void setSaddress(string);
	string getSaddress() const;

	void setSphone(string);
	string getSphone() const;

	void setRname(string);
	string getRname() const;

	void setRaddress(string);
	string getRaddress() const;

	void setRphone(string);
	string getRphone() const;

	void pprint() const;


private:
	string pID;//���� id 
	string Sname;//���������� 
	string Saddress;//�����˵�ַ 
	string Sphone;//�������ֻ��� 
	string Rname;//�ռ������� 
	string Raddress;//�ռ��˵�ַ 
	string Rphone;//�ռ����ֻ��� 

};
#endif