#pragma once

class basicwidget
{

public:
	basicwidget(int x, int y, int w, int h);
	int width();
	int height();
	void set_fixed_size(int w, int h);
	int x();
	int y();
	void move(int x, int y);
	//virtual void show() = 0;
protected:
	int m_x;
	int m_y;
	int m_w;
	int m_h;
};

