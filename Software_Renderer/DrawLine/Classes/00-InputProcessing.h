

#ifndef __DL_INPUT_PROCESSING_H__
#define __DL_INPUT_PROCESSING_H__

#include<gl/glut.h> 

//=========================================================================
//
//							输入处理 - 键盘响应
//
//=========================================================================

void ProcessKeyboard(unsigned char key,int x,int y)			// 键盘响应
{
	if (key == 'p')
	{
		GLfloat ang = -10;			
		glRotatef(ang, 0,0,1);
		glutPostRedisplay();
	}
}


//=========================================================================
//
//							输入处理 - 鼠标响应
//
//=========================================================================

void ProcessMouse(int button,int state,int x,int y)			// 鼠标响应
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		GLfloat ang = -10;			
		glRotatef(ang, 0,0,1);
		glutPostRedisplay();
	} else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		GLfloat ang = 10;			
		glRotatef(ang, 0,0,1);
		glutPostRedisplay();
	}
}



#endif // __DL_INPUT_PROCESSING_H__