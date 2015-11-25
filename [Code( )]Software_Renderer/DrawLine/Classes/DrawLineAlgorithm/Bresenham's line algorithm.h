
#ifndef __DL_Bresenham_Line_Algorithm_H__
#define __DL_Bresenham_Line_Algorithm_H__


#include <vector>
#include "00-DataDefinition.h"

/*		本文 学习到内容

Digital Differential Analyzer 画线算法
中点画线算法
Bresenham 画线算法

*/

// 前置声明
void creat_Line_Point_Set_By_Int_Compute(const float startX, const float  startY, const float endX, const float endY, std::vector<Point2D_int> & pointSet);



/*
	第1个参数是要画的直线【内含2个点的位置数据】， 
	第2个参数 接收 画这条线 所需要的 点的集合。

	然后这里线的宽度 是1像素
*/

//=========================================================================
//
//					 Digital Differential Analyzer algorithm - 数值微分-DDA直线算法
//
//=========================================================================

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

	// 确定 递增值是正还是负
	int sign = 1;
	if (k<0) sign = -1;


	// X方向每前进一个单位时，Y方向就相应的判断 是+1还是+0个单位。
	for (float addy = drawLine.startPos.y + k; backP.x < drawLine.endPos.x; addy += k) {	//增量y
		backP.x += 1;

		// 判断 Y方向是 +1 还是 +0 个单位
		if ( abs(addy - frontP.y) * 2 > 1 )
		{
			backP.y += sign;
		}

		// 把点压入集合中
		pointSet.push_back(backP);

		frontP = backP;
	}
}


//=========================================================================
//
//					象限转换接口
//
//=========================================================================
enum Eight_Interval {		// 以X轴为初始，逆时针算起。 
	F1,
	F2,						// k > 1 || k < -1 的直线
};

/*	坐标转换接口
	一般式 8个区间都可以画 

	转换后的 line 的 坐标：endPos.x > startPos.x
	这个还支持 画 水平线 和画 垂直线
*/ 
void transform_Line_Pos(const Line2D & Line1, std::vector<Point2D_int> & pointSet)
{
	float dy = Line1.endPos.y - Line1.startPos.y;
	float dx = Line1.endPos.x - Line1.startPos.x;
	

	if (0 == dx) {		// 画一条 竖直直线
		// 好像不需要做特殊判断，以后做优化的时候加这块吧，专门画横着的 扫描线的。
	}

	float k = dy/dx;	// 直线的斜率

	Line2D drawLine = Line1;

	// x 和 y 互换
	int posState = F1; 
	if (k > 1 || k < -1) { 
		drawLine.startPos.x = Line1.startPos.y;
		drawLine.startPos.y = Line1.startPos.x;
		drawLine.endPos.x = Line1.endPos.y;
		drawLine.endPos.y = Line1.endPos.x;
		posState = F2;
	}

	// startPos 和 endPos 互换，直线的起始点和终点确定。
	if (drawLine.endPos.x < drawLine.startPos.x) {
		auto tem = drawLine.startPos;
		drawLine.startPos = drawLine.endPos;
		drawLine.endPos = tem;
	}

	// 生成中间结果
	//creat_Line_Point_Set_By_Int_Compute0(drawLine, pointSet);
	creat_Line_Point_Set_By_Int_Compute(drawLine.startPos.x, drawLine.startPos.y, drawLine.endPos.x, drawLine.endPos.y, pointSet);

	// 中间结果的 坐标转换
	if (F2 == posState) {
		for (auto & er : pointSet) {
			auto tem = er.x;
			er.x = er.y;
			er.y = tem;
		}
	}
}


//=========================================================================
//
//					 Bresenham's line algorithm - 布雷森汉姆直线算法
//
//=========================================================================
// 第3版 - 把K改成整数运算[注意到上面的 k 可以改掉，不需要出现 k 以及 除法运算  k = dy/dx; ]
/*
	01 把 dy 和 dx 定义为 整型。
	02 把 dy/dx 代入到 上面的 k 中去，然后进行等式变化，最后消除除法和浮点运算。 
	其实就是初中数学知识。

	最终效果：全程没有 浮点 和 浮点除法 运算。
*/
void creat_Line_Point_Set_By_Int_Compute(const float startX, const float  startY, const float endX, const float endY, std::vector<Point2D_int> & pointSet)
{
	int dy = (int)(endY - startY);
	int dx = (int)(endX - startX);

	Point2D_int frontP, backP;	
	frontP.x = (int)startX;		//  点离散化到整数级别 - 后期改进为 点的取舍
	frontP.y = (int)startY;
	backP = frontP;

	// 确定 递增值是正还是负
	int sign = 1;
	if (dy < 0) sign = -1;

	// X方向每前进一个单位时，Y方向就相应的判断 是+1还是+0个单位。
	for (int addy = (int)(dx*startY + dy); backP.x < endX; addy += dy) {		
		backP.x += 1;

		// 判断 Y方向是 +1 还是 +0 个单位
		if ( abs(2*addy - 2*dx*frontP.y) > dx ) backP.y += sign;

		// 把点压入集合中
		pointSet.push_back(backP);

		frontP = backP;
	}
}




// 第4版 - 一般式 8个区间都可以画 
/*
	对应坐标轴 的8个区间：
*/



/*

DDA称为数值微分画线算法,是直线生成算法中最简单的一种.原理相当简单,就是最直观的根据斜率的偏移程度,决定是以x为步进方向还是以y为步进方向.
然后在相应的步进方向上,步进变量每次增加一个像素,而另一个相关坐标变量则为Yk_1=Yk+m（以x为步进变量为例,m为斜率）

假定直线斜率k在0~1之间,当前象素点为（xp,yp）,则下一个象素点有两种可选择点P1（xp+1,yp）或P2（xp+1,yp+1）.
若P1与P2的中点（xp+1,yp+0.5）称为M,Q为理想直线与x=xp+1垂线的交点.
当M在Q的下方时,则取P2应为下一个象素点；当M在Q的上方时,则取P1为下一个象素点.这就是中点画线法的基本原理

Bresenham：过各行、各列像素中心构造一组虚拟网格线,按直线从起点到终点的顺序计算直线各垂直网格线的交点,
然后确定该列像素中与此交点最近的像素.该算法的优点在于可以采用增量计算,使得对于每一列,只要检查一个误差项的符号,就可以确定该列所求的像素.
大概就是这样,

http://www.zybang.com/question/1bb07a44f423a59dd0bec08237baa7a3.html


*/




//=========================================================================
// 其他优化版本

// 中点画法

// 

#endif // __DL_Bresenham_Line_Algorithm_H__