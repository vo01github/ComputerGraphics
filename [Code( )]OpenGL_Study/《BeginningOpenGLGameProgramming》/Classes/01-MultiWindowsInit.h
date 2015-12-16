

#pragma once

#include <tchar.h>



class MultiWindows 
{
public:
	static int windowsInit(int argc,_TCHAR* argv[]);

	void static renderSceneAll(void);					// 所有 窗口的渲染
	void static mainWindowsRender(void);				// 主窗口渲染
	void static myDisplay1(void);						// 子窗口渲染


	static MultiWindows* sharedSceneManager();			// 单例模式

	static void TimerFunction(int value);				// 给定时器调用的。
	static void subTimerFunction(int value);				// 给定时器调用的。


	//static
private:

	static MultiWindows* m_pSceneManager;

	static float* m_corners;
	static int frameCount;
};




