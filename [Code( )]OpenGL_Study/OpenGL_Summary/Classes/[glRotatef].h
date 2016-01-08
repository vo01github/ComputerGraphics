
#ifndef __OS_glRotatef_USE_H__
#define __OS_glRotatef_USE_H__

#include <tchar.h>

class GlRotatef {

public:
	static	int		initRotate( int argc,_TCHAR* argv[] );

private:
	static	void	myDisplay();  
	static	void	myDisplay_Test_Rotate_Obj();	//	旋转 90度 视角 
	static	void	myDisplay_Rotate_Obj();			//	旋转 45度 视角

	static	void	Draw_3D_Coordinate_System_On_Windows_function();		// 绘制坐标系

	static	float	changeNumSize(float insert);

	

};

#endif // __OS_glRotatef_USE_H__