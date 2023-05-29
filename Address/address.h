#pragma once
#include <iostream>
using namespace std;
#include <string.h>

#define MAX 1000

//��ϵ�˽ṹ��
struct Person
{
	string name;
	int sex;//1����2��Ů
	int age;
	string number;
	string addr;
};
//ͨѶ¼�ṹ��
struct Addressbook
{
	Person AddressArr[MAX];
	int size;
};

//�˵�
void Show_menu();
//��������
void input_name(Addressbook &abs, int i);
//�����Ա�
void input_sex(Addressbook &abs, int i);
//��������
void input_age(Addressbook &abs, int i);
//����绰
void input_number(Addressbook &abs, int i);
//�����ַ
void input_addr(Addressbook &abs, int i);
//�����ϵ��
void add_person(Addressbook &abs);
//��ʾ��ϵ��
void Output_person(Addressbook &abs);
//ƥ����ϵ��
int is_persion(Addressbook &abs, string name);
//ɾ����ϵ��
void delete_persion(Addressbook &abs);
//������ϵ��
void find_persion(Addressbook &abs);
//�޸���ϵ��
void revise_persion(Addressbook &abs);
//�����ϵ��
void clear_persion(Addressbook &abs);