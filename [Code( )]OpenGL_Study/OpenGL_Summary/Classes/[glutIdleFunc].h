#pragma once;


#include <tchar.h>

class GlutIdleFunc {

public:
	static	int		init( int argc,_TCHAR* argv[] );

private:

	// 注册的回调函数
	static	void	displayCall();						//  窗口注册的函数
	static	void	changeSizeCall(int w, int h);		//  改变窗口注册的函数

	static	void	renderScene();
};

