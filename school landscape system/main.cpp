#include "UI.h"
#include "graph.h"

int main() {
	UI landscape_system;
	while (true)
	{
		int result2,result3;
		int result1 = landscape_system.mainManu();
		if (result1 == 0)
		{
			landscape_system.mapPage();
			system("pause");
		}
		else if (result1 == 1)
		{
			result2= landscape_system.searchPage();
			if (result2 == 0) {
				landscape_system.searchLandscape();
				system("pause");
			}
			if (result2 == 1) {
				landscape_system.shortestPath_floid();
				system("pause");
			}
		}
		else if (result1 == 2)
		{
			result3 = landscape_system.renewPage();
			if (result3 == 0) {
				landscape_system.addVertex();
				system("pause");
			}
			else if (result3 == 1) {
				landscape_system.renewVertex();
				system("pause");

			}
			else if (result3 == 2) {
				landscape_system.deletePage();
				system("pause");

			}
		}

		else
		{
			cout << endl << endl;
			return -1;
		}
	}

	return 0;
}