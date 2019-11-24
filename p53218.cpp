#include <iostream>
using namespace std;

int main()
{
int n1,n2;
int max;
   max=0;
	cout << "Enter the first integer: ";
    cin >> n1;
		cout << endl;
	cout << "Enter the second integer: ";
	cin >> n2;
if(n1<n2)
{ max = n2;
cout << max << "is large.";}

if (n1>n2)
{max = n1;
cout << max << "is large.";}
if(n1==n2)
{cout << "These numbers are equal.";}
 return 0;}