#include <iostream>
using namespace std;
#include "address.h"

int main()
{
	Addressbook abs;
	abs.size = 0;
	
	while (1)
	{
		Show_menu();
		cout << "请选择操作：";
		int flag = 0;
		cin >> flag;

		switch (flag)
		{
			/*<< "**** 1.添加联系人 ****\n"
				<< "**** 2.显示联系人 ****\n"
				<< "**** 3.删除联系人 ****\n"
				<< "**** 4.查找联系人 ****\n"
				<< "**** 5.修改联系人 ****\n"
				<< "**** 6.清空联系人 ****\n"
				<< "**** 0.退出通讯录 ****\n"*/
		case 1:
			add_person(abs);
			break;
		case 2:
			Output_person(abs);
			break;
		case 3:
			delete_persion(abs);
			break;
		case 4:
			find_persion(abs);
			break;
		case 5:
			revise_persion(abs);
			break;
		case 6:
			clear_persion(abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;

		default:
			break;
		}
	}

	system("pause");
	return 0;
}