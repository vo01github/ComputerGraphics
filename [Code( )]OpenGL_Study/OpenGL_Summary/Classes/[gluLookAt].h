#pragma once;


#include <tchar.h>

class GluLookAt {

public:
	static	int		init( int argc,_TCHAR* argv[] );

private:

	// register callbacks
	static	void	displayCall();						// 注册 重绘事件
	static	void	changeSizeCall(int w, int h);		// 注册 窗体更改大小事件 【第1次渲染时也会被调用】
	static	void	renderScene();						// 注册 系统空闲事件

	static	void	processNormalKeys(unsigned char key, int x, int y);
	static	void	processSpecialKeys(int key, int x, int y); 

	static	void	drawSnowMan();
};

