// 《BeginningOpenGLGameProgramming》.cpp : 定义控制台应用程序的入口点。
#include "stdafx.h"

//#include "01-windowsInit.h"
#include "01-MultiWindowsInit.h"
#include <windows.h>  
//#include "[zsj]-IPC-Pipe.h"
//#include "NamedPipeServer.h"

//#include "[zsj]-Multithreading.h"		// 包含了这个，就把下面的 main 屏蔽掉。

#if 1

//主函数，所谓主函数其实就是主线程执行的函数。  
int _tmain(int argc, _TCHAR* argv[])
{
	// 只显示一个窗口
#if 0
	OpenGLwindowsSon* zsj = new OpenGLwindowsSon();
	zsj->windowsInit(argc, argv);
#endif

	// 显示父窗口 + 子窗口
	MultiWindows* zsj = new MultiWindows();
	zsj->windowsInit(argc, argv);
	

	return 0;
}

#endif



