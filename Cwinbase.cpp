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

// ����ʾ�������ʾ���еĿؼ�
void CwinBase::show()
{
	//�������
	CTool::paintWindow(this->x, this->y, this->w, this->h);
	//�����ؼ���������
	for (unsigned int i = 0; i < this->ctrlArry.size(); i++)
	{
		this->ctrlArry.at(i)->show();//this->ctrlArry.at(i) �� Ctrlbase*���͵ģ�ִ�еľ��Ǹ����show����
	}
}

//��������������
/* Ŀ�꣺ �༭��������롢��ť���Ե��
*  1.���Ҫ��λ����һ���༭������ǵ�һ����ť��λ����
*     ���ҵ���һ���༭������ǵ�һ����ť     ȥ�����ң� ȥ�ؼ�����������ȥ��  �ж������Ǳ༭������ǰ�ť��
*     ��궨λ
*  2. ��������
*        key = CTool::getKey();
*        ����Ƿ��򰴼���
*                 ��������°����� Ŀ�꣺���һ��Ҫ��λ����һ���༭���������һ����ť��λ����
*                        ����i++    �ж������Ǳ༭������ǰ�ť��    ����Ƕ�λ   ��������أ� i++   for
*                        Ҫע�� i��ȡֵ��Χ��[0, size()-1]
*				  ��������ϰ����� Ŀ�꣺���һ��Ҫ��λ����һ���༭���������һ����ť��λ����
*                        ����i--    �ж������Ǳ༭������ǰ�ť��    ����Ƕ�λ   ��������أ� i--   for
*                        Ҫע�� i��ȡֵ��Χ��[0, size()-1]
		����ǻس���
				�ж�һ�µ�ǰ�Ŀؼ��ǲ��ǰ�ť������ǰ�ť���Ϳ���ȥִ�а�ťҵ��
		�����ַ���
				�ж�һ�µ�ǰ�Ŀؼ��ǲ��Ǳ༭������Ǳ༭�򣬾͵��ñ༭��ļ���������������ַ����ж�

*/

void CwinBase::winRun()
{
	int i;
	short key;
	for (i = 0; i < (signed)this->ctrlArry.size(); i++)
	{
		if (this->ctrlArry.at(i)->getType() == 2) //�༭��
		{
			CTool::gotoxy(0, 0);	//�����ת��ʹ���ڽ���ȫ����ʾ
			CTool::gotoxy(this->ctrlArry.at(i)->getX() + 3 + strlen(this->ctrlArry.at(i)->getContent()), this->ctrlArry.at(i)->getY() + 1);
			break;
		}
		else if (this->ctrlArry.at(i)->getType() == 3) //��ť
		{
			CTool::gotoxy(0, 0);	//�����ת��ʹ���ڽ���ȫ����ʾ
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
				i = 0; //������β�͵ĵط����²�ȥ�ˣ��ô�ͷ��ʼ������
			}
			for (; i < (signed)this->ctrlArry.size(); i++)
			{
				if (this->ctrlArry.at(i)->getType() == 2) //�༭��
				{
					CTool::gotoxy(this->ctrlArry.at(i)->getX() + 3 + strlen(this->ctrlArry.at(i)->getContent()), this->ctrlArry.at(i)->getY() + 1);
					break;
				}
				else if (this->ctrlArry.at(i)->getType() == 3) //��ť
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
				i = (signed)this->ctrlArry.size() - 1; //������ͷ�ĵط����ϲ�ȥ�ˣ��ô�β�Ϳ�ʼ������
			}
			for (; i >= 0; i--)
			{
				if (this->ctrlArry.at(i)->getType() == 2) //�༭��
				{
					CTool::gotoxy(this->ctrlArry.at(i)->getX() + 3 + strlen(this->ctrlArry.at(i)->getContent()), this->ctrlArry.at(i)->getY() + 1);
					break;
				}
				else if (this->ctrlArry.at(i)->getType() == 3) //��ť
				{
					CTool::gotoxy(this->ctrlArry.at(i)->getX() + 5, this->ctrlArry.at(i)->getY() + 1);
					break;
				}
				if (i == 0)
				{
					i = (signed)this->ctrlArry.size(); //������ͷ�ĵط����ϲ�ȥ�ˣ��ô�β�Ϳ�ʼ������
				}
			}
			break;
		case ENTER://�س�
			if (this->ctrlArry.at(i)->getType() == 3) //��ť
			{
				this->focusIndex = i;// �����ʱ���س�������ؼ��������Ϳ���
				return;// ����winrun������������ȥ����ť��ҵ����   doAction()

			}
			break;
		default:
			if (this->ctrlArry.at(i)->getType() == 2) //�༭��
			{
				//���ñ༭���keyListen()����
				this->ctrlArry.at(i)->keylisten(key);
			}
			break;

		}
	}
}

//��ťҵ��ķַ�����
int CwinBase::doAction()
{
	return 0;
}