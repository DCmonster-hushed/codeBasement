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
	string pID;//货物 id 
	string Sname;//发件人姓名 
	string Saddress;//发件人地址 
	string Sphone;//发件人手机号 
	string Rname;//收件人姓名 
	string Raddress;//收件人地址 
	string Rphone;//收件人手机号 

};
#endif