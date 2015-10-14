
#include<stdlib.h>
#include<cstdio>
#include<stdlib.h>
#include <cstdio>
#include <iostream>
#include <time.h> 
#include <windows.h>  

using namespace std;
#include "00-DataDefinition.h"
#include<gl/glut.h> 


/*		下面 学习到内容

*/


//=========================================================================
//
//							15000 个 三角形的绘制
//
//=========================================================================

/*
	(2)GL_TRIANGLES ，将每3个顶点为一组画出一个三角形，如果剩余的顶点个数不足3个则忽略。
	运行效果如下所示:
*/

unsigned short getCurrentTime()    
{    
	SYSTEMTIME sys; 
	GetLocalTime( &sys ); 

	unsigned short Milliseconds = sys.wMilliseconds;		// 获取毫秒

	return Milliseconds;
}   

void myDisplay_GL_TRIANGLES_15000(void)	// 画三角形，
{  
	glClear(GL_COLOR_BUFFER_BIT);  

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// 获取秒
	//struct tm *tm; 
	//time_t timep;
	//time(&timep); 
	//tm = localtime(&timep); 
	//int gameSec1		= tm->tm_sec;

	/// 先获取进入时间
	unsigned short start = getCurrentTime();

	float dis = 6.0f;		// 两个三角形 之间隔了有多少像素。
	int num_wrap = 130;		// 横着画 130 个 就换行。

	for (int i = 0; i < 15000; ++i)
	{
		glBegin(GL_TRIANGLES );
		glVertex3f(-1.0 + ((float)(i%num_wrap))*dis/(ScreenSize.x/2),	1.0 - ((float)(i/num_wrap))*dis/(ScreenSize.x/2),0);		//	点P1  
		glVertex3f(-1.0 + (-3/(ScreenSize.x/2)) + ((float)(i%num_wrap))*dis/(ScreenSize.x/2),	1.0 + (-3/(ScreenSize.x/2)) - ((float)(i/num_wrap))*dis/(ScreenSize.x/2),0);	//	点P2 
		glVertex3f(-1.0 + (+3/(ScreenSize.x/2)) + ((float)(i%num_wrap))*dis/(ScreenSize.x/2),	1.0 + (-3/(ScreenSize.x/2)) - ((float)(i/num_wrap))*dis/(ScreenSize.x/2),0);		//	点P3 
		glEnd(); 
	}
	
	unsigned short end = getCurrentTime();

	// 获取秒
	//struct tm *tm2; 
	//time_t timep2;
	//time(&timep2); 
	//tm2 = localtime(&timep2); 
	//int gameSec2		= tm2->tm_sec;

	glFlush(); 
} 



#if 0
/*
	(3)GL_TRIANGLES_STRIP 于GL_LINE_STRIP类似，画出顶点列表中所有由【任意连续三点】所组成的三角形。
*/
void myDisplay_GL_TRIANGLE_STRIP(void)	// 画三角形，
{  
	glClear(GL_COLOR_BUFFER_BIT);  

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(-0.5,-0.5);		//	点P1  
	glVertex2f(-0.5,0.5);		//	点P2 
	glVertex2f(0.5,0.5);		//	点P3 

	glVertex2f(0.5,-0.5);		//	点P4  
	glVertex2f(0.9,-0.8);		//	点P4

	glEnd();  
	glFlush(); 
}

/*
	(4)GL_TRIANGLE_FAN 所有三角形都以第一点为顶点，另外两个顶点为连续顶点。
*/
void myDisplay_GL_TRIANGLE_FAN(void)	// 画三角形，
{  
	glClear(GL_COLOR_BUFFER_BIT);  

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(-0.5,-0.5);		//	点P1  
	glVertex2f(-0.5,0.5);		//	点P2 
	glVertex2f(0.5,0.5);		//	点P3 

	glVertex2f(0.5,-0.5);		//	点P4  
	glVertex2f(0.9,-0.8);		//	点P4
	glVertex2f(0.6,-0.7);		//	点P4

	glEnd();  
	glFlush(); 
}

#endif
