#pragma once

#include <tchar.h>



class OpenGLwindows 
{
public:
	static int windowsInit(int argc,_TCHAR* argv[]);
	void static myDisplay(void);

	static OpenGLwindows* sharedSceneManager();			// 单例模式

	static void TimerFunction(int value);				// 给定时器调用的。



	//static
private:

	static OpenGLwindows* m_pSceneManager;

	static float* m_corners;
	static int frameCount;
};


class OpenGLwindowsSon  : public  OpenGLwindows
{

};


