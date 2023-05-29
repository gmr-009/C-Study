#pragma once
#include <iostream>
using namespace std;
#include <string.h>

#define MAX 1000

//联系人结构体
struct Person
{
	string name;
	int sex;//1、男2、女
	int age;
	string number;
	string addr;
};
//通讯录结构体
struct Addressbook
{
	Person AddressArr[MAX];
	int size;
};

//菜单
void Show_menu();
//输入姓名
void input_name(Addressbook &abs, int i);
//输入性别
void input_sex(Addressbook &abs, int i);
//输入年龄
void input_age(Addressbook &abs, int i);
//输入电话
void input_number(Addressbook &abs, int i);
//输入地址
void input_addr(Addressbook &abs, int i);
//添加联系人
void add_person(Addressbook &abs);
//显示联系人
void Output_person(Addressbook &abs);
//匹配联系人
int is_persion(Addressbook &abs, string name);
//删除联系人
void delete_persion(Addressbook &abs);
//查找联系人
void find_persion(Addressbook &abs);
//修改联系人
void revise_persion(Addressbook &abs);
//清空联系人
void clear_persion(Addressbook &abs);