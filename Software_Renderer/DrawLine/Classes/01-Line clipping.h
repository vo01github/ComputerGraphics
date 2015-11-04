
#ifndef __DL_Line_Clipping_H__
#define __DL_Line_Clipping_H__

#include <vector>
#include "00-DataDefinition.h"
#include "00-DataInit.h"
#include <limits>

/*		本文 学习到内容

 Line clipping 画线算法

待自己实现一遍。
*/


//=========================================================================
//
//					 Line clipping algorithm - 2D直线剪切算法
//
//=========================================================================

/*
思路： 直线与矩形框有4种可能。
1：线段完全在 矩形框内
2：线段完全不在矩形框内
3：线段有一半不在矩形框内
4：线段有2部分不在矩形框内，1部分在矩形框内。

判断思路：
判断 线段 与 矩形四条边 的交点有几个。
2个交点，第4种情况。
1个交点，第3种情况。
0个交点，需要进行判断是第1种情况 还是 第2种情况。
*/

void create_widows()
{
	ClippingSize.LeftDownPoint.x = ScreenSize.x * scaleScreen * (-1.0f);
	ClippingSize.LeftDownPoint.y = ScreenSize.y * scaleScreen * (-1.0f);
	ClippingSize.RightUpPoint.x = ScreenSize.x * scaleScreen * (1.0f);
	ClippingSize.RightUpPoint.y = ScreenSize.y * scaleScreen * (1.0f);
}

//=========================================================================
//
//		特殊直线的判断： X = a, Y = b, 的特殊直线。
//
//=========================================================================

// 判断直线是否 与矩形框的 4条直线相交的点的个数
void judgeLineRect(Line2D & checkLine, const Rect2D & checkRect)
{
	// 四条特殊的直线
	float xR	=	ClippingSize.RightUpPoint.x;
	float xL	=	ClippingSize.LeftDownPoint.x;
	float yUp	=	ClippingSize.RightUpPoint.y;
	float yDown	=	ClippingSize.LeftDownPoint.y;


}


//=========================================================================
//
//					 Math - 数学部分
//
//=========================================================================
// 求一条直线的斜率
float getLineK(const Line2D & line)
{
	float dy = line.endPos.y - line.startPos.y;
	float dx = line.endPos.x - line.startPos.x;

	// 垂直时，斜率无穷大
	if (dx == 0) return std::numeric_limits<float>::infinity();		

	return  dy/dx;	// 直线的斜率
}

/*
	求特殊的直线是否相交：
	比如一条直线和一个垂直线【X=常量】是否相交，与一条水平线【Y=常量】是否相交
*/

// isX 为 true 时说明，要判断的特殊直线就是X。
std::vector<Point2D> twoLineIntersection(const Line2D & line1, const float & Xcon, const float & Ycon, bool isX)
{
	float k1 =  getLineK(line1);

	std::vector<Point2D> result;
	if (isX) { 
		float big = line1.startPos.x > line1.endPos.x ? line1.startPos.x : line1.endPos.x;
		float small = line1.startPos.x < line1.endPos.x ? line1.startPos.x : line1.endPos.x;
		if (Xcon >= big || Xcon <= small) return result;
	} else {
		float big = line1.startPos.y > line1.endPos.y ? line1.startPos.y : line1.endPos.y;
		float small = line1.startPos.y < line1.endPos.y ? line1.startPos.y : line1.endPos.y;
		if (Ycon >= big || Ycon <= small) return result;
	}

#if 0
	if (k1 == k2) return std::vector<Point2D>();	// 两条直线平行。
	result.push_back();
#endif

	return result;
}



//=========================================================================
//
//		下面写的是 通用式，完全没有 考虑到 矩形框的特殊性， X = a, Y = b, 的特殊直线。
//		所以计算起来超级复杂，已经放弃这样的使用了。
//=========================================================================

#if 0
// 判断直线是否 与矩形框相交
void judgeLineRect(Line2D & checkLine, const Rect2D & checkRect)
{
	int point_in_num = 0;
	int line_in_num = 0;
	if (judgeContinePoint(checkLine.startPos, checkRect)) ++point_in_num;
	if (judgeContinePoint(checkLine.endPos, checkRect)) ++point_in_num;

	std::vector<Point2D> line_in_rect;
	if (point_in_num == 2)	// 线段2个点都在矩形框内，第1种情况。
	{
		// 第1种情况。
		// 不需要调用 clipping 函数
	} else {
		line_in_rect = judgeLineIntersectionRect(checkLine, checkRect);
		line_in_num = line_in_rect.size();
		if (line_in_num == 0 && point_in_num == 0)	// 线段与矩形框4个边 都没有交集。
		{
			// 第2种情况。
			// 也不需要调用 clipping 函数，直接直线不用显示了。
		} else if (line_in_num == 1)
		{
			//  第3种情况。
			// 需要调用 clipping 函数
		} else if (line_in_num == 2)
		{
			//  第4种情况。
			// 需要调用 clipping 函数
			clippingLine(checkLine, line_in_rect);
		}
	}
}

