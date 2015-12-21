
#pragma once


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

typedef struct Point_2D_World_Discrete_Integer		// 点离散化成整型 
{
	int x;
	int y;
}Point2D_int;

typedef struct Line_2D_World
{
	Point2D startPos;
	Point2D endPos;
}Line2D;

typedef struct Triangle_2D_World
{
	Point2D p1;
	Point2D p2;
	Point2D p3;
}Triangle2D;

typedef struct Rect_2D_World
{
	Point2D LeftDownPoint;
	Point2D RightUpPoint;
}Rect2D;


