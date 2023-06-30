#pragma once
#include "CLabel.h"	//��ǩ��
#include "CButton.h"	//��ť��
#include "CEdit.h"	//�༭����
#include "CTool.h"	//������
#include "CwinBase.h"	//���ڻ���
#include "CmyData.h"	//���ݿ���
#include "CLoginWin.h"	//��¼������

class CseldevWin : public CwinBase
{
public:
	CseldevWin(int x = 0, int y = 0, int w = 0, int h = 0);
	~CseldevWin();
	int doAction();
	void show();
	static int getdevID;
private:
	CLabel* titleLabel;
	CButton* insertButton;
	CButton* deleteButton;
	CButton* backButton;
};


