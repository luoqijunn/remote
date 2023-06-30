#include "CseldevWin.h"

//静态数据初始化
int CseldevWin ::getdevID = 0;

CseldevWin::CseldevWin(int x, int y, int w, int h) : CwinBase(x, y, w, h)
{
	//初始化
	this->insertButton = nullptr;
	this->deleteButton = nullptr;
	this->backButton = nullptr;

	//创建CLabel对象
	this->titleLabel = new CLabel(40, 2, "选 择 设 备");
	
	//添加到控件向量容器中
	this->ctrlArry.push_back(this->titleLabel);		//0
	
}

// 先显示大框、再显示所有的控件
void CseldevWin::show()
{
	
	//删除除标题外的标签，对其他标签重新构建
	while(ctrlArry.size() != 1)
	{
		delete ctrlArry.back();
		ctrlArry.erase(ctrlArry.end() - 1);
	}

	//获取唯一的mydata对象
	CmyData* mydata = CmyData::getMydata();
	memset(mydata->sql, 0, strlen(mydata->sql));	//sql语句使用前清空
	sprintf(mydata->sql, "select * from  devstate_info where username = '%s';", CLoginWin::getusername);
	int res = mydata->getRes_exec();
	if (res != 0)
	{
		cout << "查询失败" << endl;
	}
	else
	{
		//cout << "查询成功" << endl;
		for (int i = 0, j = 0; i < mydata->row; i++)
		{
			this->ctrlArry.push_back(new CButton(20 + (i % 4) * 12, 5 + (i / 4) * 3, 6, 3, mydata->qres[7 * i + 9]));		//数据库查询有多少设备，按行显示，每行4个设备对应的按钮，插入到向量容器中
		}
	}
	//创建CButton对象
	this->insertButton = new CButton(28, 14, 6, 3, "添 加");//end-3
	this->deleteButton = new CButton(40, 14, 6, 3, "删 除");//end-2
	this->backButton = new CButton(52, 14, 6, 3, "返 回");	//end-1
	//在向量容器中最后加入
	this->ctrlArry.push_back(this->insertButton);	
	this->ctrlArry.push_back(this->deleteButton);	
	this->ctrlArry.push_back(this->backButton);		

	//画界面框
	CTool::paintWindow(this->x, this->y, this->w, this->h);
	
	//遍历控件向量容器
	for (unsigned int i = 0; i < this->ctrlArry.size(); i++)
	{
		this->ctrlArry.at(i)->show();//this->ctrlArry.at(i) 是 Ctrlbase*类型的，执行的就是父类的show函数
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
	if (this->focusIndex == (this->ctrlArry.size() - 1))	//选择返回按钮
	{
		return 0;
	}
	if (this->focusIndex == (this->ctrlArry.size() - 2))	//选择删除按钮
	{
		return 4;
	}
	if (this->focusIndex == (this->ctrlArry.size() - 3))	//选择添加按钮
	{
		if (12 == (this->ctrlArry.size() - 4))
		{
			//cout << "设备数已达上限" << endl;
			//调用tips对话框
			CTool::tips = " 设备数已达上限";
			CTool::tipsret = 2;
			return 6;
		}
		return 3;
	}
	else
	{
		CmyData* mydata = CmyData::getMydata();
		memset(mydata->sql, 0, strlen(mydata->sql));	//sql语句使用前清空
		sprintf(mydata->sql, "select * from devstate_info where username = '%s';", CLoginWin::getusername);
		int res = mydata->getRes_exec();
		if (res != 0)
		{
			//cout << "查询失败" << endl;
			//system("pause");
			//调用tips对话框
			CTool::tips = "   设备选择失败";
			CTool::tipsret = 2;
			return 6;
		}
		else
		{
			//cout << "查询成功" << endl;
			getdevID = atoi(mydata->qres[(this->focusIndex) * mydata->col]);
			//cout << getdevID << endl;
			//cout << atoi(mydata->qres[((this->focusIndex) * mydata->col) + 3]) << endl;
			//system("pause");
			if (1 == atoi(mydata->qres[((this->focusIndex) * mydata->col) + 3]))	//空调
				return 5;
			else if (2 == atoi(mydata->qres[((this->focusIndex) * mydata->col) + 3]))	//灯
				return 5;
			else
			{
				//调用tips对话框
				CTool::tips = "   设备选择失败";
				CTool::tipsret = 2;
				return 6;
			}
		}	
	}
}