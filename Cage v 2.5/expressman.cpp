#include "expressman.h"

expressman::expressman(string eid, string k, string ename, string eph)
{
	seteID(eid);
	setkey(k);
	seteName(ename);
	setePhone(eph);
}
void expressman::seteID(string eid)
{
	eID = eid;
}
string expressman::geteID() const
{
	return eID;
}
void expressman::seteName(string ename)
{
	eName = ename;
}
string expressman::geteName() const
{
	return eName;
}
void expressman::setkey(string k)
{
	key = k;
}
string expressman::getkey() const
{
	return key;
}
void expressman::setePhone(string eph)
{
	ePhone = eph;
}
string expressman::getePhone() const
{
	return ePhone;
}