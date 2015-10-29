
#include<stdlib.h>
#include<cstdio>
#include<stdlib.h>
#include <cstdio>
#include <iostream>
using namespace std;

#include<gl/glut.h> 
#include <vector>

/*		下面 学习到内容

POINTS
LINES
TRIANGLES
Rect
POLYGON

*/

#define VF std::vector<float>
#define VVF std::vector<VF>

//=========================================================================
//
//							点的绘制
//
//=========================================================================
void myDisplay_POINTS(void)  
{  
	glClear(GL_COLOR_BUFFER_BIT);  
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5.0f);
	glBegin(GL_POINTS);  
	glVertex2f(-0.5,-0.5);		//	点P1  
	glVertex2f(-0.5,0.5);		//	点P2  
	glVertex2f(0.5,0.5);		//	点P3  
	glVertex2f(0.5,-0.5);		//	点P4  
	glEnd();  
	glFlush(); 
}  

/*
代码解释

名字以glVertex开头的一系列函数用于指定顶点坐标，名字里的2表示2维即两个坐标(x和y)，f表示坐标的类型是float。

这一系列函数包括：
glVertex2d
glVertex2f
glVertex3f
glVertex3fv
等等。
数字表示参数的个数，字母表示参数的类型，具体含义是

s表示16位整数（OpenGL中将这个类型定义为GLshort），
i表示32位整数（OpenGL中将这个类型定义为GLint和GLsizei），
f表示32位浮点数（OpenGL中将这个类型定义为GLfloat和GLclampf），
d表示64位浮点数（OpenGL中将这个类型定义为GLdouble和GLclampd）。
v表示传递的几个参数将使用指针的方式，见下面的例子。
*/

void myDisplay_POINTS_byOthers(void)  
{  
	glVertex2i(1, 3);                           
	glVertex2f(1.0f, 3.0f);  
	glVertex3f(1.0f, 3.0f, 0.0f);  
	glVertex4f(1.0f, 3.0f, 0.0f, 1.0f);  

	GLfloat VertexArr3[] = {1.0f, 3.0f, 0.0f};  
	glVertex3fv(VertexArr3); 
}  

/*
	glVertex2f(-0.5, 0.5) ;
	这一句的意思就是给出一个点，其x坐标和y坐标分别为-0.5和0.5。在本节的例子中，
	你可以认为坐标原点在窗口的中心，x轴向右为正, y轴向上为正。窗口绘图区的高度度和宽度都是1。
*/

//=========================================================================
//
//							线段的绘制
//
//=========================================================================
void myDisplay_LINES(void)		// 画个矩形
{  
	glClear(GL_COLOR_BUFFER_BIT);  

	glBegin(GL_LINES);
	glVertex2f(-0.5,-0.5);		//	点P1  
	glVertex2f(-0.5,0.5);		//	点P2 

	glVertex2f(0.5,0.5);		//	点P3  
	glVertex2f(0.5,-0.5);		//	点P4  

	glVertex2f(-0.5,0.5);		//	点P2  
	glVertex2f(0.5,0.5);		//	点P3 

	glVertex2f(-0.5,-0.5);		//	点P1
	glVertex2f(0.5,-0.5);		//	点P4  

	glEnd();  
	glFlush(); 
}  



/*	线段的绘制
glBegin函数的参数是告诉程序对后面给出的点集进行什么操作。这个参数的常见取值有：
(1) GL_POINTS:画出单个的点，点之间没有任何连线。
(2) GL_LINES:两个点一组，每组之间一条线段。
(3) GL_LINE_STRIP:用给出的点画出一条连续折线，除最后一个点外。每一个点都是下一段的起点。
(4) GL_LINE_LOOP:用给出的点画出一个闭合折线。也就是在GL_LINE_STRIP的基础上再把最后一个点和第一个点连起来。
*/

