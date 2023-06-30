#include "CTool.h"

string CTool::tips = "\0";
int CTool::tipsret = 0;

//要显示内容的坐标值
void CTool::gotoxy(int x, int y)
{
	COORD p; //定义结构体变量p
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//获得当前函数句柄
	p.X = x;
	p.Y = y; //将光标的目标移动到位置传递给结构体
	SetConsoleCursorPosition(handle, p);
}
//打印窗口
void CTool::paintWindow(int startX, int startY, int width, int height)
{
	int i = 0;//循环变量i初始化
	//打印顶部
	//光标定位 找规律 ┗ ┛ ┏ ┓ ┃ ━
	//顶部 y行不变 x 列在变 (x到x+width)
	gotoxy(startX, startY); //光标起始
	printf("┏"); //光标起始定位先打印左上角
	for (i = 0; i < width * 2 - 4; i++) //控制循环次数width-2次 打印顶部
	{
		printf("━");
	}
	printf("┓");
	//左边 x列不变 y行在变 (y到y+height) 打印左竖线
	for (i = 1; i <= height - 2; i++) //竖线这边i初始值为1（第一行打过了） <=
	{
		gotoxy(startX, startY + i);//打印左竖线时光标一直移动 Y行在变
		printf("┃"); //打印左竖线
	}
	//右边 x不变 =startx+width-1(x列) y在变 y 到 y+height(y行)右竖线
	for (i = 1; i <= height - 2; i++)//竖线这边i初始值为1（第一行打过了） <=
	{
		gotoxy(startX + width * 2 - 3, startY + i);// startx+(width-1)*2-1 宽一//个横杠两个字符 横杠中文字符占两列
		printf("┃"); //打印右竖线
	}
	//底部 x在变化 y不变 （x到x+width） ━ 打印
	gotoxy(startX, startY + height - 1);//找到左下角
	printf("┗");//打印左下角
	for (i = 0; i < width * 2 - 4; i++) //打印底部 打印横杠
	{
		printf("━");
	}
	printf("┛");//打印右下角
	gotoxy(startX, startX + height);
}
//转换上下左右key值
short CTool::getkey(void)
{
	short key = _getch();
	if (224 == key)
	{
		short ch = _getch();
		switch (ch)
		{
		case 72:
			//上
			return UP;
		case 80:
			//下
			return DOWN;
		case 75:
			//左
			return LEFT;
		case 77:
			//右
			return RIGHT;
		}
	}
	return key;
}
