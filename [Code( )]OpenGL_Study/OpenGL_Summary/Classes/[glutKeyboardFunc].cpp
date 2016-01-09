

#include <vector>
#include<gl/glut.h> 
#include "[glutKeyboardFunc].h"


//=========================================================================
//
//		注册键盘响应  ：glutKeyboardFunc	: glutSpecialFunc
//
//=========================================================================
/*
GLUT提供两个函数来为键盘事件注册回调函数.第一个是glutKeyboardFunc,用于告知窗体系统处理普通按键事件.例如字母,数字,和ASCII包含的内码.原型如下:

void glutKeyboardFunc(void (*func) (unsigned char key, int x, int y));

func - 处理普通按键事件的函数.如果传入NULL值则忽略普通按钮。

glutKeyboarFunc绑定的函数必须返回三个结果值.第一个是按键对应的ASCII内码,
其余两个是按钮触发时鼠标所在的位置.鼠标位置是相对于窗体客户端的左上角.
*/

/*
特殊键处理.GLUT提供了glutSpecialFunc函数来处理,原型如下:
void glutSpecialFunc(void (*func) (int key, int x, int y));

常量GLUT_KEY_*是在glut.h头文件中预定义的.该常量的具体定义如下:

复制代码
GLUT_KEY_F1				F1 function key
GLUT_KEY_F2				F2 function key
GLUT_KEY_F3				F3 function key
GLUT_KEY_F4				F4 function key
GLUT_KEY_F5				F5 function key
GLUT_KEY_F6				F6 function key
GLUT_KEY_F7				F7 function key
GLUT_KEY_F8				F8 function key
GLUT_KEY_F9				F9 function key
GLUT_KEY_F10			F10 function key
GLUT_KEY_F11			F11 function key
GLUT_KEY_F12			F12 function key
GLUT_KEY_LEFT			Left function key
GLUT_KEY_RIGHT			Right function key
GLUT_KEY_UP				Up function key
GLUT_KEY_DOWN			Down function key
GLUT_KEY_PAGE_UP		Page Up function key
GLUT_KEY_PAGE_DOWN		Page Down function key
GLUT_KEY_HOME			Home function key
GLUT_KEY_END			End function key
GLUT_KEY_INSERT			Insert function key
*/



/*	Ctrl, Alt和Shift键

有时我们需要处理编辑键,例如ctrl,alt和shift. GLUT提供一个函数来监测编辑键.
但是该函数只能在键盘和鼠标输入事件的绑定函数里面调用.原型如下:

int glutGetModifiers(void);

该函数的返回值是三个可选的常量(包含在glut.h头文件中),用位或组合形式.

GLUT_ACTIVE_SHIFT - 通知shift键被按下,或者大写锁在开启状态.如果两者都是开启状态,就反而是不大写.

GLUT_ACTIVE_CTRL - 通知ctrl键被按下.

GLUT_ACTIVE_ALT - 通知alt键被按下.
*/

static float red=1.0f, blue=1.0f, green=1.0f;
static float angle = 0.0f;

void GlutKeyboardFunc::processNormalKeys(unsigned char key, int x, int y) 
{

/*
当用户输入esc键的时候退出程序.留意到当看到glutMainLoop函数时,
我们会注意到它是在一个死循环中,永远不会返回.
跳出死循环的唯一办法是调用系统的exit函数.
这就是函数里面需要实现的部分,当用户按esc键的时候,我们要调用系统exit函数来促使程序终止.
*/
	// 27 对应 ESC 键
	if (key == 27){
		exit(0);
	} else if (key == 'r') {
		int mod = glutGetModifiers();
		if (mod == GLUT_ACTIVE_ALT)
		{
			exit(0);
		} else if (mod == GLUT_ACTIVE_CTRL)
		{
			red = 0.0;
			green = 1.0;
			blue = 0.0; 
		}  else if (mod == GLUT_ACTIVE_SHIFT)
		{
			red = 0.0;
			green = 0.0;
			blue = 1.0;
		}
		
	}
		
}

void GlutKeyboardFunc::processSpecialKeys(int key, int x, int y) 
{

	switch(key) {
	case GLUT_KEY_F1 :
		red = 1.0;
		green = 0.0;
		blue = 0.0; break;
	case GLUT_KEY_F2 :
		red = 0.0;
		green = 1.0;
		blue = 0.0; break;
	case GLUT_KEY_F3 :
		red = 0.0;
		green = 0.0;
		blue = 1.0; break;
	}
}




void GlutKeyboardFunc::renderScene(void) {

	// Clear Color Buffers 把缓存上的像素颜色数据全部清除。
	glClear(GL_COLOR_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

#if 0
	// Set the camera - 这个好像没有必要
	gluLookAt(    0.0f, 0.0f, 1.0f,
		0.0f, 0.0f,  0.0f,
		0.0f, 1.0f,  0.0f);
#endif

	//glRotatef(angle, 0.0f, 1.0f, 0.0f);	// 绕着 y轴旋转
	glRotatef(angle, 0.0f, 0.0f, 1.0f);		// 绕着 z轴旋转

	glColor3f(red, green, blue);
	glBegin(GL_TRIANGLES);
	glVertex3f(-1.0f,-1.0f, 0.0f);
	glVertex3f( 1.0f, 0.0f, 0.0);
	glVertex3f( 0.0f, 1.0f, 0.0);
	glEnd();

	angle += 0.1f;

	glutSwapBuffers();
}


int GlutKeyboardFunc::init( int argc,_TCHAR* argv[] )
{
	glutInit(&argc,(char**)argv);

	// 创建窗口
	glutInitWindowPosition(100, 100);				// 定义窗体的位置
	glutInitWindowSize(800, 800);					// 定义窗体的大小
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);	// 定义显示模式
	glutCreateWindow("全局地图和轨迹显示");			// 完成以上3个以后就可以定义窗体了
	
	// 注册回调函数
	// register callbacks
	glutDisplayFunc(renderScene);					// 注册 重绘事件
	glutReshapeFunc(changeSizeCall);				// 注册 窗体更改大小事件 【第1次渲染时也会被调用】
	glutIdleFunc(renderScene);						// 注册 系统空闲事件

	// 注册键盘响应 
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);

	glutMainLoop();									// 事件处理死循环
	
	return 0;  
}

void GlutKeyboardFunc::displayCall()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	glVertex3f(-0.5,-0.5,0.0);
	glVertex3f(0.5,0.0,0.0);
	glVertex3f(0.0,0.5,0.0);
	glEnd();
	glFlush();
}

void GlutKeyboardFunc::changeSizeCall(int w, int h) {

#if 0
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if(h == 0) h = 1;
	float ratio = 1.0 * w / h;

	glViewport(0, 0, w, h);

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	gluOrtho2D(0, 1, 0, 1);  //using normalized device coordinates 
	//glViewport(0, 0, 800, 800);

	// Set the viewport to be the entire window
	//glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	// Set the correct perspective.
	//gluPerspective(45,ratio,1,100);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);

#endif
}
