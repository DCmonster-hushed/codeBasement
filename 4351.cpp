#include <iostream>
using namespace std;
#include <cmath>
/*int main()
{
int i,r=1;
cin>>i;
while(i>=1)
{
r=r*i;
i--;
}
cout<<r<<endl;
return 0;
}*/

/*int main()
{
int i,r=1;
double x,y=1;
cout<<"确定精度(1/?) ?=";
cin>>i;
while(r<=i)
{
  y=y*r;
  x=x+(1.0/y);
  r++;
}
cout<<"e="<<x<<endl;
return 0;
}*/


int main()
{
int i,r=1;
double x,y=1,z;
cout<<"确定精度(1/?) ?=";
cin>>i;
cout<<"输入变量X:";
cin>>z;
while(r<=i)
{
  y=y*r;
  x=x+(z/y);
  r++;
  z=pow(z,r);
}
cout<<"e="<<x<<endl;
return 0;
}
