#include "CinsdevWin.h"

CinsdevWin::CinsdevWin(int x, int y, int w, int h) : CwinBase(x, y, w, h)
{
	//����CLabel����
	this->titleLabel = new CLabel(43, 2, "�� �� �� ��");
	this->devnameLabel = new CLabel(29, 5, "�豸����");
	this->devtypeLabel = new CLabel(29, 8, "�豸���ͣ�");
	this->typetipLabel = new CLabel(10, 10, "tips���豸����ֻ���������֡�1Ϊ�յ���2Ϊ�ƹ⣬3Ϊ������4Ϊ������5Ϊ��أ�6Ϊ��ˮ��");
	//����CEdit����
	this->devnameEdit = new CEdit(39, 4, 15, 3, "", 1, 2, 6, 4);
	this->devtypeEdit = new CEdit(39, 7, 15, 3, "", 0, 1, 2, 1);
	//����CButton����
	this->confirmButton = new CButton(28, 14, 6, 3, "ȷ ��");
	this->exitButton = new CButton(59, 14, 6, 3, "�� ��");

	//��ӵ��ؼ�����������
	this->ctrlArry.push_back(this->titleLabel);		//0
	this->ctrlArry.push_back(this->devnameLabel);	//1
	this->ctrlArry.push_back(this->devtypeLabel);	//2
	this->ctrlArry.push_back(this->typetipLabel);	//3
	this->ctrlArry.push_back(this->devnameEdit);	//4
	this->ctrlArry.push_back(this->devtypeEdit);	//5
	this->ctrlArry.push_back(this->confirmButton);	//6
	this->ctrlArry.push_back(this->exitButton);		//7

}

CinsdevWin::~CinsdevWin()
{
	delete this->titleLabel;
	delete this->devnameLabel;
	delete this->devtypeLabel;
	delete this->devnameEdit;
	delete this->devtypeEdit;
	delete this->confirmButton;
	delete this->exitButton;
}
int CinsdevWin::doAction()
{
	if (this->focusIndex == 6)
	{
		//����ǰ��ѯ�豸���Ƿ��ظ�
		//��ȡΨһ��mydata����
		CmyData* mydata = CmyData::getMydata();
		memset(mydata->sql, 0, strlen(mydata->sql));	//sql���ʹ��ǰ���
		sprintf(mydata->sql, "select * from devstate_info where username = '%s' and devname = '%s';", CLoginWin::getusername, this->devnameEdit->getContent());
		int res = mydata->getRes_exec();
		if (res != 0)
		{
			memset(this->devnameEdit->getContent(), 0, 20);	//����༭��
			memset(this->devtypeEdit->getContent(), 0, 20);
			//cout << "��ѯʧ��" << endl;
			//����tips�Ի���
			CTool::tips = "      ���ʧ��";
			CTool::tipsret = 2;
			return 6;
		}
		else
		{
			//cout << "��ѯ�ɹ�" << endl;
			if (mydata->row)
			{
				memset(this->devnameEdit->getContent(), 0, 20);	//����༭��
				memset(this->devtypeEdit->getContent(), 0, 20);
				//cout << "�豸���ظ�" << endl;
				//cout << "���ʧ��" << endl;
				//system("pause");
				// ʧ�� ���治��
				//����tips�Ի���
				CTool::tips = "     �豸���ظ�";
				CTool::tipsret = 3;
				return 6;
			}
			else
			{
				//���ظ�����û��豸��
				memset(mydata->sql, 0, strlen(mydata->sql));	//sql���ʹ��ǰ���
				sprintf(mydata->sql, "insert into devstate_info values(null, '%s', '%s', %d, 0, 20, 1);", CLoginWin::getusername, this->devnameEdit->getContent(), atoi(this->devtypeEdit->getContent()));
				int res = mydata->getRes_exec();
				if (res != 0)
				{
					memset(this->devnameEdit->getContent(), 0, 20);	//����༭��
					memset(this->devtypeEdit->getContent(), 0, 20);
					//cout << "���ʧ��" << endl;
					//����tips�Ի���
					CTool::tips = "      ���ʧ��";
					CTool::tipsret = 2;
					return 6;
				}
				else
				{
					memset(this->devnameEdit->getContent(), 0, 20);	//����༭��
					memset(this->devtypeEdit->getContent(), 0, 20);
					//cout << "��ӳɹ�" << endl;
					//����tips�Ի���
					CTool::tips = "      ��ӳɹ�";
					CTool::tipsret = 2;
					return 6;
				}
				//system("pause");
				// �ɹ� ����ѡ���豸����				
			}
		}

	}
	else if (this->focusIndex == 7)
	{
		memset(this->devnameEdit->getContent(), 0, 20);	//����༭��
		memset(this->devtypeEdit->getContent(), 0, 20);
		//cout << "���ذ�ť��ѡ����" << endl;
		//ѡ�񷵲� ����ѡ���豸����
		return 2;
	}
	else
		return 2;	
}
