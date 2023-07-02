
#pragma once
#include "CLabel.h"	//��ǩ��
#include "CButton.h"	//��ť��
#include "CEdit.h"	//�༭����
#include "CTool.h"	//������
#include "CwinBase.h"	//���ڻ���

	class CcurtainWin : public CwinBase
	{

	public:
		CcurtainWin(int x = 0, int y = 0, int w = 0, int h = 0);
		~CcurtainWin();
		void show();
		int doAction();

	private:
		//��ǩ��
		CLabel* cacLabel;		//������
		CLabel* openGateLabel;	// ������ǰ����

		//��Ӱ�ť
		CButton* openGateButton;	//��������

		CButton* backButton;		//����
	};





