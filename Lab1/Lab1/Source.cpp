#include "PCI.h"
#include <iostream>
using namespace std;

int main()
{
	HDEVINFO infoSet = unitsPCI::getInfoSet();

	unitsPCI::getInfo(infoSet);

	if (!SetupDiDestroyDeviceInfoList(infoSet))//����������� ������
	{
		cout << GetLastError() << endl;
	}
	system("pause");
	return 0;
}