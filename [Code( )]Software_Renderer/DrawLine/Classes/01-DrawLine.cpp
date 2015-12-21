


#include<gl/glut.h> 
#include "00-DataDefinition.h"
#include "00-DataInit.h"
#include "DrawLineAlgorithm/DrawLineInterface.h"
#include "01-Line clipping.h"
#include "01-DrawLine.h"

//=========================================================================
//
//							数据
//
//=========================================================================
// 定义要画的直线的集合
const Line2D  drawLineSet[]	= {


	{ {10, 10},		{100, 30}	},
	{ {10, 20},		{50, 100}	},
	{ {-5, 10},		{-20, 90}	},
	{ {-10, 20},	{-120, 40}	},

	{ {10, -10},	{100, -30}	},
	{ {10, -20},	{50, -100}	},
	{ {-5, -10},	{-20, -90}	},
	{ {-10, -20},	{-120, -40}	},

	{ {10, 120},	{10, -40}	},
	{ {-10, 120},	{90, 120}	},			// 一条水平线
};		


//=========================================================================
//
//							画测试用的线
//
//=========================================================================

void myDisplay_Draw_Line_On_Windows_function(std::vector<Point2D_int> draw2DPointSet)  
{  
	//用描点法画出直线来  
	glColor3f(1.0, 0.0, 0.0);				// 决定要画的线的颜色
	glBegin(GL_POINTS); 

	// 初始化要裁剪的区域
	clippedWidowsInit();

	for (const auto & line : drawLineSet) {
		drawLine(line, draw2DPointSet);	// 计算出要画的直线的点的集合
	}

	glEnd(); 
}  


//=========================================================================
//
//				计算要画的直线，把点集合装到容器里去
//
//=========================================================================
void drawLine(const Line2D & line, std::vector<Point2D_int> & drawPointSet)
{
	// 清空容器
	drawPointSet.clear();

	// 对要画的直线进行裁剪
	Line2D clippedLine = line;		// clippedLineFromRect 会修改传递进去的参数 line
	if (clippedLineFromRect(clippedLine, ClippingSize)) {
		// 计算出要画的直线的点的集合
		draw2DLine(clippedLine, drawPointSet); 

		// 开始画
		for (const auto & point : drawPointSet) {
			glVertex2f(point.x , point.y);	
		}
	}

}