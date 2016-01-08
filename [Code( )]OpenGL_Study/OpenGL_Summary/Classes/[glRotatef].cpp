

#include <vector>
#include<gl/glut.h> 
#include "[glRotatef].h"



// 数据部分
const float CoordinateL = 0.6;		// 要画的坐标轴长
const float taiangleL	= 0.05;		// 要画在坐标轴头上的三角形长

static bool isFirstRun = true;

// 类定义部分
float GlRotatef::changeNumSize(float insert)
{
	return (insert/8000.0f);
}

void GlRotatef::myDisplay()  
{  
	GlRotatef::myDisplay_Rotate_Obj();

}

int GlRotatef::initRotate( int argc,_TCHAR* argv[] )
{
	glutInit(&argc,(char**)argv);					// 初始化glut,必须调用，复制黏贴这句话即可  
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);	// 设置显示方式，RGB、单缓冲。当然还有GLUT_INDEX索引颜色 GLUT_DOUBLE双缓冲(Qt中看到过双缓冲)  
	glutInitWindowPosition(300,300);				// 窗口在显示器屏幕中的位置，指定的是窗口左上角的坐标。(0,0)就会显示在屏幕左上角。  
	glutInitWindowSize(800.0f, 800.0f);					// 设置所需窗口大小  

	glutCreateWindow((char*)argv[0]);				// 这样也行啊？
	glutDisplayFunc(myDisplay);	
	glutMainLoop();									// 无限执行的循环，glutMainLoop()会判断窗口是否需要进行重绘， 会自动调用 glutDisplayFunc()中注册的函数。   
	return 0;  
}


/*
	旋转有2种方式：一个旋转物体【使用 glRotatef()】，一个旋转摄像头【使用gluLookAt()】。
*/

/*
参考文章：
用PyOpenGL叩开3D的心扉——OpenGL全解析（3）			【这篇文章讲解了 使用 python 来写 OpenGL 的，以后有机会可以看下】
https://eyehere.net/2011/learn-opengl-3d-by-pyopengl-3/
	glRotatef(1, 0, 1, 0)是一个旋转函数，
	简单来说四个参数第一个是角度，
	后三个是一个向量，意义就是绕着这个向量旋转，这里是绕着Y轴旋转1°。
	这一度一度的累加，最后使得茶壶围绕Y轴不停的旋转。
	从这里我们也能看出来，我们指定了一个旋转的角度后，
	重新绘制并不会复位，而是在上一次旋转的结果上继续旋转。
	这是一个非常重要的概念，OpenGL是一个状态机，一旦你指定了某种状态，知道再指定位置，它会保持那种状态。
	不仅仅是旋转，包括以后的光照贴图等等，都遵循这样的规律。
	
OpenGL中glRotatef()函数究竟对矩阵做了什么？
http://blog.csdn.net/gamesdev/article/details/9929211
	这篇文章，讲解的 glRotatef 操纵了哪些矩阵，好吧，没仔细看。

	然后这个博客有很多文章讲解 OpenGL 的教程,有空看看吧。
*/


/*
我自己的理解：
	glRotatef(1, 0, 1, 0)：
	（0，1，0）是一个向量，与Y轴平行。
	然后右手握向量轴，大拇指指向向量所指方向，逆时针旋转的角度， 单位是度。
	这个向量轴所在的坐标是在 物体坐标系上，不是摄像机坐标系中，也就是不是投影坐标系中的。

	如何验证 是在 物体坐标系上，而不是摄像机坐标系呢。
	请看 myDisplay_Test_Rotate_Obj()
*/

void GlRotatef::myDisplay_Test_Rotate_Obj()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//  ================================ 旋转摄像头 ================================
	if (isFirstRun == true) {		// 保证只运行一次
		isFirstRun = false;

		GLfloat ang = -90;			// 先旋转90度，使我们绘制的X轴 指向屏幕外面，绘制的Z轴沿着 屏幕X轴方向
		glRotatef(ang, 0,1,0);

		GLfloat up = -20;
		glRotatef(up, 0,0,1);		// 这个时候，沿着Z轴旋转，我们就能确定到底是沿着 物体的Z轴旋转，还是在以 屏幕的Z轴旋转了。
	}

	// 最终结果 确定 是沿着物体的 Z轴在进行旋转，OK。

	Draw_3D_Coordinate_System_On_Windows_function();
}


