

#include <vector>
#include<gl/glut.h> 
#include "[glutReshapeFunc].h"


//=========================================================================
//
//					注册 改变窗口时的 回调函数 ：glutReshapeFunc
//
//=========================================================================
/*
当改变窗体大小的时候,高宽比例改变,三角形就会扭曲.得到这样的效果的原因是我们没设置正确的视觉.
视觉默认是声明宽高比为1并依此来绘图.所以当比例改变的时候,视觉会发生扭曲.
因此,每次比例改变的时候视觉必须要重新计算.

GLUT提供了一个回调接口给窗体大小改变事件.
此外,该函数在窗体初始化创建的时候也会被调用,
所以即便你初始化的窗体不是正方形看上去也不会有问题.

01：	如果注册了这个函数glutReshapeFunc，那么在创建窗口的时候就要调用到。


其他教学文章：
http://www.cnblogs.com/yxnchinahlj/archive/2010/10/30/1865298.html
http://blog.sina.com.cn/s/blog_46da01db0100juxw.html

*/



int GlutReshapeFunc::init( int argc,_TCHAR* argv[] )
{
	glutInit(&argc,(char**)argv);

	// 创建窗口
	glutInitWindowPosition(100, 100);				// 定义窗体的位置
	glutInitWindowSize(800, 800);					// 定义窗体的大小
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);	// 定义显示模式
	glutCreateWindow("改变窗体大小");			// 完成以上3个以后就可以定义窗体了
	
	// 回调函数注册
	glutDisplayFunc(displayCall);					// 注册 渲染 回调函数
	glutReshapeFunc(changeSizeCall);				// 注册 改变窗口时的 回调函数，第1次渲染时也会被调用

	//
	glutMainLoop();									// 事件处理死循环
	
	return 0;  
}

void GlutReshapeFunc::displayCall()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	glVertex3f(-2,-2,-5.0);
	glVertex3f(2,0.0,-5.0);
	glVertex3f(0.0,2,-5.0);
	glEnd();
	glFlush();
}

void GlutReshapeFunc::changeSizeCall(int w, int h) 
{
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if(h == 0) h = 1;
	float ratio = 1.0 * w / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	//gluPerspective(45,1,1,100);	-- 默认的设置参数？
	gluPerspective(45,ratio,1,100);

	//glOrtho(-2.5, 2.5, -2.5, 2.5, -10, 10);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}


//void changeSize(GLsizei w, GLsizei h)
//{
//	GLfloat aspectRatio;
//
//	if (h == 0)
//	{
//		h = 1;
//	}
//
//	glViewport(0, 0, w, h);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//
//	aspectRatio = (GLfloat)w / (GLfloat)h;
//
//	GLdouble left = PlotCubes::xStartCordinate;
//	GLdouble right = PlotCubes::xEndCordinate;
//	GLdouble bottom = PlotCubes::yStartCordinate;
//	GLdouble top = PlotCubes::yEndCordinate;
//	GLdouble near = PlotCubes::zStartCordinate;
//	GLdouble far = PlotCubes::zEndCordinate;
//
//	if (w <= h)
//	{
//		glOrtho(left, right, bottom / aspectRatio, top / aspectRatio, near, far);
//	}
//	else
//	{
//		glOrtho(left*aspectRatio, right*aspectRatio, bottom, top, near, far);
//	}
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
