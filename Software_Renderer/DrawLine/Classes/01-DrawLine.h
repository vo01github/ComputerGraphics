
#ifndef __DL_Draw_Line_H__
#define __DL_Draw_Line_H__


#include <vector>
#include<gl/glut.h> 
#include "00-DataDefinition.h"
#include "00-DataInit.h"
#include "DrawLineAlgorithm/DrawLineInterface.h"
#include "[zsj]-3D Coordinate System.h"


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
	{ {-10, 120},	{90, 120}	},
};		
std::vector<Point2D_int> drawPointSet;					// 集成了要画出的点

//=========================================================================
//
//							画个坐标系
//
//=========================================================================

void myDisplay_Draw_Line_On_Windows_function(void)  
{  
	glClear(GL_COLOR_BUFFER_BIT); 

	// 画一个矩形实心框，代表视觉区域
	glColor3f(1.0, 1.0,1.0);				// 白色
	glRectf(-scaleScreen*ScreenSize.x/2, -scaleScreen*ScreenSize.y/2, 
			scaleScreen*ScreenSize.x/2, scaleScreen*ScreenSize.y/2);		//画一个矩形[左下角 + 右上角] 

	// 画个笛卡尔坐标系
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);  
	glVertex2f(-ScreenSize.x, 0.0f);  
	glVertex2f(ScreenSize.x, 0.0f);         // 以上两个点可以画x轴，坐标原点在正中心。  
	glVertex2f(0.0f, -ScreenSize.y);  
	glVertex2f(0.0f, ScreenSize.y);         // 以上两个点可以画y轴  
	glEnd();  

	//用描点法画出直线来  
	glColor3f(1.0, 0.0, 0.0);				// 决定要画的线的颜色
	glBegin(GL_POINTS); 
	for (const auto & line : drawLineSet) {
		drawPointSet.clear();

		//计算出要画的点
		draw2DLine(line, drawPointSet);
		for (const auto & point : drawPointSet) {
			//glVertex2f(point.x *2.0f/ScreenSize.x, point.y*2.0f/ScreenSize.y);		// 坐标转换，转换成 -1.0～1.0的坐标
			glVertex2f(point.x , point.y);	
		}
	}
	glEnd();  

	glFlush();  

	myDisplay_Draw_3D_Coordinate_System_On_Windows_function();
}  


#endif // __DL_Draw_Line_H__