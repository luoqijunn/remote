#pragma once
#include "CLabel.h"	//��ǩ��
#include "CButton.h"	//��ť��
#include "CEdit.h"	//�༭����
#include "CTool.h"	//������
#include "CwinBase.h"	//���ڻ���

class ClampWin :public CwinBase
{

	public:
		ClampWin(int x = 0, int y = 0, int w = 0, int h = 0);
		~ClampWin();
		void show();//�յ���ʾ
		int doAction();

	private:
		//��ǩ��
		CLabel* cacLabel;		//����
		CLabel* openGateLabel;	// �ƿ��ر�ǩ
		CLabel* runModeLabel;	//������ģʽ��ǩ

		//��Ӱ�ť
		CButton* openGateButton;	//���ذ�ť
		CButton* runModeButton;		//����ģʽ 1. ǿ��  2. ����  3.ů��   4.��� 
		CButton* backButton;		//����
};

