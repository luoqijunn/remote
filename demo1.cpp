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

int main(void)
{
	//打开并创建数据库
	CmyData* mydata = CmyData::getMydata();
	//memset(mydata->sql, 0, strlen(mydata->sql));	//sql语句使用前清空
	//strcpy(mydata->sql, "create table if not exists user_info(ID integer primary key autoincrement, name varchar(20) not null, pwd varchar(10) default '123456');");
	////创建账户表并向其插入默认管理员账户
	//int res = mydata->noRes_exec(mydata->sql);
	//if (res != 0)
	//{
	//	cout << "建表失败" << endl;
	//}
	//else
	//{
	//	cout << "建表ok" << endl;
	//	//插入数据
	//	memset(mydata->sql, 0, strlen(mydata->sql));	//sql语句使用前清空
	//	strcpy(mydata->sql, "insert into user_info values(1001, 'admin', 'admin');");
	//	res = mydata->noRes_exec(mydata->sql);
	//	if (res != 0)
	//	{
	//		cout << "插入初始用户失败" << endl;
	//	}
	//	else
	//	{
	//		cout << "插入初始用户成功" << endl;
	//	}
	//};

	//建设备表
	//create table if not exists devstate_info(DID integer primary key autoincrement, username varchar(20) not null, devname varchar(20) not null, devtype int, opengate int, temper int, mode int);
	//insert into devstate_info values(null, 'admin', 'AC0', 1, 0, 20, 1);
	
	
	vector<CwinBase*> winArry;
	//创建登录类的对象
	CRegWin* reg = new CRegWin(13, 1, 33, 18);				// 0
	CLoginWin* login = new CLoginWin(13, 1, 33, 18);		// 1
	CseldevWin* seldev = new CseldevWin(13, 1, 33, 18);		// 2
	CinsdevWin* insdev = new CinsdevWin(13, 1, 33, 18);		// 3
	CrmdevWin* rmdev = new CrmdevWin(13, 1, 33, 18);		// 4
	CACWin* AC = new CACWin(13, 1, 19, 37);					// 5
	ChintWin* hint = new ChintWin(13, 5, 20, 9);			// 6

	winArry.push_back(login);	// 0
	winArry.push_back(reg);		// 1
	winArry.push_back(seldev);	// 2
	winArry.push_back(insdev);	// 3
	winArry.push_back(rmdev);	// 4
	winArry.push_back(AC);		// 5
	winArry.push_back(hint);	// 6


	short winres = 0;	//当前窗口是登录为0，注册为1
	while (1) 
	{
		//显示前清屏
		system("cls");
		//显示
		winArry.at(winres)->show();
		//运行
		winArry.at(winres)->winRun();
		//按钮触发事件
		winres = winArry.at(winres)->doAction();
		if (-1 == winres)	//退出按钮
		{
			break;
		}
	}

	return 0;
}