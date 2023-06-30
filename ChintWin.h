#pragma once
#include "CButton.h"	//按钮类
#include "CTool.h"	//工具类
#include "CwinBase.h"	//窗口基类



class ChintWin : public CwinBase
{
public:
	ChintWin(int x = 0, int y = 0, int w = 0, int h = 0);
	~ChintWin();
	int doAction();
	void show();
private:
	CButton* confmButton;
};


