#include "management.h"
#include<graphics.h>
#include<conio.h>
#include<iostream>
#include"pushbutton.h"
using namespace std;

management::management()
{
	::loadimage(&m_bk, "./image/bk.png", window::width(), window::height());
	::loadimage(&m_pay, "./image/pay.png", 372, 508);
	//主界面按钮初始化
	menu_btns.push_back(new pushbutton("管理员"));
	menu_btns.push_back(new pushbutton("干饭人"));
	for (int i = 0; i < menu_btns.size(); i++)
	{
		menu_btns[i]->set_fixed_size(250, 50);

		int bx = (window::width() - menu_btns[i]->width()) / 2;
		int by = 300 + i * menu_btns[i]->height();

		menu_btns[i]->move(bx, by);

	}


	//管理员界面按钮初始化
	admin_btns.push_back(new pushbutton("上一页"));
	admin_btns.push_back(new pushbutton("下一页"));
	admin_btns.push_back(new pushbutton("添加菜品"));
	admin_btns.push_back(new pushbutton("删除菜品"));
	admin_btns.push_back(new pushbutton("桌台管理"));
	for (int i = 0; i < admin_btns.size(); i++)
	{
		admin_btns[i]->set_fixed_size(150, 50);

		int bx = 50;
		int by = 150 + i * admin_btns[i]->height();

		admin_btns[i]->move(bx, by);

	}
	//桌台管理页面按钮初始化
	deskmanage_btns.push_back(new pushbutton("查看菜单"));
	deskmanage_btns.push_back(new pushbutton("清空桌子"));
	deskmanage_btns.push_back(new pushbutton("返回"));
	for (int i = 0; i < deskmanage_btns.size(); i++)
	{
		deskmanage_btns[i]->set_fixed_size(150, 50);

		int bx = 50;
		int by = 150 + i * deskmanage_btns[i]->height();

		deskmanage_btns[i]->move(bx, by);

	}

	//桌子菜单管理页面按钮初始化
	deskorder_btns.push_back(new pushbutton("上一页"));
	deskorder_btns.push_back(new pushbutton("下一页"));
	deskorder_btns.push_back(new pushbutton("返回"));
	for (int i = 0; i < deskorder_btns.size(); i++)
	{
		deskorder_btns[i]->set_fixed_size(150, 50);

		int bx = 50;
		int by = 150 + i * deskorder_btns[i]->height();

		deskorder_btns[i]->move(bx, by);

	}

	//客人界面按钮初始化
	guest_btns.push_back(new pushbutton("上一页"));
	guest_btns.push_back(new pushbutton("下一页"));
	guest_btns.push_back(new pushbutton("点菜"));
	guest_btns.push_back(new pushbutton("查看已点菜品"));
	guest_btns.push_back(new pushbutton("选择桌子"));
	guest_btns.push_back(new pushbutton("结账"));
	for (int i = 0; i < guest_btns.size(); i++)
	{
		guest_btns[i]->set_fixed_size(150, 50);

		int bx = 50;
		int by = 150 + i * guest_btns[i]->height();

		guest_btns[i]->move(bx, by);

	}
	//客人查看已点菜单界面按钮初始化
	guestorder_btns.push_back(new pushbutton("上一页"));
	guestorder_btns.push_back(new pushbutton("下一页"));
	guestorder_btns.push_back(new pushbutton("删除菜品"));
	guestorder_btns.push_back(new pushbutton("返回"));
	for (int i = 0; i < guestorder_btns.size(); i++)
	{
		guestorder_btns[i]->set_fixed_size(150, 50);

		int bx = 50;
		int by = 150 + i * guestorder_btns[i]->height();

		guestorder_btns[i]->move(bx, by);

	}

	//客人选择桌子界面按钮初始化
	guestdesk_btns.push_back(new pushbutton("选择桌子"));
	guestdesk_btns.push_back(new pushbutton("返回"));

	for (int i = 0; i < guestdesk_btns.size(); i++)
	{
		guestdesk_btns[i]->set_fixed_size(150, 50);

		int bx = 50;
		int by = 150 + i * guestdesk_btns[i]->height();

		guestdesk_btns[i]->move(bx, by);

	}
	//菜单表格的初始化
	m_show_table = new table;
	m_show_table->set_row_count(16);
	m_show_table->set_col_count(3);

	//菜单列表数据的初始化
	total_list = *load_dish_list();
}
int management::menu()
{
	//显示按钮

	for (int i = 0; i < menu_btns.size(); i++)
	{
		menu_btns[i]->show();
		menu_btns[i]->eventloop(m_msg);
		if (menu_btns[i]->isclicked())
		{
			return i;
		}
	}
	//根据按钮的点击返回操作
	return Menu;
}

