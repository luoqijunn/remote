#include "CmyData.h"

CmyData* CmyData::mydata = nullptr;

//��ȡΨһ�Ķ���
CmyData* CmyData::getMydata()
{
	if (CmyData::mydata == nullptr)//˵������û����
	{
		CmyData::mydata = new CmyData;//���캯��ִֻ��һ��
	}
	return CmyData::mydata;
}

CmyData::CmyData()
{
	this->mydb = nullptr;
	int res = sqlite3_open("./sqlite3/user.db", &this->mydb);
	if (res != SQLITE_OK)
	{
		cout << "open database error" << endl;
	}
	else
	{
		cout << "open database ok" << endl;
	}
}

//��ɾ��
int CmyData::noRes_exec(const char* sql)
{
	char* errmsg = nullptr;
	int res = sqlite3_exec(this->mydb, sql, NULL, NULL, &errmsg);
	if (res != SQLITE_OK)
	{
		cout << "exec sql error" << endl;
		return -1;
	}
	else
	{
		//cout << "exec sql ok" << endl;
		return 0;
	}
}
// sqlite3_get_table()  ��ѯ
int CmyData::getRes_exec()
{
	//memset(sql, 0, strlen(sql));	//sql���ʹ��ǰ���
	//row = 0, col = 0;

	int res = sqlite3_get_table(mydb, sql, &qres, &row, &col, &errmsg);
	if (res != SQLITE_OK)
	{
		cout << "get_table sql error" << endl;
		return -1;
	}
	else
	{
		//cout << "get_table sql ok" << endl;
		return 0;
	}
}