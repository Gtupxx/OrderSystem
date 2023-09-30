#include "basicwidget.h"

basicwidget::basicwidget(int x, int y, int w, int h)
    :m_x(x),m_y(y),m_w(w),m_h(h)
{

}

int basicwidget::width()
{
    return m_w;
}

int basicwidget::height()
{
    return m_h;
}

void basicwidget::set_fixed_size(int w, int h)
{
    this->m_w = w;
    this->m_h = h;
}

int basicwidget::x()
{
    return m_x;
}

int basicwidget::y()
{
    return m_y;
}

void basicwidget::move(int x, int y)
{
    this->m_x = x;
    this->m_y = y;
}
