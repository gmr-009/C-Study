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
		cout << "��ѡ�������";
		int flag = 0;
		cin >> flag;

		switch (flag)
		{
			/*<< "**** 1.�����ϵ�� ****\n"
				<< "**** 2.��ʾ��ϵ�� ****\n"
				<< "**** 3.ɾ����ϵ�� ****\n"
				<< "**** 4.������ϵ�� ****\n"
				<< "**** 5.�޸���ϵ�� ****\n"
				<< "**** 6.�����ϵ�� ****\n"
				<< "**** 0.�˳�ͨѶ¼ ****\n"*/
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
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;

		default:
			break;
		}
	}

	system("pause");
	return 0;
}