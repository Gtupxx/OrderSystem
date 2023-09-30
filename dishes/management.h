#pragma once
#include"window.h"
#include<vector>
#include"pushbutton.h"
#include "table.h"
#include"dishes_list.cpp"


class management
{
	enum Operator
	{
		Admin,//管理员						1
		Guest,//客人							2
		Menu,//目录（主页面）				3


		APrev,//管理员上一页					4
		ANext,//管理员下一页				5
		Adddish,//添加菜品					6
		Deldish,//删除菜品					7
		DeskManage,//桌台管理				8

		Deskorder,//桌子的菜单				9
		Cleardesk,//清空桌子					10
		Backtoadmin,//返回管理员			11

		Dprev,//								12
		Dnext,//								13
		Backtodeskmana,//返回桌台管理		14


		GPrev,//客人上一页					15
		GNext,//客人下一页					16
		Order,//点菜							17
		Displayorder,//显示已点菜品			18
		Chosedesk,//选择桌子					19
		Pay, //结账							20

		GOprev,//								21
		GOnext,//								22
		Delorder,//删除已点菜品				23
		Backtoguest,//返回客人界面			24

		Inputdesk,//输入选择桌子				25
		Backtoguest1,//返回客人界面			26



	};
public:
	management();
	int menu();
	void run();//启动管理类
	int admin();//0管理员界面
	int guest();//1客人界面

	void next();//翻页按钮的制作
	void prev();

	int adddish();//管理员三个功能
	int deldish();
	int deskmanage();

	int deskorder();//桌台管理两个功能
	int cleardesk();

	void dprev();
	void dnext();
	//backtodeskmana


	int order();//客人五个功能
	int delorder();
	int chose_desk();
	int displayorder();
	int pay();

	void inputdesk();

	void draw_backgrond();
	void eventloop();
private:
	IMAGE m_bk;
	IMAGE m_pay;
	ExMessage m_msg;

	std::vector<pushbutton*> menu_btns;
	std::vector<pushbutton*> admin_btns;
	std::vector<pushbutton*> guest_btns;
	std::vector<pushbutton*> deskmanage_btns;
	std::vector<pushbutton*> deskorder_btns;
	std::vector<pushbutton*> guestorder_btns;
	std::vector<pushbutton*> guestdesk_btns;
private://查看菜单
	table* m_show_table;
	dishes_list total_list;

	dishes_list desk_list[10];
private:
	int payflag = 0;
	int current_page = 1;
	int order_page = 1;

private:
	int desk[10];
	int current_desk = 0;
private:
	int todaymoney = 0;

private:
	int count = 0;

};

