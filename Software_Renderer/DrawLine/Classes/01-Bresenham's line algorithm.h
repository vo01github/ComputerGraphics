
#include<stdlib.h>
#include<cstdio>
#include<stdlib.h>
#include <cstdio>
#include <iostream>
using namespace std;

#include<gl/glut.h> 
#include "00-DataDefinition.h"

/*		本文 学习到内容

Bresenham 画线算法

待自己实现一遍。
*/

// 定义要画的直线
const Line2D  drawLine	= {{0, 0},	{100, 90}};


//=========================================================================
//
//							画个坐标系
//
//=========================================================================

void myDisplay_GL_LINE_LOOP_Draw_Sine_function(void)  
{  
	const GLfloat factor = 0.1f;  //缩放因子，将普通正弦函数的图像缩小10倍画到屏幕上。

	GLfloat x;  
	glClear(GL_COLOR_BUFFER_BIT);  
	glBegin(GL_LINES);  
	glVertex2f(-1.0f, 0.0f);  
	glVertex2f(1.0f, 0.0f);         // 以上两个点可以画x轴，坐标原点在正中心。  
	glVertex2f(0.0f, -1.0f);  
	glVertex2f(0.0f, 1.0f);         // 以上两个点可以画y轴  
	glEnd();  

	//用描点法画出缩放后的正弦函数图像  
	glBegin(GL_LINE_STRIP);  
	//for(x=-1.0f/factor; x<1.0f/factor; x+=0.01f)  
	//{  
	//	glVertex2f(x*factor, sin(x)*factor); 
	//	glColor3f(0.0,0.0,1.0);			 /* blue color */
	//}  
	
	glEnd();  
	glFlush();  
}  

//=========================================================================
//
//					 Bresenham's line algorithm
//
//=========================================================================

