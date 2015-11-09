
#ifndef __DL_Axis_Division_H__
#define __DL_Axis_Division_H__


#include <vector>

/*	问题：
帮我想一个算法看看
现在我的网格划分 比如x轴的是 -300到-100  -100到100 100到300……依次类推
现在比如知道x坐标 怎么知道x是属于哪个范围的
*/

/*
最终版出来了：
float: [a,b)
float c = b - a;
int index = floor( (x-b)/c );
最终范围：[b + index*c , b + (index+1)*c)
*/

// 使用举例
#if 0
[-100,100);
c = 100 - (-100) = 200;
index = floor((-50 - 100)/200) = floor(-150/200) = -1 ;

#endif


// ceil 和 floor 的使用举例
#if 0

float er = ceil(1.6);			// 2
float er1 = ceil(-0.2);			// -0
float er2 = ceil(0.2);			// 1

float er3 = floor(1.6);			// 1
float er4 = floor(-0.2);		// -1
float er5 = floor(0.2);			// 0

#endif


#endif // __DL_Axis_Division_H__