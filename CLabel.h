#pragma once
#include "CtrlBase.h"

using namespace std;

class CLabel :public CtrlBase
{
public:
	//构造函数
	CLabel(int x = 0, int y = 0, const char* content = nullptr);
	//析构函数
	~CLabel();
	//显示函数
	void show();
private: //属性
};