#define _CRT_SECURE_NO_WARNINGS

#include "CtrlBase.h"

CtrlBase::CtrlBase(int x, int y, int w, int h, const char* content, int type)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->type = type;
	//初始化
	memset(this->content, 0, sizeof(this->content));
	if (content != nullptr)
	{
		strcpy(this->content, content);
	}
}

CtrlBase::~CtrlBase()
{

}
//控件类显示函数
void CtrlBase::show()
{
	//打印控件框
	CTool::paintWindow(this->x, this->y, this->w, this->h);
	//移动光标到控件上
	CTool::gotoxy(this->x + 3, this->y + 1);
	cout << this->content << endl;

}
