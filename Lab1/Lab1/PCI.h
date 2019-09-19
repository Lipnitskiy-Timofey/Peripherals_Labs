#pragma once
#pragma comment(lib, "setupapi.lib")
#include <windows.h>
#include <SetupAPI.h>
using namespace std;

const int BUFFER = 10000;

class unitsPCI
{
public:
	static HDEVINFO getInfoSet();
	static void getInfo(HDEVINFO infoSet);
};