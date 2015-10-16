
#include<stdlib.h>
#include<cstdio>
#include<stdlib.h>
#include <cstdio>
#include <iostream>
using namespace std;

#include<gl/glut.h> 
#include "01-SimpleGraphics.h"
#include "02-ComplexGraphics.h"
#include "03-draw15000Triangles.h"
#include "00-DataDefinition.h"

void myDisplay(void)  
{  
	myDisplay_POINTS();
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
	glutInitWindowSize(ScreenSize.x, ScreenSize.y);					// 窗口大小  
	glutCreateWindow("第一个OpenGL程序");			// 创建窗口，设置标题  
	glutDisplayFunc(&myDisplay);					// 当绘制窗口时调用myDisplay，像Cocos2d-x刷帧Draw中的操作  
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
