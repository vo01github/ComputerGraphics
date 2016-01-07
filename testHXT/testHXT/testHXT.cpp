// testHXT.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "GL/glut.h"
#include <iostream>
#include <windows.h>  
#include <time.h>

#define  GLOBAL_MAP_LEFT_WEST -19200
#define  GLOBAL_MAP_RIGHT_EAST 19200
#define  GLOBAL_MAP_UP_NORTH 10800
#define  GLOBAL_MAP_BOTTOM_SOUTH -10800 //二维全局地图范围


int idWindow = 0;
int cnt = 0;
void TimerFunction(int value)
{
	cnt++;

	glutPostWindowRedisplay(idWindow);
	

	glutTimerFunc(40, TimerFunction, 1);


}

void showLocusBegin()
{
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


void showLocusPlot()
{
	showLocusBegin();//这里是重复代码 这个函数 每次都在重绘 但是我不写 网格就不停的闪 地图的格子

	/*glColor3f(1.0, 1.0, 0.0);
	glPointSize(6);
	glBegin(GL_POINTS);
	glVertex2f(CalLocus::GetInstance()->curCarState.x, CalLocus::GetInstance()->curCarState.y);
	glEnd();*/
	///////////////////////////test////////////////////////////////////////
	if (cnt % 2 == 0)
	{
		glColor3f(1.0f, 1.0f, 1.0f*rand());//颜色设置为红色 
	}
	else
	{
		glColor3f(1.0f, 0.0f, 0.0f);//颜色设置为红色 
	}
	//////////////////////////////////////////////////////////////
	//glColor3f(1.0f*rand(), 1.0f*rand(), 1.0f*rand());//颜色设置为红色
	int i = 0;
	int k = 0;
	/*int size = globalTwoDimensionalMap.size();
	cout << "openGL绘制端绘制的方格块为：" << size << endl;*/
	/*for (int obstacleCnt = 0; obstacleCnt < globalTwoDimensionalMap.size(); obstacleCnt++)
	{
	i = globalTwoDimensionalMap[obstacleCnt][0];
	k = globalTwoDimensionalMap[obstacleCnt][1];

	int xi = i - GLOBAL_MAP_OFFSET;
	int ki = k - GLOBAL_MAP_OFFSET;

	int c = 200;
	int b = 100;

	int xStart = b + xi * c;
	int xEnd = b + (xi + 1) * c;

	int zStart = ki * c;
	int zEnd = (ki + 1) * c;

	glRectf(xStart, zEnd, xEnd, zStart);
	}*/

	/////////////////////test///////////////////////////
	int xi = cnt;
	int ki = cnt;

	int c = 200;
	int b = 100;

	int xStart = b + xi * c;
	int xEnd = b + (xi + 1) * c;

	int zStart = ki * c;
	int zEnd = (ki + 1) * c;

	glRecti(xStart, zEnd, xEnd, zStart);//在这画的


	////////////////////////////////////////////////
	glPopMatrix();
	glutSwapBuffers();
	glFlush();

}




int _tmain(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 800);
	idWindow = glutCreateWindow("全局地图和轨迹显示");
	glutDisplayFunc(showLocusPlot);

	glutTimerFunc(30, TimerFunction, 1);
	glutMainLoop();
	
	
	
	return 0;
}

