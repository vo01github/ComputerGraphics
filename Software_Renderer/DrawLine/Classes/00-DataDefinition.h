
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