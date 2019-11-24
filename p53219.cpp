#include <iostream>
using namespace std;
int main()
{
cout <<"Input three different integers: ";
int a,b,c,sum,pr,sm,la;
double av;
cin>> a >> b >> c;
sum=0;
pr=0;
sm=a;
la=a;
av=0;
sum=a+b+c;
av=sum/3.0;
pr=a*b*c;
if(b<a&&b<c)
sm=b;
if(c<a&&c<b)
sm=c;
if(b>a&&b>c)
la=b;
if(c>b&&c>a)
la=c;
cout << "sum is "<<sum<<endl;
cout << "average is "<<av<<endl;
cout << "product is "<<pr<<endl;
cout << "smallest is "<<sm<<endl;
cout << "largest is "<<la<<endl;
return 0;
}