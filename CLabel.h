#pragma once
#include "CtrlBase.h"

using namespace std;

class CLabel :public CtrlBase
{
public:
	//���캯��
	CLabel(int x = 0, int y = 0, const char* content = nullptr);
	//��������
	~CLabel();
	//��ʾ����
	void show();
private: //����
};