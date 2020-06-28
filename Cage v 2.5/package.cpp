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

void package::pprint() const//��ݵ���ӡ
{
	cout << "��ݵ�" << endl;
	cout << "------------------------" << endl;
	cout << "����id:" << pID << endl;
	cout << "------------------------" << endl;
	cout << "����������:" << Sname << endl;
	cout << "�����˵�ַ:" << Saddress << endl;
	cout << "�������ֻ���:" << Sphone << endl;
	cout << "------------------------" << endl;
	cout << "�ռ�������:" << Rname << endl;
	cout << "�ռ��˵�ַ:" << Raddress << endl;
	cout << "�ռ����ֻ���:" << Rphone << endl;
}
