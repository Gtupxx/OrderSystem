#include "window.h"

window::window(int w, int h, int flag)
{
	m_handle = ::initgraph(w, h);
	::setbkmode(TRANSPARENT);
}

void window::set_window_title(const std::string& title)
{
	::SetWindowText(m_handle, title.c_str());
}

int window::exec()
{
	return 0;
}

int window::width()
{
	return ::getwidth();
}

int window::height()
{
	return ::getheight();
}

void window::clear()
{
	::cleardevice();
}

void window::begin_draw()
{
	::BeginBatchDraw();
}

void window::flush_draw()
{
	::FlushBatchDraw();
}

void window::end_draw()
{
	::EndBatchDraw();
}

HWND window::my()
{
	return m_handle;
}
