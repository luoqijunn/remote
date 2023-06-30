#include "CEdit.h"
//���캯��
CEdit::CEdit(int x, int y, int w, int h, const char* content, bool ips, unsigned int minlen, unsigned int maxlen, int inputtype) : CtrlBase(x, y, w, h, content, 2)
{
	this->ips = ips;
	this->minlen = minlen;
	this->maxlen = maxlen;
	this->inputtype = inputtype;
	
}
//��������
CEdit::~CEdit()
{
	//cout << "~CButton finish" << endl;
}

//�༭������ʾ����
void  CEdit::show()
{
	//��ӡ�ؼ���
	CTool::paintWindow(this->x, this->y, this->w, this->h);
	//�ƶ���굽�ؼ���
	CTool::gotoxy(this->x + 3, this->y + 1);
	if (strlen(this->content) == 0)
		cout << "���Ȳ�������" << this->minlen << endl;
	else
		cout << this->content << endl;

}

void CEdit::keylisten(short key)	//����������ʾ�жϺ���
{
	/*
	��������ַ���һϵ�е��жϴ�������Ҫ��ı������ʾ��
	this->ips ����ʾ�ĸ�ʽ
	this->iputType �������������������  1����
	this->maxLen�������ַ����ȣ������ǰ�Ѿ�������ַ��ĸ����ﵽ����󳤶ȵģ���û����������
	1. �ȼ��㵱ǰ�Ѿ������˼����ַ�   int count = strlen();
	   �ж� �ַ��ĸ�������󳤶��Ƿ����
		  �����ȣ��Ͳ�������
		  �������ȣ� ˵�����Ա��棬Ҫ�ж�������ַ��Ƿ�������ǵ���Ҫ
				�ж�����Ҫ������ĸ�����ֻ�����ĸ�����ֵ����
				if  this->iputType == 1   ˵������Ҫ�������֣��������ж�key�����ǲ�������
					 if key>='0' && key<='9'
						  ����  �� this->content[count] = key
						  ��ʾ��Ҫע����ʾ�ĸ�ʽ
								if  this->ips == 1     _putch(key);
								if  this->ips == 2     _putch('*')

	*/
	int count = (int)strlen(this->content);
	if (key == 8 && count > 0) //�˸�Ĳ���
	{
		//
		printf("\b \b");//�ѽ�������ʾ���ַ���� 
		this->content[count - 1] = '\0'; //�ͱ��浽�����ж�Ӧ���ַ����
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
		if (this->inputtype == 1)//����
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
		else if (this->inputtype == 2)//��ĸ
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
		else if (this->inputtype == 3)//��ĸ��������
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
		else if (this->inputtype == 4)//��Ӣ�Ļ�����
		{
			if (key >= 'A' && key <= 'Z' || key >= 'a' && key <= 'z' || key >= '0' && key <= '9')	//Ӣ�Ļ�����
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
			//����
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