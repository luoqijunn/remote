#pragma once
#include "CLabel.h"	//��ǩ��
#include "CButton.h"	//��ť��
#include "CEdit.h"	//�༭����
#include "CTool.h"	//������
#include "CwinBase.h"	//���ڻ���

class CLoginWin :public CwinBase
{
public:
	CLoginWin(int x = 0, int y = 0, int w = 0, int h = 0);
	~CLoginWin();
	int doAction();
	static char getusername[20];
private:
	CLabel* titleLabel;
	CLabel* userLabel;
	CLabel* pwdLabel;
	CButton* loginButton;
	CButton* regButton;
	CButton* exitButton;
	CEdit* userEdit;
	CEdit* pwdEdit;
};

