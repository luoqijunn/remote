#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string.h> 
#include "CmyData.h"

enum
{
	ENTER = 13,
	TAB = 9,
	UP = -4,
	DOWN,
	LEFT,
	RIGHT
};

using namespace std;

class CTool
{
public:
	static void gotoxy(int x, int y);	//移动光标
	static void paintWindow(int startX, int startY, int width, int height);	//画框
	static short getkey(void);	//转换上下左右key值
	static string tips;	//提示框内容
	static int tipsret;	//提示框返回值
};

