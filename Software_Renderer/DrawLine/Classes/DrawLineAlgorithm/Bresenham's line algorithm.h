
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

/*
	第1个参数是要画的直线【内含2个点的位置数据】， 
	第2个参数 接收 画这条线 所需要的 点的集合。

	然后这里线的宽度 是1像素
*/


// 第1版 - 浮点型运算
void creat_Line_Point_Set_By_Float_Compute(const Line2D & drawLine, std::vector<Point2D> & pointSet)
{
	float dy = drawLine.endPos.y - drawLine.startPos.y;
	float dx = drawLine.endPos.x - drawLine.startPos.x;
	float k = dy/dx;	// 直线的斜率

	Point2D frontP = drawLine.startPos;		// 前一个点
	Point2D backP;							// 下一个点

	// X方向每前进一个单位时，Y方向就相应的判断 是+1还是+0个单位。
	for (float addy = drawLine.startPos.y + k; addy < dy; addy += k) {	//增量y
		
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

// 第2版 - 改成整数运算[注意到上面的 frontP 和 backP 可以改为整数类型]
void creat_Line_Point_Set_By_Int_Compute0(const Line2D & drawLine, std::vector<Point2D_int> & pointSet)
{
	float dy = drawLine.endPos.y - drawLine.startPos.y;
	float dx = drawLine.endPos.x - drawLine.startPos.x;
	float k = dy/dx;	// 直线的斜率

	Point2D_int frontP, backP;	
	frontP.x = (int)drawLine.startPos.x;		//  点离散化到整数级别 - 后期改进为 点的取舍
	frontP.y = (int)drawLine.startPos.y;
	backP = frontP;

	// X方向每前进一个单位时，Y方向就相应的判断 是+1还是+0个单位。
	for (float addy = drawLine.startPos.y + k; addy < dy; addy += k) {	//增量y
		backP.x += 1;

		// 判断 Y方向是 +1 还是 +0 个单位
		if ( (addy - frontP.y) * 2 > 1 )
		{
			backP.y += 1;
		}

		// 把点压入集合中
		pointSet.push_back(backP);

		frontP = backP;
	}
}

// 第3版 - 把K改成整数运算[注意到上面的 k 可以改掉，不需要出现 k 以及 除法运算  k = dy/dx; ]
/*
	01 把 dy 和 dx 定义为 整型。
	02 把 dy/dx 代入到 上面的 k 中去，然后进行等式变化，最后消除除法和浮点运算。 
	其实就是初中数学知识。

	最终效果：全程没有 浮点 和 浮点除法 运算。
*/
void creat_Line_Point_Set_By_Int_Compute(const Line2D & drawLine, std::vector<Point2D_int> & pointSet)
{
	int dy = (int)(drawLine.endPos.y - drawLine.startPos.y);
	int dx = (int)(drawLine.endPos.x - drawLine.startPos.x);

	Point2D_int frontP, backP;	
	frontP.x = (int)drawLine.startPos.x;		//  点离散化到整数级别 - 后期改进为 点的取舍
	frontP.y = (int)drawLine.startPos.y;
	backP = frontP;

	// X方向每前进一个单位时，Y方向就相应的判断 是+1还是+0个单位。
	for (int addy = (int)(drawLine.startPos.y + dy); backP.x < drawLine.endPos.x; addy += dy) {	
		backP.x += 1;

		// 判断 Y方向是 +1 还是 +0 个单位
		if ( 2*addy > dx + 2*dx*frontP.y )
		{
			backP.y += 1;
		}

		// 把点压入集合中
		pointSet.push_back(backP);

		frontP = backP;
	}
}



// 第4版 - 一般式 8个区间都可以画 
/*
	对应坐标轴 的8个区间：
*/

enum Eight_Interval {
	F1,
	F2,
	F3,
	F4,

	F5,
	F6,
	F7,
	F8,
};

void creat_Line_Point_Set_By_Int_Compute_8Interval(const Line2D & originalLine, std::vector<Point2D_int> & pointSet)
{
	int ds1 = (int)(originalLine.endPos.y - originalLine.startPos.y);
	int ds2 = (int)(originalLine.endPos.x - originalLine.startPos.x);

	const Line2D drawLine = originalLine;

	int dx = ds1 > ds2 ? ds1 : ds2;
	int dy = ds1 > ds2 ? ds2 : ds1;
	

	Point2D_int frontP, backP;	
	frontP.x = (int)drawLine.startPos.x;		//  点离散化到整数级别 - 后期改进为 点的取舍
	frontP.y = (int)drawLine.startPos.y;
	backP = frontP;

	// X方向每前进一个单位时，Y方向就相应的判断 是+1还是+0个单位。
	for (int addy = (int)(drawLine.startPos.y + dy); backP.x < drawLine.endPos.x; addy += dy) {	
		backP.x += 1;

		// 判断 Y方向是 +1 还是 +0 个单位
		if ( 2*addy > dx + 2*dx*frontP.y )
		{
			backP.y += 1;
		}

		// 把点压入集合中
		pointSet.push_back(backP);

		frontP = backP;
	}
}





//=========================================================================
// 其他优化版本

// 中点画法

// 

#endif // __DL_Bresenham_Line_Algorithm_H__