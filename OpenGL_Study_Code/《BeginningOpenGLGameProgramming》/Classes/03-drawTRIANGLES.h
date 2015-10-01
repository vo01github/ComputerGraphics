
#include<stdlib.h>
#include<cstdio>
#include<stdlib.h>
#include <cstdio>
#include <iostream>
using namespace std;

#include<gl/glut.h> 


/*		本文 学习到内容

凸多边形模拟圆


*/
// OpenGLTest3.cpp : 定义控制台应用程序的入口点。
//
#include <GLTools.h>
#include <GLShaderManager.h>//导入GLTools着色管理器
#ifdef _APPLE_
#include <glut/glut.h>
#else
#define FREEGLUT_STATIC //添加处理宏
#include <GL/glut.h>
#endif
//着色管理器
GLShaderManager shaderManager;
GLBatch triangleBatch;
//在改变窗口大小时，接受新的宽高
void ChangeSize(int w,int h)
{
 glViewport(0,0,w,h);//修改从目的坐标系到屏幕坐标系上的映射
}
void SetupRC()
{
 //清理窗口颜色（设置背景颜色）
 glClearColor(0,0,1,1);
 shaderManager.InitializeStockShaders();
 GLfloat vVerts[] = {-0.5f,0.0f,0.0f,
      0.5f,0.0f,0.0f,
      0.0f,0.5f,0.0f};
 //对三角形顶点批次进行封装
 triangleBatch.Begin(GL_TRIANGLES,3);
 triangleBatch.CopyVertexData3f(vVerts);
 triangleBatch.End();
}
void RenderScene(void)
{
	 //清除缓冲区
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	 GLfloat vRed[] = {1.0,0.0f,0.0f,1.0f};
	 shaderManager.UseStockShader(GLT_SHADER_IDENTITY,vRed);
	 triangleBatch.Draw();
	 // 执行缓冲区交换回显示缓冲区
	 glutSwapBuffers();
}
int _tmain(int argc, char* argv[])
{
	 //设置当前工作目录，Windows中不起作用，mac中，将目录改为程序绑定目录
	 gltSetWorkingDirectory(argv[0]);
	 //初始化GLUI库
	 glutInit(&argc,argv);
	 /*
	 设置创建窗口时使用的显示方式
	 GLUT_DOUBLE：使用双缓冲窗口
	 GLUT_RGBA：使用RGBA颜色模式
	 GLUT_DEPTH：标志一个深缓冲区分配为显示的一部分
	 GLUT_STENCIL：确保有一个可用的模版缓冲区
	 */
	 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
	 //设置窗口大小
	 glutInitWindowSize(800,600);
	 //设置窗口标题
	 glutCreateWindow("三角形");
	 //消息循环，调用不同时间的回调函数
	 glutReshapeFunc(ChangeSize);
	 glutDisplayFunc(RenderScene);
	 //进行渲染前，判断初始化过程中是否出错
	 GLenum err = glewInit();
	 if(GLEW_OK != err)
	 {
	  fprintf(stderr,"初始化错误:%sn",glewGetErrorString(err));
	 }
	 //设置渲染环境
	 SetupRC();
	 //开始主消息循环
	 glutMainLoop();//在主窗口被关闭之前，不会返回，一个应用只需调用一次。负责处理系统特定消息、按键动作等。
	 return 0;
}