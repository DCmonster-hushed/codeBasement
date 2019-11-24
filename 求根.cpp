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
cout<<"无实根！";
}
if (delta==0)
{
r1=((-b)+sqrt(delta))/2*a;
r2=((-b)-sqrt(delta))/2*a;
cout<<"有两个相等根！为"<<r1<<endl;
}
if (delta>0)
{r1=((-b)+sqrt(delta))/2*a;
r2=((-b)-sqrt(delta))/2*a;
cout<<"有两个实根，为"<<r1<<"和"<<r2;
}
return 0;
}