void clippingLine(Line2D & checkLine, std::vector<Point2D> restult)
{
	// if restult.size()
}


// 判断点是否 在 矩形框内
bool judgeContinePoint(const Point2D & checkPoint, const Rect2D & checkRect)
{
	// 生成矩形的四个点
	const Point2D p1 = checkRect.LeftDownPoint;
	const Point2D p3 = checkRect.RightUpPoint;
	float x_min = (p1.x > p3.x ? p3.x : p1.x);
	float x_max = (p1.x < p3.x ? p3.x : p1.x);
	float y_min = (p1.y > p3.y ? p3.y : p1.y);
	float y_max = (p1.y < p3.y ? p3.y : p1.y);

	// 判断是否在矩形框内
	if (checkPoint.x < x_max && checkPoint.x > x_min &&
		checkPoint.y < y_max && checkPoint.y > y_min)
	{
		return true;
	}

	return false;
}

// 由矩形框的两点，返回四条线段.
//【这2点可以是（左下角-右上角），也可以是（左上角-右下角），只要是对角线就可以】
std::vector<Line2D> get4LineByTwoPoint(const Point2D& p1, const Point2D& p3)
{
	if (p1.x == p3.x || p1.y == p3.y) return std::vector<Line2D> ();	// 两点是垂直或者水平关系。

	const Point2D p2 = {p1.x, p3.y};
	const Point2D p4 = {p3.x, p1.y};

	const Line2D L1 = {p1, p2};
	const Line2D L2 = {p2, p3};
	const Line2D L3 = {p3, p4};
	const Line2D L4 = {p4, p1};

	std::vector<Line2D> result;
	result.push_back(L1);
	result.push_back(L2);
	result.push_back(L3);
	result.push_back(L4);

	return result;
}

// 判断线段 是否和 矩形框的四条边 有交集
// 返回 交点的集合容器
std::vector<Point2D> judgeLineIntersectionRect(const Line2D & checkLine, const Rect2D & checkRect)
{
	std::vector<Line2D> lineSet = get4LineByTwoPoint(checkRect.LeftDownPoint, checkRect.RightUpPoint);

	std::vector<Point2D> result;
	for (const auto & line : lineSet)
	{
		std::vector<Point2D> er = twoLineIntersection(line, checkLine);
		if (er.size() == 1)	// 说明有交集
		{
			result.push_back(er[0]);
		}
	}

	return result;
}

//=========================================================================
//
//					 Math - 数学部分
//
//=========================================================================




// 计算出任意角度的两个线段的交点-点斜式/一般式
/*
	这个是求任何角度的2直线是否相交，计算量太大了，实际上我们这里是在求特殊的直线是否相交：
	比如一条直线和一个垂直线【X=常量】是否相交，与一条水平线【Y=常量】是否相交
	这样想来，就可以大大减少运算量了。
*/

std::vector<Point2D> twoLineIntersection(const Line2D & line1, const Line2D & line2)
{
	float k1 =  getLineK(line1);
	float k2 =  getLineK(line2);

	
	if (k1 == k2) return std::vector<Point2D>();	// 两条直线平行。

	float x = (line2.endPos.y - line1.endPos.y + line1.endPos.x - line2.endPos.x)/(k1-k2);
	float y1 = (x - line1.endPos.x)*k1 + line1.endPos.y;
	float y2 = (x - line2.endPos.x)*k2 + line2.endPos.y;

	std::vector<Point2D> result;
	if (y1 - y2 < 0.001)		// 说明 y1 == y2
	{
		Point2D er = {x, y1};
		result.push_back(er);
	}

	return result;
}

// 利用矩阵式 计算两条直线的交点
/*

*/


// 其他判断 两直线交集的点。
Point2D twoLineIntersection1(const Line2D & line1, const Line2D & line2)
{

}

#endif

#endif // __DL_Line_Clipping_H__