
#pragma  once

// 前置声明

extern Rect2D ClippingSize;		// 要裁剪的区域

void clippedWidowsInit();
bool clippedLineFromRect(Line2D & checkLine, const Rect2D & checkRect);

//=========================================================================
//
//					 Math - 数学部分
//
//=========================================================================

// 求一条直线的斜率
float getLineK(const Line2D & line);

// 与特殊直线的相交判断
std::vector<Point2D> twoLineIntersection(const Line2D & line1, const std::vector<float> & xVertical, const std::vector<float> & yLevel);