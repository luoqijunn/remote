#include "CTool.h"

string CTool::tips = "\0";
int CTool::tipsret = 0;

//Ҫ��ʾ���ݵ�����ֵ
void CTool::gotoxy(int x, int y)
{
	COORD p; //����ṹ�����p
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//��õ�ǰ�������
	p.X = x;
	p.Y = y; //������Ŀ���ƶ���λ�ô��ݸ��ṹ��
	SetConsoleCursorPosition(handle, p);
}
//��ӡ����
void CTool::paintWindow(int startX, int startY, int width, int height)
{
	int i = 0;//ѭ������i��ʼ��
	//��ӡ����
	//��궨λ �ҹ��� �� �� �� �� �� ��
	//���� y�в��� x ���ڱ� (x��x+width)
	gotoxy(startX, startY); //�����ʼ
	printf("��"); //�����ʼ��λ�ȴ�ӡ���Ͻ�
	for (i = 0; i < width * 2 - 4; i++) //����ѭ������width-2�� ��ӡ����
	{
		printf("��");
	}
	printf("��");
	//��� x�в��� y���ڱ� (y��y+height) ��ӡ������
	for (i = 1; i <= height - 2; i++) //�������i��ʼֵΪ1����һ�д���ˣ� <=
	{
		gotoxy(startX, startY + i);//��ӡ������ʱ���һֱ�ƶ� Y���ڱ�
		printf("��"); //��ӡ������
	}
	//�ұ� x���� =startx+width-1(x��) y�ڱ� y �� y+height(y��)������
	for (i = 1; i <= height - 2; i++)//�������i��ʼֵΪ1����һ�д���ˣ� <=
	{
		gotoxy(startX + width * 2 - 3, startY + i);// startx+(width-1)*2-1 ��һ//����������ַ� ��������ַ�ռ����
		printf("��"); //��ӡ������
	}
	//�ײ� x�ڱ仯 y���� ��x��x+width�� �� ��ӡ
	gotoxy(startX, startY + height - 1);//�ҵ����½�
	printf("��");//��ӡ���½�
	for (i = 0; i < width * 2 - 4; i++) //��ӡ�ײ� ��ӡ���
	{
		printf("��");
	}
	printf("��");//��ӡ���½�
	gotoxy(startX, startX + height);
}
//ת����������keyֵ
short CTool::getkey(void)
{
	short key = _getch();
	if (224 == key)
	{
		short ch = _getch();
		switch (ch)
		{
		case 72:
			//��
			return UP;
		case 80:
			//��
			return DOWN;
		case 75:
			//��
			return LEFT;
		case 77:
			//��
			return RIGHT;
		}
	}
	return key;
}
