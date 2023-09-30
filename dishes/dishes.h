#pragma once
#include <string>

class dishes//����һ����Ʒ��
{
protected:
	std::string dish_name;//����
	int dish_price;//��Ʒ�ĵ���
	std::string remark;//���ʱ�ı�ע
	std::string dish_type;//��Ʒ������
public:
	//���캯��
	dishes(const std::string& name = "Dish name", int price = 0, const std::string& type = "�Ȳ�")
	{
		dish_name = name;
		dish_price = price;
		dish_type = type;
	}
	//���ڼ򵥣�����ע��
	int get_price();
	std::string get_name();
	std::string get_remark();
	std::string get_type();
	void set_single_price(int price);
	void set_name(const std::string& name);
	void set_remark(const std::string& remark);
	void set_type(const std::string& type);
	int get_total_price();
};
