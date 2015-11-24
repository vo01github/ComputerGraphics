// 《BeginningOpenGLGameProgramming》.cpp : 定义控制台应用程序的入口点。
#include "stdafx.h"

#include "01-windowsInit.h"
#include <windows.h>  
//#include "[zsj]-IPC-Pipe.h"
#include "NamedPipeServer.h"

//子线程函数 
DWORD WINAPI ThreadFun(LPVOID pM)  
{  
	printf("子线程的线程ID号为：%d\n子线程输出Hello World\n", GetCurrentThreadId()); 

	return 0;  
}  

#if 0

//主函数，所谓主函数其实就是主线程执行的函数。  
int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE handle = CreateThread(NULL, 0, ThreadFun, NULL, 0, NULL); 

	OpenGLwindows* zsj = new OpenGLwindows();

	zsj->windowsInit(argc, argv);

	return 0;
}

#endif



