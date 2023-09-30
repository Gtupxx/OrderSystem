#pragma once
#include"configure.h"

class window
{
public:
	window(int w, int h, int flag);
	void set_window_title(const std::string& title);
	int exec();
	static int width();
	static int height();
	static void clear();
	static void begin_draw();
	static void flush_draw();
	static void end_draw();

	static HWND my();
	//按键操作和鼠标操作
	inline static bool has_msg() { return ::peekmessage(&m_msg, EM_MOUSE | EM_KEY); }//判断是有没有消息
	inline static const ExMessage& get_msg() { return m_msg; }

private:
	inline static HWND m_handle;//窗口句柄
	inline static ExMessage m_msg;//鼠标消息和键盘消息
};

