
#include<stdlib.h>
#include<cstdio>
#include<stdlib.h>
#include <cstdio>
#include <iostream>
using namespace std;

#include<gl/glut.h> 

// 一个通用 opengl 框架
/*
	http://blog.csdn.net/laomai/article/details/7269511
*/

// 画矩形
void myDisplay_Rect(void)  
{  
	glClear(GL_COLOR_BUFFER_BIT);		//清除颜色  
	glRectf(-0.5f,-0.5f,0.5f,0.5f);		//画一个矩形  
	glFlush();							//让前面的命令立即执行而不是在缓冲区，与fflush(stdout)作用类似  
}  

// 画点坐标
void myDisplay_POINTS(void)  
{  
	glClear(GL_COLOR_BUFFER_BIT);  
	glBegin(GL_POINTS);  
	glVertex2f(-0.5,-0.5);		//	点P1  
	glVertex2f(-0.5,0.5);		//	点P2  
	glVertex2f(0.5,0.5);		//	点P3  
	glVertex2f(0.5,-0.5);		//	点P4  
	glEnd();  
	glFlush(); 
}  

// 线段的绘制
void myDisplay_LINES(void)  
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



int firstGraphics(int argc,_TCHAR* argv[])  
{  
	glutInit(&argc,(char**)argv);					// 初始化glut,必须调用，复制黏贴这句话即可  
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);	// 设置显示方式，RGB、单缓冲。当然还有GLUT_INDEX索引颜色 GLUT_DOUBLE双缓冲(Qt中看到过双缓冲)  
	glutInitWindowPosition(100,100);				// 位置  
	glutInitWindowSize(400,400);					// 窗口大小  
	glutCreateWindow("第一个OpenGL程序");			// 创建窗口，设置标题  
	glutDisplayFunc(&myDisplay_LINES);					// 当绘制窗口时调用myDisplay，像Cocos2d-x刷帧Draw中的操作  
	glutMainLoop();									// 消息循环  
	return 0;  
}  

