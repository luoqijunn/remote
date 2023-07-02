
#pragma once

#include "CLabel.h"	//标签类
#include "CButton.h"	//按钮类
#include "CEdit.h"	//编辑框类
#include "CTool.h"	//工具类
#include "CwinBase.h"	//窗口基类

	class ChotwaterWin :public CwinBase
	{
	public:
		ChotwaterWin(int x = 0, int y = 0, int w = 0, int h = 0);
		~ChotwaterWin();
		void show();//空调显示
		int doAction();

	private:
		//标签类
		CLabel* cacLabel;		//热水器名
		CLabel* openGateLabel;	// 热水器开关标签
		CLabel* temperLabel;	//热水器温度标签
		CLabel* runModeLabel;	//热水器运行模式标签

		//添加按钮
		CButton* openGateButton;	//开关按钮
		CButton* runModeButton;		//运行模式   0. 加热   1. 保温
		CButton* temperAddButton;	//温度+
		CButton* temperMinButton;	//温度-
		CButton* backButton;		//返回
	};


