#include "caculate.h"
#include <iostream>
using namespace std;

int main()
{
	caculate Caculate;
	int i;
	for (i = 1; i <= 10; i++)
	{
		Caculate.solve();
	}
	Caculate.getScore();

		return 0;
}