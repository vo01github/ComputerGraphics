

#ifndef __DATA_DEFINITION_H__
#define __DATA_DEFINITION_H__

#include<stdlib.h>
#include<cstdio>
#include<stdlib.h>
#include <cstdio>

using namespace std;


//=========================================================================
//
//							数据结构定义
//
//=========================================================================
typedef struct Point_2D_World
{
	float x;
	float y;
}Point2D;


typedef struct Line_2D_World
{
	Point2D startPos;
	Point2D endPos;
}Line2D;

typedef struct Rect_2D_World
{
	Point2D LeftDownPoint;
	Point2D RightUpPoint;
}Rect2D;

//=========================================================================
//
//							数据定义
//
//=========================================================================
const Point2D ScreenSize = {800.0f, 800.0f};			// 屏幕大小

const float scaleScreen = 0.2f;						// 决定要裁剪的区域有多大

Rect2D ClippingSize;								// 要裁剪的区域

#endif // __DATA_DEFINITION_H__