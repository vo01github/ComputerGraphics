// 《BeginningOpenGLGameProgramming》.cpp : 定义控制台应用程序的入口点。
#include "stdafx.h"

#include "01-windowsInit.h"


int _tmain(int argc, _TCHAR* argv[])
{
	OpenGLwindows* zsj = new OpenGLwindows();

	zsj->windowsInit(argc, argv);

	return 0;
}
