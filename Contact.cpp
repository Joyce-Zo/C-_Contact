#include<iostream>
using namespace std;
#include<string>
#define MAX 1000
struct person  // 定义联系人结构体
{
	string name;
	int sex;
	int age;
	string tel;
	string address;
};

struct Contact // 定义通讯录结构体
{
	struct person ContactArray[MAX]; // 创建联系人结构体数组
	int size;	// 确定当前通讯录数量，上限为MAX=1000
};
void showMenu()
{
	cout << "*******************************" << endl <<
		"*******  1、添加联系人  *******" << endl <<
		"*******  2、删除联系人  *******" << endl <<
		"*******  3、显示联系人  *******" << endl <<
		"*******  4、查找联系人  *******" << endl <<
		"*******  5、修改联系人  *******" << endl <<
		"*******  6、清空联系人  *******" << endl <<
		"*******  0、退出通讯录  *******" << endl<<
		"*******************************" << endl;
	cout << "请选择：" << endl;
}

void Add(Contact* Con)
{
	if (Con->size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		cout << "请输入姓名：" << endl;
		cin >> Con->ContactArray[Con->size].name;
		
		int sex = 0;
		while (true)
		{
			cout << "请输入性别：" << endl;
			cout << "男 - 1" << "  " << "女 - 2" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				Con->ContactArray[Con->size].sex = sex;
				break;
			}
			cout << "输入错误，请重新输入！" << endl;
		}

		int age = 0;
		while (true)
		{
			cout << "请输入年龄：" << endl;
			cin >> age;
			if (age > 0 && age < 110)
			{
				Con->ContactArray[Con->size].age = age;
				break;
			}
			cout << "输入错误，请重新输入！" << endl;
		}

		cout << "请输入电话：" << endl;
		cin >> Con->ContactArray[Con->size].tel;

		cout << "请输入住址：" << endl;
		cin >> Con->ContactArray[Con->size].address;

		Con->size++; // 数量+1

		cout << "添加成功！" << endl;
		system("pause"); // 请按任意键继续
	}
	system("cls"); // 清屏
}
	
void Show(Contact* Con)
{
	if (Con->size == 0)
	{
		cout << "通讯录为空！" << endl;
		system("pause"); // 请按任意键继续
	}
	else
	{
		for (int i = 0; i < Con->size; i++)
		{
			cout << "序号：" << i+1 << "\t";
			cout << "姓名：" << Con->ContactArray[i].name << "\t";
			cout << "性别：" << (Con->ContactArray[i].sex == 1 ? "男" : "女") << "\t";// 1则返回男，否则是女
			cout << "年龄：" << Con->ContactArray[i].age << "\t";
			cout << "电话：" << Con->ContactArray[i].tel << "\t";
			cout << "住址：" << Con->ContactArray[i].address << "\t";
			cout << endl;
		}
		system("pause"); // 请按任意键继续
	}
	system("cls"); // 清屏
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
		cout << "请输入要查找人的名字：" << endl;
		string name;
		cin >> name;
		int ret = Exist(Con, name);
		if (ret == -1)
		{
			cout << "查无此人！" << endl;
		}
		else
		{
			cout << "序号：" << ret + 1 << "\t";
			cout << "姓名：" << Con->ContactArray[ret].name << "\t";
			cout << "性别：" << (Con->ContactArray[ret].sex == 1 ? "男" : "女") << "\t";// 1则返回男，否则是女
			cout << "年龄：" << Con->ContactArray[ret].age << "\t";
			cout << "电话：" << Con->ContactArray[ret].tel << "\t";
			cout << "住址：" << Con->ContactArray[ret].address << "\t";
			cout << endl;
		}
		system("pause");
		system("cls"); // 清屏
	}

void Del(Contact* Con)
{
	cout << "请输入要删除人的名字：" << endl;
	string name;
	cin >> name;
	int ret = Exist(Con,name);
	if (ret == -1)
	{
		cout << "查无此人！" << endl;
	}
	else
	{
		for (; ret < Con->size; ret++)
		{
			// 数据前移
			Con->ContactArray[ret] = Con->ContactArray[ret + 1];
		}
		Con->size--;
		cout << "删除成功！" << endl;
	}
	system("pause");
	system("cls");
}

void Mod(Contact* Con)
{
	cout << "请输入要修改人的名字：" << endl;
	string name;
	cin >> name;
	int ret = Exist(Con, name);
	if (ret == -1)
	{
		cout << "查无此人！" << endl;
	}
	else
	{
		cout << "请输入姓名：" << endl;
		cin >> Con->ContactArray[ret].name;

		int sex = 0;
		while (true)
		{
			cout << "请输入性别：" << endl;
			cout << "男 - 1" << "  " << "女 - 2" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				Con->ContactArray[Con->size].sex = sex;
				break;
			}
			cout << "输入错误，请重新输入！" << endl;
		}

		int age = 0;
		while (true)
		{
			cout << "请输入年龄：" << endl;
			cin >> age;
			if (age > 0 && age < 110)
			{
				Con->ContactArray[Con->size].age = age;
				break;
			}
			cout << "输入错误，请重新输入！" << endl;
		}

		cout << "请输入电话：" << endl;
		cin >> Con->ContactArray[ret].tel;

		cout << "请输入住址：" << endl;
		cin >> Con->ContactArray[ret].address;

		cout << "修改成功！" << endl;
	}
	system("pause");
	system("cls"); // 清屏
}

void Des(Contact* Con)
{
	char input;
	cout << "请确认是否要清空联系人？" << endl
		<< " 确认输入Y ，否则输入N" << endl;
	cin >> input;
	if (input == 'Y')
	{
		Con->size = 0;
		cout << "已清空通讯录！" << endl;
	}
	system("pause");
	system("cls"); // 清屏
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
				cout << "退出程序！" << endl;
				return 0;
				break;
			default:
				break;
		}
	}
	return 0;
}
