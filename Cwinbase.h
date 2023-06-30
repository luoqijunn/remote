#pragma once
#include "CtrlBase.h"
#include <vector>

class CwinBase
{
public:
	CwinBase(int x = 0, int y = 0, int w = 0, int h = 0);
	~CwinBase();
	virtual void show();	//先显示界面框、再显示所有的控件
	void winRun();	//界面运行函数
	virtual int doAction();	//按钮业务的分发函数 返回值表示下一次要显示的界面对应的索引(序号)

protected:
	int x, y, w, h;	//界面框的xy坐标和宽w、高h
	vector<CtrlBase*> ctrlArry;	//用来保存每一个界面中的所有的标签、编辑框、按钮对象
	int focusIndex = 0;	// 保存选择的按钮在向量容器中对应的索引值

};
