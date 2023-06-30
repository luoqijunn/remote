#pragma once
#include "CLabel.h"	//��ǩ��
#include "CButton.h"	//��ť��
#include "CEdit.h"	//�༭����
#include "CTool.h"	//������
#include "CwinBase.h"	//���ڻ���

class CRegWin : public CwinBase
{
public:
	CRegWin(int x = 0, int y = 0, int w = 0, int h = 0);
	~CRegWin();
	int doAction();

private:
	CLabel* titleLabel;
	CLabel* userLabel;
	CLabel* pwdLabel;
	CLabel* repwdLabel;
	CEdit* userEdit;
	CEdit* pwdEdit;
	CEdit* repwdEdit;
	CButton* regButton;
	CButton* backButton;

};
