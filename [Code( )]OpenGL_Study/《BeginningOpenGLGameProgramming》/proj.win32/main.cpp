// 《BeginningOpenGLGameProgramming》.cpp : 定义控制台应用程序的入口点。
#include "stdafx.h"

#include "01-windowsInit.h"
#include <windows.h>  
//#include "[zsj]-IPC-Pipe.h"
//#include "NamedPipeServer.h"

//子线程函数 
DWORD WINAPI ThreadFun(LPVOID pM)  
{  
	printf("子线程的线程ID号为：%d\n子线程输出Hello World\n", GetCurrentThreadId()); 

	return 0;  
}  

HANDLE hMutex;

struct RECVPARAM
{
	int argc;
	_TCHAR** argv;
};


DWORD WINAPI plotCubesbyOpenGL(LPVOID lpParamter)
{
	///////////////////////test 单独测试绘制代码///////////////////////////////////////////////////////
	OpenGLwindows *zsj = new OpenGLwindows();
	int argc = ( (RECVPARAM*)lpParamter )->argc;
	_TCHAR** argv = ( (RECVPARAM*)lpParamter )->argv;
	zsj->windowsInit(argc, argv);

	return 0;
}

#if 1

//主函数，所谓主函数其实就是主线程执行的函数。  
int _tmain(int argc, _TCHAR* argv[])
{
	//HANDLE handle = CreateThread(NULL, 0, ThreadFun, NULL, 0, NULL); 

	// 主线程显示窗口，主线程和子线程只会有一个显示。
	//OpenGLwindowsSon* zsj = new OpenGLwindowsSon();
	//zsj->windowsInit(argc, argv);

	// 子线程开 openGL窗口
	RECVPARAM *pRecvParam = new RECVPARAM;  //新建一个结构体指针，并赋予内存空间  
	pRecvParam->argc = argc;				//将定义好的socket赋值给结构体成员  
	pRecvParam->argv = argv;		//将主窗口句柄赋值给结构体成员  
	HANDLE hThread = CreateThread(NULL, 0, plotCubesbyOpenGL, (LPVOID)pRecvParam, 0, NULL);


	//hMutex = CreateMutexA(NULL, FALSE, "screen");
	//CloseHandle(hThread);
	while (1)
	{

	}

	return 0;
}

#endif