void management::run()
{

	int op = Menu;//获取菜单按钮的返回值
	window::begin_draw();
	while (true)
	{
		count++;
		if (count == 1000)
		{
			count = 0;
			cout << '*' << endl;
		}


		window::clear();
		draw_backgrond();
		eventloop();
		if (window::has_msg())
		{
			m_msg = window::get_msg();
			switch (m_msg.message)
			{
			case WM_KEYDOWN:
				//esc返回主界面
				if (m_msg.vkcode == VK_ESCAPE)
					op = Menu;
				break;
			default://鼠标操作

				break;

			}

		}
		switch (op)
		{
		case management::Menu:
			op = menu();//目录
			payflag = 0;
			current_desk = 0;
			break;
		case management::Admin:
			op = admin();//管理员
			current_desk = 0;
			break;
		case management::Guest:
			op = guest();//客人
			break;

		case management::APrev:
			prev();//管理员菜单上一页按钮
			op = admin();
			break;
		case management::ANext:
			next();//管理员菜单下一页按钮
			op = admin();
			break;
		case management::Adddish:
			op = adddish();//管理员添加菜品
			break;
		case management::Deldish:
			op = deldish();//管理员删除菜品
			break;
		case management::DeskManage:
			op = deskmanage();//管理员桌台管理
			break;

		case management::Deskorder:
			op = deskorder();//桌台管理显示桌子菜单
			break;
		case management::Cleardesk:
			op = cleardesk();//桌台管理清除桌子
			break;
		case management::Backtoadmin:
			op = Admin;//返回到管理员界面
			Sleep(200);
			break;

		case management::Dprev:
			dprev();//桌子菜单上一页按钮
			op = Deskorder;
			break;
		case management::Dnext:
			dnext();//桌子菜单下一页按钮
			op = Deskorder;
			break;
		case management::Backtodeskmana:
			op = DeskManage;//返回到桌台管理页面
			order_page = 1;
			current_desk = 0;
			Sleep(200);
			break;

		case management::GPrev:
			prev();//客人菜单上一页按钮
			op = guest();
			break;
		case management::GNext:
			next();//客人菜单下一页按钮
			op = guest();
			break;
		case management::Order:
			op = order();//客人点菜
			break;
		case management::Displayorder:
			op = displayorder();
			break;
		case management::Chosedesk:
			op = chose_desk();
			break;
		case management::Pay:
			op = pay();
			break;

		case management::GOprev:
			dprev();
			op = Displayorder;
			break;
		case management::GOnext:
			dnext();
			op = Displayorder;
			break;
		case management::Delorder:
			op = delorder();//客人显示菜品删除菜品
			break;
		case management::Backtoguest:

			op = Guest;//客人显示菜品返回到客人界面
			Sleep(200);

			break;


		case management::Inputdesk:
			inputdesk();
			op = Chosedesk;
			break;
		case management::Backtoguest1:
			op = Guest;//客人选择桌子返回到客人界面
			Sleep(200);
			break;

		default:
			break;
		}
		window::flush_draw();

	}
	window::end_draw();
}

