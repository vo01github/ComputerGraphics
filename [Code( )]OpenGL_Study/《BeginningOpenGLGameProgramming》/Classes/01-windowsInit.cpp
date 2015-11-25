
#include<stdlib.h>
#include<cstdio>
#include<stdlib.h>
#include <cstdio>
#include <iostream>
using namespace std;

#include<gl/glut.h> 

#include "01-windowsInit.h"
#include "01-SimpleGraphics.h"
#include "02-ComplexGraphics.h"
#include "03-draw15000Triangles.h"
#include "00-DataDefinition.h"
#include "[zsj]-3D Coordinate System.h"

#define  CUBE_ARRAY_SIZE 24   //立方体每个面有4个顶点
float* OpenGLwindows::m_corners = NULL;
OpenGLwindows* OpenGLwindows::m_pSceneManager = NULL;
int OpenGLwindows::frameCount = 0;

float	screen_scale = 1.0f/2000.0f;				// 缩放比例
int		delay_call = 500;						// ms 毫秒，延迟多少 毫秒来调用函数。

OpenGLwindows* OpenGLwindows::sharedSceneManager()
{
	if(m_pSceneManager == NULL)
	{
		m_pSceneManager = new OpenGLwindows();
	}
	return m_pSceneManager;
}



void OpenGLwindows::myDisplay(void)  
{  
	myDisplay_Draw_3D_Coordinate_System_On_Windows_function();
	showCubes();
}

// 输入
void ProcessMouse(int button,int state,int x,int y)			// 鼠标响应
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		GLfloat ang = -10;			
		glRotatef(ang, -1,0,1);
		glutPostRedisplay();
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
int OpenGLwindows::windowsInit(int argc, _TCHAR* argv[])  
{  
	glutInit(&argc, (char**) argv);					// 初始化glut,必须调用，复制黏贴这句话即可  
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);	// 设置显示方式，RGB、单缓冲。当然还有GLUT_INDEX索引颜色 GLUT_DOUBLE双缓冲(Qt中看到过双缓冲)  
	glutInitWindowPosition(300,300);				// 窗口在显示器屏幕中的位置，指定的是窗口左上角的坐标。(0,0)就会显示在屏幕左上角。  
	glutInitWindowSize(ScreenSize.x, ScreenSize.y);					// 设置所需窗口大小  

	//glutCreateWindow("第一个OpenGL程序");			// 创建窗口，设置标题  
	glutCreateWindow((char*)argv[0]);				// 这样也行啊？
	//glutDisplayFunc(&this->myDisplay);				// 当绘制窗口时调用myDisplay，像Cocos2d-x刷帧Draw中的操作  
	//glutDisplayFunc(&(OpenGLwindows::myDisplay));
	//glutDisplayFunc((OpenGLwindows::sharedSceneManager()->myDisplay));	
	glutDisplayFunc(myDisplay);	
	glutMouseFunc(&ProcessMouse);
	glutTimerFunc(500 + delay_call, TimerFunction, 1);			// 定时器的使用, 输入的参数必须用 static 函数。 第1次调用需要 500ms 以上才能保证myDisplay()那边的初始化完成。
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


glutTimerFunc 参数对应关系为：glutTimerFunc(毫秒数, 回调函数指针, 区别值);

  （1）如果用定时器的话，初始的时候注册一个定时器的回调函数，原型是
  glutTimerFunc(unsigned int millis, void (*func)(int value), int value);
  参数对应关系为：glutTimerFunc(毫秒数, 回调函数指针, 区别值);
  （2）写自己的回调函数 void OnTimer(int value);
  用value区分是哪个定时器
  （3）在函数里改变和位置有关的变量，然后调用glutPostRedisplay();用来重绘
  （4）最后再次调用glutTimerFunc，因为glut的定时器是调用一次才产生一次定时，所以如果要持续产生定时的话，
*/

void OpenGLwindows::TimerFunction(int value)
{
	frameCount++;

	//glutPostRedisplay();
	GLfloat ang = 10;			
	glRotatef(ang, -1,0,1);
	glutPostRedisplay();

	glutTimerFunc(delay_call, TimerFunction, 1);
}


void OpenGLwindows::showCubes()
{
	///////////////////////////test 绘制单个方格///////////////////////////////////////////
	//GLfloat corners[] = { -100, 100, 100,
	//	100, 100, 100,
	//	100, -100, 100,
	//	-100, -100, 100,
	//	-100, 100, -100,
	//	100, 100, -100,
	//	100, -100, -100,
	//	-100, -100, -100 };

	//GLfloat corners[] = { 300, 1500, -700,
	//	500, 1500, -700,
	//	500, 1300, -700,
	//	300, 1300, -700,
	//	300, 1500, -900,
	//	500, 1500, -900,
	//	500, 1300, -900,
	//	300, 1300, -900 };
	if ( frameCount % 2 == 0 )
	{
		GLfloat corners[] = { 
			-100*screen_scale,  100*screen_scale,  100*screen_scale,
			 100*screen_scale,  100*screen_scale,  100*screen_scale,
			 100*screen_scale, -100*screen_scale,  100*screen_scale,
			-100*screen_scale, -100*screen_scale,  100*screen_scale,
			-100*screen_scale,  100*screen_scale, -100*screen_scale,
			 100*screen_scale,  100*screen_scale, -100*screen_scale,
			 100*screen_scale, -100*screen_scale, -100*screen_scale,
			-100*screen_scale, -100*screen_scale, -100*screen_scale };
		m_corners = corners;
		cout << "原点方格" << endl;
		Sleep(1);
	}
	else
	{
		GLfloat corners[] = { 
			300*screen_scale, 1500*screen_scale, -700*screen_scale,
			500*screen_scale, 1500*screen_scale, -700*screen_scale,
			500*screen_scale, 1300*screen_scale, -700*screen_scale,
			300*screen_scale, 1300*screen_scale, -700*screen_scale,
			300*screen_scale, 1500*screen_scale, -900*screen_scale,
			500*screen_scale, 1500*screen_scale, -900*screen_scale,
			500*screen_scale, 1300*screen_scale, -900*screen_scale,
			300*screen_scale, 1300*screen_scale, -900*screen_scale };
		m_corners = corners;
		cout << "非原点方格" << endl;
		Sleep(1);
	}



	int indexes[] = { 0, 1, 2, 3, //单个立方体显示的顶点索引
		4, 5, 1, 0,
		3, 2, 6, 7,
		5, 4, 7, 6,
		1, 5, 6, 2,
		4, 0, 3, 7 };
	//////////////////////////////////////////////////////////////////////////////

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glColor3f(1.0, 1.0, 1.0);//网格线条颜色
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, m_corners);
	//glDrawElements(GL_QUADS, cubesNums * CUBE_ARRAY_SIZE, GL_UNSIGNED_INT, indexes);
	glDrawElements(GL_QUADS, CUBE_ARRAY_SIZE, GL_UNSIGNED_INT, indexes);
	glPopMatrix();

	glutSwapBuffers();

}