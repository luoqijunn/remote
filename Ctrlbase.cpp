#define _CRT_SECURE_NO_WARNINGS

#include "CtrlBase.h"

CtrlBase::CtrlBase(int x, int y, int w, int h, const char* content, int type)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->type = type;
	//��ʼ��
	memset(this->content, 0, sizeof(this->content));
	if (content != nullptr)
	{
		strcpy(this->content, content);
	}
}

CtrlBase::~CtrlBase()
{

}
//�ؼ�����ʾ����
void CtrlBase::show()
{
	//��ӡ�ؼ���
	CTool::paintWindow(this->x, this->y, this->w, this->h);
	//�ƶ���굽�ؼ���
	CTool::gotoxy(this->x + 3, this->y + 1);
	cout << this->content << endl;

}
