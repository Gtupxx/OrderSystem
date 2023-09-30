#include "pushbutton.h"

pushbutton::pushbutton(const std::string& text, int x, int y, int w, int h)
	:basicwidget(x,y,w,h),m_text(text)
{

}

void pushbutton::show()
{
	setfillcolor(current_corlor);
	::fillroundrect(m_x, m_y, m_x + m_w, m_y + m_h, 10, 10);

	settextcolor(BLACK);
	int tx = m_x + (m_w - textwidth(m_text.c_str())) / 2;
	int ty = m_y + (m_h - textheight(m_text.c_str())) / 2;
	::outtextxy(tx, ty, m_text.c_str());
	//进行一个按钮文字的居中显示
}

bool pushbutton::isin()
{
	if (m_msg.x >= m_x && m_msg.x < m_x + m_w && m_msg.y >= m_y && m_msg.y <= m_y + m_h)
	{
		return true;
	}
	return false;
}

bool pushbutton::isclicked()
{
	if (isin())
	{
		if (m_msg.message == WM_LBUTTONDOWN)
		{
			return true;
		}
	}
	return false;
}

void pushbutton::eventloop(const ExMessage& msg)
{
	m_msg = msg;
	if (!isin())
	{
		current_corlor = normal_corlor;
	}
	else
	{
		current_corlor = hover_corlor;
	}
}
