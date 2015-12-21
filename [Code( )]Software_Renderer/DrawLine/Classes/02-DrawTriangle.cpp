


#include<gl/glut.h> 
#include "00-DataDefinition.h"
#include "00-DataInit.h"
#include "DrawLineAlgorithm/DrawLineInterface.h"
#include "01-Line clipping.h"
#include "02-DrawTriangle.h"
#include "01-DrawLine.h"

//=========================================================================
//
//							数据
//
//=========================================================================
// 定义要画的三角形的集合
const Triangle2D  drawTriangleSet[]	= {


	{ {-10, 80},		{100, 30},		{-80, -60},		},
	//{ {10, 20},		{50, 100},			},
	//{ {-5, 10},		{-20, 90},			},
	//{ {-10, 20},	{-120, 40},			},

	//{ {10, -10},	{100, -30},			},
	//{ {10, -20},	{50, -100},			},
	//{ {-5, -10},	{-20, -90},			},
	//{ {-10, -20},	{-120, -40},		},

	//{ {10, 120},	{10, -40},			},
	//{ {-10, 120},	{90, 120},			},			// 一条水平线
};		
std::vector<Point2D_int> Draw2DTrianglePointSet;					// 集成了要画出的点

//=========================================================================
//
//							画测试用的三角形
//
//=========================================================================

void myDisplay_Draw_Triangle_On_Windows_function(void)  
{  
	 
	//用描点法画出直线来  
	glColor3f(1.0, 0.0, 0.0);				// 决定要画的线的颜色
	glBegin(GL_POINTS); 

	// 初始化要裁剪的区域
	clippedWidowsInit();

	for (const auto & triangle : drawTriangleSet) {
		
		drawTriangle(triangle, false);
	}

	glEnd();  

}  


void drawTriangle(const Triangle2D & triangle, bool isSolid)
{
	if (!isSolid) {
		// 确定要画的三条边
		const Line2D line[3] = {
			{triangle.p1, triangle.p2},
			{triangle.p2, triangle.p3},
			{triangle.p3, triangle.p1},
		};
		std::vector<Line2D> lines(line, line + 3);

		for (const auto & m : lines) {
			// 计算出要画的直线的点的集合
			drawLine(m, Draw2DTrianglePointSet);
		}
	}
}