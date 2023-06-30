#pragma once
#include "CLabel.h"	//标签类
#include "CButton.h"	//按钮类
#include "CEdit.h"	//编辑框类
#include "CTool.h"	//工具类
#include "CwinBase.h"	//窗口基类

class CLoginWin :public CwinBase
{
public:
	CLoginWin(int x = 0, int y = 0, int w = 0, int h = 0);
	~CLoginWin();
	int doAction();
	static char getusername[20];
private:
	CLabel* titleLabel;
	CLabel* userLabel;
	CLabel* pwdLabel;
	CButton* loginButton;
	CButton* regButton;
	CButton* exitButton;
	CEdit* userEdit;
	CEdit* pwdEdit;
};

