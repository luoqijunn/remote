#pragma once
#include "CTool.h"
#include <string.h>

using namespace std;
// 控件类
class CtrlBase
{
public:
	CtrlBase(int x = 0, int y = 0, int w = 0, int h = 0, const char* content = nullptr, int type = 1);
	~CtrlBase();
	virtual void show();
	int getX() { return this->x; }
	int getY() { return this->y; }
	char* getContent() { return this->content; }
	int getType() { return this->type; }
	virtual void keylisten(short key) {}
protected:
	int x, y, w, h;
	char content[50];
	int type;	//控件类型：1表示标签、2表示编辑框、3表示按钮
};

