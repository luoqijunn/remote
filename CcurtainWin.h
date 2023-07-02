
#pragma once
#include "CLabel.h"	//标签类
#include "CButton.h"	//按钮类
#include "CEdit.h"	//编辑框类
#include "CTool.h"	//工具类
#include "CwinBase.h"	//窗口基类

	class CcurtainWin : public CwinBase
	{

	public:
		CcurtainWin(int x = 0, int y = 0, int w = 0, int h = 0);
		~CcurtainWin();
		void show();
		int doAction();

	private:
		//标签类
		CLabel* cacLabel;		//窗户名
		CLabel* openGateLabel;	// 窗户当前开关

		//添加按钮
		CButton* openGateButton;	//窗户开关

		CButton* backButton;		//返回
	};





