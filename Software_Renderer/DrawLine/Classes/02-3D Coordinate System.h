
#ifndef __DL_3D_Coordinate_System_H__
#define __DL_3D_Coordinate_System_H__


#include <vector>
#include<gl/glut.h> 
#include "00-DataDefinition.h"
#include "00-DataInit.h"
#include "DrawLineAlgorithm/DrawLineInterface.h"


// 定义要画的直线的集合
//const Line2D  drawLineSet[]	= {
//	{ {0, 0},	{100, 90}	},
//	{ {0, 0},	{190, 190}	},
//	{ {0, 0},	{190, 50}	},
//};		
//std::vector<Point2D_int> drawPointSet;					// 集成了要画出的点

const float CoordinateL = 0.6;
const float taiangleL = 0.05;


//=========================================================================
//
//							画个坐标系
//
//=========================================================================

void myDisplay_Draw_3D_Coordinate_System_On_Windows_function(void)  
{  
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gluLookAt(	0.7, 0.2, -0.9,  
				0, 0, 0,  
				0.5, 1, 0.5);				// 调整 摄像机 镜头


	glClear(GL_COLOR_BUFFER_BIT); 
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);		// 不加这句就是画一个实心三角形了。


	// 绘制坐标轴的 直线
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 0.0);	//x轴 黄色
	glVertex3f(-CoordinateL, 0.0, 0.0);
	glVertex3f(CoordinateL, 0.0, 0.0);

	glColor3f(0.0, 1.0, 0.0);	//y轴 绿色
	glVertex3f(0.0, -CoordinateL, 0.0);
	glVertex3f(0.0, CoordinateL, 0.0);

	glColor3f(1.0, 0.0, 0.0);	//z轴 红色
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, -CoordinateL);
	glEnd();

	// 绘制坐标轴的 箭头
	glBegin(GL_TRIANGLES);

	glColor3f(1.0, 1.0, 0.0);	// x轴 黄色
	glVertex3f(CoordinateL-taiangleL, taiangleL, 0);
	glVertex3f(CoordinateL, 0, 0);
	glVertex3f(CoordinateL-taiangleL, -taiangleL, 0);

	glVertex3f(CoordinateL-taiangleL, 0, taiangleL);
	glVertex3f(CoordinateL, 0, 0);
	glVertex3f(CoordinateL-taiangleL, 0, -taiangleL);

	glColor3f(0.0, 1.0, 0.0);	// y轴 绿色
	glVertex3f(0, CoordinateL, 0);
	glVertex3f(taiangleL, CoordinateL-taiangleL, 0);
	glVertex3f(-taiangleL, CoordinateL-taiangleL, 0);

	glVertex3f(0, CoordinateL, 0);
	glVertex3f(0, CoordinateL-taiangleL, taiangleL);
	glVertex3f(0, CoordinateL-taiangleL, -taiangleL);

	glColor3f(1.0, 0.0, 0.0);	// z轴 红色
	glVertex3f(0, 0, -CoordinateL);
	glVertex3f(0, taiangleL, -CoordinateL + taiangleL);
	glVertex3f(0, -taiangleL, -CoordinateL + taiangleL);

	glVertex3f(0, 0, -CoordinateL);
	glVertex3f(taiangleL, 0, -CoordinateL + taiangleL);
	glVertex3f( -taiangleL, 0, -CoordinateL + taiangleL);
	glEnd();  

	glFlush();  
}  

//
//void changeSize(GLsizei w, GLsizei h)
//{
//	GLfloat aspectRatio;
//
//	if (h == 0)
//	{
//		h = 1;
//	}
//
//	glViewport(0, 0, w, h);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//
//	aspectRatio = (GLfloat)w / (GLfloat)h;
//
//	GLdouble left = PlotCubes::xStartCordinate;
//	GLdouble right = PlotCubes::xEndCordinate;
//	GLdouble bottom = PlotCubes::yStartCordinate;
//	GLdouble top = PlotCubes::yEndCordinate;
//	GLdouble near = PlotCubes::zStartCordinate;
//	GLdouble far = PlotCubes::zEndCordinate;
//
//	if (w <= h)
//	{
//		glOrtho(left, right, bottom / aspectRatio, top / aspectRatio, near, far);
//	}
//	else
//	{
//		glOrtho(left*aspectRatio, right*aspectRatio, bottom, top, near, far);
//	}
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}

#endif // __DL_3D_Coordinate_System_H__