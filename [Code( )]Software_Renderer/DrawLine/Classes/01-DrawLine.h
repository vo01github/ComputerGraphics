#pragma  once

#include <vector>

// 用来测试画线函数 和 剪切直线 函数的
void myDisplay_Draw_Line_On_Windows_function(std::vector<Point2D_int> draw2DPointSet);

// 画线函数的接口
void drawLine(const Line2D & line, std::vector<Point2D_int> & drawPointSet);