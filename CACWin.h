#pragma once

#include "CLabel.h"	//��ǩ��
#include "CButton.h"	//��ť��
#include "CEdit.h"	//�༭����
#include "CTool.h"	//������
#include "CwinBase.h"	//���ڻ���

class CACWin:public CwinBase
{
public:
	CACWin(int x = 0, int y = 0, int w = 0, int h = 0);
	~CACWin();
	void show();//�յ���ʾ
	int doAction();

private:
	//��ǩ��
	CLabel* cacLabel;		//�յ���
	CLabel* openGateLabel;	// �յ����ر�ǩ
	CLabel* temperLabel;	//�յ��¶ȱ�ǩ
	CLabel* runModeLabel;	//�յ�����ģʽ��ǩ

	//��Ӱ�ť
	CButton* openGateButton;	//���ذ�ť
	CButton* runModeButton;		//����ģʽ 1. �Զ�  2. ����  3. ����  4. �ͷ�
	CButton* temperAddButton;	//�¶�+
	CButton* temperMinButton;	//�¶�-
	CButton* backButton;		//����
};

