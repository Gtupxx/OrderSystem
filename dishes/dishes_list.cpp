#include"dishes.h"
#include <iostream>
#include <fstream>
#include"configure.h"
#include"window.h"

using namespace std;
static struct dishes_list
{
	dishes data;
	struct dishes_list* next = nullptr;
};
static int get_size(struct dishes_list* list)
{
	int i;
	for (i = 0; list->next != nullptr; i++)
	{
		list = list->next;
	}
	return i - 1;
}
static struct dishes_list* load_dish_list()//从文件中读取已有的菜单，尾插法并返回头指针
{
	struct dishes_list* temp, * head, * tail;
	tail = new struct dishes_list;
	temp = new struct dishes_list;
	temp->next = nullptr;
	head = new struct dishes_list;
	tail = head;
	ifstream file("file.txt", ios::in);//以读取模式打开文件
	if (!file.is_open())//判断文件是否正常打开
	{
		cout << "打开失败";
		return head;
	}
	std::string temp_name;
	std::string temp_type;
	int temp_price;
	while (!file.eof())//判断文件没有达到末尾
	{
		file >> temp_name >> temp_price >> temp_type;//读取名字和单价
		temp->data.set_name(temp_name);
		temp->data.set_single_price(temp_price);
		temp->data.set_type(temp_type);
		tail->next = temp;
		tail = tail->next;
		temp = new struct dishes_list;
	}
	return head;
}
static void del_dish(struct dishes_list* list, int num)
{
	if (num > get_size(list))
		return;
	struct dishes_list* temp = new struct dishes_list;
	temp = list;
	for (int i = 0; i < num - 1; i++)
	{
		temp = temp->next;
	}
	temp->next = temp->next->next;
}
static void save_dish_list(struct dishes_list* list)//将菜单保存到文件中
{
	ofstream file("file.txt", ios::trunc);//打开file.txt
	if (!file.is_open())//判断文件是否正常打开
	{
		cout << "打开失败";
		return;
	}
	struct dishes_list* temp = new struct dishes_list;
	temp = list->next;
	while (temp->next != nullptr)
	{
		file << temp->data.get_name() << '\t';
		file << temp->data.get_price() << '\t';
		file << temp->data.get_type() << endl;//将数据保存到file中
		temp = temp->next;
	}
}
static void display_dish_list(struct dishes_list* list, int page)
{
	struct dishes_list* temp;
	temp = list->next;
	int i = 0;
	if (temp == nullptr)
		return;
	for (int j = 0; j < (page - 1) * 15; j++)
	{
		if (temp != nullptr)
			temp = temp->next;
		else return;
	}//定位到当前页码对应的开头
	while (temp != nullptr && i < 15)
	{

		string num = to_string((page - 1) * 15 + i + 1);//将序号转为字符串格式，方便打印
		::outtextxy(250 + (50 - textwidth(num.c_str())) / 2
			, 15 + 50 + (30 - textheight(temp->data.get_name().c_str()) / 2) + i * 30
			, num.c_str());

		::outtextxy(300 + ((window::width() - 100 - 300) / 3 - textwidth(temp->data.get_name().c_str())) / 2
			, 15 + 50 + (30 - textheight(temp->data.get_name().c_str()) / 2) + i * 30
			, temp->data.get_name().c_str());//打印菜名

		string temp_price = to_string(temp->data.get_price());//将价格保存为字符串方便后续输出
		::outtextxy(300 + ((window::width() - 100 - 300) / 3 - textwidth(temp_price.c_str())) / 2
			+ (window::width() - 100 - 300) / 3
			, 15 + 50 + (30 - textheight(temp->data.get_name().c_str()) / 2) + i * 30
			, temp_price.c_str());//打印价格

		::outtextxy(300 + ((window::width() - 100 - 300) / 3 - textwidth(temp->data.get_type().c_str())) / 2
			+ 2 * (window::width() - 100 - 300) / 3
			, 15 + 50 + (30 - textheight(temp->data.get_name().c_str()) / 2) + i * 30
			, temp->data.get_type().c_str());//打印菜品类型
		//cout << temp->data.get_name() << '\t' << temp->data.get_price();
		//cout <<'\t' << temp->data.get_type() << endl;
		temp = temp->next;
		i++;
	}
}
static void add_dish(const std::string& new_name = "dish_name", int new_price = 100, const std::string& type = "主食")//添加菜品，尾插法
{
	ofstream file("file.txt", ios::out | ios::app);//打开file.txt
	if (!file.is_open())//判断文件是否正常打开
	{
		cout << "打开失败";
		return;
	}
	file << new_name << '\t';
	file << new_price << '\t';
	file << type << endl;//将数据保存到file中
}
static int search_dish(struct dishes_list* list, const std::string& name)//寻找指定的菜名，返回序号
{
	int i = 0;
	struct dishes_list* temp = new struct dishes_list;
	temp = list->next;
	while (temp != nullptr)
	{
		if (temp->data.get_name() == name)
			return i;
		temp = temp->next;
		i++;
	}
	cout << "Did Not Found!";
	return -1;//失败返回-1
}