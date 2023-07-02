#include "CLabel.h"
#include "CButton.h"
#include "CEdit.h"
#include "CRegWin.h"
#include "CLoginWin.h"
#include "CseldevWin.h"
#include "CinsdevWin.h"
#include "CrmdevWin.h"
#include "CACWin.h"
#include "ChintWin.h"
#include "ClampWin.h"
#include "CwindowWin.h"
#include "CcurtainWin.h"
#include "CmonitorWin.h"
#include "ChotwaterWin.h"

int main(void)
{
	//�򿪲��������ݿ�
	CmyData* mydata = CmyData::getMydata();
	//memset(mydata->sql, 0, strlen(mydata->sql));	//sql���ʹ��ǰ���
	//strcpy(mydata->sql, "create table if not exists user_info(ID integer primary key autoincrement, name varchar(20) not null, pwd varchar(10) default '123456');");
	////�����˻����������Ĭ�Ϲ���Ա�˻�
	//int res = mydata->noRes_exec(mydata->sql);
	//if (res != 0)
	//{
	//	cout << "����ʧ��" << endl;
	//}
	//else
	//{
	//	cout << "����ok" << endl;
	//	//��������
	//	memset(mydata->sql, 0, strlen(mydata->sql));	//sql���ʹ��ǰ���
	//	strcpy(mydata->sql, "insert into user_info values(1001, 'admin', 'admin');");
	//	res = mydata->noRes_exec(mydata->sql);
	//	if (res != 0)
	//	{
	//		cout << "�����ʼ�û�ʧ��" << endl;
	//	}
	//	else
	//	{
	//		cout << "�����ʼ�û��ɹ�" << endl;
	//	}
	//};

	//���豸��
	//create table if not exists devstate_info(DID integer primary key autoincrement, username varchar(20) not null, devname varchar(20) not null, devtype int, opengate int, temper int, mode int);
	//insert into devstate_info values(null, 'admin', 'AC0', 1, 0, 20, 1);
	
	
	vector<CwinBase*> winArry;
	//������¼��Ķ���
	CRegWin* reg = new CRegWin(13, 1, 33, 18);				// 0 ע��
	CLoginWin* login = new CLoginWin(13, 1, 33, 18);		// 1 ��¼
	CseldevWin* seldev = new CseldevWin(13, 1, 33, 18);		// 2 ѡ��
	CinsdevWin* insdev = new CinsdevWin(7, 1, 45, 18);		// 3 ���
	CrmdevWin* rmdev = new CrmdevWin(13, 1, 33, 18);		// 4 ɾ��
	CACWin* AC = new CACWin(13, 1, 19, 37);					// 5 �յ�
	ChintWin* hint = new ChintWin(13, 5, 20, 9);			// 6 ��ʾ����
	ClampWin* lamp = new ClampWin(13, 1, 19, 37);			// 7 �ƹ���
	CwindowWin* window = new CwindowWin(13, 1, 19, 37);		// 8 ����
	CcurtainWin* curtain = new CcurtainWin(13, 1, 19, 37);	// 9 ����
	CmonitorWin* monitor = new CmonitorWin(13, 1, 19, 37);	//10 ���
	ChotwaterWin* hotwater = new ChotwaterWin(13, 1, 19, 37); //11 ��ˮ��

	winArry.push_back(login);	// 0
	winArry.push_back(reg);		// 1
	winArry.push_back(seldev);	// 2
	winArry.push_back(insdev);	// 3
	winArry.push_back(rmdev);	// 4
	winArry.push_back(AC);		// 5
	winArry.push_back(hint);	// 6
	winArry.push_back(lamp);    // 7
	winArry.push_back(window);  // 8
	winArry.push_back(curtain); // 9
	winArry.push_back(monitor); // 10
	winArry.push_back(hotwater); // 11


	short winres = 0;	//��ǰ�����ǵ�¼Ϊ0��ע��Ϊ1
	while (1) 
	{
		//��ʾǰ����
		system("cls");
		//��ʾ
		winArry.at(winres)->show();
		//����
		winArry.at(winres)->winRun();
		//��ť�����¼�
		winres = winArry.at(winres)->doAction();
		if (-1 == winres)	//�˳���ť
		{
			break;
		}
	}

	return 0;
}