#include <iostream>
using namespace std;

int main()
{
int t;
double m;
double s;
cout<<"Enter hours worked(-1 to end):";
while (cin>>t&&t!=-1)
{
cout<<"Enter hourly rate of the worker($00.00):";
cin>>m;
  if (t<=40.00)
  {s=t*m;}
  else
  {s=40*m+(t-40)*m*1.5;}
 cout<<"Salary is $"<<s<<endl;
cout<<"Enter hours worked(-1 to end):";
}
return 0;
}