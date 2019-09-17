#pragma once
#include <windows.h> 
#include <SetupAPI.h>
#include <stdio.h>
#include <Windows.h>
#include <setupapi.h>
#include <vector>
#include <devguid.h>
#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <clocale>
#define BUFFER 10000
void getInfo(HDEVINFO infoSet);
HDEVINFO getInfoSet();
#pragma comment(lib, "setupapi.lib")