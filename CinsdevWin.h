#pragma once
#include "CLabel.h"	//��ǩ��
#include "CButton.h"	//��ť��
#include "CEdit.h"	//�༭����
#include "CTool.h"	//������
#include "CwinBase.h"	//���ڻ���
#include "CmyData.h"	//���ݿ���
#include "CLoginWin.h"	//��¼������


class CinsdevWin : public CwinBase
{
public:
	CinsdevWin(int x = 0, int y = 0, int w = 0, int h = 0);
	~CinsdevWin();
	int doAction();

private:
	CLabel* titleLabel;
	CLabel* devnameLabel;
	CLabel* devtypeLabel;
	CLabel* typetipLabel;
	CEdit* devnameEdit;
	CEdit* devtypeEdit;
	CButton* confirmButton;
	CButton* exitButton;
};

