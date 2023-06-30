#pragma once

#include "CTool.h"
#include "CtrlBase.h"

using namespace std;
class CEdit : public CtrlBase
{
public:
	CEdit(int x = 0, int y = 0, int w = 0, int h = 0, const char* content = nullptr, bool ips = 1, unsigned int minlen = 5, unsigned int maxlen = 16, int inputtype = 3);	//构造函数
	~CEdit();	//析构函数
	void keylisten(short key);	//键盘监听函数
	void show();
	unsigned int getminlen() { return this->minlen; }
private: //属性
	bool ips;	//1为明文，0为密文
	unsigned int minlen;	//最小输入长度
	unsigned int maxlen;	//最大输入长度
	int inputtype;	//允许输入的类型：1为数字，2为字母，3为两者
};


