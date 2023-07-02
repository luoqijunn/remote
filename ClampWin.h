#pragma once
#include "CLabel.h"	//标签类
#include "CButton.h"	//按钮类
#include "CEdit.h"	//编辑框类
#include "CTool.h"	//工具类
#include "CwinBase.h"	//窗口基类

class ClampWin :public CwinBase
{

	public:
		ClampWin(int x = 0, int y = 0, int w = 0, int h = 0);
		~ClampWin();
		void show();//空调显示
		int doAction();

	private:
		//标签类
		CLabel* cacLabel;		//灯名
		CLabel* openGateLabel;	// 灯开关标签
		CLabel* runModeLabel;	//灯运行模式标签

		//添加按钮
		CButton* openGateButton;	//开关按钮
		CButton* runModeButton;		//运行模式 1. 强光  2. 弱光  3.暖光   4.冷光 
		CButton* backButton;		//返回
};

