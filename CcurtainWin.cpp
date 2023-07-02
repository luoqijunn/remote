#include "CcurtainWin.h"

#include "CseldevWin.h"

CcurtainWin::CcurtainWin(int x, int y, int w, int h) :CwinBase(x, y, w, h)
{
	//创建CLabel对象
	this->cacLabel = new CLabel(25, 2, " 窗帘控制器");
	this->openGateLabel = new CLabel(16, 5, "窗帘开启：");



	//添加按钮
	this->openGateButton = new CButton(14, 17, 18, 4, "          窗帘开/关");

	this->backButton = new CButton(14, 32, 18, 4, "            返 回");


	//添加到控件向量容器中
	this->ctrlArry.push_back(this->cacLabel);		//0
	this->ctrlArry.push_back(this->openGateLabel);	//1
	this->ctrlArry.push_back(this->openGateButton);	//2

	this->ctrlArry.push_back(this->backButton);		//3
}


CcurtainWin::~CcurtainWin()
{
	delete this->cacLabel;
	delete this->openGateLabel;
	delete this->openGateButton;

}

void CcurtainWin::show()
{
	CmyData* mydata = CmyData::getMydata();
	memset(mydata->sql, 0, strlen(mydata->sql));	//sql语句使用前清空
	sprintf(mydata->sql, "select * from devstate_info where DID = %d;", CseldevWin::getdevID);
	int res = mydata->getRes_exec();
	if (res != 0)
	{
		//cout << "查询失败" << endl;
	}
	else
	{
		CTool::gotoxy(26, 5);	//开关
		if (strcmp(mydata->qres[4 + 7], "0"))
			cout << "关" << endl;
		else
			cout << "开" << endl;
	}
	//画界面框
	CTool::paintWindow(this->x, this->y, this->w, this->h);
	//画显示框
	CTool::paintWindow(this->x + 1, this->y + 3, this->w - 1, this->h - 25);
	//遍历控件向量容器
	for (unsigned int i = 0; i < this->ctrlArry.size(); i++)
	{
		this->ctrlArry.at(i)->show();
	}
}


int CcurtainWin::doAction()
{
	//数据库操作准备
	CmyData* mydata = CmyData::getMydata();
	int res = 0;
	if (this->focusIndex == 2)	//开关
	{
		memset(mydata->sql, 0, strlen(mydata->sql));	//sql语句使用前清空
		sprintf(mydata->sql, "update devstate_info set opengate = %d where DID = %d;", (atoi(mydata->qres[4 + 7]) + 1) % 2, CseldevWin::getdevID);
		res = mydata->noRes_exec(mydata->sql);
		if (res != 0)
		{
			//cout << "操作开关失败" << endl;
			return 9;
		}
		else
		{
			//cout << "操作开关成功" << endl;
			return 9;
		}
		//system("pause");
	}

	else if (this->focusIndex == 3)	//返回
	{
		return 2;
	}
	return 0;
}