int management::admin()
{
	::outtextxy(0, 0, "今日流水：           元");
	::outtextxy(75, 0, to_string(todaymoney).c_str());
	//显示按钮
	for (int i = 0; i < admin_btns.size(); i++)
	{
		admin_btns[i]->show();
		admin_btns[i]->eventloop(m_msg);
		if (admin_btns[i]->isclicked())
		{
			Sleep(200);//停止200ms，防止翻页翻过头
			return i + 3;
		}
	}
	//cout << "admin" << endl;
	//显示页码
	::outtextxy(300 + 2 * ((window::width() - 100 - 300) / 3)
		+ ((window::width() - 100 - 300) / 3 - textwidth("第        页"))
		, 50 - textheight("第        页"), "第        页");
	string num = to_string(current_page);
	::outtextxy(300 + 2 * ((window::width() - 100 - 300) / 3) + 30
		+ ((window::width() - 100 - 300) / 3 - textwidth("第        页"))
		, 50 - textheight("第        页"), num.c_str());
	m_show_table->show();//显示表格
	display_dish_list(&total_list, current_page);//显示表格内的数据
	return Admin;
}

int management::guest()
{


	//显示按钮
	for (int i = 0; i < guest_btns.size(); i++)
	{
		guest_btns[i]->show();
		guest_btns[i]->eventloop(m_msg);
		if (guest_btns[i]->isclicked())
		{
			Sleep(200);//停止200ms，防止翻页翻过头
			return i + 14;
		}
	}
	// cout << "guest" << endl;
	 //显示页码
	::outtextxy(300 + 2 * ((window::width() - 100 - 300) / 3)
		+ ((window::width() - 100 - 300) / 3 - textwidth("第        页"))
		, 50 - textheight("第        页"), "第        页");
	string num = to_string(current_page);
	::outtextxy(300 + 2 * ((window::width() - 100 - 300) / 3) + 30
		+ ((window::width() - 100 - 300) / 3 - textwidth("第        页"))
		, 50 - textheight("第        页"), num.c_str());
	m_show_table->show();//绘制表格
	display_dish_list(&total_list, current_page);//打印表格数据
	return Guest;
}

void management::next()
{
	if (current_page < get_size(&total_list) / 15 + 1)
		current_page++;
}

void management::prev()
{
	if (current_page > 1)
		current_page--;
}

int management::adddish()
{
	dishes newdish;
	char name[10];
	char charprice[10];
	char type[10];
	int price = 0;
	InputBox(name, 10, "请输入菜品名称\n请不要输入空格等特殊字符！");
	InputBox(charprice, 10, "请输入菜品价格\n请不要输入空格等特殊字符！");
	InputBox(type, 10, "请输入菜品类型\n请不要输入空格等特殊字符！");
	if (name[0] == '\0' && type[0] == '\0')
	{
		MessageBox(window::my(), "添加失败，请检查输入！", NULL, MB_OK | MB_ICONHAND);
		return Admin;
	}
	else
	{
		MessageBox(window::my(), "添加成功！", NULL, MB_OK | MB_ICONASTERISK);
	}
	for (int i = 0; charprice[i] != '\0'; i++)
	{
		price *= 10;
		price += charprice[i] - '0';
	}//将字符串类型的价格转为整形
	add_dish(name, price, type);
	total_list = *load_dish_list();//添加完成后刷新列表
	return Admin;
}

int management::deldish()
{
	char charnum[10];
	InputBox(charnum, 10, "请输入要删除的菜品序号");
	int num = 0;

	for (int i = 0; charnum[i] != '\0'; i++)
	{
		num *= 10;
		num += charnum[i] - '0';
	}//将字符串类型转为整形
	if (num > get_size(&total_list))
	{
		MessageBox(window::my(), "删除失败，请检查输入！", NULL, MB_OK | MB_ICONHAND);
		return Admin;
	}
	else
	{
		MessageBox(window::my(), "删除成功！", NULL, MB_OK | MB_ICONASTERISK);
	}
	del_dish(&total_list, num);
	Sleep(100);
	save_dish_list(&total_list);
	total_list = *load_dish_list();
	/*total_list = *del_dish(&total_list, num);
	save_dish_list(&total_list);*/
	return Admin;
}

