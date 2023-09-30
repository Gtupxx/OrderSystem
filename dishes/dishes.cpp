#include "dishes.h"

int dishes::get_price()
{
	return dish_price;
}
std::string dishes::get_name()
{
	return dish_name;
}
std::string dishes::get_remark()
{
	return remark;
}
std::string dishes::get_type()
{
	return dish_type;
}
void dishes::set_single_price(int price)
{
	this->dish_price = price;
}
void dishes::set_name(const std::string& name)
{
	this->dish_name = name;
}
void dishes::set_remark(const std::string& remark)
{
	this->remark = remark;
}
void dishes::set_type(const std::string& type)
{
	this->dish_type = type;
}