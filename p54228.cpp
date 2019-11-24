#include <iostream>
using namespace std;
int main()
{
cout<<"输入一个五位整数：";
int a;
cin>>a;
int b,c,d,e,f;
b=a/10000;
c=(a-b*10000)/1000;
d=(a-c*1000-b*10000)/100;
f=a%10;
e=(a/10)%10;

cout<<b<<"   "<<c<<"   "<<d<<"   "<<e<<"   "<<f<<endl;

return 0;}