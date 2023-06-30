#include "CLabel.h"
//构造函数
CLabel::CLabel(int x, int y, const char* content) : CtrlBase(x, y, 0, 0, content, 1)
{

}
//析构函数
CLabel::~CLabel()
{
	//cout << "~CLabel finish" << endl;
}

//显示内容
void CLabel::show(void)
{
	//移动光标的位置
	CTool::gotoxy(this->x, this->y);
	//在该位置上显示内容
	cout << this->content << endl;
}