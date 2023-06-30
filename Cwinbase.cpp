#include "CwinBase.h"
#include "CEdit.h"

CwinBase::CwinBase(int x, int y, int w, int h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->ctrlArry.clear();
}

CwinBase::~CwinBase()
{

}

// 先显示大框、再显示所有的控件
void CwinBase::show()
{
	//画界面框
	CTool::paintWindow(this->x, this->y, this->w, this->h);
	//遍历控件向量容器
	for (unsigned int i = 0; i < this->ctrlArry.size(); i++)
	{
		this->ctrlArry.at(i)->show();//this->ctrlArry.at(i) 是 Ctrlbase*类型的，执行的就是父类的show函数
	}
}

//界面运行起来：
/* 目标： 编辑框可以输入、按钮可以点击
*  1.光标要定位到第一个编辑框或者是第一个按钮的位置上
*     先找到第一个编辑框或者是第一个按钮     去哪里找？ 去控件向量容器中去找  判断类型是编辑框或者是按钮的
*     光标定位
*  2. 键盘输入
*        key = CTool::getKey();
*        如果是方向按键：
*                 如果是向下按键： 目标：光标一定要定位到下一个编辑框或者是下一个按钮的位置上
*                        索引i++    判断类型是编辑框或者是按钮的    如果是定位   如果不是呢？ i++   for
*                        要注意 i的取值范围是[0, size()-1]
*				  如果是向上按键： 目标：光标一定要定位到上一个编辑框或者是上一个按钮的位置上
*                        索引i--    判断类型是编辑框或者是按钮的    如果是定位   如果不是呢？ i--   for
*                        要注意 i的取值范围是[0, size()-1]
		如果是回车：
				判断一下当前的控件是不是按钮，如果是按钮，就可以去执行按钮业务
		其他字符：
				判断一下当前的控件是不是编辑框，如果是编辑框，就调用编辑框的监听函数对输入的字符做判断

*/

void CwinBase::winRun()
{
	int i;
	short key;
	for (i = 0; i < (signed)this->ctrlArry.size(); i++)
	{
		if (this->ctrlArry.at(i)->getType() == 2) //编辑框
		{
			CTool::gotoxy(0, 0);	//多次跳转，使窗口界面全部显示
			CTool::gotoxy(this->ctrlArry.at(i)->getX() + 3 + strlen(this->ctrlArry.at(i)->getContent()), this->ctrlArry.at(i)->getY() + 1);
			break;
		}
		else if (this->ctrlArry.at(i)->getType() == 3) //按钮
		{
			CTool::gotoxy(0, 0);	//多次跳转，使窗口界面全部显示
			CTool::gotoxy(this->ctrlArry.at(i)->getX() + 5, this->ctrlArry.at(i)->getY() + 1);
			break;
		}
	}
	while (1)
	{
		key = CTool::getkey();
		//cout << key << endl;
		switch (key)
		{
		case DOWN:
		case TAB:
			i++;
			if (i == (signed)this->ctrlArry.size())
			{
				i = 0; //到达了尾巴的地方，下不去了，让从头开始再来找
			}
			for (; i < (signed)this->ctrlArry.size(); i++)
			{
				if (this->ctrlArry.at(i)->getType() == 2) //编辑框
				{
					CTool::gotoxy(this->ctrlArry.at(i)->getX() + 3 + strlen(this->ctrlArry.at(i)->getContent()), this->ctrlArry.at(i)->getY() + 1);
					break;
				}
				else if (this->ctrlArry.at(i)->getType() == 3) //按钮
				{
					CTool::gotoxy(this->ctrlArry.at(i)->getX() + 5, this->ctrlArry.at(i)->getY() + 1);
					break;
				}
			}

			break;
		case UP:
			i--;
			if (i < 0)
			{
				i = (signed)this->ctrlArry.size() - 1; //到达了头的地方，上不去了，让从尾巴开始再来找
			}
			for (; i >= 0; i--)
			{
				if (this->ctrlArry.at(i)->getType() == 2) //编辑框
				{
					CTool::gotoxy(this->ctrlArry.at(i)->getX() + 3 + strlen(this->ctrlArry.at(i)->getContent()), this->ctrlArry.at(i)->getY() + 1);
					break;
				}
				else if (this->ctrlArry.at(i)->getType() == 3) //按钮
				{
					CTool::gotoxy(this->ctrlArry.at(i)->getX() + 5, this->ctrlArry.at(i)->getY() + 1);
					break;
				}
				if (i == 0)
				{
					i = (signed)this->ctrlArry.size(); //到达了头的地方，上不去了，让从尾巴开始再来找
				}
			}
			break;
		case ENTER://回车
			if (this->ctrlArry.at(i)->getType() == 3) //按钮
			{
				this->focusIndex = i;// 保存此时按回车的这个控件的索引就可以
				return;// 结束winrun函数，接下来去做按钮的业务处理   doAction()

			}
			break;
		default:
			if (this->ctrlArry.at(i)->getType() == 2) //编辑框
			{
				//调用编辑框的keyListen()函数
				this->ctrlArry.at(i)->keylisten(key);
			}
			break;

		}
	}
}

//按钮业务的分发函数
int CwinBase::doAction()
{
	return 0;
}