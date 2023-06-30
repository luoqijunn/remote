#pragma once

#include "CLabel.h"	//标签类
#include "CButton.h"	//按钮类
#include "CEdit.h"	//编辑框类
#include "CTool.h"	//工具类
#include "CwinBase.h"	//窗口基类

class CACWin:public CwinBase
{
public:
	CACWin(int x = 0, int y = 0, int w = 0, int h = 0);
	~CACWin();
	void show();//空调显示
	int doAction();

private:
	//标签类
	CLabel* cacLabel;		//空调名
	CLabel* openGateLabel;	// 空调开关标签
	CLabel* temperLabel;	//空调温度标签
	CLabel* runModeLabel;	//空调运行模式标签

	//添加按钮
	CButton* openGateButton;	//开关按钮
	CButton* runModeButton;		//运行模式 1. 自动  2. 制冷  3. 制热  4. 送风
	CButton* temperAddButton;	//温度+
	CButton* temperMinButton;	//温度-
	CButton* backButton;		//返回
};

