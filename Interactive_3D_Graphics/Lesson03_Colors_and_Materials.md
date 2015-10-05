

# Lesson 03: Colors and Materials 

"颜色" 和 "材料"

笔记下载地址
>
https://www.udacity.com/wiki/cs291


## Overview of the Lesson 课程前瞻


我们将学会颜色如何定义，以及它们在显示时的一些限制。

学会创建和控制 不同类型的材质。

## The Programmable Pipeline 可编程渲染管线

流程：
1-应用程序 发送 三角形给 GPU 
2-GPU决定三角形的顶点在屏幕上的哪个位置，包括Z-depth(z-深度)，三角形内的每个像素的阴影部分。

但是现在这条流水线 是可以编程的。

流水线里转换到屏幕上的那个部分，可以通过 Vertex Shader(顶点着色器)完成。
比如修改输入的三个顶点中的一个顶点，改变其坐标，改变颜色。


## RGB Color Definition

在交互式渲染系统中，颜色被定义为 3种变量，red,green,blue。

每个颜色值 被叫做通道。

不过计算机里面排序一般是叫 BGR

通常定义颜色的数值有2种方式：
一种是浮点值，0.0 to 1.0
一种是整型值，0 to 255

## Color Definition

### subtractive color  -  CMYK

### ADDITIVE COLOR - RGB

R + G = Y
R + B = M
G + B = C

## Setting the Color

在 js 里面如何设置颜色

	var stepMaterialVertical = new THREE.MeshLambertMaterial( { color: 0xA85F35 } );

	// 如果不往里面传递任何参数，直接就默认是白色的。
	var spMaterialVertical = new THREE.MeshLambertMaterial();
	spMaterialVertical.color.r = 1;
	spMaterialVertical.color.g = 1;
	spMaterialVertical.color.b = 1;

	// 初始化方式1
	spMaterialVertical.color.setRGB(1,0,0);
	
	// 初始化方式2
	spMaterialVertical.color.setHex(0xA85F35);


## The Color Cube

## 练习题：Vertex Attributes

XYZ,RGB,
	

书签：

https://www.udacity.com/course/viewer#!/c-cs291/l-91376562/e-151413669/m-151215813


 









