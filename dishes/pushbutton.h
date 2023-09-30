#pragma once
#include "basicwidget.h"
#include"configure.h"

class pushbutton :
	public basicwidget
{
public:
	pushbutton(const std::string& text = "Button", int x = 0, int y = 0, int w = 100, int h = 30);
	void show();
	bool isin();//判断鼠标是否在按钮上
	bool isclicked();//判断是否被点击
	void eventloop(const ExMessage& msg);
private:
	COLORREF normal_corlor = RGB(241, 222, 190);
	COLORREF current_corlor = RGB(241, 222, 190);
	COLORREF hover_corlor = RGB(147, 199, 255);
private:
	std::string m_text;
	ExMessage m_msg;
};

