#pragma once
#include "basicwidget.h"
class table :
    public basicwidget
{
public:
    table(int row = 0, int col = 0);
    void set_row_count(int row);
    void set_col_count(int col);

    void show();//显示菜单
    void desk_show();//显示桌子列表
private:
    int m_rows;
    int m_cols;

};

