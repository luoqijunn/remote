#pragma once
#include "CLabel.h"	//��ǩ��
#include "CButton.h"	//��ť��
#include "CEdit.h"	//�༭����
#include "CTool.h"	//������
#include "CwinBase.h"	//���ڻ���
#include "CmyData.h"	//���ݿ���
#include "CLoginWin.h"	//��¼������


class CrmdevWin : public CwinBase
{
public:
	CrmdevWin(int x = 0, int y = 0, int w = 0, int h = 0);
	~CrmdevWin();
	int doAction();

private:
	CLabel* titleLabel;
	CLabel* devnameLabel;
	CEdit* devnameEdit;
	CButton* confirmButton;
	CButton* exitButton;
};
