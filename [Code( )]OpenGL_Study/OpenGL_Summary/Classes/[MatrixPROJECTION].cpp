

#include <vector>
#include<gl/glut.h> 
#include "[MatrixPROJECTION].h"


//=========================================================================
//
//			投影矩阵:GL_PROJECTION		
//	透视函数:glFrustum(), gluPerspective()和glOrtho() 用法	
//
//=========================================================================
/*

	好吧，2个投影，平行投影的效果可以跑出来。
	透视投影的效果还没有跑出来。

	可以参考的资料有《OpenGL编程指南(原书第8版)》 “第5章 视口变换，剪切与反馈”
*/



int MatrixPROJECTION::init( int argc,_TCHAR* argv[] )
{
	glutInit(&argc,(char**)argv);

	// 创建窗口
	glutInitWindowPosition(100, 100);				// 定义窗体的位置
	glutInitWindowSize(800, 800);					// 定义窗体的大小
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);	// 定义显示模式
	glutCreateWindow("投影矩阵");			// 完成以上3个以后就可以定义窗体了
	
	// 回调函数注册
	glutDisplayFunc(displayCall);					// 注册 渲染 回调函数
	glutReshapeFunc(changeSizeCall);				// 注册 改变窗口时的 回调函数，第1次渲染时也会被调用

	//
	glutMainLoop();									// 事件处理死循环
	
	return 0;  
}

void MatrixPROJECTION::displayCall()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

#if 0
	glBegin(GL_);
	glVertex3f(-2,-2,-5.0);
	glVertex3f(2,0.0,-5.0);
	glVertex3f(0.0,2,-5.0);
	glEnd();
#endif

	// 画2条长度一样的线段
	glBegin(GL_LINES);
	glVertex3f(-0.5,0,0);		//	点P1  
	glVertex3f(0.5,0,0);		//	点P2 

	glVertex3f(-0.5,0.2,-0.5);		//	点P1  
	glVertex3f(0.5,0.2,-0.5);		//	点P2 
	glEnd(); 

#if 0
	// // 画一个茶壶。
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(-0.8,0,0);
	glutWireTeapot(0.5);		
#endif

	glFlush();
}

void MatrixPROJECTION::changeSizeCall(int w, int h) 
{
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if(h == 0) h = 1;
	float ratio = 1.0 * w / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);		//将当前矩阵指定为投影矩阵

	// Reset Matrix
	glLoadIdentity();					//然后把矩阵设为单位矩阵

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// 创建一个透视投影
	//glFrustum(-2, 2, -2, 2, -100, 100);

	// 透视投影
	gluPerspective(30,ratio,10,100);

	// 平行投影
	// left, right, bottom, top, 近处，远处. 【近处和远处 不应该取相同的值】
	//glOrtho(-2, 2, -2, 2, -100, 100);

	
	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
/*
	在调用glMatrixMode(GL_MODELVIEW)时，系统会自动将几何变换栈清空并压入单位矩阵，
	因此不必再调用glLoadIdentity()函数。
*/ 


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
