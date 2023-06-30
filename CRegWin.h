#pragma once
#include "CLabel.h"	//标签类
#include "CButton.h"	//按钮类
#include "CEdit.h"	//编辑框类
#include "CTool.h"	//工具类
#include "CwinBase.h"	//窗口基类

class CRegWin : public CwinBase
{
public:
	CRegWin(int x = 0, int y = 0, int w = 0, int h = 0);
	~CRegWin();
	int doAction();

private:
	CLabel* titleLabel;
	CLabel* userLabel;
	CLabel* pwdLabel;
	CLabel* repwdLabel;
	CEdit* userEdit;
	CEdit* pwdEdit;
	CEdit* repwdEdit;
	CButton* regButton;
	CButton* backButton;

};
