#include "CEdit.h"
//构造函数
CEdit::CEdit(int x, int y, int w, int h, const char* content, bool ips, unsigned int minlen, unsigned int maxlen, int inputtype) : CtrlBase(x, y, w, h, content, 2)
{
	this->ips = ips;
	this->minlen = minlen;
	this->maxlen = maxlen;
	this->inputtype = inputtype;
	
}
//析构函数
CEdit::~CEdit()
{
	//cout << "~CButton finish" << endl;
}

//编辑框类显示函数
void  CEdit::show()
{
	//打印控件框
	CTool::paintWindow(this->x, this->y, this->w, this->h);
	//移动光标到控件上
	CTool::gotoxy(this->x + 3, this->y + 1);
	if (strlen(this->content) == 0)
		cout << "长度不得少于" << this->minlen << endl;
	else
		cout << this->content << endl;

}

void CEdit::keylisten(short key)	//键盘输入显示判断函数
{
	/*
	对输入的字符做一系列的判断处理，符和要求的保存和显示：
	this->ips ：显示的格式
	this->iputType ：允许输入的数据类型  1数字
	this->maxLen：最大的字符长度，如果当前已经保存的字符的个数达到了最大长度的，就没法继续保存
	1. 先计算当前已经保存了几个字符   int count = strlen();
	   判断 字符的个数与最大长度是否相等
		  如果相等，就不做处理
		  如果不相等， 说明可以保存，要判断输入的字符是否符合我们的需要
				判断我们要的是字母、数字还是字母、数字的组合
				if  this->iputType == 1   说明我们要的是数字，接下来判断key到底是不是数字
					 if key>='0' && key<='9'
						  保存  ： this->content[count] = key
						  显示：要注意显示的格式
								if  this->ips == 1     _putch(key);
								if  this->ips == 2     _putch('*')

	*/
	int count = (int)strlen(this->content);
	if (key == 8 && count > 0) //退格的操作
	{
		//
		printf("\b \b");//把界面上显示的字符清掉 
		this->content[count - 1] = '\0'; //就保存到数组中对应的字符清掉
		return;
	}
	//cout << this->inputtype << endl;
	//cout << this->ips << endl;
	//cout << this->maxlen << endl;
	//cout << count << endl;
	if (count == 0)
	{
		CTool::gotoxy(this->x + 16, this->y + 1);
		for(int i = 0; i < 13; i++)
		cout << "\b \b";
	}
	if (this->maxlen == count)
	{
		return;
	}
	else
	{
		if (this->inputtype == 1)//数字
		{
			if (key >= '0' && key <= '9')
			{
				this->content[count] = key + '\0';
				if (this->ips == 1)
				{
					_putch(key);
				}
				else if (this->ips == 0)
				{
					_putch('*');
				}
			}
		}
		else if (this->inputtype == 2)//字母
		{
			if (key >= 'A' && key <= 'Z' || key >= 'a' && key <= 'z')
			{
				this->content[count] = key + '\0';
				if (this->ips == 1)
				{
					_putch(key);
				}
				else if (this->ips == 0)
				{
					_putch('*');
				}
			}
		}
		else if (this->inputtype == 3)//字母或者数字
		{
			if (key >= 'A' && key <= 'Z' || key >= 'a' && key <= 'z' || key >= '0' && key <= '9')
			{
				this->content[count] = key + '\0';
				if (this->ips == 1)
				{
					_putch(key);
				}
				else if (this->ips == 0)
				{
					_putch('*');
				}
			}
		}
		else if (this->inputtype == 4)//中英文或数字
		{
			if (key >= 'A' && key <= 'Z' || key >= 'a' && key <= 'z' || key >= '0' && key <= '9')	//英文或数字
			{
				this->content[count] = key + '\0';
				if (this->ips == 1)
				{
					_putch(key);
				}
				else if (this->ips == 0)
				{
					_putch('*');
				}
			}
			//中文
			else if ((unsigned)key >= 0xA1 && (unsigned)key <= 0xFE)
			{
				short key2 = _getch();
				if ((unsigned)key2 >= 0xA1 && (unsigned)key2 <= 0xFE)
				{
					this->content[count++] = key + '\0';
					this->content[count] = key2 + '\0';
					printf("%c%c", key, key2);
				}
			}
	
		}
	}

}