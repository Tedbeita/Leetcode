#include "manager.h"

Manager::Manager(int Id, string name, int dId)
{
	this->m_Id = Id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

//��ʾ������Ϣ
void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ������ϰ彻�������񣬲���ѹեԱ��" << endl;
}

//��ȡ��λ����
string Manager::getDeptName()
{
	return string("����");
}