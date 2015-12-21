#pragma  once

#include <vector>

// 用来测试画线函数 和 剪切直线 函数的
void myDisplay_Draw_Triangle_On_Windows_function(std::vector<Point2D_int> draw2DPointSet);  

// 画线函数的接口
void drawTriangle(const Triangle2D & triangle, bool isSolid, std::vector<Point2D_int> & drawPointSet);