

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

习题地址：
	

## Color Interpolation - 色彩插值

### rasterization 光栅化

在给 一个三角形的三个顶点 设置了颜色：红，绿，蓝，之后。要理解的关键点是 三角形 如何光栅化(rasterization) 三角形的剩余部分 的管道(pipeline)。

we linearly interpolate【线性插值】 across the triangle and fade from one to zero.

material shading 材料着色


## The Color Gamut - 色域

关键词：

color slice - 色片

CIE XYZ color space   
背景资料：

颜色模型
>
http://blog.ibireme.com/2013/08/12/color-model/

 - "三原色"的原理是由生理因素造成的。

 - 色域图：在二维平面上表现颜色空间，把r、g两个值绘制到二维空间得到的图就是色域图。
 - 马蹄形曲线就表示单色的光谱（即光谱轨迹）

顯示色彩的奧秘 v0.3
>
http://sophai.github.io/Enigma/posts/M43/colorspace.html

视频: 煎蛋小学堂：你看到的红色和我看到的是一样的吗？
>
http://v.youku.com/v_show/id_XNTQ5NzAxMTQ0.html


Mach Bands - **马赫带**  
背景资料：
>
http://aboutdada.com/?p=298

device's color gamma - 设备的色彩 伽玛值


字幕：
颜色可以被显示在你的显示器上面，



## A Simple Lighting Model - 一个简单的照明模式

可以见图：Lesson03_A_Simple_Lighting_Model_示意图.png

Emissive - 发射的 - 光源

Ambient - 环境 - 墙或者其他反光的物体（比如墙，光打到墙上再反射到物体上）

Diffuse - 扩散 - 眼睛的位置。

Specular - 镜面 - 物体的光泽（shininess of an object）

关键字：  
 - fragment -片段

## Kiss of Death

surface color = 

	emissive + ambient [are both solid colors]

For each light:

	Diffuse(Light) + Specular(Light, view)

Diffuse depends on the light's direction,
Specular depends on the light's direction and view.

	C = F + A + summation(D(L) + S(L,V)); 

## Light on a Diffuse Sphere 

diffused material - 漫射材料

scatter light - 散射光

下面开始补充 线性代数 基础了。

## Normalizing a Vector - 归一化向量

教你如何求向量长度。



## The Dot Product - 点乘

点乘法 = cos角度

## The Dot Product in Detail - 点乘的细节


书签：




 









