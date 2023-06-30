#include "CLoginWin.h"

char CLoginWin::getusername[20] = "\0";

CLoginWin::CLoginWin(int x, int y, int w, int h) :CwinBase(x, y, w, h)
{
	//创建CLabel对象
	this->titleLabel = new CLabel(39, 2, "登 录 系 统");
	this->userLabel = new CLabel(25, 5, "账号：");
	this->pwdLabel = new CLabel(25, 8, "密码：");
	//创建CEdit对象
	this->userEdit = new CEdit(35, 4, 15, 3, "", 1);
	this->pwdEdit = new CEdit(35, 7, 15, 3, "", 0);
	//创建CButton对象
	this->loginButton = new CButton(28, 14, 6, 3, "登 录");
	this->regButton = new CButton(40, 14, 6, 3, "注 册");
	this->exitButton = new CButton(52, 14, 6, 3, "退 出");
	
	//this->frame = new CButton(13, 1, 33, 18, "");
	
	//添加到控件向量容器中
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
	if (this->focusIndex == 5) //如果你选择是登录， 切换到登录界面
	{
		if (!strlen(this->userEdit->getContent()) || !strlen(this->pwdEdit->getContent()))
		{
			memset(this->pwdEdit->getContent(), 0, 20);	//清除密码编辑框
			//cout << "用户名和密码不能为空" << endl;
			//调用tips对话框
			CTool::tips = "用户名和密码不能为空";
			CTool::tipsret = 0;
			return 6;
		}
		//cout << "登录按钮被选择" << endl;
		//登录验证
		CmyData* mydata = CmyData::getMydata();
		memset(mydata->sql, 0, strlen(mydata->sql));	//sql语句使用前清空
		sprintf(mydata->sql, "select * from user_info where name = '%s';", this->userEdit->getContent());
		int res = mydata->getRes_exec();
		if (res != 0)
		{
			memset(this->pwdEdit->getContent(), 0, 20);	//清除密码编辑框
			//cout << "查询失败" << endl;
			//system("pause");
			//调用tips对话框
			CTool::tips = "      登录失败";
			CTool::tipsret = 0;
			return 6;
		}
		else
		{

			//cout << "查询成功" << endl;
			if (!(mydata->row))
			{
				memset(this->pwdEdit->getContent(), 0, 20);	//清除密码编辑框
				//cout << "该用户不存在" << endl;
				//system("pause");
				//调用tips对话框
				CTool::tips = "用户名或密码错误";
				CTool::tipsret = 0;
				return 6;
			}
			else
			{
				if (strcmp(this->pwdEdit->getContent(), mydata->qres[2+3]))
				{
					memset(this->pwdEdit->getContent(), 0, 20);	//清除密码编辑框
					//cout << "用户名或密码错误" << endl;
					//system("pause");
					//失败 显示登录界面 return 0;
					//调用tips对话框
					CTool::tips = "用户名或密码错误";
					CTool::tipsret = 0;
					return 6;
				}
				else
				{
					//cout << "登录成功" << endl;
					memset(getusername, 0, sizeof(getusername));
					strcpy(getusername, this->userEdit->getContent());
					memset(this->pwdEdit->getContent(), 0, 20);	//清除密码编辑框
					//system("pause");
					// 成功 进入一个新的界面  return -2;
					//调用tips对话框
					CTool::tips = "      登录成功";
					CTool::tipsret = 2;
					return 6;
				}
			}
		}
	}
	else if (this->focusIndex == 6)
	{
		//cout << "注册按钮被选择了" << endl;
		//选择注册 进入注册界面
		memset(this->pwdEdit->getContent(), 0, 20);	//清除密码编辑框
		return 1;
	}
	else if (this->focusIndex == 7)
	{
		//选择退出 退出程序
		//cout << "退出按钮被选择了" << endl;
		memset(this->pwdEdit->getContent(), 0, 20);	//清除密码编辑框
		return -1;
	}
	else
		return -1;
}