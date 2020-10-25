#pragma once
#include <string>
#include <ctime>
using namespace std;

class Case
{
public:
	Case(string, int);//初始化当前存放货物id(空为0)
	void setCode(double);//设置取件码
	double getCode();//返回取件码
	void setState(int);//改变格子状态
	int getState();//返回格子状态
	void setIntime(int);//设置放入时间
	int getIntime();//返回放入时间
	void setNowpID(string);//设置现存放货物的id
	string getNowpID();//返回现存放货物的id
	void setSize(int);//设置柜子大小
	int getSize();//返回柜子大小

	void make_code();  //生成密码
	int expired();    //过期判断

private:
	double code;
	int state = 1;
	int intime = 0;
	string nowpID = "0";
	int size; //1-A 小, 2-B 中, 3-C 大
};

