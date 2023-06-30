//#include "CLoginWin.h"
#include "CRegWin.h"

CRegWin::CRegWin(int x, int y, int w, int h) : CwinBase(x, y, w, h)
{
	//创建CLabel对象
	this->titleLabel = new CLabel(40, 2, "注 册 系 统");
	this->userLabel = new CLabel(25, 5, "账号：");
	this->pwdLabel = new CLabel(25, 8, "密码：");
	this->repwdLabel = new CLabel(25, 11, "确认密码：");
	//创建CEdit对象
	this->userEdit = new CEdit(35, 4, 15, 3, "", 1);
	this->pwdEdit = new CEdit(35, 7, 15, 3, "", 0);
	this->repwdEdit = new CEdit(35, 10, 15, 3, "", 0);
	//创建CButton对象
	this->regButton = new CButton(33, 14, 6, 3, "注 册");
	this->backButton = new CButton(48, 14, 6, 3, "返 回");

	//this->frame = new CButton(13, 1, 33, 18, "");
	
	//添加到控件向量容器中
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
		//cout << "注册按钮被选择了" << endl;
		//注册业务
		if (strlen(this->userEdit->getContent()) < this->userEdit->getminlen() || strlen(this->pwdEdit->getContent()) < this->userEdit->getminlen())
		{
			memset(this->pwdEdit->getContent(), 0, 20);	//清除密码编辑框
			memset(this->repwdEdit->getContent(), 0, 20);
			//cout << "用户名的长度不能少于" << this->userEdit->getminlen() << endl;
			//cout << "密码的长度不能少于" << this->pwdEdit->getminlen() << endl;
			//注册失败  return 1;  继续显示注册界面
			//调用tips对话框
			CTool::tips = "用户名或密码的长度过短";
			CTool::tipsret = 1;
			return 6;
		}
		if (strcmp(this->pwdEdit->getContent(), this->repwdEdit->getContent()))
		{
			memset(this->pwdEdit->getContent(), 0, 20);	//清除密码编辑框
			memset(this->repwdEdit->getContent(), 0, 20);
			//cout << "密码与确认密码不一致" << endl;
			//注册失败  return 1;  继续显示注册界面
			//调用tips对话框
			CTool::tips = "密码与确认密码不一致";
			CTool::tipsret = 1;
			return 6;
		}
		//获取唯一的mydata对象
		CmyData* mydata = CmyData::getMydata();
		memset(mydata->sql, 0, strlen(mydata->sql));	//sql语句使用前清空
		sprintf(mydata->sql, "select * from user_info where name = '%s';", this->userEdit->getContent());
		int res = mydata->getRes_exec();
		if (res != 0)
		{
			memset(this->pwdEdit->getContent(), 0, 20);	//清除密码编辑框
			memset(this->repwdEdit->getContent(), 0, 20);
			//cout << "查询失败" << endl;
			//调用tips对话框
			CTool::tips = "      注册失败";
			CTool::tipsret = 0;
			return 6;
		}
		else
		{
			//cout << "查询成功" << endl;
			if (mydata->row)
			{
				memset(this->pwdEdit->getContent(), 0, 20);	//清除密码编辑框
				memset(this->repwdEdit->getContent(), 0, 20);
				//cout << "该用户已存在" << endl;
				//调用tips对话框
				CTool::tips = "   该用户已存在";
				CTool::tipsret = 1;
				return 6;
			}
			else
			//插入数据
			{
				memset(mydata->sql, 0, strlen(mydata->sql));	//sql语句使用前清空
				sprintf(mydata->sql, "insert into user_info values(null, '%s', '%s');", this->userEdit->getContent(), this->pwdEdit->getContent());
				res = mydata->noRes_exec(mydata->sql);
				if (res != 0)
				{
					memset(this->pwdEdit->getContent(), 0, 20);	//清除密码编辑框
					memset(this->repwdEdit->getContent(), 0, 20);
					//cout << "用户注册失败" << endl;
					//调用tips对话框
					CTool::tips = "   用户注册失败";
					CTool::tipsret = 0;
					return 6;
				}
				else
				{
					memset(this->pwdEdit->getContent(), 0, 20);	//清除密码编辑框
					memset(this->repwdEdit->getContent(), 0, 20);
					//cout << "用户注册成功" << endl;
					//调用tips对话框
					CTool::tips = "   用户注册成功";
					CTool::tipsret = 0;
					return 6;
				}
			}
		}
		//system("pause");
		//注册成功  return 0;  显示登录界面
	}
	else if (this->focusIndex == 8) //选择返回按钮， 切换到登录界面
	{
		memset(this->pwdEdit->getContent(), 0, 20);	//清除密码编辑框
		memset(this->repwdEdit->getContent(), 0, 20);
		//选择登录  return 1;  进入登录界面
		//cout << "登录按钮被选择" << endl;
		return 0;
	}
	else
		return -1;
}