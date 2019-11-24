#include <iostream>
using namespace std;

int main()
{
cout<<"Please enter a sentence in English.";
char sentence[500];
cin.getline (sentence,500);
int count = 0;
int i;
for(char*str=sentence;str[i];str++)
{
	if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
	{
		count++;
	}
}
cout<<count;
return 0;
}
//int j=1;
//int a,e,i,o,u;
//while (j<=count)
//{
//	switch(sentence)
//	{
//	case'a':;
//			a++;
//			break;
//	case'e':;
//			e++;
//			break;
//	case'i':;
//			i++;
//			break;
//	case'o':;
//			o++;
//			break;
//	case'u':;
//			u++;
//break;
//	}
//j++;
//}
//cout<<"a: "<<a<<"  e: "<<e<<"  i: "<<i<<"  o: "<<o<<"  u: "<<u<<endl;
//return 0;
//}