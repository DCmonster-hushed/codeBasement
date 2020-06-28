#include "Cage.h"

Cage::Cage(double a)
{
	setcID(a);
}

void Cage::setcID(double a)//���ù���ID
{
	a > 0 ? cID = a : cID = 0;
}

double Cage::getcID()//���ع���ID
{
	return cID;
}

void Cage::deposit()//���
{
	int i = 0;
	double code_created;
	string tempID;//������Ż���id
	int a; //������Ӵ�С
	if (cMun == 0)
		cout << "��ݹ�������\n";
	if (cMun > 0)
	{
		cout << "��ѡ����Ӵ�С��1С�� 2�У� 3��)>";
		cin >> a;
		for (i = 0; i < cases.size(); i++)
		{
			if (cases[i].getState() == 1 && cases[i].getSize() == a)
				break;
		}
		cout << "���������ID\n";//��ʵ��Ӧ���Աɨ�����������
		cin >> tempID;
		cases[i].setNowpID(tempID);
		cout << "�����Ѵ򿪣���������\n";
		system("pause");//��ʵ��Ӧ�������Ĺ���
		cases[i].setState(0);
		cout << "�����Ѵ���" << i + 1 << "�Ÿ�\n";
		cases[i].make_code();
		code_created = cases[i].getCode();
		checkcode(i, code_created);
		cout << "����ȡ����Ϊ��" << code_created << "�ڿ�ݹ�" << getcID() << " ��(���������ʾ�����뷢�͵��û��Ĺ���)";
		cMun--;
		makeRecord(0, i);
	}
	time_t present;
	time(&present);
	cases[i].setIntime(present);
}

void Cage::checkcode(int a, double code)//����
{
	int i;
	double tempcode;
	for (i = 0; i < cases.size(); i++)
	{
		if (i != a && code == cases[i].getCode())
		{
			cases[a].make_code();
			tempcode = cases[a].getCode();
			checkcode(a, tempcode);//�ݹ���ر�֤����Ψһ
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

		cout << setw(3) << left << (cases[i].getState() == 1 ? "��" : "��");//1Ϊȡ�ߣ��ɴ�
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
		cout << "�����ȡ���룡\n";
	if (codeReply != -1)
	{
		cout << "�����Ѵ򿪣���ȡ����Ʒ\n";
		system("pause");//��Ӧ��ʵȡ�߿�ݶ���
		cases[codeReply].setState(1);
		cout << "�����\n";
		cases[codeReply].setNowpID("0");
		makeRecord(1, codeReply);
	}
	codeReply = -1;
}

void Cage::code_in()
{
	int i;
	double tempCode;
	cout << "������ȡ����\n";
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
				cout << i + 1 << "�Ź��ѳ�ʱ\n";
				cases[i].setState(-1);
				cout << "��ѡ���Ƿ�Ҫȡ�����ڻ��1ȡ����0��ȡ��";
				int a; cin >> a;
				if (a == 1)
				{
					cout << "�����Ѵ򿪣���ȡ�߻���";
					cases[i].setState(1);
					cout << "����ȡ������Ϣ�������ѹ��ڣ���ȥ�������ȡ�����Ļ��" << endl;
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
	cout << "�����˻�����";
	cin >> tempID;
	cout << "�������룺";
	cin >> tempKey;
	for (i = 0; i < expressmen.size(); i++)
	{
		if (expressmen[i].geteID() == tempID && expressmen[i].getkey() == tempKey)
		{
			cout << "��½�ɹ�";
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

void Cage::makeRecord(int flag, int i)//flag == 0->�����¼��flag == 1 -> ȡ����¼�� flag == 2-> ��ʱ��¼,flag == 3 -> ��ʱ�ɿ��Աȡ��    i��cases�±�
{
	ofstream record("record.txt", ios::app);
	if (flag == 0)
	{
		time_t timep;
		time(&timep);
		struct tm t;
		localtime_s(&t, &timep);
		strftime(strTime, sizeof(strTime), "%Y-%m-%d %H:%M:%S", &t);
		record << strTime << "\t" << i + 1 << "�Ź����" << cases[i].getNowpID() << endl;
	}
	if (flag == 1)
	{
		time_t timep;
		time(&timep);
		struct tm t;
		localtime_s(&t, &timep);
		strftime(strTime, sizeof(strTime), "%Y-%m-%d %H:%M:%S", &t);
		record << strTime << "\t" << i + 1 << "�Ź�ȡ��" << cases[i].getNowpID() << endl;

	}
	if (flag == 2)
	{
		time_t timep;
		time(&timep);
		struct tm t;
		localtime_s(&t, &timep);
		strftime(strTime, sizeof(strTime), "%Y-%m-%d %H:%M:%S", &t);
		record << strTime << "\t" << i + 1 << "�Ź�ʱ" << cases[i].getNowpID() << endl;
	}
	if (flag == 3)
	{
		time_t timep;
		time(&timep);
		struct tm t;
		localtime_s(&t, &timep);
		strftime(strTime, sizeof(strTime), "%Y-%m-%d %H:%M:%S", &t);
		record << strTime << "\t" << i + 1 << "�ɿ��Ա��ʱԭ��ȡ��" << cases[i].getNowpID() << endl;
	}
	record.close();
}

