#pragma once
#include "sqlite3.h"
#include <iostream>

using namespace std;

class CmyData
{
public:
	static CmyData* getMydata();//获取唯一的对象
	//增删改    sqilte3_exec()   
	int noRes_exec(const char* sql);
	// sqlite3_get_table()  查询
	int getRes_exec();
	char sql[256] = "\0";	//保存查询语句
	char** qres = nullptr;	//保存查询结果
	int row = 0, col = 0;	//row为行，col为列
	char* errmsg = nullptr;	//保存错误信息
private:
	CmyData();
	static CmyData* mydata;//保存唯一的对象
	sqlite3* mydb;	//保存打开的数据库对象
};

