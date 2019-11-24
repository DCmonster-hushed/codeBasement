#include <iostream>
using namespace std;

int main()
{
cout<<"输入年收入：";
int i,j;
double q;
cin>>i;
cout<<endl;
j=i-60000;
if(j<=36000)
{
q=j*0.3;}
if(j<=144000&&j>36000)
{q=j*0.1-2520;
}
if(j<=300000&&j>144000)
{
q=j*0.2-16920;}
if(j<=420000&&j>300000)
{
q=j*0.25-31920;}
if(j<=660000&&j>400000)
{
q=j*0.3-52920;}
if(j<=960000&&j>660000)
{q=j*0.35-85920;}
if(j>960000)
{q=j*0.45-181920;}
cout<<"全年应缴纳税款："<<q;
return 0;
}