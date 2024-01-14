#include <iostream>
#pragma once
#include <ctime>
#define ClickTrai 0x5A
#define ClickPhai 0x58
struct CauTrucBang
{
	short SDong=0;
	short SCot=0;
	short SSoBom=0;
	short SSoCo=0;
	short SSoODaMo=0;
};

struct CauTrucO
{
	bool BCoBom= false;
	bool BCamCo = false;
	bool BDaMo =false;
	short SBomLanCan = 0;
};