int management::deskmanage()
{
	//显示按钮

	for (int i = 0; i < deskmanage_btns.size(); i++)
	{
		deskmanage_btns[i]->show();
		deskmanage_btns[i]->eventloop(m_msg);
		if (deskmanage_btns[i]->isclicked())
		{
			return i + 8;
		}
	}

	m_show_table->desk_show();//显示桌子表格

	for (int i = 0; i < 10; i++)
	{
		string num = to_string(i + 1);
		::outtextxy(270 + ((window::width() - 100 - 300) / 2 - textwidth("号桌子")) / 2
			, 50 + i * 48 + (48 - textheight("号桌子")) / 2, "号桌子");
		::outtextxy(230 + ((window::width() - 100 - 300) / 2 - textwidth(num.c_str())) / 2
			, 50 + i * 48 + (48 - textheight(num.c_str())) / 2, num.c_str());//打印桌子号

		if (desk[i])
		{
			::outtextxy(280 + ((window::width() - 100 - 300) / 2 - textwidth("有人")) / 2
				+ (window::width() - 100 - 300) / 2
				, 50 + i * 48 + (48 - textheight("有人")) / 2, "有人");
		}
		else
		{
			::outtextxy(280 + ((window::width() - 100 - 300) / 2 - textwidth("无人")) / 2
				+ (window::width() - 100 - 300) / 2
				, 50 + i * 48 + (48 - textheight("无人")) / 2, "无人");
		}
	}//显示桌子信息

	return DeskManage;
}

int management::deskorder()
{
	//显示按钮

	for (int i = 0; i < deskorder_btns.size(); i++)
	{
		deskorder_btns[i]->show();
		deskorder_btns[i]->eventloop(m_msg);
		if (deskorder_btns[i]->isclicked())
		{
			Sleep(100);
			return i + 11;
		}
	}
	m_show_table->show();

	char charnum[10];

	if (!current_desk)
	{
		InputBox(charnum, 10, "请输入要查看的桌子序号");
		for (int i = 0; charnum[i] != '\0'; i++)
		{
			current_desk = 0;
			current_desk *= 10;
			current_desk += charnum[i] - '0';
		}//将字符串类型的价格转为整形
		if (desk[current_desk - 1] == 0)
		{
			MessageBox(window::my(), "该桌子无人！", NULL, MB_OK | MB_ICONHAND);
			current_desk = 0;
			return DeskManage;
		}
		if (current_desk - 1 >= 10)
		{
			MessageBox(window::my(), "无效的桌子序号！！", NULL, MB_OK | MB_ICONHAND);
			current_desk = 0;
			return DeskManage;
		}
	}
	//显示页码
	::outtextxy(300 + 2 * ((window::width() - 100 - 300) / 3)
		+ ((window::width() - 100 - 300) / 3 - textwidth("第        页"))
		, 50 - textheight("第        页"), "第        页");
	string num = to_string(order_page);
	::outtextxy(300 + 2 * ((window::width() - 100 - 300) / 3) + 30
		+ ((window::width() - 100 - 300) / 3 - textwidth("第        页"))
		, 50 - textheight("第        页"), num.c_str());
	display_dish_list(&desk_list[current_desk - 1], order_page);
	//display_dish_list(&total_list, order_page);

	return Deskorder;
}

int management::cleardesk()
{
	char charnum[10];
	InputBox(charnum, 10, "请输入要清空的桌子序号");
	for (int i = 0; charnum[i] != '\0'; i++)
	{
		current_desk = 0;
		current_desk *= 10;
		current_desk += charnum[i] - '0';
	}//将字符串类型的价格转为整形
	desk[current_desk - 1] = 0;
	if (current_desk - 1 >= 10)
	{
		MessageBox(window::my(), "无效的桌子序号！！", NULL, MB_OK | MB_ICONHAND);
		current_desk = 0;
		return DeskManage;
	}
	desk_list[current_desk - 1] = *new struct dishes_list;
	MessageBox(window::my(), "已清空该桌子", NULL, MB_OK | MB_ICONASTERISK);
	return DeskManage;
}

