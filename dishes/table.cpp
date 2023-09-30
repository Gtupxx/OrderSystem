#include "table.h"
#include"configure.h"
#include"window.h"
table::table(int row, int col)
	:basicwidget(300, 50, 0, 0)
	, m_rows(row)
	, m_cols(col)
{

}

void table::set_row_count(int row)
{
	m_rows = row;
}

void table::set_col_count(int col)
{
	m_cols = col;
}

void table::show()
{
	//确定表格的行数与列数
	//绘制表格背景
	setfillcolor(RGB(246, 255, 228));
	fillroundrect(m_x - 50, m_y, window::width() - 100, 50 + (m_rows) * 30, 10, 10);
	setlinecolor(BLACK);


	//绘制横线部分
	for (int i = 0; i < m_rows + 1; i++)
	{
		line(m_x - 50, m_y + i * 30, window::width() - 100, m_y + i * 30);
	}
	//绘制竖线部分
	for (int i = 0; i < m_cols + 1; i++)
	{
		line(m_x + i * (window::width() - 100 - 300) / 3
			, m_y
			, m_x + i * (window::width() - 100 - 300) / 3
			, 50 + (m_rows) * 30);
	}
	//打印序号表头
	::outtextxy(m_x - 50 + (50 - textwidth("序号")) / 2
		, m_y + (30 - textheight("序号")) / 2, "序号");
	//打印表头
	std::string head[4] = { "菜名","价格","类型" };
	for (int i = 0; i < 4; i++)
	{
		::outtextxy(m_x + i * (window::width() - 100 - 300) / 3
			+ ((window::width() - 100 - 300) / 3 - textwidth(head[i].c_str())) / 2
			, m_y + (30 - textheight(head[i].c_str())) / 2
			, head[i].c_str());
	}

}

void table::desk_show()
{
	//确定表格的行数与列数
	//绘制表格背景
	setfillcolor(RGB(246, 255, 228));
	fillroundrect(m_x - 50, m_y, window::width() - 100, 50 + (m_rows) * 30, 10, 10);
	setlinecolor(BLACK);

	for (int i = 0; i < 11; i++)
	{
		line(m_x - 50, m_y + i * 48, window::width() - 100, m_y + i * 48);//横线部分
	}
	line((m_x - 50 + window::width() - 100) / 2, m_y
		, (m_x - 50 + window::width() - 100) / 2, m_y + 480);
}
