#include <iostream>
using namespace std;
char code;
char aCode;
int tem=0;

class f1
{
  public:
  transCode()
  {tem=int(code)+3;
	aCode=char(tem);
return 0;
  }
};


int main()
{
	f1 tCode;
while(cin>>code)
{
tCode.transCode();
cout<<aCode;
}

return 0;
}