void myDisplay_LINE_STRIP(void)	// 画个矩形
{  
	glClear(GL_COLOR_BUFFER_BIT);  

	glBegin(GL_LINE_STRIP);
	glVertex2f(-0.5,-0.5);		//	点P1  
	glVertex2f(-0.5,0.5);		//	点P2 
	glVertex2f(0.5,0.5);		//	点P3  
	glVertex2f(0.5,-0.5);		//	点P4  
	glVertex2f(-0.5,-0.5);

	glEnd();  
	glFlush(); 
} 

void myDisplay_LINE_LOOP(void)	// 画个矩形
{  
	glClear(GL_COLOR_BUFFER_BIT);  

	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.5,-0.5);		//	点P1  
	glVertex2f(-0.5,0.5);		//	点P2 
	glVertex2f(0.5,0.5);		//	点P3  
	glVertex2f(0.5,-0.5);		//	点P4  

	glEnd();  
	glFlush(); 
} 

//=========================================================================
//
//							绘制凸多边形
//
//=========================================================================

/*
	glBegin函数还提供了以下几个参数来画出凸多边形。所谓凸多边形，是指它要满足如下性质：
	把该多边形任意一边向两方无限延长成为一条直线后，其他各边均在此直线的同侧。

	(1)GL_POLYGON，这个参数用后面的顶点列表画出一个凸多边形。

	默认情况下，opengl在画多边形时，会自动用指定颜色(默认为白色)填充其内部。
	如果想只显示多边形的边线而不填充其内部，可以在glBegin函数之前加上一句
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);    这个语句的作用告诉opengl只画出边框，但不填充内部。
*/
void myDisplay_GL_POLYGON(void)	// 画个矩形
{  
	glClear(GL_COLOR_BUFFER_BIT);  

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);		//glPolygonMode()指定了如何绘制面的方式，GL_LINE为只画线，GL_FILL则是默认的填充。	

	glBegin(GL_POLYGON);
	glVertex2f(-0.5,-0.5);		//	点P1  
	glVertex2f(-0.5,0.5);		//	点P2 
	glVertex2f(0.5,0.5);		//	点P3  
	glVertex2f(0.5,-0.5);		//	点P4  
	glVertex2f(0.9,-0.8);		//	点P4

	glEnd();  
	glFlush(); 
} 

/*
	(2)GL_TRIANGLES ，将每3个顶点为一组画出一个三角形，如果剩余的顶点个数不足3个则忽略。
	运行效果如下所示:
*/

void myDisplay_GL_TRIANGLES(void)	// 画三角形，
{  
	glClear(GL_COLOR_BUFFER_BIT);  

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glBegin(GL_TRIANGLES );
	glVertex2f(-0.5,-0.5);		//	点P1  
	glVertex2f(-0.5,0.5);		//	点P2 
	glVertex2f(0.5,0.5);		//	点P3 

	glVertex2f(0.5,-0.5);		//	点P4  
	glVertex2f(0.5,-0.8);		//	点P4  
	glVertex2f(0.7,-0.9);		//	点P4  

	glEnd();  
	glFlush(); 
} 

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

/*
	(5) GL_QUADS:每4个顶点为一组画出一个四边形。如果剩余点数不足4个，则忽略。
*/

/*
	(6) GL_QUAD_STRIP:每两个顶点为一组，任意连续的两组画出一个四边形。如果有8个点为P1到P8，则最后画出3个4边形

	P1P2P3P4，

	P3P4P5P6，

	P5P6P7P8。
*/


// 画矩形
/*
opengl还提供了一个直接画矩形的函数系列

glRect[sifd]，中括号里的字符代表参数类型

s：short 短整型

i：integet 整型

f：float浮点型

d：double 双精度型。

例如下面的代码画出一个矩形框，左下角为(-0.5,-0.5)，右上角为(0.5, 0.5)
*/
void myDisplay_Rect(void)  
{  
	glClear(GL_COLOR_BUFFER_BIT);		//清除颜色  
	glRectf(-0.9f,-0.9f,0.5f,0.5f);		//画一个矩形[左下角 + 右上角]  
	glFlush();							//让前面的命令立即执行而不是在缓冲区，与fflush(stdout)作用类似  
}  
