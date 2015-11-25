#ifndef __OBJECT_MAN_H__
#define __OBJECT_MAN_H__



#include <tchar.h>



class OpenGLwindows 
{
public:
	static int windowsInit(int argc,_TCHAR* argv[]);
	void static myDisplay(void);

	static OpenGLwindows* sharedSceneManager();			// 单例模式

	static void TimerFunction(int value);				// 给定时器调用的。

	static void showCubes();

	//static
private:

	static OpenGLwindows* m_pSceneManager;

	static float* m_corners;
	static int frameCount;
};


class OpenGLwindowsSon  : public  OpenGLwindows
{

};


#endif // __OBJECT_MAN_H__