//=========================================================================
//
//							画个坐标系-成功演示 示例
//
//=========================================================================

/*
	画一个3D坐标系，然后进行旋转，使之出现在我们需要的视角上面。
*/
void GlRotatef::myDisplay_Rotate_Obj()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//  ================================ 旋转摄像头 ================================
	if (isFirstRun == true) {		// 保证只运行一次
		isFirstRun = false;

		GLfloat ang = -45;			// 右手握轴，逆时针旋转的角度， 单位是度。这个轴所在的坐标是在 物体坐标系上，不是摄像机坐标系中，也就是不是投影坐标系中的。
		glRotatef(ang, 0,1,0);

		// 会在上一个glRotatef 的状态上 进行旋转
		GLfloat up = -20;			
		glRotatef(up, -1,0,1);		// 	这里向量取值(-1,0,1)，这个向量与 我们现在的视角到源点(0,0,0)的连线相垂直。	
	}

	Draw_3D_Coordinate_System_On_Windows_function();
}


//  ================================ 绘制3D 坐标轴 ================================
void GlRotatef::Draw_3D_Coordinate_System_On_Windows_function(void)  
{  
	glClear(GL_COLOR_BUFFER_BIT); 

	glutWireTeapot(0.5);		// 画一个茶壶。

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);		// 不加这句就是画一个实心三角形了。

	// 绘制坐标轴的 直线
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 0.0);	//x轴 黄色
	glVertex3f(-CoordinateL, 0.0, 0.0);
	glVertex3f(CoordinateL, 0.0, 0.0);

	glColor3f(0.0, 1.0, 0.0);	//y轴 绿色
	glVertex3f(0.0, -CoordinateL, 0.0);
	glVertex3f(0.0, CoordinateL, 0.0);

	glColor3f(1.0, 0.0, 0.0);	//z轴 红色，与OpenGL的Z轴是反方向的。
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, -CoordinateL);
	glEnd();

	// 绘制坐标轴的 箭头
	glBegin(GL_TRIANGLES);

	glColor3f(1.0, 1.0, 0.0);	// x轴 黄色
	glVertex3f(CoordinateL-taiangleL, taiangleL, 0);
	glVertex3f(CoordinateL, 0, 0);
	glVertex3f(CoordinateL-taiangleL, -taiangleL, 0);

	glVertex3f(CoordinateL-taiangleL, 0, taiangleL);
	glVertex3f(CoordinateL, 0, 0);
	glVertex3f(CoordinateL-taiangleL, 0, -taiangleL);

	glColor3f(0.0, 1.0, 0.0);	// y轴 绿色
	glVertex3f(0, CoordinateL, 0);
	glVertex3f(taiangleL, CoordinateL-taiangleL, 0);
	glVertex3f(-taiangleL, CoordinateL-taiangleL, 0);

	glVertex3f(0, CoordinateL, 0);
	glVertex3f(0, CoordinateL-taiangleL, taiangleL);
	glVertex3f(0, CoordinateL-taiangleL, -taiangleL);

	glColor3f(1.0, 0.0, 0.0);	// z轴 红色
	glVertex3f(0, 0, -CoordinateL);
	glVertex3f(0, taiangleL, -CoordinateL + taiangleL);
	glVertex3f(0, -taiangleL, -CoordinateL + taiangleL);

	glVertex3f(0, 0, -CoordinateL);
	glVertex3f(taiangleL, 0, -CoordinateL + taiangleL);
	glVertex3f( -taiangleL, 0, -CoordinateL + taiangleL);

	glEnd();  
	glFlush();  
}  



