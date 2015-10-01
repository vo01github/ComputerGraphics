
#include<stdlib.h>
#include<cstdio>
#include<stdlib.h>
#include <cstdio>
#include <iostream>
using namespace std;

#include<gl/glut.h> 


/*		本文 学习到内容

凸多边形模拟圆


*/


//=========================================================================
//
//							凸多边形模拟圆
//
//=========================================================================

void myDisplay_GL_LINE_LOOP_Draw_Cycile(void)  
{  
	const int n = 200;  
	const GLfloat R = 0.5f;  
	const GLfloat Pi = 3.1415926536f;  
  
	glClear(GL_COLOR_BUFFER_BIT);  
	glBegin(GL_LINE_LOOP);  

	for(int i = 0; i < n; ++i) {
		glVertex2f(R*cos(2*Pi/n*i), R*sin(2*Pi/n*i));  
	} 
		
	glEnd();  
	glFlush();  
}  


//=========================================================================
//
//							正弦函数图形
//
//=========================================================================

void myDisplay_GL_LINE_LOOP_Draw_Sine_function(void)  
{  
	const GLfloat factor = 0.1f;  //缩放因子，将普通正弦函数的图像缩小10倍画到屏幕上。

	GLfloat x;  
	glClear(GL_COLOR_BUFFER_BIT);  
	glBegin(GL_LINES);  
	glVertex2f(-1.0f, 0.0f);  
	glVertex2f(1.0f, 0.0f);         // 以上两个点可以画x轴  
	glVertex2f(0.0f, -1.0f);  
	glVertex2f(0.0f, 1.0f);         // 以上两个点可以画y轴  
	glEnd();  

	//用描点法画出缩放后的正弦函数图像  
	glBegin(GL_LINE_STRIP);  
	for(x=-1.0f/factor; x<1.0f/factor; x+=0.01f)  
	{  
		glVertex2f(x*factor, sin(x)*factor); 
		glColor3f(0.0,0.0,1.0);			 /* blue color */
	}  
	
	glEnd();  
	glFlush();  
}  