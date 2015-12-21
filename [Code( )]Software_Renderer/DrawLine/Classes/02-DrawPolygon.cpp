


#include<gl/glut.h> 
#include "00-DataDefinition.h"
#include "00-DataInit.h"
#include "DrawLineAlgorithm/DrawLineInterface.h"
#include "01-Line clipping.h"
#include "02-DrawPolygon.h"
#include "01-DrawLine.h"

//=========================================================================
//
//							数据
//
//=========================================================================
// 定义要画的三角形的集合
const Point2D  drawPolygonSet[]	= {


	{-10, 80},		{100, 30},	{30, -60},		{-80, -60},		
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


//=========================================================================
//
//							画测试用的三角形
//
//=========================================================================

void myDisplay_Draw_Polygon_On_Windows_function(std::vector<Point2D_int> draw2DPointSet)  
{  
	//用描点法画出直线来  
	glColor3f(1.0, 0.0, 0.0);				// 决定要画的线的颜色
	glBegin(GL_POINTS); 

	// 初始化要裁剪的区域
	clippedWidowsInit();

	// 生成数据
	std::vector<Point2D>  polygon;
	for (auto m : drawPolygonSet) {
		polygon.push_back(m);
	}
		
	drawPolygon(polygon, false, draw2DPointSet);
	

	glEnd();  

}  


void drawPolygon(const std::vector<Point2D> & polygon, bool isSolid, std::vector<Point2D_int> & drawPointSet)
{
	if (!isSolid) {
		// 生成要画的所有边
		std::vector<Line2D> lines;
		for (int i = 0; i < polygon.size(); ++i) {
			Point2D start = polygon[i];
			Point2D end = polygon[(i+1)%polygon.size()];
			Line2D singleLine = {start, end};
			lines.push_back(singleLine);
		}
		

		for (const auto & m : lines) {
			// 计算出要画的直线的点的集合
			drawLine(m, drawPointSet);
		}
	}
}