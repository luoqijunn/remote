#include "ClampWin.h"
#include "CseldevWin.h"

ClampWin::ClampWin(int x, int y, int w, int h) :CwinBase(x, y, w, h)
{
	//����CLabel����
	this->cacLabel = new CLabel(25, 2, "�ƹ������");
	this->openGateLabel = new CLabel(16, 5, "�ƿ�����");
	this->runModeLabel = new CLabel(16, 13, "�ƹ�״̬��");

	//��Ӱ�ť
	this->openGateButton = new CButton(14, 17, 18, 4, "          �ƹ⿪/��");

	this->runModeButton = new CButton(14, 27, 18, 4, "         �ƹ�����״̬");
	this->backButton = new CButton(14, 32, 18, 4, "            �� ��");


	//��ӵ��ؼ�����������
	this->ctrlArry.push_back(this->cacLabel);		//0
	this->ctrlArry.push_back(this->openGateLabel);	//1
	this->ctrlArry.push_back(this->runModeLabel);	//2

	this->ctrlArry.push_back(this->openGateButton);	//3
	this->ctrlArry.push_back(this->runModeButton);	//4
	this->ctrlArry.push_back(this->backButton);		//5
}


ClampWin::~ClampWin()
{
	delete this->cacLabel;

	delete this->openGateLabel;
	delete this->runModeLabel;

	delete this->openGateButton;
	delete this->runModeButton;

}

void ClampWin::show()
{
	CmyData* mydata = CmyData::getMydata();
	memset(mydata->sql, 0, strlen(mydata->sql));	//sql���ʹ��ǰ���
	sprintf(mydata->sql, "select * from devstate_info where DID = %d;", CseldevWin::getdevID);
	int res = mydata->getRes_exec();
	if (res != 0)
	{
		cout << "��ѯʧ��" << endl;
	}
	else
	{
		CTool::gotoxy(26, 5);	//����
		if (strcmp(mydata->qres[4 + 7], "0"))
			cout << "��" << endl;
		else
			cout << "��" << endl;
		CTool::gotoxy(26, 13);	//ģʽ
		if (!strcmp(mydata->qres[6 + 7], "0"))		//0. ǿ��
			cout << "ǿ��" << endl;
		else if (!strcmp(mydata->qres[6 + 7], "1"))	//1. ����
			cout << "����" << endl;
		else if (!strcmp(mydata->qres[6 + 7], "2"))	//2. ů��
			cout << "ů��" << endl;
		else if (!strcmp(mydata->qres[6 + 7], "3"))	//3. ���
			cout << "���" << endl;
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


int ClampWin::doAction()
{
	//���ݿ����׼��
	CmyData* mydata = CmyData::getMydata();
	int res = 0;
	if (this->focusIndex == 3)	//����
	{
		memset(mydata->sql, 0, strlen(mydata->sql));	//sql���ʹ��ǰ���
		sprintf(mydata->sql, "update devstate_info set opengate = %d where DID = %d;", (atoi(mydata->qres[4 + 7]) + 1) % 2, CseldevWin::getdevID);
		res = mydata->noRes_exec(mydata->sql);
		if (res != 0)
		{
			//cout << "��������ʧ��" << endl;
			return 7;
		}
		else
		{
			//cout << "�������سɹ�" << endl;
			return 7;
		}
		//system("pause");
	}
	else if (this->focusIndex == 4)	//�л�ģʽ
	{
		int tempmode = atoi(mydata->qres[6 + 7]);
		tempmode = (tempmode + 1) % 4;

		memset(mydata->sql, 0, strlen(mydata->sql));	//sql���ʹ��ǰ���
		sprintf(mydata->sql, "update devstate_info set mode = %d where DID = %d;", tempmode, CseldevWin::getdevID);
		//cout << mydata->sql << endl;
		//system("pause");
		res = mydata->noRes_exec(mydata->sql);
		if (res != 0)
		{
			//cout << "�����л�ģʽʧ��" << endl;
			//system("pause");
			return 7;
		}
		else
		{
			//cout << "�����л�ģʽ�ɹ�" << endl;
			return 7;
		}
		//system("pause");
	}
	else if (this->focusIndex == 5)	//����
	{
		return 2;
	}
	return 0;
}
