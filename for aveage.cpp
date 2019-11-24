#include <iostream>
using namespace std;

int main()
{
int a,total = 0,i=0;
double average;
cin>>a;
for (a;9999)
{
total = total + a;
i++;
cin>>a;
}
average = (double)total / i;
cout << average;
return 0;}