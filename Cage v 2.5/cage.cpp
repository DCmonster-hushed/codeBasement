#include "Cage.h"

Cage::Cage(double a)
{
	setcID(a);
}

void Cage::setcID(double a)//设置柜子ID
{
	a > 0 ? cID = a : cID = 0;
}

double Cage::getcID()//返回柜子ID
{
	return cID;
}

void Cage::deposit()//存件
{
	int i = 0;
	double code_created;
	string tempID;//即将存放货物id
	int a; //代表柜子大小
	if (cMun == 0)
		cout << "快递柜已满！\n";
	if (cMun > 0)
	{
		cout << "请选择柜子大小（1小， 2中， 3大)>";
		cin >> a;
		for (i = 0; i < cases.size(); i++)
		{
			if (cases[i].getState() == 1 && cases[i].getSize() == a)
				break;
		}
		cout << "请输入货物ID\n";//现实对应快递员扫描货物条形码
		cin >> tempID;
		cases[i].setNowpID(tempID);
		cout << "柜门已打开，请放入货物\n";
		system("pause");//现实对应放入货物的过程
		cases[i].setState(0);
		cout << "货物已存入" << i + 1 << "号格\n";
		cases[i].make_code();
		code_created = cases[i].getCode();
		checkcode(i, code_created);
		cout << "生成取件码为：" << code_created << "在快递柜" << getcID() << " 中(用输出来表示将密码发送到用户的过程)";
		cMun--;
		makeRecord(0, i);
	}
	time_t present;
	time(&present);
	cases[i].setIntime(present);
}

void Cage::checkcode(int a, double code)//查重
{
	int i;
	double tempcode;
	for (i = 0; i < cases.size(); i++)
	{
		if (i != a && code == cases[i].getCode())
		{
			cases[a].make_code();
			tempcode = cases[a].getCode();
			checkcode(a, tempcode);//递归查重保证密码唯一
		}
	}

}

void Cage::totalCheck()
{
	cout << endl;
	for (int i = 0; i < cases.size(); i++)
	{
		if (cases[i].getSize() == 1)
			cout << "A" << i + 1 << setw(2);
		if (cases[i].getSize() == 2)
			cout << "B" << i + 1 << setw(2);
		if (cases[i].getSize() == 3)
			cout << "C" << i + 1 << setw(2);

		cout << setw(3) << left << (cases[i].getState() == 1 ? "√" : "×");//1为取走，可存
		if ((i + 1) % 4 == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
}

void Cage::pickUp()
{
	code_in();
	if (codeReply == -1)
		cout << "错误的取件码！\n";
	if (codeReply != -1)
	{
		cout << "柜门已打开，请取走物品\n";
		system("pause");//对应现实取走快递动作
		cases[codeReply].setState(1);
		cout << "请关门\n";
		cases[codeReply].setNowpID("0");
		makeRecord(1, codeReply);
	}
	codeReply = -1;
}

void Cage::code_in()
{
	int i;
	double tempCode;
	cout << "请输入取件码\n";
	cin >> tempCode;
	for (i = 0; i < cases.size(); i++)
	{
		if (cases[i].getCode() == tempCode)
		{
			codeReply = i;
			break;
		}
	}
	if (i == cases.size())
		codeReply = -1;
}

void Cage::check_expired_total()
{
	for (int i = 0; i < cases.size(); i++)
	{
		if ((cases[i].getState() == 0) || (cases[i].getState() == -1))
		{
			if (cases[i].expired() >= 10)
			{
				cout << i + 1 << "号柜已超时\n";
				cases[i].setState(-1);
				cout << "请选择是否要取出过期货物（1取出，0不取）";
				int a; cin >> a;
				if (a == 1)
				{
					cout << "柜门已打开，请取走货物";
					cases[i].setState(1);
					cout << "发给取件人信息“货物已过期，请去快递中心取走您的货物”" << endl;
					makeRecord(3, i);
				}
				if (a == 0)
				{
					makeRecord(2, i);
				}
			}
		}
	}
}

bool Cage::log_in()
{
	string  tempID, tempKey;
	int i;
	cout << "输入账户名：";
	cin >> tempID;
	cout << "输入密码：";
	cin >> tempKey;
	for (i = 0; i < expressmen.size(); i++)
	{
		if (expressmen[i].geteID() == tempID && expressmen[i].getkey() == tempKey)
		{
			cout << "登陆成功";
			return true;
		}
	}
	if (i == expressmen.size())
		return false;
}


void Cage::addexpressman(expressman e)
{
	expressmen.push_back(e);
};
void Cage::addcase(Case c)
{
	cases.push_back(c);
}

void Cage::makeRecord(int flag, int i)//flag == 0->存入记录，flag == 1 -> 取出记录， flag == 2-> 超时记录,flag == 3 -> 超时由快递员取走    i是cases下标
{
	ofstream record("record.txt", ios::app);
	if (flag == 0)
	{
		time_t timep;
		time(&timep);
		struct tm t;
		localtime_s(&t, &timep);
		strftime(strTime, sizeof(strTime), "%Y-%m-%d %H:%M:%S", &t);
		record << strTime << "\t" << i + 1 << "号柜存入" << cases[i].getNowpID() << endl;
	}
	if (flag == 1)
	{
		time_t timep;
		time(&timep);
		struct tm t;
		localtime_s(&t, &timep);
		strftime(strTime, sizeof(strTime), "%Y-%m-%d %H:%M:%S", &t);
		record << strTime << "\t" << i + 1 << "号柜取出" << cases[i].getNowpID() << endl;

	}
	if (flag == 2)
	{
		time_t timep;
		time(&timep);
		struct tm t;
		localtime_s(&t, &timep);
		strftime(strTime, sizeof(strTime), "%Y-%m-%d %H:%M:%S", &t);
		record << strTime << "\t" << i + 1 << "号柜超时" << cases[i].getNowpID() << endl;
	}
	if (flag == 3)
	{
		time_t timep;
		time(&timep);
		struct tm t;
		localtime_s(&t, &timep);
		strftime(strTime, sizeof(strTime), "%Y-%m-%d %H:%M:%S", &t);
		record << strTime << "\t" << i + 1 << "由快递员因超时原因取走" << cases[i].getNowpID() << endl;
	}
	record.close();
}

