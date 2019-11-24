#include <iostream>
using namespace std;
int main()
{
const double pi=3.14159;
cout << "输入整数半径：";
int r;
cin>> r;
int d;
double c,s;
d=2*r;
c=2*pi*r;
s=pi*r*r*0.5;
cout<<"周长=2*pi*"<<r<<"="<<c<<endl;
cout<<"面积=1/2*pi*"<<r<<"^2="<<s<<endl;
cout<<"直径=2*"<<r<<"="<<d<<endl;

return 0;}