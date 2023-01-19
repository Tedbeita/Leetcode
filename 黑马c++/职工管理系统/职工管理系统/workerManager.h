#pragma once	//��ֹͷ�ļ��ظ�����
#include <iostream>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include <fstream>
#define FILENAME "empFile.txt"


class WorkerManager {
public:

	WorkerManager();

	void Show_Menu();

	void ExitSystem();
	//���ְ��
	void Add_Emp();

	void save();

	//�ж�ְ���Ƿ�Ϊ�յı�־
	bool FileIsEmpty;

	//ͳ���ļ�������
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	void show_Emp();

	void Del_Emp();

	int IsExist(int id);

	void modify_Emp();

	void find_Emp();

	//����
	void sort();

	void cleanFile();

	~WorkerManager();




	//ְ������ָ��
	Worker** m_EmpArray;
	//ְ������
	int m_EmpNum;


};
