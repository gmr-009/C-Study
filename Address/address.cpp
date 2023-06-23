#include "address.h"
//菜单
void Show_menu()
{
	cout << "**********************\n"
		<< "**** 1.添加联系人 ****\n"
		<< "**** 2.显示联系人 ****\n"
		<< "**** 3.删除联系人 ****\n"
		<< "**** 4.查找联系人 ****\n"
		<< "**** 5.修改联系人 ****\n"
		<< "**** 6.清空联系人 ****\n"
		<< "**** 0.退出通讯录 ****\n"
		<< "**********************"
		<< endl;
}
//输入姓名
//添加注释
void input_name(Addressbook &abs, int i)
{
	string* name = new string;
	cout << "请输入姓名：";
	cin >> *name;
	abs.AddressArr[i].name = *name;
	delete name;
}
//输入性别
void input_sex(Addressbook &abs, int i)
{
	cout << "请输入性别：\t1、男\t2、女" << endl;
	while (true)
	{
		int* sex = new int;//1、男2、女
		cin >> *sex;
		if (*sex == 1 || *sex == 2)
		{
			abs.AddressArr[i].sex = *sex;
			break;
		}
		cout << "输入有误请重新输入" << endl;
		delete sex;
	}
}
	
//输入年龄
void input_age(Addressbook &abs, int i)
{
	int* age = new int;
	cout << "请输入年龄：";
	cin >> *age;
	abs.AddressArr[i].age = *age;
	delete age;
}
//输入电话
void input_number(Addressbook &abs, int i)
{
	string *number = new string;
	cout << "请输入电话：";
	cin >> *number;
	abs.AddressArr[i].number = *number;
	delete number;
}
//输入地址
void input_addr(Addressbook &abs, int i)
{
	string* addr = new string;
	cout << "请输入地址：";
	cin >> *addr;
	abs.AddressArr[i].addr = *addr;
	delete addr;
}
//添加联系人
void add_person(Addressbook &abs)
{
	if (abs.size == MAX)
	{
		cout << "通讯录已满；添加失败；" << endl;
	}
	else
	{
		input_name(abs, abs.size);
		input_sex(abs, abs.size);
		input_age(abs, abs.size);
		input_number(abs, abs.size);
		input_addr(abs, abs.size);

		abs.size++;
		cout << "添加成功；\n";
	}
	system("pause");
	system("cls");
}
//显示联系人
void Output_person(Addressbook &abs)
{
	if (abs.size == 0)
	{
		cout << "通讯录为空；" << endl;
	}
	else
	{
		for (int i = 0; i < abs.size; i++)
		{
			cout << "姓名：" << abs.AddressArr[i].name
				<< "\t性别：" << (abs.AddressArr[i].sex == 1 ? "男" : "女")
				<< "\t年龄：" << abs.AddressArr[i].age
				<< "\t电话：" << abs.AddressArr[i].number
				<< "\t地址：" << abs.AddressArr[i].addr
				<< endl;
		}
		cout << "显示完成；" << endl;
	}
	system("pause");
	system("cls");
}
//匹配联系人
int is_persion(Addressbook &abs, string name)
{
	for (int i = 0; i < abs.size; i++)
	{
		if (abs.AddressArr[i].name == name)
		{
			return i;
		}
	}
	return -1;
}
//删除联系人
void delete_persion(Addressbook &abs)
{
	cout << "请输入你要删除的联系人姓名：";
	string name;
	cin >> name;
	int flag = is_persion(abs, name);
	if (flag != -1)
	{
		for (int i = flag; i < abs.size; i++)
		{
			abs.AddressArr[i] = abs.AddressArr[i + 1];
		}
		abs.size--;
		cout << "删除成功；" << endl;
	}
	else
	{
		cout << "查无此人；" << endl;
	}
	system("pause");
	system("cls");
}
//查找联系人
void find_persion(Addressbook &abs)
{
	cout << "请输入你要查找的联系人姓名：";
	string name;
	cin >> name;
	int flag = is_persion(abs, name);
	if (flag != -1)
	{
		cout << "姓名：" << abs.AddressArr[flag].name
			<< "\t性别：" << (abs.AddressArr[flag].sex == 1 ? "男" : "女")
			<< "\t年龄：" << abs.AddressArr[flag].age
			<< "\t电话：" << abs.AddressArr[flag].number
			<< "\t地址：" << abs.AddressArr[flag].addr
			<< endl;
	}
	else
	{
		cout << "查无此人；" << endl;
	}
	system("pause");
	system("cls");
}
//修改联系人
void revise_persion(Addressbook &abs)
{
	cout << "请输入你要修改的联系人姓名：";
	string name;
	cin >> name;
	int flag = is_persion(abs, name);

	if (flag != -1)
	{
		cout << "请选择要修改的项：姓名；性别；年龄；电话；住址；\n输入0退出修改！" << endl;
		string str1[] = { "0","姓名","性别","年龄","电话","住址" };
		while (true)
		{
			string str;
			cin >> str;
			int flag1 = -1;
			for (int i = 0; i < 5; i++)
			{
				if (str1[i] == str)
				{
					flag1 = i;
					continue;
				}
			}
			switch (flag1)
			{
			case 0:
				cout << "退出！" << endl;
				goto to;
			case 1:
				input_name(abs, flag);
				break;
			case 2:
				input_sex(abs, flag);
				break;
			case 3:
				input_age(abs, flag);
				break;
			case 4:
				input_number(abs, flag);
				break;
			case 5:
				input_addr(abs, flag);
				break;
			default:
				cout << "输入有误，请重新输入；" << endl;
				break;
			}
			cout << "修改成功！" << endl;
		}
	}
	else
	{
		cout << "查无此人；" << endl;
	}
to:
	system("pause");
	system("cls");
}
//清空联系人
void clear_persion(Addressbook &abs)
{
	cout << "是否清空联系人：1、是，2、否" << endl;
	int i = 2;
	cin >> i;
	if (i == 1)
	{
		abs.size = 0;
		cout << "通讯录已清空" << endl;
	}
	system("pause");
	system("cls");
}