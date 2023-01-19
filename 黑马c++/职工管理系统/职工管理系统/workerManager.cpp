#include "workerManager.h"

WorkerManager::WorkerManager()
{
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		//��ʼ������
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.�ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) 
	{
		cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.�ļ����ڲ��Ҽ�¼����
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int  i = 0; i <this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

void WorkerManager::Show_Menu()
{
	cout << "******************************" << endl;
	cout << "********0.�˳�����ϵͳ********" << endl;
	cout << "********1.����ְ����Ϣ********" << endl;
	cout << "********2.��ʾְ����Ϣ********" << endl;
	cout << "********3.ɾ����ְְ��********" << endl;
	cout << "********4.�޸�ְ����Ϣ********" << endl;
	cout << "********5.����ְ����Ϣ********" << endl;
	cout << "********6.���ձ������********" << endl;
	cout << "********7.��������ĵ�********" << endl;
	cout << "******************************" << endl;

}

//�˳�ϵͳ 
void WorkerManager::ExitSystem()
{
	cout << "��ӭ���´�ʹ��" << endl;
	system("pause");
	exit(0); 
}

void WorkerManager::Add_Emp()
{
	cout << "���������ְ������" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//���
		//�����¿ռ�Ĵ�С
		int newSize = this->m_EmpNum + addNum;//�¿ռ����ԭ��+����

		//�����¿ռ�
		Worker** newspace = new Worker * [newSize];

		//��ԭ�������ݿ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newspace[i] = this->m_EmpArray[i];
			}
		}

		//�������������
		for (int i = 0; i < addNum; i++)
		{
			int id = 0;
			string name;
			int dselect;

			cout << "�������" << i + 1 << "��ְ����ţ�" << endl;
			cin >> id;

			cout << "�������" << i + 1 << "��ְ��������" << endl;
			cin >> name;

			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dselect;

			Worker* worker = NULL;
			switch (dselect)
			{
			case 1:
				worker = new Employee(id, name, 1);
					break;
			case 2:
				worker = new Manager(id, name, 2);
					break;
			case 3:
				worker = new Boss(id, name, 3);
					break;
			default:
				break;
			}

			//������ְ��ָ�뱣�浽������
			newspace[this->m_EmpNum + i] = worker;

		}
		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;
		//�����¿ռ�ָ��
		this->m_EmpArray = newspace;
		//�����¿ռ�����
		this->m_EmpNum = newSize;
		//����ְ����Ϊ�ձ�־
		this->FileIsEmpty = false;
		//��������
		this->save();
		cout << "�ɹ����" << addNum << "����ְ��" << endl;


		system("pause");
		system("cls");
	}
	else
	{
		//����
		cout << "��������" << endl;
	}
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//д�ļ�
	//д��
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();


}

int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	int id;
	string name;
	int did;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		//ͳ����������
		num++;
		 
	}
	return num;
}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;
	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;

		if (did == 1)
		{
			worker = new Employee(id, name, did);
		}
		else if(did == 2)
		{
			worker = new Manager(id, name, did);
		}
		else
		{
			worker = new Boss(id, name, did);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkerManager::show_Emp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ�����Ͳ���Ա��" << endl;

	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showInfo();

		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::Del_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		//����ְ�����ɾ��ְ��
		cout << "������Ҫɾ��ְ���ı��" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			//��������������
			this->m_EmpNum--;
			//���µ��ļ���
			this->save();

			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "�Ҳ�����Ķ���" << endl;
		}
		

	}
	system("pause");
	system("cls");
}

int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_Id == id) {
			index = i;		//�ҵ�ְ��
			break;
		}
	}
	return index; 
}

void WorkerManager::modify_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		//����ְ������޸�ְ��
		cout << "������Ҫ�޸�ְ���ı��" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);

		if (index != -1)
		{
			delete this->m_EmpArray[index];

			int newid = 0;
			string newname = "";
			int newselect = 0;

			cout << "�ҵ���Ķ��󣬿��Ի���������" << endl;
			cout << "�������µ�ְ����ţ�" << endl;
			cin >> newid;

			cout << "�������µ�ְ��������" << endl;
			cin >> newname;

			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> newselect;
			
			Worker* worker = NULL;
			
			switch (newselect)
			{
			case 1:
				worker = new Employee(newid, newname, 1);
				break;
			case 2:
				worker = new Manager(newid, newname, 2);
				break;
			case 3:
				worker = new Boss(newid, newname, 3);
				break;
			default:
				break;
			}
			this->m_EmpArray[index] = worker;

			//���µ��ļ���
			this->save();

			cout << "�޸ĳɹ�" << endl;
		}
		else
		{
			cout << "�Ҳ�����Ķ���" << endl;
		}

		
	}

	system("pause");
	system("cls");

}

void WorkerManager::find_Emp()
{
	if (this->FileIsEmpty)
	{
		cout << "�յ�" << endl;

	}
	else
	{
		cout << "��������ҵķ�ʽ" << endl;
		cout << "1.��Ų���" << endl;
		cout << "2����������" << endl;

		int select;
		cin >> select;
		if (select == 1)
		{
			//��Ų���
			int id;
			cout << "��������" << endl;
			cin >> id;
			
			int ret = this->IsExist(id);
			if (ret != -1)
			{
				//�ҵ�
				cout << "���ж�����" << endl;
				this->m_EmpArray[ret]->showInfo();

			}
			else {
				cout << "�Ҳ�������" << endl;
			}
		}
		else if (select == 2)
		{
			//��������
			string name;
			cout << "���������ְ����������" << endl;
			cin >> name;

			//����һ���Ƿ�鵽�ı�־
			bool flag = false;

			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "�ҵ��ˣ�����ǣ�" << this->m_EmpArray[i]->m_Id << endl;
					this->m_EmpArray[i]->showInfo();

					flag = true;
				}
			}

			if (flag == false)
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
		{
			cout << "����ѡ������" << endl;
		}
	}
	system("pause");
	system("cls");
  
}

void WorkerManager::sort()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1ְ��������" << endl;
		cout << "2ְ���Ž���" << endl;

		int select = 0;
		int minormax = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minormax = i;
			for (int j = i+ 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//����
				{
					if (this->m_EmpArray[minormax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minormax = j;
					}
				}
				else//����
				{
					if (this->m_EmpArray[minormax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minormax = j;
					}
				}
			}
			if (i != minormax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minormax];
				this->m_EmpArray[minormax] = temp;
			}
		}
		
	}

	cout << "����ɹ�" << endl;
	this->save();
	this->show_Emp();
}

void WorkerManager::cleanFile()
{
	cout << "ȷ����գ�" << endl;
	cout << "1ȷ��" << endl;
	cout << "2����" << endl;
	
	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);//ɾ���ļ��������´���
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			//ɾ��������ÿ��ְ������
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			//ɾ������������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->FileIsEmpty = true;
			cout << "��ճɹ�" << endl;
		}
	}



	system("pause");
	system("cls");
}