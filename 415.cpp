#include <iostream>
using namespace std;

int main()
{
double sales;
double salary;
cout<<"Enter sales in dollars(-1 to end):";
while(cin>>sales&&sales!=-1)
{
salary=200 + sales*0.9;
cout<<"Salary is: $"<<salary<<endl;
cout<<"Enter sales in dollars(-1 to end):";
}
return 0;}