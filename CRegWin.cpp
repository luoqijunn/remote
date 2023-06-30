//#include "CLoginWin.h"
#include "CRegWin.h"

CRegWin::CRegWin(int x, int y, int w, int h) : CwinBase(x, y, w, h)
{
	//����CLabel����
	this->titleLabel = new CLabel(40, 2, "ע �� ϵ ͳ");
	this->userLabel = new CLabel(25, 5, "�˺ţ�");
	this->pwdLabel = new CLabel(25, 8, "���룺");
	this->repwdLabel = new CLabel(25, 11, "ȷ�����룺");
	//����CEdit����
	this->userEdit = new CEdit(35, 4, 15, 3, "", 1);
	this->pwdEdit = new CEdit(35, 7, 15, 3, "", 0);
	this->repwdEdit = new CEdit(35, 10, 15, 3, "", 0);
	//����CButton����
	this->regButton = new CButton(33, 14, 6, 3, "ע ��");
	this->backButton = new CButton(48, 14, 6, 3, "�� ��");

	//this->frame = new CButton(13, 1, 33, 18, "");
	
	//��ӵ��ؼ�����������
	this->ctrlArry.push_back(this->titleLabel);	//0
	this->ctrlArry.push_back(this->userLabel);	//1
	this->ctrlArry.push_back(this->pwdLabel);	//2
	this->ctrlArry.push_back(this->repwdLabel);	//3
	this->ctrlArry.push_back(this->userEdit);	//4
	this->ctrlArry.push_back(this->pwdEdit);	//5
	this->ctrlArry.push_back(this->repwdEdit);	//6
	this->ctrlArry.push_back(this->regButton);	//7
	this->ctrlArry.push_back(this->backButton);	//8
	
}
CRegWin::~CRegWin()
{
	delete this->titleLabel;
	delete this->userLabel;
	delete this->pwdLabel;
	delete this->repwdLabel;
	delete this->userEdit;
	delete this->pwdEdit;
	delete this->repwdEdit;
	delete this->regButton;
	delete this->backButton;
}

int CRegWin::doAction()
{
	if (this->focusIndex == 7)
	{
		//cout << "ע�ᰴť��ѡ����" << endl;
		//ע��ҵ��
		if (strlen(this->userEdit->getContent()) < this->userEdit->getminlen() || strlen(this->pwdEdit->getContent()) < this->userEdit->getminlen())
		{
			memset(this->pwdEdit->getContent(), 0, 20);	//�������༭��
			memset(this->repwdEdit->getContent(), 0, 20);
			//cout << "�û����ĳ��Ȳ�������" << this->userEdit->getminlen() << endl;
			//cout << "����ĳ��Ȳ�������" << this->pwdEdit->getminlen() << endl;
			//ע��ʧ��  return 1;  ������ʾע�����
			//����tips�Ի���
			CTool::tips = "�û���������ĳ��ȹ���";
			CTool::tipsret = 1;
			return 6;
		}
		if (strcmp(this->pwdEdit->getContent(), this->repwdEdit->getContent()))
		{
			memset(this->pwdEdit->getContent(), 0, 20);	//�������༭��
			memset(this->repwdEdit->getContent(), 0, 20);
			//cout << "������ȷ�����벻һ��" << endl;
			//ע��ʧ��  return 1;  ������ʾע�����
			//����tips�Ի���
			CTool::tips = "������ȷ�����벻һ��";
			CTool::tipsret = 1;
			return 6;
		}
		//��ȡΨһ��mydata����
		CmyData* mydata = CmyData::getMydata();
		memset(mydata->sql, 0, strlen(mydata->sql));	//sql���ʹ��ǰ���
		sprintf(mydata->sql, "select * from user_info where name = '%s';", this->userEdit->getContent());
		int res = mydata->getRes_exec();
		if (res != 0)
		{
			memset(this->pwdEdit->getContent(), 0, 20);	//�������༭��
			memset(this->repwdEdit->getContent(), 0, 20);
			//cout << "��ѯʧ��" << endl;
			//����tips�Ի���
			CTool::tips = "      ע��ʧ��";
			CTool::tipsret = 0;
			return 6;
		}
		else
		{
			//cout << "��ѯ�ɹ�" << endl;
			if (mydata->row)
			{
				memset(this->pwdEdit->getContent(), 0, 20);	//�������༭��
				memset(this->repwdEdit->getContent(), 0, 20);
				//cout << "���û��Ѵ���" << endl;
				//����tips�Ի���
				CTool::tips = "   ���û��Ѵ���";
				CTool::tipsret = 1;
				return 6;
			}
			else
			//��������
			{
				memset(mydata->sql, 0, strlen(mydata->sql));	//sql���ʹ��ǰ���
				sprintf(mydata->sql, "insert into user_info values(null, '%s', '%s');", this->userEdit->getContent(), this->pwdEdit->getContent());
				res = mydata->noRes_exec(mydata->sql);
				if (res != 0)
				{
					memset(this->pwdEdit->getContent(), 0, 20);	//�������༭��
					memset(this->repwdEdit->getContent(), 0, 20);
					//cout << "�û�ע��ʧ��" << endl;
					//����tips�Ի���
					CTool::tips = "   �û�ע��ʧ��";
					CTool::tipsret = 0;
					return 6;
				}
				else
				{
					memset(this->pwdEdit->getContent(), 0, 20);	//�������༭��
					memset(this->repwdEdit->getContent(), 0, 20);
					//cout << "�û�ע��ɹ�" << endl;
					//����tips�Ի���
					CTool::tips = "   �û�ע��ɹ�";
					CTool::tipsret = 0;
					return 6;
				}
			}
		}
		//system("pause");
		//ע��ɹ�  return 0;  ��ʾ��¼����
	}
	else if (this->focusIndex == 8) //ѡ�񷵻ذ�ť�� �л�����¼����
	{
		memset(this->pwdEdit->getContent(), 0, 20);	//�������༭��
		memset(this->repwdEdit->getContent(), 0, 20);
		//ѡ���¼  return 1;  �����¼����
		//cout << "��¼��ť��ѡ��" << endl;
		return 0;
	}
	else
		return -1;
}