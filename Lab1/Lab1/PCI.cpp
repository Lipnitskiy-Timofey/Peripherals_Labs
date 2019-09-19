#include "PCI.h"
#include <iostream>
using namespace std;

HDEVINFO unitsPCI::getInfoSet()
	{
		HDEVINFO infoSet = SetupDiGetClassDevs(nullptr, "PCI",
			nullptr, DIGCF_ALLCLASSES); //Формирование списка устройств
													 //Вернет -1 при неудаче

		if (infoSet == INVALID_HANDLE_VALUE)
			return nullptr;
		else
			return infoSet;
	}

void unitsPCI::getInfo(HDEVINFO infoSet)
{
	int i = 0;
	TCHAR buffer[BUFFER];
	SP_DEVINFO_DATA deviceInfoData;

	do
	{
		ZeroMemory(&deviceInfoData, sizeof(SP_DEVINFO_DATA));
		deviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
	
		if (SetupDiEnumDeviceInfo(infoSet, i, &deviceInfoData) == false)
		{
			if (GetLastError() == ERROR_NO_MORE_ITEMS)
			{
				break;
			}
		}
	
		SetupDiEnumDeviceInfo(infoSet, i++, &deviceInfoData);
	
		SetupDiGetDeviceInstanceId(infoSet, &deviceInfoData,
			buffer, sizeof(buffer), nullptr);
		cout << "Buffer: " << buffer << endl;
		char vendor[5];
		for (int k = 0; k < 4; k++)
		{
			vendor[k] = tolower(strstr(buffer, "VEN")[k + 4]);
		}
		vendor[4] = '\0';

		char device[5];
		for (int j = 0; j < 4; j++)
		{
			device[j] = tolower(strstr(buffer, "DEV")[j + 4]);
		}
		device[4] = '\0';

		cout << "DeviceID: " << device << endl;
		cout << "VendorID: " << vendor << endl;
		cout << endl;
	}
	while (true);
}