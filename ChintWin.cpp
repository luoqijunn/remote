#include "ChintWin.h"

ChintWin::ChintWin(int x, int y, int w, int h) : CwinBase(x, y, w, h)
{
	//����CButton����
	this->confmButton = new CButton(27, 10, 6, 3, "ȷ ��");//end-3

	//��ӵ��ؼ�����������
	this->ctrlArry.push_back(this->confmButton);		//0
}

ChintWin::~ChintWin()
{
	delete this->confmButton;
}

// ����ʾ�������ʾ���еĿؼ�
void ChintWin::show()
{
	CTool::gotoxy(22, 7);
	cout << CTool::tips << endl;
	//�������
	CTool::paintWindow(this->x, this->y, this->w, this->h);
	//�����ؼ���������
	for (unsigned int i = 0; i < this->ctrlArry.size(); i++)
	{
		this->ctrlArry.at(i)->show();//this->ctrlArry.at(i) �� Ctrlbase*���͵ģ�ִ�еľ��Ǹ����show����
	}
}

int ChintWin::doAction()
{
	return CTool::tipsret;
}