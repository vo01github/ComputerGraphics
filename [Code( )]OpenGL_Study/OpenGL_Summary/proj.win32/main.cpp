// 《BeginningOpenGLGameProgramming》.cpp : 定义控制台应用程序的入口点。
#include "stdafx.h"

#include "01-windowsInit.h"


int _tmain(int argc, _TCHAR* argv[])
{
	OpenGLwindows* OpenGL_Summary = new OpenGLwindows();
	OpenGL_Summary->windowsInit(argc, argv);
	return 0;
}
