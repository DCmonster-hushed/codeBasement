#include <iostream>
using namespace std;
int main()
{
int a,b,c;
a=0,b=0,c=0;
cin>>a>>b>>c;

if(a+b>c&&b+c>a&&a+c>b)
{cout<<"able";}
else
{cout<<"unable";}
return 0;}