#include "CinsdevWin.h"

CinsdevWin::CinsdevWin(int x, int y, int w, int h) : CwinBase(x, y, w, h)
{
	//创建CLabel对象
	this->titleLabel = new CLabel(43, 2, "添 加 设 备");
	this->devnameLabel = new CLabel(29, 5, "设备名：");
	this->devtypeLabel = new CLabel(29, 8, "设备类型：");
	this->typetipLabel = new CLabel(10, 10, "tips：设备类型只可输入数字。1为空调，2为灯光，3为窗户，4为窗帘，5为监控，6为热水器");
	//创建CEdit对象
	this->devnameEdit = new CEdit(39, 4, 15, 3, "", 1, 2, 6, 4);
	this->devtypeEdit = new CEdit(39, 7, 15, 3, "", 0, 1, 2, 1);
	//创建CButton对象
	this->confirmButton = new CButton(28, 14, 6, 3, "确 认");
	this->exitButton = new CButton(59, 14, 6, 3, "返 回");

	//添加到控件向量容器中
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
		//插入前查询设备名是否重复
		//获取唯一的mydata对象
		CmyData* mydata = CmyData::getMydata();
		memset(mydata->sql, 0, strlen(mydata->sql));	//sql语句使用前清空
		sprintf(mydata->sql, "select * from devstate_info where username = '%s' and devname = '%s';", CLoginWin::getusername, this->devnameEdit->getContent());
		int res = mydata->getRes_exec();
		if (res != 0)
		{
			memset(this->devnameEdit->getContent(), 0, 20);	//清除编辑框
			memset(this->devtypeEdit->getContent(), 0, 20);
			//cout << "查询失败" << endl;
			//调用tips对话框
			CTool::tips = "      添加失败";
			CTool::tipsret = 2;
			return 6;
		}
		else
		{
			//cout << "查询成功" << endl;
			if (mydata->row)
			{
				memset(this->devnameEdit->getContent(), 0, 20);	//清除编辑框
				memset(this->devtypeEdit->getContent(), 0, 20);
				//cout << "设备名重复" << endl;
				//cout << "添加失败" << endl;
				//system("pause");
				// 失败 界面不变
				//调用tips对话框
				CTool::tips = "     设备名重复";
				CTool::tipsret = 3;
				return 6;
			}
			else
			{
				//无重复添加用户设备表
				memset(mydata->sql, 0, strlen(mydata->sql));	//sql语句使用前清空
				sprintf(mydata->sql, "insert into devstate_info values(null, '%s', '%s', %d, 0, 20, 1);", CLoginWin::getusername, this->devnameEdit->getContent(), atoi(this->devtypeEdit->getContent()));
				int res = mydata->getRes_exec();
				if (res != 0)
				{
					memset(this->devnameEdit->getContent(), 0, 20);	//清除编辑框
					memset(this->devtypeEdit->getContent(), 0, 20);
					//cout << "添加失败" << endl;
					//调用tips对话框
					CTool::tips = "      添加失败";
					CTool::tipsret = 2;
					return 6;
				}
				else
				{
					memset(this->devnameEdit->getContent(), 0, 20);	//清除编辑框
					memset(this->devtypeEdit->getContent(), 0, 20);
					//cout << "添加成功" << endl;
					//调用tips对话框
					CTool::tips = "      添加成功";
					CTool::tipsret = 2;
					return 6;
				}
				//system("pause");
				// 成功 进入选择设备界面				
			}
		}

	}
	else if (this->focusIndex == 7)
	{
		memset(this->devnameEdit->getContent(), 0, 20);	//清除编辑框
		memset(this->devtypeEdit->getContent(), 0, 20);
		//cout << "返回按钮被选择了" << endl;
		//选择返册 进入选择设备界面
		return 2;
	}
	else
		return 2;	
}
