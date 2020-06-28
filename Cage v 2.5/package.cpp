#include "package.h"

package::package(string pid, string sname, string sadd, string sph, string rname, string radd, string rph)
{
	setpID(pid);
	setSname(sname);
	setSaddress(sadd);
	setSphone(sph);
	setRname(rname);
	setRaddress(radd);
	setRphone(rph);
}

void package::setpID(string pid)
{
	pID = pid;
}

string package::getpID() const
{
	return pID;
}

void package::setSname(string sname)
{
	Sname = sname;
}
string package::getSname() const
{
	return Sname;
}

void package::setSaddress(string sadd)
{
	Saddress = sadd;
}

string package::getSaddress() const
{
	return Saddress;
}

void package::setSphone(string sph)
{
	Sphone = sph;
}

string package::getSphone() const
{
	return Sphone;
}

void package::setRname(string rname)
{
	Rname = rname;
}

string package::getRname() const
{
	return Rname;
}

void package::setRaddress(string radd)
{
	Raddress = radd;
}

string package::getRaddress() const
{
	return Raddress;
}

void package::setRphone(string rph)
{
	Rphone = rph;
}

string package::getRphone() const
{
	return Rphone;
}

void package::pprint() const//快递单打印
{
	cout << "快递单" << endl;
	cout << "------------------------" << endl;
	cout << "货物id:" << pID << endl;
	cout << "------------------------" << endl;
	cout << "发件人姓名:" << Sname << endl;
	cout << "发件人地址:" << Saddress << endl;
	cout << "发件人手机号:" << Sphone << endl;
	cout << "------------------------" << endl;
	cout << "收件人姓名:" << Rname << endl;
	cout << "收件人地址:" << Raddress << endl;
	cout << "收件人手机号:" << Rphone << endl;
}
