#pragma once
#include "CTool.h"
#include <string.h>

using namespace std;
// �ؼ���
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
	int type;	//�ؼ����ͣ�1��ʾ��ǩ��2��ʾ�༭��3��ʾ��ť
};

