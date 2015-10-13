

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



//=========================================================================
//
//							数据定义
//
//=========================================================================
const Point2D ScreenArea = {400.0f, 400.0f};			// 屏幕大小





#endif // __DATA_DEFINITION_H__