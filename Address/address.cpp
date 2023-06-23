#include "address.h"
//�˵�
void Show_menu()
{
	cout << "**********************\n"
		<< "**** 1.�����ϵ�� ****\n"
		<< "**** 2.��ʾ��ϵ�� ****\n"
		<< "**** 3.ɾ����ϵ�� ****\n"
		<< "**** 4.������ϵ�� ****\n"
		<< "**** 5.�޸���ϵ�� ****\n"
		<< "**** 6.�����ϵ�� ****\n"
		<< "**** 0.�˳�ͨѶ¼ ****\n"
		<< "**********************"
		<< endl;
}
//��������
//���ע��
void input_name(Addressbook &abs, int i)
{
	string* name = new string;
	cout << "������������";
	cin >> *name;
	abs.AddressArr[i].name = *name;
	delete name;
}
//�����Ա�
void input_sex(Addressbook &abs, int i)
{
	cout << "�������Ա�\t1����\t2��Ů" << endl;
	while (true)
	{
		int* sex = new int;//1����2��Ů
		cin >> *sex;
		if (*sex == 1 || *sex == 2)
		{
			abs.AddressArr[i].sex = *sex;
			break;
		}
		cout << "������������������" << endl;
		delete sex;
	}
}
	
//��������
void input_age(Addressbook &abs, int i)
{
	int* age = new int;
	cout << "���������䣺";
	cin >> *age;
	abs.AddressArr[i].age = *age;
	delete age;
}
//����绰
void input_number(Addressbook &abs, int i)
{
	string *number = new string;
	cout << "������绰��";
	cin >> *number;
	abs.AddressArr[i].number = *number;
	delete number;
}
//�����ַ
void input_addr(Addressbook &abs, int i)
{
	string* addr = new string;
	cout << "�������ַ��";
	cin >> *addr;
	abs.AddressArr[i].addr = *addr;
	delete addr;
}
//�����ϵ��
void add_person(Addressbook &abs)
{
	if (abs.size == MAX)
	{
		cout << "ͨѶ¼���������ʧ�ܣ�" << endl;
	}
	else
	{
		input_name(abs, abs.size);
		input_sex(abs, abs.size);
		input_age(abs, abs.size);
		input_number(abs, abs.size);
		input_addr(abs, abs.size);

		abs.size++;
		cout << "��ӳɹ���\n";
	}
	system("pause");
	system("cls");
}
//��ʾ��ϵ��
void Output_person(Addressbook &abs)
{
	if (abs.size == 0)
	{
		cout << "ͨѶ¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < abs.size; i++)
		{
			cout << "������" << abs.AddressArr[i].name
				<< "\t�Ա�" << (abs.AddressArr[i].sex == 1 ? "��" : "Ů")
				<< "\t���䣺" << abs.AddressArr[i].age
				<< "\t�绰��" << abs.AddressArr[i].number
				<< "\t��ַ��" << abs.AddressArr[i].addr
				<< endl;
		}
		cout << "��ʾ��ɣ�" << endl;
	}
	system("pause");
	system("cls");
}
//ƥ����ϵ��
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
//ɾ����ϵ��
void delete_persion(Addressbook &abs)
{
	cout << "��������Ҫɾ������ϵ��������";
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
		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}
//������ϵ��
void find_persion(Addressbook &abs)
{
	cout << "��������Ҫ���ҵ���ϵ��������";
	string name;
	cin >> name;
	int flag = is_persion(abs, name);
	if (flag != -1)
	{
		cout << "������" << abs.AddressArr[flag].name
			<< "\t�Ա�" << (abs.AddressArr[flag].sex == 1 ? "��" : "Ů")
			<< "\t���䣺" << abs.AddressArr[flag].age
			<< "\t�绰��" << abs.AddressArr[flag].number
			<< "\t��ַ��" << abs.AddressArr[flag].addr
			<< endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}
	system("pause");
	system("cls");
}
//�޸���ϵ��
void revise_persion(Addressbook &abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ��������";
	string name;
	cin >> name;
	int flag = is_persion(abs, name);

	if (flag != -1)
	{
		cout << "��ѡ��Ҫ�޸ĵ���������Ա����䣻�绰��סַ��\n����0�˳��޸ģ�" << endl;
		string str1[] = { "0","����","�Ա�","����","�绰","סַ" };
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
				cout << "�˳���" << endl;
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
				cout << "�����������������룻" << endl;
				break;
			}
			cout << "�޸ĳɹ���" << endl;
		}
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}
to:
	system("pause");
	system("cls");
}
//�����ϵ��
void clear_persion(Addressbook &abs)
{
	cout << "�Ƿ������ϵ�ˣ�1���ǣ�2����" << endl;
	int i = 2;
	cin >> i;
	if (i == 1)
	{
		abs.size = 0;
		cout << "ͨѶ¼�����" << endl;
	}
	system("pause");
	system("cls");
}