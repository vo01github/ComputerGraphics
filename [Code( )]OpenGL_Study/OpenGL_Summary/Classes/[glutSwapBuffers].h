#pragma once;


#include <tchar.h>

class GlutSwapBuffers {

public:
	static	int		init( int argc,_TCHAR* argv[] );

private:
	static	void	showLocusPlot();				//  窗口注册的函数
	static	void	showLocusBegin();				//	只绘制一次的函数，绘制坐标系
	static	void	TimerFunction(int value);		//	定时函数

};

