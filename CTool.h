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
	static void gotoxy(int x, int y);	//�ƶ����
	static void paintWindow(int startX, int startY, int width, int height);	//����
	static short getkey(void);	//ת����������keyֵ
	static string tips;	//��ʾ������
	static int tipsret;	//��ʾ�򷵻�ֵ
};

