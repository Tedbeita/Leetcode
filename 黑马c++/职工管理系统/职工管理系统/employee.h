#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "worker.h"

class Employee :public Worker
{
public:
	Employee(int Id,string name,int dId);
	
	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡ��λ����
	virtual string getDeptName();
};