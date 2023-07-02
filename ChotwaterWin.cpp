#include "ChotwaterWin.h"
#include "CseldevWin.h"

ChotwaterWin::ChotwaterWin(int x, int y, int w, int h) :CwinBase(x, y, w, h)
{
	//����CLabel����
	this->cacLabel = new CLabel(25, 2, "��ˮ��������");
	this->openGateLabel = new CLabel(16, 5, "��ˮ��������");
	this->temperLabel = new CLabel(16, 9, "��ˮ���¶ȣ�");
	this->runModeLabel = new CLabel(16, 13, "��ˮ��״̬��");

	/*this->openGateShowLabel = new CLabel(26, 5, "1");
	this->temperShowLabel = new CLabel(26, 9, "2");
	this->runModeShowLabel = new CLabel(26, 13, "3");*/

	//��Ӱ�ť
	this->openGateButton = new CButton(14, 17, 18, 4, "        ��ˮ����/��");
	this->temperAddButton = new CButton(15, 22, 8, 4, "   +");
	this->temperMinButton = new CButton(33, 22, 8, 4, "   -");
	this->runModeButton = new CButton(14, 27, 18, 4, "         ��ˮ��״̬");
	this->backButton = new CButton(14, 32, 18, 4, "            �� ��");


	//��ӵ��ؼ�����������
	this->ctrlArry.push_back(this->cacLabel);		//0
	this->ctrlArry.push_back(this->openGateLabel);	//1
	this->ctrlArry.push_back(this->temperLabel);	//2
	this->ctrlArry.push_back(this->runModeLabel);	//3
	this->ctrlArry.push_back(this->openGateButton);	//4
	this->ctrlArry.push_back(this->temperAddButton);//5
	this->ctrlArry.push_back(this->temperMinButton);//6
	this->ctrlArry.push_back(this->runModeButton);	//7
	this->ctrlArry.push_back(this->backButton);		//8
}


ChotwaterWin::~ChotwaterWin()
{
	delete this->cacLabel;
	delete this->openGateLabel;
	delete this->temperLabel;
	delete this->runModeLabel;
	delete this->openGateButton;
	delete this->temperAddButton;
	delete this->temperMinButton;
	delete this->runModeButton;

}

void ChotwaterWin::show()
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
		CTool::gotoxy(28, 5);	//����
		if (strcmp(mydata->qres[4 + 7], "0"))
			cout << "��" << endl;
		else
			cout << "��" << endl;
		CTool::gotoxy(28, 9);	//�¶�
		cout << mydata->qres[5 + 7] << "��" << endl;
		CTool::gotoxy(28, 13);	//ģʽ
		if (!strcmp(mydata->qres[6 + 7], "0"))		//0. ����
			cout << "����ģʽ" << endl;
		else if (!strcmp(mydata->qres[6 + 7], "1"))	//1. ����
			cout << "����ģʽ" << endl;

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


int ChotwaterWin::doAction()
{
	//���ݿ����׼��
	CmyData* mydata = CmyData::getMydata();
	int res = 0;
	if (this->focusIndex == 4)	//����
	{
		memset(mydata->sql, 0, strlen(mydata->sql));	//sql���ʹ��ǰ���
		sprintf(mydata->sql, "update devstate_info set opengate = %d where DID = %d;", (atoi(mydata->qres[4 + 7]) + 1) % 2, CseldevWin::getdevID);
		res = mydata->noRes_exec(mydata->sql);
		if (res != 0)
		{
			//cout << "��������ʧ��" << endl;
			return 11;
		}
		else
		{
			//cout << "�������سɹ�" << endl;
			return 11;
		}
		//system("pause");
	}
	else if (this->focusIndex == 5)	//�¶ȼ�
	{
		memset(mydata->sql, 0, strlen(mydata->sql));	//sql���ʹ��ǰ���
		sprintf(mydata->sql, "update devstate_info set temper = %d where DID = %d;", atoi(mydata->qres[5 + 7]) + 1, CseldevWin::getdevID);
		res = mydata->noRes_exec(mydata->sql);
		if (res != 0)
		{
			//cout << "�����¶ȼ�ʧ��" << endl;
			return 11;
		}
		else
		{
			//cout << "�����¶ȼӳɹ�" << endl;
			return 11;
		}
		//system("pause");
	}
	else if (this->focusIndex == 6)	//�¶ȼ�
	{
		memset(mydata->sql, 0, strlen(mydata->sql));	//sql���ʹ��ǰ���
		sprintf(mydata->sql, "update devstate_info set temper = %d where DID = %d;", atoi(mydata->qres[5 + 7]) - 1, CseldevWin::getdevID);
		res = mydata->noRes_exec(mydata->sql);
		if (res != 0)
		{
			//cout << "�����¶ȼ�ʧ��" << endl;
			return 11;
		}
		else
		{
			//cout << "�����¶ȼ��ɹ�" << endl;
			return 11;
		}
		//system("pause");
	}
	else if (this->focusIndex == 7)	//�л�ģʽ
	{
		int tempmode = atoi(mydata->qres[6 + 7]);
		tempmode = (tempmode + 1) % 2;

		memset(mydata->sql, 0, strlen(mydata->sql));	//sql���ʹ��ǰ���
		sprintf(mydata->sql, "update devstate_info set mode = %d where DID = %d;", tempmode, CseldevWin::getdevID);
		//cout << mydata->sql << endl;
		//system("pause");
		res = mydata->noRes_exec(mydata->sql);
		if (res != 0)
		{
			//cout << "�����л�ģʽʧ��" << endl;
			//system("pause");
			return 11;
		}
		else
		{
			//cout << "�����л�ģʽ�ɹ�" << endl;
			return 11;
		}
		//system("pause");
	}
	else if (this->focusIndex == 8)	//����
	{
		return 2;
	}
	return 0;
}
