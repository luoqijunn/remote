#include "ChintWin.h"

ChintWin::ChintWin(int x, int y, int w, int h) : CwinBase(x, y, w, h)
{
	//创建CButton对象
	this->confmButton = new CButton(27, 10, 6, 3, "确 认");//end-3

	//添加到控件向量容器中
	this->ctrlArry.push_back(this->confmButton);		//0
}

ChintWin::~ChintWin()
{
	delete this->confmButton;
}

// 先显示大框、再显示所有的控件
void ChintWin::show()
{
	CTool::gotoxy(22, 7);
	cout << CTool::tips << endl;
	//画界面框
	CTool::paintWindow(this->x, this->y, this->w, this->h);
	//遍历控件向量容器
	for (unsigned int i = 0; i < this->ctrlArry.size(); i++)
	{
		this->ctrlArry.at(i)->show();//this->ctrlArry.at(i) 是 Ctrlbase*类型的，执行的就是父类的show函数
	}
}

int ChintWin::doAction()
{
	return CTool::tipsret;
}