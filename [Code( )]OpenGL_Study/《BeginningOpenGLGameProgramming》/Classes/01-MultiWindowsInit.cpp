
#include<stdlib.h>
#include<cstdio>
#include<stdlib.h>
#include <cstdio>
#include <iostream>
using namespace std;

#include<gl/glut.h> 

#include "01-MultiWindowsInit.h"
#include "01-SimpleGraphics.h"
#include "02-ComplexGraphics.h"
#include "03-draw15000Triangles.h"
#include "00-DataDefinition.h"
#include "[zsj]-3D Coordinate System.h"


// 双窗口 可参考的文章 示例;
// http://cg2010studio.com/2011/06/27/subwindow/


//#define  CUBE_ARRAY_SIZE 24   //立方体每个面有4个顶点
float* MultiWindows::m_corners = NULL;
MultiWindows* MultiWindows::m_pSceneManager = NULL;
int MultiWindows::frameCount = 0;

const float	screen_scale = 1.0f/2000.0f;				// 缩放比例
const int		delay_call = 100;						// ms 毫秒，延迟多少 毫秒来调用函数。

static int mainWindow;
static int subWindow1; 
static int subWindow2;

MultiWindows* MultiWindows::sharedSceneManager()
{
	if(m_pSceneManager == NULL)
	{
		m_pSceneManager = new MultiWindows();
	}
	return m_pSceneManager;
}

//=========================================================================
//
//							窗口渲染
//
//=========================================================================
void MultiWindows::renderSceneAll( void )
{
	mainWindowsRender();
	myDisplay1();
}


void MultiWindows::mainWindowsRender(void)  
{  
	// 测试用例
	glClear(GL_COLOR_BUFFER_BIT); 
	glColor3f(1.0, 1.0, 1.0);		// 白色
	glutWireTeapot(0.5);			// 画个大茶壶
	
	
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
	glutSwapBuffers();
}

void MultiWindows::myDisplay1(void)  
{  
	glClear(GL_COLOR_BUFFER_BIT); 
	glColor3f(1.0, 1.0, 0.0);	//黄色
	glutWireTeapot(0.5); 
	glutSwapBuffers();
}

void MultiWindows::myDisplay2(void)  
{  
	glClear(GL_COLOR_BUFFER_BIT); 
	glColor3f(0.0, 0.0, 1.0);	//色蓝
	glutWireTeapot(0.5); 
	glutSwapBuffers();
}

// 输入
static void ProcessMouse(int button,int state,int x,int y)			// 鼠标响应
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		GLfloat ang = -10;			
		glRotatef(ang, -1,0,1);
		glutPostRedisplay();		// 标记当前窗口需要重新绘制

	} else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		GLfloat ang = 10;			
		glRotatef(ang, -1,0,1);
		glutPostRedisplay();

	}
}




//=========================================================================
//
//							窗口初始化
//
//=========================================================================
int MultiWindows::windowsInit(int argc, _TCHAR* argv[])  
{  
	glutInit(&argc, (char**) argv);					// 初始化glut,必须调用，复制黏贴这句话即可  
	//glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);	// 设置显示方式，RGB、单缓冲。当然还有GLUT_INDEX索引颜色 GLUT_DOUBLE双缓冲(Qt中看到过双缓冲) 
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(300,300);				// 窗口在显示器屏幕中的位置，指定的是窗口左上角的坐标。(0,0)就会显示在屏幕左上角。  
	glutInitWindowSize(ScreenSize.x, ScreenSize.y);					// 设置所需窗口大小  

	// 创建主窗口
	mainWindow  = glutCreateWindow((char*)argv[0]);				// 这样也行啊？
	glutDisplayFunc(mainWindowsRender);							// callbacks for main window
	glutMouseFunc(ProcessMouse);					// 主窗口 开启响应 鼠标函数
	//glutTimerFunc(delay_call, TimerFunction, 1);
	//glutIdleFunc(renderSceneAll);								// 核心的一行代码

	

	// 创建子窗口1
	subWindow1 = glutCreateSubWindow(mainWindow , 30, 30, 250, 250);		//子窗口的原点和尺寸，（其原点是主窗口的右上角起始位置）
	glutDisplayFunc(myDisplay1);								//绘制子窗口颜色
	//glutPostWindowRedisplay(subWindow1);						//通知标识符为id1的窗口重新绘制
	glutMouseFunc(&ProcessMouse);					// 子窗口 开启响应 鼠标函数
	//glutTimerFunc(500 + delay_call, subTimerFunction, 1);

	// 创建子窗口2
	subWindow2 = glutCreateSubWindow(mainWindow , 100, 100, 250, 250);		//子窗口的原点和尺寸，（其原点是主窗口的右上角起始位置）
	glutDisplayFunc(myDisplay2);								//绘制子窗口颜色
	glutMouseFunc(&ProcessMouse);					// 子窗口 开启响应 鼠标函数


	glutMainLoop();									// 无限执行的循环，glutMainLoop()会判断窗口是否需要进行重绘， 会自动调用 glutDisplayFunc()中注册的函数。   
	return 0;  
}  

/*	初始化说明
1、首先将必要的头文件glut.h包含进来，以便使用opengl提供的函数库
2、mydisplay是程序员自己写的回调函数，用于在窗口内进行画图。在主函数里用glutDisplayFunc把它注册之后，
每次窗口里的图像需要刷新时，就调用这个我们写的mydisplay函数。
3、glutInitWindowSize函数指定窗体的宽度和高度
4、glutInitWindowPosition指定窗口左上角的坐标
5、glutCreateWindow建立一个窗体
6、glutMainLoop进入窗体消息循环。
以后如无特别说明，后面的例子代码只改动display函数的内容即可。
*/


void MultiWindows::TimerFunction(int value)
{
	//frameCount++;


	GLfloat ang = 10;			
	glRotatef(ang, -1,0,1);
	glutPostWindowRedisplay(mainWindow);			// 指定的窗口需要重新绘制，去调用 glutDisplayFunc(mainWindowsRender); 里注册的 mainWindowsRender 函数。
	//glutPostRedisplay();							// 标记当前窗口的图像层需要重新绘制
	glutTimerFunc(delay_call, TimerFunction, 1);
	
}

void MultiWindows::subTimerFunction(int value)
{
	GLfloat ang = 10;			
	glRotatef(ang, -1,0,1);
	glutPostWindowRedisplay(subWindow1);
	glutTimerFunc(500+delay_call, subTimerFunction, 1);
}
