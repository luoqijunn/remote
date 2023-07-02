#include "CcurtainWin.h"

#include "CseldevWin.h"

CcurtainWin::CcurtainWin(int x, int y, int w, int h) :CwinBase(x, y, w, h)
{
	//����CLabel����
	this->cacLabel = new CLabel(25, 2, " ����������");
	this->openGateLabel = new CLabel(16, 5, "����������");



	//��Ӱ�ť
	this->openGateButton = new CButton(14, 17, 18, 4, "          ������/��");

	this->backButton = new CButton(14, 32, 18, 4, "            �� ��");


	//��ӵ��ؼ�����������
	this->ctrlArry.push_back(this->cacLabel);		//0
	this->ctrlArry.push_back(this->openGateLabel);	//1
	this->ctrlArry.push_back(this->openGateButton);	//2

	this->ctrlArry.push_back(this->backButton);		//3
}


CcurtainWin::~CcurtainWin()
{
	delete this->cacLabel;
	delete this->openGateLabel;
	delete this->openGateButton;

}

void CcurtainWin::show()
{
	CmyData* mydata = CmyData::getMydata();
	memset(mydata->sql, 0, strlen(mydata->sql));	//sql���ʹ��ǰ���
	sprintf(mydata->sql, "select * from devstate_info where DID = %d;", CseldevWin::getdevID);
	int res = mydata->getRes_exec();
	if (res != 0)
	{
		//cout << "��ѯʧ��" << endl;
	}
	else
	{
		CTool::gotoxy(26, 5);	//����
		if (strcmp(mydata->qres[4 + 7], "0"))
			cout << "��" << endl;
		else
			cout << "��" << endl;
	}
	//�������
	CTool::paintWindow(this->x, this->y, this->w, this->h);
	//����ʾ��
	CTool::paintWindow(this->x + 1, this->y + 3, this->w - 1, this->h - 25);
	//�����ؼ���������
	for (unsigned int i = 0; i < this->ctrlArry.size(); i++)
	{
		this->ctrlArry.at(i)->show();
	}
}


int CcurtainWin::doAction()
{
	//���ݿ����׼��
	CmyData* mydata = CmyData::getMydata();
	int res = 0;
	if (this->focusIndex == 2)	//����
	{
		memset(mydata->sql, 0, strlen(mydata->sql));	//sql���ʹ��ǰ���
		sprintf(mydata->sql, "update devstate_info set opengate = %d where DID = %d;", (atoi(mydata->qres[4 + 7]) + 1) % 2, CseldevWin::getdevID);
		res = mydata->noRes_exec(mydata->sql);
		if (res != 0)
		{
			//cout << "��������ʧ��" << endl;
			return 9;
		}
		else
		{
			//cout << "�������سɹ�" << endl;
			return 9;
		}
		//system("pause");
	}

	else if (this->focusIndex == 3)	//����
	{
		return 2;
	}
	return 0;
}

