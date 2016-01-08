

#include <vector>
#include<gl/glut.h> 
#include "[glutSwapBuffers].h"



// 数据部分
#define  GLOBAL_MAP_LEFT_WEST		-19200
#define  GLOBAL_MAP_RIGHT_EAST		19200
#define  GLOBAL_MAP_UP_NORTH		10800
#define  GLOBAL_MAP_BOTTOM_SOUTH	-10800 //二维全局地图范围

static int	idWindow	= 0;
static int	cnt			= 0;
static bool isFirstRun	= true;

// 宏切换控制部分
//#define USE_DOUBLE_BUFFER
/*
	画一个方块，第1次画到（1，1），第2次就画到（2，2），第3次就画到（3，3），依次类推。
	定义了就 使用双缓冲模式，每画一次方块，就切换一次 绘制的缓冲块。然后同时 屏幕去读取上一个缓冲。
	不定义就使用 单缓冲模式。每次 调用 glFlush(); 就让屏幕去读取缓冲。
*/

/*	网上的解释部分
	简单地说glFlush就是强制刷新吧，要知道OPENGL是使用一条渲染管线线性处理命令的，
	一般情况下，我们提交给OPENGL的指令并不是马上送到驱动程序里执行的，而是放到一个缓冲区里面，
	等这个缓冲区满了再一次过发到驱动程序里执行；很多时候只有几条指令是填充不满那个缓冲区的，
	这就是说这些指令根本没有被发送到驱动里，所以我们要调用glFlush来强制把这些指令送到驱动里进行处理。

	glutSwapBuffers其实就是交换缓冲区啦，估计是你的程序使用的是双缓冲技术吧；
	用了这种技术的话，你所有的绘制都是绘制到一个后台的缓冲区里面的，
	如果不交换缓冲区，就看不到绘制的东西了，就这么回事~

	上面的回答，根本没有说到重点。 当执行双缓冲交换的时候，使用glutSwapBuffers。 
	但是在有 glutSwapBuffers 的情况下， 不需要 glFlush 就可以达到同样的效果，
	因为我们执行双缓冲交换的时候，就隐形的执行了一次刷新操作。 
	所以，设置了双缓冲的时候，一般是使用glutSwapBuffers，而不是使用glFlush，
	如果两个都使用了，那么就会出现渲染帧率很低。

	GLUT_DOUBLE：使用双缓存。以避免把计算机作图的过程都表现出来，或者为了平滑地实现动画。 
*/

// 类定义部分
void GlutSwapBuffers::TimerFunction(int value)
{
	cnt++;

	//glutPostWindowRedisplay(idWindow);
	glutPostRedisplay();
	glutTimerFunc(40, TimerFunction, 1);
}


void GlutSwapBuffers::showLocusBegin()
{

	if (isFirstRun)
	{
#ifndef USE_DOUBLE_BUFFER
		isFirstRun = false;
#endif

		glMatrixMode(GL_PROJECTION);//重新设置坐标系系统
		glLoadIdentity();

		glOrtho(GLOBAL_MAP_LEFT_WEST, GLOBAL_MAP_RIGHT_EAST, GLOBAL_MAP_BOTTOM_SOUTH, GLOBAL_MAP_UP_NORTH, 1.0, -1.0);

		//绘制网格线
		glBegin(GL_LINES);
		glColor3f(0.0f, 1.0f, 1.0f);//颜色设置为青色  

		int i = 0;
		for (i = GLOBAL_MAP_LEFT_WEST; i < GLOBAL_MAP_RIGHT_EAST; i += 200)
		{
			glVertex2f(GLOBAL_MAP_LEFT_WEST, i);
			glVertex2f(GLOBAL_MAP_RIGHT_EAST, i);//横线

			glVertex2f(i + 100, GLOBAL_MAP_BOTTOM_SOUTH);//纵线
			glVertex2f(i + 100, GLOBAL_MAP_UP_NORTH);
		}
		glEnd();


		//原点
		glColor3f(1.0, 0.0, 0.0);
		glPointSize(5);
		glBegin(GL_POINTS);
		glVertex2f(0.0, 0.0);
		glEnd();

	}

}


void GlutSwapBuffers::showLocusPlot()
{
	showLocusBegin();//这里是重复代码 这个函数 每次都在重绘 但是我不写 网格就不停的闪 地图的格子

	///////////////////////////test////////////////////////////////////////
	if (cnt % 2 == 0)
	{
		//glColor3f(1.0f, 1.0f, 1.0f*rand());//颜色设置为？色 
		glColor3f(1.0f, 0.0f, 0.0f);//颜色设置为红色
	}
	else
	{
		glColor3f(1.0f, 0.0f, 0.0f);//颜色设置为红色 
	}
	//////////////////////////////////////////////////////////////
	int i = 0;
	int k = 0;


	/////////////////////test///////////////////////////
	int xi = cnt;
	int ki = cnt;

	int c = 200;
	int b = 100;

	int xLeft = b + xi * c;
	int xRight = b + (xi + 1) * c;

	int zDown = ki * c;
	int zUp = (ki + 1) * c;

	glRecti(xLeft, zUp, xRight, zDown);//在这画的

	////////////////////////////////////////////////
#ifdef USE_DOUBLE_BUFFER
	glutSwapBuffers();
#else
	glFlush();
#endif

}


int GlutSwapBuffers::init( int argc,_TCHAR* argv[] )
{
	glutInit(&argc,(char**)argv);

#ifdef USE_DOUBLE_BUFFER
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
#else
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
#endif

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 800);
	idWindow = glutCreateWindow("全局地图和轨迹显示");
	glutDisplayFunc(showLocusPlot);

	glutTimerFunc(30, TimerFunction, 1);
	glutMainLoop();
	
	return 0;  
}



