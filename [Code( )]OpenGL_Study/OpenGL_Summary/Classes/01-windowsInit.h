#ifndef __OBJECT_MAN_H__
#define __OBJECT_MAN_H__



#include <tchar.h>



class OpenGLwindows 
{
public:
	int windowsInit(int argc,_TCHAR* argv[]);
	void static myDisplay(void);

	static OpenGLwindows* sharedSceneManager();			// 单例模式

private:
	static OpenGLwindows* m_pSceneManager;

	int templateTest(int argc,_TCHAR* argv[]);
};




#endif // __OBJECT_MAN_H__