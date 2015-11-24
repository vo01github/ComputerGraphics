
#ifndef __IPC_NAME_PIPE_SERVER_H__
#define __IPC_NAME_PIPE_SERVER_H__


#include <vector>


#include <Windows.h>
#include <tchar.h>
#include <process.h>
#include <iostream>
#include <stdio.h>
using namespace std;

////用来保存在客户端通过 CreateFile 打开的命名管道句柄
HANDLE            hNamedPipe;

const char *    pStr        = "Zachary456";
#define MY_PIPE_NAME L"\\\\.\\pipe\\ZacharyPipe"


// 前置声明
void OpenNamedPipeInClient();				//打开命名管道
void NamedPipeReadInClient();				//客户端从命名管道中读取数据
void NamedPipeWriteInClient();				//客户端往命名管道中写入数据


int main(int argc, char * argv)
{
	OpenNamedPipeInClient();

	//接收服务端发来的数据
	NamedPipeReadInClient();

	//往命名管道中写入数据
	NamedPipeWriteInClient();

	system("pause");
}


void OpenNamedPipeInClient()
{
	//等待连接命名管道
	if(!WaitNamedPipe(MY_PIPE_NAME, NMPWAIT_WAIT_FOREVER))
	{
		cout<<"命名管道实例不存在 ..."<<endl<<endl;
		return;
	}

	//打开命名管道
	hNamedPipe = CreateFile(MY_PIPE_NAME, GENERIC_READ | GENERIC_WRITE, 
		0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if(INVALID_HANDLE_VALUE == hNamedPipe)
	{
		cout<<"打开命名管道失败 ..."<<endl<<endl;
		return;
	}
}


void NamedPipeReadInClient()
{
	char *                pReadBuf;
	DWORD                dwRead;

	pReadBuf = new char[strlen(pStr) + 1];
	memset(pReadBuf, 0, strlen(pStr) + 1);

	//从命名管道中读取数据
	if(!ReadFile(hNamedPipe, pReadBuf, strlen(pStr), &dwRead, NULL))
	{
		delete []pReadBuf;

		cout<<"读取数据失败 ..."<<endl<<endl;
		return;
	}
	cout<<"读取数据成功：    "<<pReadBuf<<endl<<endl;
}


void NamedPipeWriteInClient()
{
	DWORD                dwWrite;

	//向命名管道中写入数据
	if(!WriteFile(hNamedPipe, pStr, strlen(pStr), &dwWrite, NULL))
	{
		cout<<"写入数据失败 ..."<<endl<<endl;
		return;
	}
	cout<<"写入数据成功：    "<<pStr<<endl<<endl;
}




#endif // __IPC_NAME_PIPE_SERVER_H__