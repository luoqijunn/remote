#pragma once
#include "CLabel.h"	//标签类
#include "CButton.h"	//按钮类
#include "CEdit.h"	//编辑框类
#include "CTool.h"	//工具类
#include "CwinBase.h"	//窗口基类
#include "CmyData.h"	//数据库类
#include "CLoginWin.h"	//登录窗口类


class CrmdevWin : public CwinBase
{
public:
	CrmdevWin(int x = 0, int y = 0, int w = 0, int h = 0);
	~CrmdevWin();
	int doAction();

private:
	CLabel* titleLabel;
	CLabel* devnameLabel;
	CEdit* devnameEdit;
	CButton* confirmButton;
	CButton* exitButton;
};

