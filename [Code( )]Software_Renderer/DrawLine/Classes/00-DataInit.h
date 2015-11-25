

#ifndef __DL_DATA_INIT_H__
#define __DL_DATA_INIT_H__


#include "00-DataDefinition.h"

//=========================================================================
//
//							数据定义
//
//=========================================================================

// 常量
const Point2D ScreenSize = {500.0f, 500.0f};		// 屏幕大小
const float scaleScreen = 0.2f;						// 决定要裁剪的区域有多大

Rect2D ClippingSize;								// 要裁剪的区域


#endif // __DL_DATA_INIT_H__