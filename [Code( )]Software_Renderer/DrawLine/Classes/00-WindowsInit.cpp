

#include<stdlib.h>
#include<cstdio>
#include<stdlib.h>
#include <cstdio>
#include <iostream>
#include <tchar.h>

#include<gl/glut.h> 
#include "00-DataDefinition.h"
#include "00-DataInit.h"
#include "00-InputProcessing.h"
#include "00-WindowsInit.h"
#include "01-DrawLine.h"
#include "02-DrawTriangle.h"

//#include "02-ComplexGraphics.h"
//#include "02-3D Coordinate System.h"

//#include "stdafx.h"

// 前置声明
void changeSize(GLsizei w, GLsizei h);






void myDisplay()  
{  
	glClear(GL_COLOR_BUFFER_BIT); 

	drawCoordinateSystem();
	myDisplay_Draw_Triangle_On_Windows_function();
	//myDisplay_Draw_Line_On_Windows_function();


	glFlush(); 
}

//=========================================================================
//
//							画个坐标系
//
//=========================================================================
void drawCoordinateSystem()
{
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
}


//=========================================================================
//
//							窗口初始化
//
//=========================================================================
int windowsInit(int argc,_TCHAR* argv[])  
{  
	glutInit(&argc,(char**)argv);					// 初始化glut,必须调用，复制黏贴这句话即可  
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);	// 设置显示方式，RGB、单缓冲。当然还有GLUT_INDEX索引颜色 GLUT_DOUBLE双缓冲(Qt中看到过双缓冲)  
	glutInitWindowPosition(300,300);				// 窗口在显示器屏幕中的位置，指定的是窗口左上角的坐标。(0,0)就会显示在屏幕左上角。  
	glutInitWindowSize(ScreenSize.x, ScreenSize.y);	// 窗口大小  
	glutCreateWindow("SoftwareRasterizerRenderer");			// 创建窗口，设置标题  
	//glClearColor(1.0f,1.0f,1.0f,1.0f);
	glutKeyboardFunc(&ProcessKeyboard);
	glutMouseFunc(&ProcessMouse);
	glutDisplayFunc(&myDisplay);					// 当绘制窗口时调用myDisplay，像Cocos2d-x刷帧Draw中的操作  
	glutReshapeFunc(changeSize);
	glutMainLoop();									// 消息循环  
	return 0;  
}  

/*	初始化说明
1、首先将必要的头文件glut.h包含进来，以便使用opengl提供的函数库
2、display是程序员自己写的回调函数，用于在窗口内进行画图。在主函数里用glutDisplayFunc把它注册之后，
每次窗口里的图像需要刷新时，就调用这个我们写的display函数。
3、glutInitWindowSize函数指定窗体的宽度和高度
4、glutInitWindowPosition指定窗口左上角的坐标
5、glutCreateWindow建立一个窗体
6、glutMainLoop进入窗体消息循环。
以后如无特别说明，后面的例子代码只改动display函数的内容即可。
*/




//窗口大小改变时，保持长宽比不变，调用的登记函数  
void changeSize(GLsizei w,GLsizei h)
{  
	if (h == 0)  
	{  
		h = 1;  
	}  
	glViewport(0,0,w,h);//设置视区尺寸  

	//重置坐标系统，使投影变换复位  
	glMatrixMode(GL_PROJECTION);  
	glLoadIdentity();  

	//建立修剪空间的范围  
	if (w <= h)  
	{  
		glOrtho(-ScreenSize.x/2, ScreenSize.x/2, -ScreenSize.y/2, ScreenSize.y/2*h/w, 1.0f,-1.0f);  
	}  
	else  
	{  
		glOrtho(-ScreenSize.x/2*w/h, ScreenSize.x/2*w/h, -ScreenSize.y/2*w/h, ScreenSize.y/2, 1.0f,-1.0f);  
	}  
	glMatrixMode(GL_MODELVIEW);  
	glLoadIdentity();  
} 


