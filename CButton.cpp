#include "CButton.h"

//构造函数
CButton::CButton(int x, int y, int w, int h, const char* content) : CtrlBase(x, y, w, h, content, 3)
{
	
}
//析构函数
CButton::~CButton()
{
	//cout << "~CButton finish" << endl;
}
