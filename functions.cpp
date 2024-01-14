#include "main.h"
#include "functions.h"
#include "Console.h"
using namespace std;
CauTrucBang CTBang;
CauTrucO** CTO;


COORD CViTriConTro;

bool BSuDungPhim = false;


void taoMang2ChieuDong()
{
	CTO = new CauTrucO * [CTBang.SDong];
	for (int i = 0; i < CTBang.SDong; ++i)
	{
		CTO[i] = new CauTrucO[CTBang.SCot];
	}

};
void xoaMang2ChieuDong()
{
	for (int i = 0; i < CTBang.SDong; ++i)
	{
		delete[] CTO[i];

	}
	delete[] CTO;
};
void khoiTao(short SDong, short SCot, short SSoBom)
{
	CTBang.SDong = SDong;
	CTBang.SCot = SCot;
	CTBang.SSoBom = SSoBom;
	CTBang.SSoODaMo = 0;
	CTBang.SSoCo = 0;
	taoMang2ChieuDong();
	veBang();
	taoBomNgauNhien();
	xuatBom();
	xoaMang2ChieuDong();
}
short toaDoX(short SX)
{
	return (SX * 2);
}
short toaDoY(short SY)
{
	return (SY);
}

void veO(short SX, short SY, short SKieu)
{
	switch (SKieu)
	{
	case 0:
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 0, 10, "  ");
		break;
	case 1:
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 9, 15, "1 ");
		break;
	case 2:
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 2, 15, "2 ");
		break;
	case 3:
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 12, 15, "3 ");
		break;
	case 4:
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 1, 15, "4 ");
		break;
	case 5:
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 4, 15, "5 ");
		break;
	case 6:
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 3, 15, "6 ");
		break;
	case 7:
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 0, 15, "7 ");
		break;
	case 8:
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 13, 15, "8 ");
		break;
	case 9:
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 0, 12, "B ");
		break;
	case 10:
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 0, 8, "  ");
		break;
	case 11:
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 0, 7, "  ");
		break;
	case 12:
		setColorBGTextXY(toaDoX(SX) + 1, toaDoY(SY), 0, 13, " ");
		break;
	case 13:
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 12, 14, "P ");
		break;
	case 14:
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 15, 16, "Px");
		break;
	case 15:
		setColorBGTextXY(toaDoX(SX), toaDoY(SY), 12, 14, "  ");
		break;

	}

} 
void veBang()
{
	for (int i = 0; i < CTBang.SDong; ++i)
	{
		for (int j = 0; j < CTBang.SCot; ++j)
		{

			if (CTO[i][j].BCamCo)
				veO(j, i, 13);
			else if (CTO[i][j].SBomLanCan)
				veO(j, i, CTO[i][j].SBomLanCan);
			else if (CTO[i][j].BDaMo)
				veO(j, i, 0);
			else if ((i + j) % 2)
				veO(i, j, 11);
			else
				veO(j, i, 10);
			if (BSuDungPhim)
				veO(CViTriConTro.X, CViTriConTro.Y, 12);
		}
	}
}
void taoBomNgauNhien()
{
	short SSoBom = CTBang.SSoBom;
	short SI, SJ;
	while (SSoBom)
	{
		SI = rand() % CTBang.SDong;
		SJ = rand() % CTBang.SCot;
		if (CTO[SI][SJ].BCoBom)
			continue;

		CTO[SI][SJ].BCoBom = true;
		--SSoBom;
	}
}
void xuatBom()
{
	for (int i = 0; i < CTBang.SDong; ++i)
	{
		for (int j = 0; j < CTBang.SCot; ++j)
		{
			cout << CTO[i][j].BCoBom << " ";
		}
		cout << endl;
	}
}
void clickPhai(short SX, short SY)
{
	if (!CTO[SX][SY].BDaMo)
	{
		if (CTO[SX][SY].BCamCo)
		{
			CTO[SX][SY].BCamCo = false;
			CTBang.SSoCo--;
		}
		else
		{
			CTO[SX][SY].BCamCo = true;
			CTBang.SSoCo++;
		}
	}
	veBang();
}
short demBomLanCan(short SX, short SY)
{
	short SDem = 0;
	for (int i = SX - 1; i <= SX + 1; ++i)
	{
		for (int j = SY - 1; i <= SY + 1; ++j)
		{
			if (i < 0 || i >= CTBang.SDong || j < 0 || j >= CTBang.SCot || (i == SX && j == SY))
				continue;
			if (CTO[i][j].BCoBom)
				++SDem;
		}
	}
	return SDem;
}
void moO(short SX, short SY)
{
	if (!CTO[SX][SY].BDaMo && !CTO[SX][SY].BCamCo)
	{
		CTO[SX][SY].BDaMo = true;
		if (CTO[SX][SY].BCoBom)
			exit(0);
		else
		{
			CTBang.SSoODaMo++;
			short SSoBomLanCan = demBomLanCan(SX, SY);
			if (SSoBomLanCan)
				CTO[SX][SY].SBomLanCan = SSoBomLanCan;
			else
			{
				for (int i = SX - 1; i <= SX + 1; ++i)
				{
					for (int j = SY - 1; i <= SY + 1; ++j)
					{
						if (i < 0 || i >= CTBang.SDong || j < 0 || j >= CTBang.SCot || (i == SX && j == SY))
							continue;
						moO(i, j);
					}
				}
			}
		}
	}
}
void clickTrai(short SX, short SY)
{
	if (!CTO[SX][SY].BDaMo && !CTO[SX][SY].BCamCo)
	{
		moO(SX, SY);
		veBang();
	}
}
void xuLyPhim(KEY_EVENT_RECORD key)
{
	if (key.bKeyDown)
	{
		switch (key.wVirtualKeyCode)
		{
		case VK_UP:
			//	cout << "Mui ten len"<<endl;
			BSuDungPhim = true;
			CViTriConTro.Y = ((CViTriConTro.Y == 0) ? CTBang.SDong - 1 : CViTriConTro.Y - 1);
			veBang();
			break;
		case VK_DOWN:
			//	cout << "Mui ten xuong"<<endl;
			BSuDungPhim = true;
			CViTriConTro.Y = ((CViTriConTro.Y == CTBang.SDong - 1) ? 0 : CViTriConTro.Y + 1);
			veBang();
			break;
		case VK_LEFT:
			//	cout << "Mui ten trai"<<endl;
			BSuDungPhim = true;
			CViTriConTro.X = ((CViTriConTro.X == 0) ? CTBang.SCot - 1 : CViTriConTro.X - 1);
			veBang();
			break;
		case VK_RIGHT:
			//	cout << "Mui ten phai"<<endl;
			BSuDungPhim = true;
			CViTriConTro.X = ((CViTriConTro.X == CTBang.SCot - 1) ? 0 : CViTriConTro.X + 1);
			veBang();
			break;
		case VK_RETURN:
			cout << "Enter" << endl;
			break;
		case VK_ESCAPE:
			cout << "ESC" << endl;
			break;
		case ClickTrai://Mo O(Z)
			//cout << "Z"<<endl;
			clickTrai(CViTriConTro.Y, CViTriConTro.X);
			break;
		case ClickPhai://Cam Co(X)
			//	cout << "X"<<endl;
			clickPhai(CViTriConTro.Y, CViTriConTro.X);
			break;
		}
	}
}
void xuLySuKien()
{
	while (1) {
		DWORD DWNumberOfEvents = 0;
		DWORD DWNumberOfEventsRead = 0;

		HANDLE HConsoleInput = GetStdHandle(STD_INPUT_HANDLE);
		GetNumberOfConsoleInputEvents(HConsoleInput, &DWNumberOfEvents);
		if (DWNumberOfEvents)
		{
			INPUT_RECORD* IREventBuffer = new INPUT_RECORD[DWNumberOfEvents];
			ReadConsoleInput(HConsoleInput, IREventBuffer, DWNumberOfEvents, &DWNumberOfEventsRead);
			for (DWORD i = 0; i < DWNumberOfEvents; ++i)
			{
				if (IREventBuffer[i].EventType == KEY_EVENT)
				{
					xuLyPhim(IREventBuffer[i].Event.KeyEvent);


				}
			}
		}

	}
}