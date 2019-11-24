#include <iostream>
using namespace std;

int main()
{
cout<<"N\t"<<"10*N\t"<<"100*N\t"<<"1000*N\t\n";
int n=1;
while(n<=5)
{cout<<n<<"\t"<<n*10<<"\t"<<n*100<<"\t"<<n*1000<<"\t"<<endl;
n++;
}
return 0;}