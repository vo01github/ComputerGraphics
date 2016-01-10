

#include <vector>
#include<gl/glut.h> 
#include "[gluLookAt].h"


//=========================================================================
//
//		移动镜头  ：gluLookAt	
//
//=========================================================================
/*

*/
static float angle=0.0;
// actual vector representing the camera's direction
static float lx=0.0f,lz=-1.0f;
// XZ position of the camera
static float x=0.0f,z=5.0f;

static bool isFirstRun = true;


//=========================================================================
//								按键处理
//=========================================================================
void GluLookAt::processNormalKeys(unsigned char key, int x, int y) 
{
	if (key == 27) {		// 27 对应 ESC 键
		exit(0);
	} 
}

void GluLookAt::processSpecialKeys(int key, int x, int y) 
{
	float fraction = 0.1f;

	switch (key) {
	case GLUT_KEY_LEFT :
		angle -= 0.01f;
		lx = sin(angle);
		lz = -cos(angle);
		break;
	case GLUT_KEY_RIGHT :
		angle += 0.01f;
		lx = sin(angle);
		lz = -cos(angle);
		break;
	case GLUT_KEY_UP :
		x += lx * fraction;
		z += lz * fraction;
		break;
	case GLUT_KEY_DOWN :
		x -= lx * fraction;
		z -= lz * fraction;
		break;
	}
}




void GluLookAt::renderScene(void) {

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	// Set the camera
	gluLookAt(    x, 1.0f, z,
		x+lx, 1.0f,  z+lz,
		0.0f, 1.0f,  0.0f);

	// Draw ground
	glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_QUADS);
	glVertex3f(-100.0f, 0.0f, -100.0f);
	glVertex3f(-100.0f, 0.0f,  100.0f);
	glVertex3f( 100.0f, 0.0f,  100.0f);
	glVertex3f( 100.0f, 0.0f, -100.0f);
	glEnd();

	// Draw 36 SnowMen
	for(int i = -3; i < 3; i++) {
		for(int j=-3; j < 3; j++) {
			glPushMatrix();
			glTranslatef(i*10.0,0,j * 10.0);
			drawSnowMan();
			glPopMatrix();
		}
	}

	glutSwapBuffers();
}


int GluLookAt::init( int argc,_TCHAR* argv[] )
{
	glutInit(&argc,(char**)argv);

	// 创建窗口
	glutInitWindowPosition(100, 100);				// 定义窗体的位置
	glutInitWindowSize(800, 800);					// 定义窗体的大小
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);	// 定义显示模式
	glutCreateWindow("按下键盘移动镜头");			// 完成以上3个以后就可以定义窗体了
	
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

void GluLookAt::displayCall()
{
	
}

void GluLookAt::drawSnowMan() {

	glColor3f(1.0f, 1.0f, 1.0f);

	// Draw Body
	glTranslatef(0.0f ,0.75f, 0.0f);
	glutSolidSphere(0.75f,20,20);

	// Draw Head
	glTranslatef(0.0f, 1.0f, 0.0f);
	glutSolidSphere(0.25f,20,20);

	// Draw Eyes
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0.05f, 0.10f, 0.18f);
	glutSolidSphere(0.05f,10,10);
	glTranslatef(-0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.05f,10,10);
	glPopMatrix();

	// Draw Nose
	glColor3f(1.0f, 0.5f , 0.5f);
	glRotatef(0.0f,1.0f, 0.0f, 0.0f);
	glutSolidCone(0.08f,0.5f,10,2);
}

void GluLookAt::changeSizeCall(int w, int h) 
{
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if(h == 0) h = 1;
	float ratio = 1.0 * w / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45,ratio,1,100);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}
