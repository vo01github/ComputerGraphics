
#ifndef __DL_Bresenham_Line_Algorithm_H__
#define __DL_Bresenham_Line_Algorithm_H__


#include <vector>
#include "00-DataDefinition.h"

/*		本文 学习到内容

Bresenham 画线算法

*/

//=========================================================================
//
//					 Bresenham's line algorithm - 布雷森汉姆直线算法
//
//=========================================================================

// 第1版

// 第一个参数是要画的直线， 第2个参数 接收 画这条线 所需要的 点的集合。
void creat_Line_Point_Set(const Line2D & drawLine, std::vector<Point2D> &pointSet)
{
	float dy = drawLine.endPos.y - drawLine.startPos.y;
	float dx = drawLine.endPos.x - drawLine.startPos.x;
	float k = dy/dx;	// 直线的斜率

	Point2D frontP = drawLine.startPos;		// 前一个点
	Point2D backP;							// 下一个点

	// X方向每前进一个单位时，Y方向就相应的判断 是+1还是+0个单位。
	for (float addy = 0; addy < dy; addy += k) {	//增量y
		
		backP = frontP;
		backP.x += 1;

		// 判断 Y方向是 +1 还是 +0 个单位
		if (addy - frontP.y > 0.5f)
		{
			backP.y += 1;
		}

		// 把点压入集合中
		pointSet.push_back(backP);

		frontP = backP;
	}
}

// 第2版 - 改成整数运算

// 第3版 - 8个区间都可以画 

//=========================================================================
// 其他优化版本

// 中点画法

// 

#endif // __DL_Bresenham_Line_Algorithm_H__