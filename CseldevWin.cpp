#include "CseldevWin.h"

//��̬���ݳ�ʼ��
int CseldevWin ::getdevID = 0;

CseldevWin::CseldevWin(int x, int y, int w, int h) : CwinBase(x, y, w, h)
{
	//��ʼ��
	this->insertButton = nullptr;
	this->deleteButton = nullptr;
	this->backButton = nullptr;

	//����CLabel����
	this->titleLabel = new CLabel(40, 2, "ѡ �� �� ��");
	
	//��ӵ��ؼ�����������
	this->ctrlArry.push_back(this->titleLabel);		//0
	
}

// ����ʾ�������ʾ���еĿؼ�
void CseldevWin::show()
{
	
	//ɾ����������ı�ǩ����������ǩ���¹���
	while(ctrlArry.size() != 1)
	{
		delete ctrlArry.back();
		ctrlArry.erase(ctrlArry.end() - 1);
	}

	//��ȡΨһ��mydata����
	CmyData* mydata = CmyData::getMydata();
	memset(mydata->sql, 0, strlen(mydata->sql));	//sql���ʹ��ǰ���
	sprintf(mydata->sql, "select * from  devstate_info where username = '%s';", CLoginWin::getusername);
	int res = mydata->getRes_exec();
	if (res != 0)
	{
		cout << "��ѯʧ��" << endl;
	}
	else
	{
		//cout << "��ѯ�ɹ�" << endl;
		for (int i = 0, j = 0; i < mydata->row; i++)
		{
			this->ctrlArry.push_back(new CButton(20 + (i % 4) * 12, 5 + (i / 4) * 3, 6, 3, mydata->qres[7 * i + 9]));		//���ݿ��ѯ�ж����豸��������ʾ��ÿ��4���豸��Ӧ�İ�ť�����뵽����������
		}
	}
	//����CButton����
	this->insertButton = new CButton(28, 14, 6, 3, "�� ��");//end-3
	this->deleteButton = new CButton(40, 14, 6, 3, "ɾ ��");//end-2
	this->backButton = new CButton(52, 14, 6, 3, "�� ��");	//end-1
	//������������������
	this->ctrlArry.push_back(this->insertButton);	
	this->ctrlArry.push_back(this->deleteButton);	
	this->ctrlArry.push_back(this->backButton);		

	//�������
	CTool::paintWindow(this->x, this->y, this->w, this->h);
	
	//�����ؼ���������
	for (unsigned int i = 0; i < this->ctrlArry.size(); i++)
	{
		this->ctrlArry.at(i)->show();//this->ctrlArry.at(i) �� Ctrlbase*���͵ģ�ִ�еľ��Ǹ����show����
	}
}

CseldevWin::~CseldevWin()
{
	delete this->titleLabel;
	delete this->insertButton;
	delete this->deleteButton;
	delete this->backButton;
}
int CseldevWin::doAction()
{
	/*cout << this->focusIndex << endl;
	cout << this->ctrlArry.size() << endl;
	system("pause");*/
	if (this->focusIndex == (this->ctrlArry.size() - 1))	//ѡ�񷵻ذ�ť
	{
		return 0;
	}
	if (this->focusIndex == (this->ctrlArry.size() - 2))	//ѡ��ɾ����ť
	{
		return 4;
	}
	if (this->focusIndex == (this->ctrlArry.size() - 3))	//ѡ����Ӱ�ť
	{
		if (12 == (this->ctrlArry.size() - 4))
		{
			//cout << "�豸���Ѵ�����" << endl;
			//����tips�Ի���
			CTool::tips = " �豸���Ѵ�����";
			CTool::tipsret = 2;
			return 6;
		}
		return 3;
	}
	else
	{
		CmyData* mydata = CmyData::getMydata();
		memset(mydata->sql, 0, strlen(mydata->sql));	//sql���ʹ��ǰ���
		sprintf(mydata->sql, "select * from devstate_info where username = '%s';", CLoginWin::getusername);
		int res = mydata->getRes_exec();
		if (res != 0)
		{
			//cout << "��ѯʧ��" << endl;
			//system("pause");
			//����tips�Ի���
			CTool::tips = "   �豸ѡ��ʧ��";
			CTool::tipsret = 2;
			return 6;
		}
		else
		{
			//cout << "��ѯ�ɹ�" << endl;
			getdevID = atoi(mydata->qres[(this->focusIndex) * mydata->col]);
			//cout << getdevID << endl;
			//cout << atoi(mydata->qres[((this->focusIndex) * mydata->col) + 3]) << endl;
			//system("pause");
			if (1 == atoi(mydata->qres[((this->focusIndex) * mydata->col) + 3]))	//�յ�
				return 5;
			else if (2 == atoi(mydata->qres[((this->focusIndex) * mydata->col) + 3]))	//��
				return 5;
			else
			{
				//����tips�Ի���
				CTool::tips = "   �豸ѡ��ʧ��";
				CTool::tipsret = 2;
				return 6;
			}
		}	
	}
}