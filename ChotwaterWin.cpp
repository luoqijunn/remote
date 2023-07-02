#include "ChotwaterWin.h"
#include "CseldevWin.h"

ChotwaterWin::ChotwaterWin(int x, int y, int w, int h) :CwinBase(x, y, w, h)
{
	//创建CLabel对象
	this->cacLabel = new CLabel(25, 2, "热水器控制器");
	this->openGateLabel = new CLabel(16, 5, "热水器开启：");
	this->temperLabel = new CLabel(16, 9, "热水器温度：");
	this->runModeLabel = new CLabel(16, 13, "热水器状态：");

	/*this->openGateShowLabel = new CLabel(26, 5, "1");
	this->temperShowLabel = new CLabel(26, 9, "2");
	this->runModeShowLabel = new CLabel(26, 13, "3");*/

	//添加按钮
	this->openGateButton = new CButton(14, 17, 18, 4, "        热水器开/关");
	this->temperAddButton = new CButton(15, 22, 8, 4, "   +");
	this->temperMinButton = new CButton(33, 22, 8, 4, "   -");
	this->runModeButton = new CButton(14, 27, 18, 4, "         热水器状态");
	this->backButton = new CButton(14, 32, 18, 4, "            返 回");


	//添加到控件向量容器中
	this->ctrlArry.push_back(this->cacLabel);		//0
	this->ctrlArry.push_back(this->openGateLabel);	//1
	this->ctrlArry.push_back(this->temperLabel);	//2
	this->ctrlArry.push_back(this->runModeLabel);	//3
	this->ctrlArry.push_back(this->openGateButton);	//4
	this->ctrlArry.push_back(this->temperAddButton);//5
	this->ctrlArry.push_back(this->temperMinButton);//6
	this->ctrlArry.push_back(this->runModeButton);	//7
	this->ctrlArry.push_back(this->backButton);		//8
}


ChotwaterWin::~ChotwaterWin()
{
	delete this->cacLabel;
	delete this->openGateLabel;
	delete this->temperLabel;
	delete this->runModeLabel;
	delete this->openGateButton;
	delete this->temperAddButton;
	delete this->temperMinButton;
	delete this->runModeButton;

}

void ChotwaterWin::show()
{
	CmyData* mydata = CmyData::getMydata();
	memset(mydata->sql, 0, strlen(mydata->sql));	//sql语句使用前清空
	sprintf(mydata->sql, "select * from devstate_info where DID = %d;", CseldevWin::getdevID);
	int res = mydata->getRes_exec();
	if (res != 0)
	{
		cout << "查询失败" << endl;
	}
	else
	{
		CTool::gotoxy(28, 5);	//开关
		if (strcmp(mydata->qres[4 + 7], "0"))
			cout << "关" << endl;
		else
			cout << "开" << endl;
		CTool::gotoxy(28, 9);	//温度
		cout << mydata->qres[5 + 7] << "℃" << endl;
		CTool::gotoxy(28, 13);	//模式
		if (!strcmp(mydata->qres[6 + 7], "0"))		//0. 加热
			cout << "加热模式" << endl;
		else if (!strcmp(mydata->qres[6 + 7], "1"))	//1. 制冷
			cout << "保温模式" << endl;

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


int ChotwaterWin::doAction()
{
	//数据库操作准备
	CmyData* mydata = CmyData::getMydata();
	int res = 0;
	if (this->focusIndex == 4)	//开关
	{
		memset(mydata->sql, 0, strlen(mydata->sql));	//sql语句使用前清空
		sprintf(mydata->sql, "update devstate_info set opengate = %d where DID = %d;", (atoi(mydata->qres[4 + 7]) + 1) % 2, CseldevWin::getdevID);
		res = mydata->noRes_exec(mydata->sql);
		if (res != 0)
		{
			//cout << "操作开关失败" << endl;
			return 11;
		}
		else
		{
			//cout << "操作开关成功" << endl;
			return 11;
		}
		//system("pause");
	}
	else if (this->focusIndex == 5)	//温度加
	{
		memset(mydata->sql, 0, strlen(mydata->sql));	//sql语句使用前清空
		sprintf(mydata->sql, "update devstate_info set temper = %d where DID = %d;", atoi(mydata->qres[5 + 7]) + 1, CseldevWin::getdevID);
		res = mydata->noRes_exec(mydata->sql);
		if (res != 0)
		{
			//cout << "操作温度加失败" << endl;
			return 11;
		}
		else
		{
			//cout << "操作温度加成功" << endl;
			return 11;
		}
		//system("pause");
	}
	else if (this->focusIndex == 6)	//温度减
	{
		memset(mydata->sql, 0, strlen(mydata->sql));	//sql语句使用前清空
		sprintf(mydata->sql, "update devstate_info set temper = %d where DID = %d;", atoi(mydata->qres[5 + 7]) - 1, CseldevWin::getdevID);
		res = mydata->noRes_exec(mydata->sql);
		if (res != 0)
		{
			//cout << "操作温度减失败" << endl;
			return 11;
		}
		else
		{
			//cout << "操作温度减成功" << endl;
			return 11;
		}
		//system("pause");
	}
	else if (this->focusIndex == 7)	//切换模式
	{
		int tempmode = atoi(mydata->qres[6 + 7]);
		tempmode = (tempmode + 1) % 2;

		memset(mydata->sql, 0, strlen(mydata->sql));	//sql语句使用前清空
		sprintf(mydata->sql, "update devstate_info set mode = %d where DID = %d;", tempmode, CseldevWin::getdevID);
		//cout << mydata->sql << endl;
		//system("pause");
		res = mydata->noRes_exec(mydata->sql);
		if (res != 0)
		{
			//cout << "操作切换模式失败" << endl;
			//system("pause");
			return 11;
		}
		else
		{
			//cout << "操作切换模式成功" << endl;
			return 11;
		}
		//system("pause");
	}
	else if (this->focusIndex == 8)	//返回
	{
		return 2;
	}
	return 0;
}
