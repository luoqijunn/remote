#include "CLoginWin.h"

char CLoginWin::getusername[20] = "\0";

CLoginWin::CLoginWin(int x, int y, int w, int h) :CwinBase(x, y, w, h)
{
	//����CLabel����
	this->titleLabel = new CLabel(39, 2, "�� ¼ ϵ ͳ");
	this->userLabel = new CLabel(25, 5, "�˺ţ�");
	this->pwdLabel = new CLabel(25, 8, "���룺");
	//����CEdit����
	this->userEdit = new CEdit(35, 4, 15, 3, "", 1);
	this->pwdEdit = new CEdit(35, 7, 15, 3, "", 0);
	//����CButton����
	this->loginButton = new CButton(28, 14, 6, 3, "�� ¼");
	this->regButton = new CButton(40, 14, 6, 3, "ע ��");
	this->exitButton = new CButton(52, 14, 6, 3, "�� ��");
	
	//this->frame = new CButton(13, 1, 33, 18, "");
	
	//��ӵ��ؼ�����������
	this->ctrlArry.push_back(this->titleLabel);	//0
	this->ctrlArry.push_back(this->userLabel);	//1
	this->ctrlArry.push_back(this->pwdLabel);	//2
	this->ctrlArry.push_back(this->userEdit);	//3
	this->ctrlArry.push_back(this->pwdEdit);	//4
	this->ctrlArry.push_back(this->loginButton);//5
	this->ctrlArry.push_back(this->regButton);	//6
	this->ctrlArry.push_back(this->exitButton);	//7
	
}
CLoginWin::~CLoginWin()
{
	delete this->titleLabel;
	delete this->userLabel;
	delete this->pwdLabel;
	delete this->userEdit;
	delete this->pwdEdit;
	delete this->loginButton;
	delete this->regButton;
	delete this->exitButton;
}

int CLoginWin::doAction()
{
	if (this->focusIndex == 5) //�����ѡ���ǵ�¼�� �л�����¼����
	{
		if (!strlen(this->userEdit->getContent()) || !strlen(this->pwdEdit->getContent()))
		{
			memset(this->pwdEdit->getContent(), 0, 20);	//�������༭��
			//cout << "�û��������벻��Ϊ��" << endl;
			//����tips�Ի���
			CTool::tips = "�û��������벻��Ϊ��";
			CTool::tipsret = 0;
			return 6;
		}
		//cout << "��¼��ť��ѡ��" << endl;
		//��¼��֤
		CmyData* mydata = CmyData::getMydata();
		memset(mydata->sql, 0, strlen(mydata->sql));	//sql���ʹ��ǰ���
		sprintf(mydata->sql, "select * from user_info where name = '%s';", this->userEdit->getContent());
		int res = mydata->getRes_exec();
		if (res != 0)
		{
			memset(this->pwdEdit->getContent(), 0, 20);	//�������༭��
			//cout << "��ѯʧ��" << endl;
			//system("pause");
			//����tips�Ի���
			CTool::tips = "      ��¼ʧ��";
			CTool::tipsret = 0;
			return 6;
		}
		else
		{

			//cout << "��ѯ�ɹ�" << endl;
			if (!(mydata->row))
			{
				memset(this->pwdEdit->getContent(), 0, 20);	//�������༭��
				//cout << "���û�������" << endl;
				//system("pause");
				//����tips�Ի���
				CTool::tips = "�û������������";
				CTool::tipsret = 0;
				return 6;
			}
			else
			{
				if (strcmp(this->pwdEdit->getContent(), mydata->qres[2+3]))
				{
					memset(this->pwdEdit->getContent(), 0, 20);	//�������༭��
					//cout << "�û������������" << endl;
					//system("pause");
					//ʧ�� ��ʾ��¼���� return 0;
					//����tips�Ի���
					CTool::tips = "�û������������";
					CTool::tipsret = 0;
					return 6;
				}
				else
				{
					//cout << "��¼�ɹ�" << endl;
					memset(getusername, 0, sizeof(getusername));
					strcpy(getusername, this->userEdit->getContent());
					memset(this->pwdEdit->getContent(), 0, 20);	//�������༭��
					//system("pause");
					// �ɹ� ����һ���µĽ���  return -2;
					//����tips�Ի���
					CTool::tips = "      ��¼�ɹ�";
					CTool::tipsret = 2;
					return 6;
				}
			}
		}
	}
	else if (this->focusIndex == 6)
	{
		//cout << "ע�ᰴť��ѡ����" << endl;
		//ѡ��ע�� ����ע�����
		memset(this->pwdEdit->getContent(), 0, 20);	//�������༭��
		return 1;
	}
	else if (this->focusIndex == 7)
	{
		//ѡ���˳� �˳�����
		//cout << "�˳���ť��ѡ����" << endl;
		memset(this->pwdEdit->getContent(), 0, 20);	//�������༭��
		return -1;
	}
	else
		return -1;
}