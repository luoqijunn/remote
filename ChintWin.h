#pragma once
#include "CButton.h"	//��ť��
#include "CTool.h"	//������
#include "CwinBase.h"	//���ڻ���



class ChintWin : public CwinBase
{
public:
	ChintWin(int x = 0, int y = 0, int w = 0, int h = 0);
	~ChintWin();
	int doAction();
	void show();
private:
	CButton* confmButton;
};


