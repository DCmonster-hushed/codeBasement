#pragma once
#include <string>
#include <ctime>
using namespace std;

class Case
{
public:
	Case(string, int);//��ʼ����ǰ��Ż���id(��Ϊ0)
	void setCode(double);//����ȡ����
	double getCode();//����ȡ����
	void setState(int);//�ı����״̬
	int getState();//���ظ���״̬
	void setIntime(int);//���÷���ʱ��
	int getIntime();//���ط���ʱ��
	void setNowpID(string);//�����ִ�Ż����id
	string getNowpID();//�����ִ�Ż����id
	void setSize(int);//���ù��Ӵ�С
	int getSize();//���ع��Ӵ�С

	void make_code();  //��������
	int expired();    //�����ж�

private:
	double code;
	int state = 1;
	int intime = 0;
	string nowpID = "0";
	int size; //1-A С, 2-B ��, 3-C ��
};

