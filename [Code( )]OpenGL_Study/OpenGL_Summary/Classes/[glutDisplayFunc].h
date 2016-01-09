#pragma once;


#include <tchar.h>

class GlutDisplayFunc {

public:
	static	int		init( int argc,_TCHAR* argv[] );

private:
	static	void	displayCall();				//  窗口注册的函数
};

