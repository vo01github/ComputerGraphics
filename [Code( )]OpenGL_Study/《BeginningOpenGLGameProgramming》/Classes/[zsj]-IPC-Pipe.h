
#ifndef __DL_IPC_PIPE_H__
#define __DL_IPC_PIPE_H__


#include <vector>


#include <Windows.h>
#include <tchar.h>
#include <process.h>
#include <iostream>
#include <stdio.h>
using namespace std;
HANDLE readpipe,writepipe;

/*
也可以用管道进行通信，管道是流式通信的一种方式，管道有两种命名管道和匿名管道。
匿名管道的创建可以调用CreatePipe()，创建命名管道可以调用CreateNamedPipe()，
调用WriteFile通过管道发送数据，ReadFile从管道读取数据。


对于匿名管道的话，其也只能实现本机上进程之间的通信，
你要是能够实现本机进程间的通信也就算了，
关键是它还只用来实现本地的父子进程之间的通信，也太局限了吧？


对于匿名管道而言，其只能实现在父进程和子进程之间进行通信，而对于命名管道而言，
其不仅可以在本地机器上实现两个进程之间的通信，还可以跨越网络实现两个进程之间的通信。


*/

unsigned int __stdcall stage1(void * param)
{
	char buf[200];
	DWORD len;
	for (int i=0;i<10;i++)
	{
		sprintf_s(buf,"Text %i",i);
		WriteFile(writepipe,buf,strlen(buf)+1,&len,0);
	}
	CloseHandle(writepipe);
	return 0;
}

unsigned int __stdcall stage2(void * param)
{
	char buf[200];
	DWORD len;
	while(ReadFile(readpipe,buf,200,&len,0))
	{
		DWORD offset=0;
		while(offset<len)
		{
			cout<<&buf[offset]<<endl;
			offset+=strlen(&buf[offset])+1;
		}
	}
	CloseHandle(readpipe);
	return 0;
}

// 匿名管道的创建
int _tmain(int argc, _TCHAR* argv[]){
	HANDLE thread1,thread2;
	CreatePipe(&readpipe,&writepipe,0,0);			
	thread1=(HANDLE)_beginthreadex(0,0,&stage1,0,0,0);
	thread2=(HANDLE)_beginthreadex(0,0,&stage2,0,0,0);
	WaitForSingleObject(thread1,INFINITE);
	WaitForSingleObject(thread2,INFINITE);
	getchar();
	return 0;
}











#endif // __DL_IPC_PIPE_H__