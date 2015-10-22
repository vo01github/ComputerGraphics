
#ifndef __DL_DRAW_LINE_INTERFACE_H__
#define __DL_DRAW_LINE_INTERFACE_H__


#include <vector>


// 前置声明
struct Point_2D_World;
typedef	struct Point_2D_World Point2D;
struct Point_2D_World_Discrete_Integer;
typedef	struct Point_2D_World_Discrete_Integer Point2D_int;
struct Line_2D_World;
typedef	struct Line_2D_World Line2D;
	

//=========================================================================
//
//					 Draw Line Interface
//
//=========================================================================



void draw2DLine(const Line2D & drawLine,  std::vector<Point2D_int> & pointSet);



#endif // __DL_DRAW_LINE_INTERFACE_H__