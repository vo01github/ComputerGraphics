

#include <vector>
#include<gl/glut.h> 
#include "[glutDisplayFunc].h"


//=========================================================================
//
//					定义显示模式 ：glutInitDisplayMode
//
//=========================================================================
/*
参数mode是由GLUT库预定义的可选值组成的一个布尔组合(OR位模式),用来指定颜色模型和缓冲的数量和类型.

预定义常量如下:
GLUT_RGBA / GLUT_RGB - 选择RGBA窗体.这是默认选项.
GLUT_INDEX - 选择颜色索引模式

显示模式允许选择单缓冲或双缓冲的窗体,预定义常量如下:
GLUT_SINGLE - 单缓存窗体
GLUT_DOUBLE - 双缓冲窗体,需要支持平滑运动

另外,你可以指定专用的缓冲集合
GLUT_ACCUM - 堆缓冲
GLUT_STENCIL - 模版缓冲
GLUT_DEPTH - 深度缓冲

假定你要创建一个RGB的双缓冲和深度缓冲的窗体.你要做的是用"或"合并这些常量.
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT DEPTH);
*/



//=========================================================================
//
//				渲染函数和回调注册 ：glutDisplayFunc
//
//=========================================================================
/*
该绑定操作叫作注册一个回调.GLUT会在需要渲染的时候调用该函数.

现在就告诉GLUT库renderScene函数需要在窗体绘制的时候调用.GLUT有一个专门函数来做绑定回调函数的操作,
需要在窗体创建的时候调用,原型如下:
void glutDisplayFunc(void (*funcName)(void));

告诉GLUT一个事件对应哪个函数的方法是注册回调函数(callback function).
每一个事件类型GLUT都提供一个指定的函数来注册回调函数.
*/



//=========================================================================
//
//				事件处理循环 ：glutMainLoop
//
//=========================================================================
/*
GLUT进入事件处理循环之后会获得程序的控制权.GLUT会等待事件(event)发生,然后检查有没有绑定的函数来处理它.

所以在GLUT进入它的事件处理循环之前,我们要先告诉GLUT事件发生时需要调用哪个函数来处理.

你是不是想问什么是事件(event).事件就是诸如键盘的键被按下,鼠标被移动,窗体需要绘制(到显示器屏幕),
还有窗体被改变大小,还有很多.. 
*/

int GlutDisplayFunc::init( int argc,_TCHAR* argv[] )
{
	glutInit(&argc,(char**)argv);

	glutInitWindowPosition(100, 100);				// 定义窗体的位置
	glutInitWindowSize(800, 800);					// 定义窗体的大小
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);	// 定义显示模式
	glutCreateWindow("初始化");						// 完成以上3个以后就可以定义窗体了
	
	glutDisplayFunc(displayCall);					// 注册-渲染函数-回调

	glutMainLoop();									// 事件处理死循环
	
	return 0;  
}

void GlutDisplayFunc::displayCall()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	glVertex3f(-0.5,-0.5,0.0);
	glVertex3f(0.5,0.0,0.0);
	glVertex3f(0.0,0.5,0.0);
	glEnd();
	glFlush();
}



