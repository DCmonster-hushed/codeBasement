#include <iostream>
using namespace std;

int main()
{
 int x,a,b,c,d,z=0;
 cout<<"Enter the original number:";
 cin>>x;
a=x/1000;
 b=(x-a*1000)/100;
 c=(x-a*1000-b*100)/10;
 d=x%10;
 
 a=(a+7)%10;
 b=(b+7)%10;
 c=(c+7)%10;
 d=(d+7)%10;

 z=a;
 a=c;
 c=z;

z=b;
b=d;
d=z;

cout<<a<<b<<c<<d<<endl;

return 0;}

/////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main()
{
 int x,a,b,c,d,z=0;
 cout<<"Enter the coded number:";
 cin>>x;
a=x/1000;
 b=(x-a*1000)/100;
 c=(x-a*1000-b*100)/10;
 d=x%10;
 z=a;
 a=c;
 c=z;

z=b;
b=d;
d=z;

if(a<=6&&a>=0)
{a+=3;}
else
{a-=7;}

if(b<=6&&b>=0)
{b+=3;}
else
{b-=7;}

if(c<=6&&c>=0)
{c+=3;}
else
{c-=7;}

if(d<=6&&d>=0)
{d+=3;}
else
{d-=7;}

cout<<"The original code is :"<<a<<b<<c<<d<<endl;
return 0;
}