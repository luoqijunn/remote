#pragma once
#include "sqlite3.h"
#include <iostream>

using namespace std;

class CmyData
{
public:
	static CmyData* getMydata();//��ȡΨһ�Ķ���
	//��ɾ��    sqilte3_exec()   
	int noRes_exec(const char* sql);
	// sqlite3_get_table()  ��ѯ
	int getRes_exec();
	char sql[256] = "\0";	//�����ѯ���
	char** qres = nullptr;	//�����ѯ���
	int row = 0, col = 0;	//rowΪ�У�colΪ��
	char* errmsg = nullptr;	//���������Ϣ
private:
	CmyData();
	static CmyData* mydata;//����Ψһ�Ķ���
	sqlite3* mydb;	//����򿪵����ݿ����
};

