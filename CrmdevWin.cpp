#include "CrmdevWin.h"

CrmdevWin::CrmdevWin(int x, int y, int w, int h) : CwinBase(x, y, w, h)
{
	//创建CLabel对象
	this->titleLabel = new CLabel(39, 2, "删 除 设 备");
	this->devnameLabel = new CLabel(25, 5, "设备名：");
	//创建CEdit对象
	this->devnameEdit = new CEdit(35, 4, 15, 3, "", 1, 2, 6, 4);
	//创建CButton对象
	this->confirmButton = new CButton(28, 14, 6, 3, "确 认");
	this->exitButton = new CButton(52, 14, 6, 3, "返 回");

	//添加到控件向量容器中
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
		//删除设备
		//获取唯一的mydata对象
		CmyData* mydata = CmyData::getMydata();
		memset(mydata->sql, 0, strlen(mydata->sql));	//sql语句使用前清空
		sprintf(mydata->sql, "select * from devstate_info where username = '%s' and devname = '%s';", CLoginWin::getusername, this->devnameEdit->getContent());
		int res = mydata->getRes_exec();
		if (res != 0)
		{
			memset(this->devnameEdit->getContent(), 0, 20);	//清除编辑框
			//cout << "查询失败" << endl;.
			//调用tips对话框
			CTool::tips = "      删除失败";
			CTool::tipsret = 2;
			return 6;
		}
		else
		{
			//cout << "查询成功" << endl;
			if (mydata->row == 0)
			{
				memset(this->devnameEdit->getContent(), 0, 20);	//清除编辑框
				//cout << "无此设备" << endl;
				//调用tips对话框
				CTool::tips = "      无此设备";
				CTool::tipsret = 2;
				return 6;
			}
			else
			{
				memset(mydata->sql, 0, strlen(mydata->sql));	//sql语句使用前清空
				sprintf(mydata->sql, "delete from devstate_info where username = '%s' and devname = '%s';", CLoginWin::getusername, this->devnameEdit->getContent());
				res = mydata->noRes_exec(mydata->sql);
				if (res != 0)
				{
					memset(this->devnameEdit->getContent(), 0, 20);	//清除编辑框
					//cout << "删除失败" << endl;
					//调用tips对话框
					CTool::tips = "      删除失败";
					CTool::tipsret = 2;
					return 6;
				}
				else
				{
					memset(this->devnameEdit->getContent(), 0, 20);	//清除编辑框
					//cout << "删除成功" << endl;
					//调用tips对话框
					CTool::tips = "      删除成功";
					CTool::tipsret = 2;
					return 6;
				}
			}
		}
		
	}
	else if (this->focusIndex == 4)
	{
		//cout << "返回按钮被选择了" << endl;
		//选择返册 进入选择设备界面
		memset(this->devnameEdit->getContent(), 0, 20);	//清除编辑框
		return 2;
	}
	else
		return 2;
}

