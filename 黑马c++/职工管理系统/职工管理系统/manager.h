#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "worker.h"

class Manager : public Worker
{
public:
	Manager (int Id, string name, int dId);

	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡ��λ����
	virtual string getDeptName();
};