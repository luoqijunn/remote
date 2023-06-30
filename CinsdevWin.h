#pragma once
#include "CLabel.h"	//标签类
#include "CButton.h"	//按钮类
#include "CEdit.h"	//编辑框类
#include "CTool.h"	//工具类
#include "CwinBase.h"	//窗口基类
#include "CmyData.h"	//数据库类
#include "CLoginWin.h"	//登录窗口类


class CinsdevWin : public CwinBase
{
public:
	CinsdevWin(int x = 0, int y = 0, int w = 0, int h = 0);
	~CinsdevWin();
	int doAction();

private:
	CLabel* titleLabel;
	CLabel* devnameLabel;
	CLabel* devtypeLabel;
	CLabel* typetipLabel;
	CEdit* devnameEdit;
	CEdit* devtypeEdit;
	CButton* confirmButton;
	CButton* exitButton;
};

