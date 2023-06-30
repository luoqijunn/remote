#pragma once

#include "CTool.h"
#include "CtrlBase.h"

using namespace std;
class CEdit : public CtrlBase
{
public:
	CEdit(int x = 0, int y = 0, int w = 0, int h = 0, const char* content = nullptr, bool ips = 1, unsigned int minlen = 5, unsigned int maxlen = 16, int inputtype = 3);	//���캯��
	~CEdit();	//��������
	void keylisten(short key);	//���̼�������
	void show();
	unsigned int getminlen() { return this->minlen; }
private: //����
	bool ips;	//1Ϊ���ģ�0Ϊ����
	unsigned int minlen;	//��С���볤��
	unsigned int maxlen;	//������볤��
	int inputtype;	//������������ͣ�1Ϊ���֣�2Ϊ��ĸ��3Ϊ����
};


