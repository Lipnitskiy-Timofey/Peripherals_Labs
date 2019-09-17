#include "PCI.h"
#include <iostream>
using namespace std;
int main()
{
	HDEVINFO infoSet = getInfoSet();

	getInfo(infoSet);

	if (!SetupDiDestroyDeviceInfoList(infoSet))
	{
		cout << GetLastError() << endl;
	}
	system("pause");
	return 0;
}