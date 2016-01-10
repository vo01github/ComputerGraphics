

#include <vector>
#include<gl/glut.h> 
#include "[glutIdleFunc].h"


//=========================================================================
//
//					注册 绑定应用程序空闲时事件 ：glutIdleFunc
//					// 其实就是相当于 cocos2dx 里面的 update() 函数
//=========================================================================
/*
首先我们要告知GLUT应用程序当处于空闲时,渲染函数要被调用.
这样可促使GLUT保持调用渲染函数来启用动画效果.

GLUT提供一个函数glutIdleFunc来让你注册一个回调函数用于绑定应用程序空闲时事件.

void glutIdleFunc(void (*func)(void));

func – 空闲事件触发的函数		
*/

static float angle = 0.0f;

void GlutIdleFunc::renderScene(void) {

	// Clear Color Buffers 把缓存上的像素颜色数据全部清除。
	glClear(GL_COLOR_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	// Set the camera
	gluLookAt(    0.0f, 0.0f, 10.0f,
		0.0f, 0.0f,  0.0f,
		0.0f, 1.0f,  0.0f);

	glRotatef(angle, 0.0f, 1.0f, 0.0f);	// 绕着 y轴旋转

	glBegin(GL_TRIANGLES);
	glVertex3f(-1.0f,-1.0f, 0.0f);
	glVertex3f( 1.0f, 0.0f, 0.0);
	glVertex3f( 0.0f, 1.0f, 0.0);
	glEnd();

	angle += 0.1f;

	glutSwapBuffers();
}


int GlutIdleFunc::init( int argc,_TCHAR* argv[] )
{
	glutInit(&argc,(char**)argv);

	// 创建窗口
	glutInitWindowPosition(100, 100);				// 定义窗体的位置
	glutInitWindowSize(800, 800);					// 定义窗体的大小
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);	// 定义显示模式
	glutCreateWindow("绑定应用程序空闲时事件");		// 完成以上3个以后就可以定义窗体了
	
	// 注册回调函数
	// register callbacks
	glutDisplayFunc(renderScene);					// 注册 重绘事件
	glutReshapeFunc(changeSizeCall);				// 注册 窗体更改大小事件 【第1次渲染时也会被调用】
	glutIdleFunc(renderScene);						// 注册 系统空闲事件

	//
	glutMainLoop();									// 事件处理死循环
	
	return 0;  
}

void GlutIdleFunc::displayCall()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	glVertex3f(-0.5,-0.5,0.0);
	glVertex3f(0.5,0.0,0.0);
	glVertex3f(0.0,0.5,0.0);
	glEnd();
	glFlush();
}

void GlutIdleFunc::changeSizeCall(int w, int h) {

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


	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}
