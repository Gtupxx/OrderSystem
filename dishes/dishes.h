#pragma once
#include <string>

class dishes//定义一个菜品类
{
protected:
	std::string dish_name;//菜名
	int dish_price;//菜品的单价
	std::string remark;//点菜时的备注
	std::string dish_type;//菜品的种类
public:
	//构造函数
	dishes(const std::string& name = "Dish name", int price = 0, const std::string& type = "热菜")
	{
		dish_name = name;
		dish_price = price;
		dish_type = type;
	}
	//过于简单，不做注释
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