void management::dprev()
{
	if (order_page > 1)
		order_page--;
}

void management::dnext()
{
	if (order_page < 3)
		order_page++;
}

int management::order()
{
	//显示按钮

	for (int i = 0; i < guestorder_btns.size(); i++)
	{
		guestorder_btns[i]->show();
		guestorder_btns[i]->eventloop(m_msg);
		if (guestorder_btns[i]->isclicked())
		{
			return i + 20;
		}
	}
	m_show_table->show();
	display_dish_list(&total_list, current_page);
	if (current_desk == 0)
	{
		MessageBox(window::my(), "请先选择就餐的桌子！", NULL, MB_OK | MB_ICONHAND);
		return Guest;
	}
	char charnum[10];
	InputBox(charnum, 10, "请输入要点的菜品序号");
	int num = 0;

	for (int i = 0; charnum[i] != '\0'; i++)
	{
		num *= 10;
		num += charnum[i] - '0';
	}//将字符串类型转为整形
	if (num > get_size(&total_list))
	{
		MessageBox(window::my(), "点菜失败，请检查输入！", NULL, MB_OK | MB_ICONHAND);
		return Guest;
	}

	struct dishes_list* from = &total_list;

	struct dishes_list* temp, * tail;
	tail = new struct dishes_list;
	temp = new struct dishes_list;
	temp->next = nullptr;
	tail = &desk_list[current_desk - 1];
	std::string temp_name;
	std::string temp_type;
	int temp_price;
	while (tail->next != nullptr)
	{
		tail = tail->next;
	}
	for (int i = 0; i < num; i++)
	{
		from = from->next;
	}
	temp_name = from->data.get_name();
	temp_price = from->data.get_price();
	temp_type = from->data.get_type();
	temp->data.set_name(temp_name);
	temp->data.set_single_price(temp_price);
	temp->data.set_type(temp_type);
	temp->next = nullptr;
	tail->next = temp;
	tail = tail->next;
	temp = new struct dishes_list;
	tail = new struct dishes_list;


	return Guest;
}

int management::delorder()
{
	char charnum[10];
	InputBox(charnum, 10, "请输入要删除的菜品序号");
	int num = 0;

	for (int i = 0; charnum[i] != '\0'; i++)
	{
		num *= 10;
		num += charnum[i] - '0';
	}//将字符串类型转为整形
	if (num > get_size(&desk_list[current_desk - 1]))
	{
		MessageBox(window::my(), "删除失败，请检查输入！", NULL, MB_OK | MB_ICONHAND);
		return Guest;
	}
	else
	{
		MessageBox(window::my(), "删除成功！", NULL, MB_OK | MB_ICONASTERISK);
	}
	del_dish(&desk_list[current_desk - 1], num);
	return Displayorder;
}

int management::chose_desk()
{
	//显示按钮

	for (int i = 0; i < guestdesk_btns.size(); i++)
	{
		guestdesk_btns[i]->show();
		guestdesk_btns[i]->eventloop(m_msg);
		if (guestdesk_btns[i]->isclicked())
		{
			return i + 24;
		}
	}
	m_show_table->desk_show();//显示桌子表格

	for (int i = 0; i < 10; i++)
	{
		string num = to_string(i + 1);
		::outtextxy(270 + ((window::width() - 100 - 300) / 2 - textwidth("号桌子")) / 2
			, 50 + i * 48 + (48 - textheight("号桌子")) / 2, "号桌子");
		::outtextxy(230 + ((window::width() - 100 - 300) / 2 - textwidth(num.c_str())) / 2
			, 50 + i * 48 + (48 - textheight(num.c_str())) / 2, num.c_str());//打印桌子号

		if (desk[i])
		{
			::outtextxy(280 + ((window::width() - 100 - 300) / 2 - textwidth("有人")) / 2
				+ (window::width() - 100 - 300) / 2
				, 50 + i * 48 + (48 - textheight("有人")) / 2, "有人");
		}
		else
		{
			::outtextxy(280 + ((window::width() - 100 - 300) / 2 - textwidth("无人")) / 2
				+ (window::width() - 100 - 300) / 2
				, 50 + i * 48 + (48 - textheight("无人")) / 2, "无人");
		}
	}//显示桌子信息

	return Chosedesk;
}

