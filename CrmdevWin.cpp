#include "CrmdevWin.h"

CrmdevWin::CrmdevWin(int x, int y, int w, int h) : CwinBase(x, y, w, h)
{
	//����CLabel����
	this->titleLabel = new CLabel(39, 2, "ɾ �� �� ��");
	this->devnameLabel = new CLabel(25, 5, "�豸����");
	//����CEdit����
	this->devnameEdit = new CEdit(35, 4, 15, 3, "", 1, 2, 6, 4);
	//����CButton����
	this->confirmButton = new CButton(28, 14, 6, 3, "ȷ ��");
	this->exitButton = new CButton(52, 14, 6, 3, "�� ��");

	//��ӵ��ؼ�����������
	this->ctrlArry.push_back(this->titleLabel);		//0
	this->ctrlArry.push_back(this->devnameLabel);	//1
	this->ctrlArry.push_back(this->devnameEdit);	//2
	this->ctrlArry.push_back(this->confirmButton);	//3
	this->ctrlArry.push_back(this->exitButton);		//4

}

CrmdevWin::~CrmdevWin()
{
	delete this->titleLabel;
	delete this->devnameLabel;
	delete this->devnameEdit;
	delete this->confirmButton;
	delete this->exitButton;
}
int CrmdevWin::doAction()
{
	if (this->focusIndex == 3)
	{
		//ɾ���豸
		//��ȡΨһ��mydata����
		CmyData* mydata = CmyData::getMydata();
		memset(mydata->sql, 0, strlen(mydata->sql));	//sql���ʹ��ǰ���
		sprintf(mydata->sql, "select * from devstate_info where username = '%s' and devname = '%s';", CLoginWin::getusername, this->devnameEdit->getContent());
		int res = mydata->getRes_exec();
		if (res != 0)
		{
			memset(this->devnameEdit->getContent(), 0, 20);	//����༭��
			//cout << "��ѯʧ��" << endl;.
			//����tips�Ի���
			CTool::tips = "      ɾ��ʧ��";
			CTool::tipsret = 2;
			return 6;
		}
		else
		{
			//cout << "��ѯ�ɹ�" << endl;
			if (mydata->row == 0)
			{
				memset(this->devnameEdit->getContent(), 0, 20);	//����༭��
				//cout << "�޴��豸" << endl;
				//����tips�Ի���
				CTool::tips = "      �޴��豸";
				CTool::tipsret = 2;
				return 6;
			}
			else
			{
				memset(mydata->sql, 0, strlen(mydata->sql));	//sql���ʹ��ǰ���
				sprintf(mydata->sql, "delete from devstate_info where username = '%s' and devname = '%s';", CLoginWin::getusername, this->devnameEdit->getContent());
				res = mydata->noRes_exec(mydata->sql);
				if (res != 0)
				{
					memset(this->devnameEdit->getContent(), 0, 20);	//����༭��
					//cout << "ɾ��ʧ��" << endl;
					//����tips�Ի���
					CTool::tips = "      ɾ��ʧ��";
					CTool::tipsret = 2;
					return 6;
				}
				else
				{
					memset(this->devnameEdit->getContent(), 0, 20);	//����༭��
					//cout << "ɾ���ɹ�" << endl;
					//����tips�Ի���
					CTool::tips = "      ɾ���ɹ�";
					CTool::tipsret = 2;
					return 6;
				}
			}
		}
		
	}
	else if (this->focusIndex == 4)
	{
		//cout << "���ذ�ť��ѡ����" << endl;
		//ѡ�񷵲� ����ѡ���豸����
		memset(this->devnameEdit->getContent(), 0, 20);	//����༭��
		return 2;
	}
	else
		return 2;
}

