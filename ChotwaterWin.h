
#pragma once

#include "CLabel.h"	//��ǩ��
#include "CButton.h"	//��ť��
#include "CEdit.h"	//�༭����
#include "CTool.h"	//������
#include "CwinBase.h"	//���ڻ���

	class ChotwaterWin :public CwinBase
	{
	public:
		ChotwaterWin(int x = 0, int y = 0, int w = 0, int h = 0);
		~ChotwaterWin();
		void show();//�յ���ʾ
		int doAction();

	private:
		//��ǩ��
		CLabel* cacLabel;		//��ˮ����
		CLabel* openGateLabel;	// ��ˮ�����ر�ǩ
		CLabel* temperLabel;	//��ˮ���¶ȱ�ǩ
		CLabel* runModeLabel;	//��ˮ������ģʽ��ǩ

		//��Ӱ�ť
		CButton* openGateButton;	//���ذ�ť
		CButton* runModeButton;		//����ģʽ   0. ����   1. ����
		CButton* temperAddButton;	//�¶�+
		CButton* temperMinButton;	//�¶�-
		CButton* backButton;		//����
	};