int management::displayorder()
{

	//显示按钮
	for (int i = 0; i < guestorder_btns.size(); i++)
	{
		guestorder_btns[i]->show();
		guestorder_btns[i]->eventloop(m_msg);
		if (guestorder_btns[i]->isclicked())
		{
			Sleep(200);//停止200ms，防止翻页翻过头
			return i + 20;
		}
	}
	::outtextxy(300 + 2 * ((window::width() - 100 - 300) / 3)
		+ ((window::width() - 100 - 300) / 3 - textwidth("第        页"))
		, 50 - textheight("第        页"), "第        页");
	string num = to_string(order_page);
	::outtextxy(300 + 2 * ((window::width() - 100 - 300) / 3) + 30
		+ ((window::width() - 100 - 300) / 3 - textwidth("第        页"))
		, 50 - textheight("第        页"), num.c_str());
	m_show_table->show();//显示表格
	if (current_desk == 0)
	{
		MessageBox(window::my(), "请先选择就餐的桌子！", NULL, MB_OK | MB_ICONHAND);
		return Guest;
	}
	display_dish_list(&desk_list[current_desk - 1], order_page);//显示表格内的数据

	return Displayorder;
}

int management::pay()
{
	if (current_desk == 0)
	{
		MessageBox(window::my(), "请先选择就餐的桌子！", NULL, MB_OK | MB_ICONHAND);
		return Guest;
	}
	int money = 0;
	struct dishes_list* temp;
	temp = &desk_list[current_desk - 1];
	while (temp != nullptr)
	{
		money += temp->data.get_price();
		temp = temp->next;
	}

	::putimage(294, 50, &m_pay);
	::outtextxy(294 + (372 - textwidth("本次一共消费：         元")) / 2, 420, "本次一共消费:          元");
	::outtextxy(294 + (372 - textwidth("本次一共消费：         元")) / 2, 450, "(按下esc键退出)");
	::outtextxy(505, 420, to_string(money).c_str());
	if (!payflag)
	{
		todaymoney += money;
		payflag = 1;
	}


	return Pay;
}

void management::inputdesk()
{
	char charnum[10];
	if (current_desk)
	{
		MessageBox(window::my(), "请勿重复选择！\n如需更改请与管理员联系！", NULL, MB_OK | MB_ICONHAND);
		Sleep(200);
	}
	if (!current_desk)
	{
		InputBox(charnum, 10, "请输入要选择的桌子序号");
		for (int i = 0; charnum[i] != '\0'; i++)
		{
			current_desk *= 10;
			current_desk += charnum[i] - '0';
		}//将字符串类型转为整形
		if (desk[current_desk - 1] == 1)
		{
			MessageBox(window::my(), "该桌子有人！", NULL, MB_OK | MB_ICONHAND);
			current_desk = 0;
			return;
		}
		if (current_desk - 1 >= 10)
		{
			MessageBox(window::my(), "无效的桌子序号！！", NULL, MB_OK | MB_ICONHAND);
			current_desk = 0;
			return;
		}

		desk[current_desk - 1] = 1;
	}
}

void management::draw_backgrond()
{
	::putimage(0, 0, &m_bk);
}

void management::eventloop()
{
	//m_show_table->show();
}
