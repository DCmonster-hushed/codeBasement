#include <iostream>
using namespace std;

int main()
{
	int i,j=2;
	cout <<"输入要判断的数：";
	cin>>i;
	while (j<i)
	{if(i%j==0)
	{cout<<"该数不是素数"<<endl;
	break;
	}
	j ++;
	}
if (j==i)
cout<<"该数是素数"<<endl;
return 0;
} 