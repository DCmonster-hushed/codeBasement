#include <iostream>
#include <ctime>
using namespace std;

int main()
{int x;
cout<<"Let's guess the number!\n";
	srand(time(NULL));
x=rand()%101;
	int n;
	cin>>n;
	while(n!=x)
	{if (n<=x)
	{cout<<"小了，再来！";
	cin>>n;
	}
	 if (n>=x)
	 {cout<<"大了，再来！";
	 cin>>n;
	}
	}
if (n==x)
cout<<"bingo!!";
return 0;
}