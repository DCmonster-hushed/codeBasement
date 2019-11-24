#include <iostream>
using namespace std;

int main()
{
cout<<"¼ÆËã½üËÆ¦ÐÖµ"<<endl;
double pi=4;
double i=1;
int j=-1;
while(i<10000000)
{
	pi=pi+4*1.0/(i+2)*j;
	i=i+2;
	j=-j;
}
cout<<pi<<endl;
return 0;
}