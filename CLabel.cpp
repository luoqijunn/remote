#include "CLabel.h"
//���캯��
CLabel::CLabel(int x, int y, const char* content) : CtrlBase(x, y, 0, 0, content, 1)
{

}
//��������
CLabel::~CLabel()
{
	//cout << "~CLabel finish" << endl;
}

//��ʾ����
void CLabel::show(void)
{
	//�ƶ�����λ��
	CTool::gotoxy(this->x, this->y);
	//�ڸ�λ������ʾ����
	cout << this->content << endl;
}