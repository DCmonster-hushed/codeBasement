#include <iostream>
#include <cmath>
using namespace std;

int main()
{
cout<<"Enter a  b  c:";
int a,b,c;
cin>>a;
cin>>b;
cin>>c;
int delta;
double r1,r2;
delta = b*b-(4*a*c);
if (delta<0)
{
cout<<"��ʵ����";
}
if (delta==0)
{
r1=((-b)+sqrt(delta))/2*a;
r2=((-b)-sqrt(delta))/2*a;
cout<<"��������ȸ���Ϊ"<<r1<<endl;
}
if (delta>0)
{r1=((-b)+sqrt(delta))/2*a;
r2=((-b)-sqrt(delta))/2*a;
cout<<"������ʵ����Ϊ"<<r1<<"��"<<r2;
}
return 0;
}