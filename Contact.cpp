#include<iostream>
using namespace std;
#include<string>
#define MAX 1000
struct person  // ������ϵ�˽ṹ��
{
	string name;
	int sex;
	int age;
	string tel;
	string address;
};

struct Contact // ����ͨѶ¼�ṹ��
{
	struct person ContactArray[MAX]; // ������ϵ�˽ṹ������
	int size;	// ȷ����ǰͨѶ¼����������ΪMAX=1000
};
void showMenu()
{
	cout << "*******************************" << endl <<
		"*******  1�������ϵ��  *******" << endl <<
		"*******  2��ɾ����ϵ��  *******" << endl <<
		"*******  3����ʾ��ϵ��  *******" << endl <<
		"*******  4��������ϵ��  *******" << endl <<
		"*******  5���޸���ϵ��  *******" << endl <<
		"*******  6�������ϵ��  *******" << endl <<
		"*******  0���˳�ͨѶ¼  *******" << endl<<
		"*******************************" << endl;
	cout << "��ѡ��" << endl;
}

void Add(Contact* Con)
{
	if (Con->size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		cout << "������������" << endl;
		cin >> Con->ContactArray[Con->size].name;
		
		int sex = 0;
		while (true)
		{
			cout << "�������Ա�" << endl;
			cout << "�� - 1" << "  " << "Ů - 2" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				Con->ContactArray[Con->size].sex = sex;
				break;
			}
			cout << "����������������룡" << endl;
		}

		int age = 0;
		while (true)
		{
			cout << "���������䣺" << endl;
			cin >> age;
			if (age > 0 && age < 110)
			{
				Con->ContactArray[Con->size].age = age;
				break;
			}
			cout << "����������������룡" << endl;
		}

		cout << "������绰��" << endl;
		cin >> Con->ContactArray[Con->size].tel;

		cout << "������סַ��" << endl;
		cin >> Con->ContactArray[Con->size].address;

		Con->size++; // ����+1

		cout << "��ӳɹ���" << endl;
		system("pause"); // �밴���������
	}
	system("cls"); // ����
}
	
void Show(Contact* Con)
{
	if (Con->size == 0)
	{
		cout << "ͨѶ¼Ϊ�գ�" << endl;
		system("pause"); // �밴���������
	}
	else
	{
		for (int i = 0; i < Con->size; i++)
		{
			cout << "��ţ�" << i+1 << "\t";
			cout << "������" << Con->ContactArray[i].name << "\t";
			cout << "�Ա�" << (Con->ContactArray[i].sex == 1 ? "��" : "Ů") << "\t";// 1�򷵻��У�������Ů
			cout << "���䣺" << Con->ContactArray[i].age << "\t";
			cout << "�绰��" << Con->ContactArray[i].tel << "\t";
			cout << "סַ��" << Con->ContactArray[i].address << "\t";
			cout << endl;
		}
		system("pause"); // �밴���������
	}
	system("cls"); // ����
}

int Exist(Contact* Con,string name)
{
	for (int i = 0; i <= Con->size; i++)
	{
		if (Con->ContactArray[i].name == name)
			return i;
		else
			return -1;
	}
}

void Find(Contact* Con)
	{
		cout << "������Ҫ�����˵����֣�" << endl;
		string name;
		cin >> name;
		int ret = Exist(Con, name);
		if (ret == -1)
		{
			cout << "���޴��ˣ�" << endl;
		}
		else
		{
			cout << "��ţ�" << ret + 1 << "\t";
			cout << "������" << Con->ContactArray[ret].name << "\t";
			cout << "�Ա�" << (Con->ContactArray[ret].sex == 1 ? "��" : "Ů") << "\t";// 1�򷵻��У�������Ů
			cout << "���䣺" << Con->ContactArray[ret].age << "\t";
			cout << "�绰��" << Con->ContactArray[ret].tel << "\t";
			cout << "סַ��" << Con->ContactArray[ret].address << "\t";
			cout << endl;
		}
		system("pause");
		system("cls"); // ����
	}

void Del(Contact* Con)
{
	cout << "������Ҫɾ���˵����֣�" << endl;
	string name;
	cin >> name;
	int ret = Exist(Con,name);
	if (ret == -1)
	{
		cout << "���޴��ˣ�" << endl;
	}
	else
	{
		for (; ret < Con->size; ret++)
		{
			// ����ǰ��
			Con->ContactArray[ret] = Con->ContactArray[ret + 1];
		}
		Con->size--;
		cout << "ɾ���ɹ���" << endl;
	}
	system("pause");
	system("cls");
}

void Mod(Contact* Con)
{
	cout << "������Ҫ�޸��˵����֣�" << endl;
	string name;
	cin >> name;
	int ret = Exist(Con, name);
	if (ret == -1)
	{
		cout << "���޴��ˣ�" << endl;
	}
	else
	{
		cout << "������������" << endl;
		cin >> Con->ContactArray[ret].name;

		int sex = 0;
		while (true)
		{
			cout << "�������Ա�" << endl;
			cout << "�� - 1" << "  " << "Ů - 2" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				Con->ContactArray[Con->size].sex = sex;
				break;
			}
			cout << "����������������룡" << endl;
		}

		int age = 0;
		while (true)
		{
			cout << "���������䣺" << endl;
			cin >> age;
			if (age > 0 && age < 110)
			{
				Con->ContactArray[Con->size].age = age;
				break;
			}
			cout << "����������������룡" << endl;
		}

		cout << "������绰��" << endl;
		cin >> Con->ContactArray[ret].tel;

		cout << "������סַ��" << endl;
		cin >> Con->ContactArray[ret].address;

		cout << "�޸ĳɹ���" << endl;
	}
	system("pause");
	system("cls"); // ����
}

void Des(Contact* Con)
{
	char input;
	cout << "��ȷ���Ƿ�Ҫ�����ϵ�ˣ�" << endl
		<< " ȷ������Y ����������N" << endl;
	cin >> input;
	if (input == 'Y')
	{
		Con->size = 0;
		cout << "�����ͨѶ¼��" << endl;
	}
	system("pause");
	system("cls"); // ����
}
int main()
{
	Contact Con;
	Con.size = 0;

	while (true)
	{
		showMenu();
		int input = 0;
		cin >> input;
		switch (input)
		{
			case 1:
				Add(&Con);
				break;
			case 2:
				Del(&Con);
				break;
			case 3:
				Show(&Con);
				break;
			case 4:
				Find(&Con);
				break;
			case 5:
				Mod(&Con);
				break;
			case 6:
				Des(&Con);
				break;
			case 0:
				cout << "�˳�����" << endl;
				return 0;
				break;
			default:
				break;
		}
	}
	return 0;
}
