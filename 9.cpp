#include <iostream>
using namespace std;
int main()
{
cout<<"输入年份：";
int a;
cin>>a;
if(a%4==0&&a%100!=0||a%400==0)
{cout<<"该年份是闰年";}
else
{cout<<"该年份不是闰年";}
return 0;}