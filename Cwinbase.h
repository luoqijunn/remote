#pragma once
#include "CtrlBase.h"
#include <vector>

class CwinBase
{
public:
	CwinBase(int x = 0, int y = 0, int w = 0, int h = 0);
	~CwinBase();
	virtual void show();	//����ʾ���������ʾ���еĿؼ�
	void winRun();	//�������к���
	virtual int doAction();	//��ťҵ��ķַ����� ����ֵ��ʾ��һ��Ҫ��ʾ�Ľ����Ӧ������(���)

protected:
	int x, y, w, h;	//������xy����Ϳ�w����h
	vector<CtrlBase*> ctrlArry;	//��������ÿһ�������е����еı�ǩ���༭�򡢰�ť����
	int focusIndex = 0;	// ����ѡ��İ�ť�����������ж�Ӧ������ֵ

};
