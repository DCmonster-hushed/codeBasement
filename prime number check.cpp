#include <iostream>
using namespace std;

int main()
{
	int i,j=2;
	cout <<"����Ҫ�жϵ�����";
	cin>>i;
	while (j<i)
	{if(i%j==0)
	{cout<<"������������"<<endl;
	break;
	}
	j ++;
	}
if (j==i)
cout<<"����������"<<endl;
return 0;
} 