#include "PCI.h"
#include <string>
#include <iostream>
using namespace std;

void getInfo(HDEVINFO infoSet)
{
	setlocale(LC_ALL, "en");
	TCHAR buffer[BUFFER];
	string deviceID;
	string vendorID;
	SP_DEVINFO_DATA deviceInfoData;
	deviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);

	for (int i = 0; SetupDiEnumDeviceInfo(infoSet, i++, &deviceInfoData);)
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

		SetupDiGetDeviceInstanceId(infoSet, &deviceInfoData, buffer, sizeof(buffer), 0);

		char vendor[5];
		for (int k = 0; k < 4; k++)
		{
			vendor[k] = tolower(strstr(buffer, "VEN")[k + 4]);
		}
		vendor[4] = '\0';
		


		char device[5];

		for (int j = 0; j < 4; j++)
			device[j] = tolower(strstr(buffer, "DEV")[j + 4]);
		device[4] = '\0';

		

		deviceID = device;
		vendorID = vendor;

		cout << "DeviceID: " << deviceID << endl;
		cout << "VendorID: " << vendorID << endl;
		cout << endl;
		

	}

}

HDEVINFO getInfoSet()
{
	HDEVINFO infoSet = SetupDiGetClassDevs(NULL, "PCI", NULL, DIGCF_ALLCLASSES);

	if (infoSet == INVALID_HANDLE_VALUE)
		return 0;
	else
		return infoSet;
	return HDEVINFO();
}


