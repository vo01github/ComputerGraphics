

# C01 Introduction 

---
### 单词

term，			terminology，			术语    
manipulate， 	operate，control			处理  
three-dimensional						三维    
synthetic，		complex					合成  
fundamental，	basic, foremost, fundamental, key, main,		基本的
inevitably，								必然  
concept，		theory,idea				概念  
practitioners，							从业人员  
Modeling，								模型  
specification	standard,format,		规范，格式  	 
appearance		shape,looks,face,surface,	外观  
interpolation							插值  
reflection，		reflex,					反射  
interact，								相互作用，相互影响  
inherited，		hereditary,traditional，	遗传，继承    
illusion，		fantasy,				错觉，幻象，幻想  
involve，		include,				涉及，包含  
core，			kernel,					核心，  
feedback，		reaction,				反馈，
force feedback，							力反馈， 		
associated，		related，correlative		关联的，联合的。  
attempt，		essay, overture，try,	尝试，企图。  
immerse，		steep, soak,bathe,		沉浸，沐浴。  
via，			by, through,			通过，     
scanning，								扫描，  
range-finding 							测距，  
endeavor								努力，  
sophisticated，	complex,				复杂的
optimized，								优化   
intellectual，							智力   
hurdle，									障碍   
robust，			healthy and strong		鲁棒性      
bottleneck								瓶颈    
examine，		inspect, censor，		检查  
Raster									光栅化   
crystal			quartz, cut glass，		水晶	  	
Liquid crystal 							液晶  	-LCD    
emit			transmit, launch, 		发射	  	
Light-emitting							发光		-LED  	
	
## 1.1 Graphics Areas

图形学可以 涉及到的领域

**Modeling**			- 模型    
**Rendering**			- 渲染，绘制  
**Animation**			- 动画  

还有一些 其他领域【还有很大发展空间的领域】：

**User interaction**			- 用户交互处理  
**Virtual reality**				- 虚拟现实【VR】   
**Visualization**				- 可视化【数据，问题，可视化】  
**Image processing**			- 图像处理  
**3D scanning**					- 3D扫描 - 【利用测距技术来建模】     
**Computational photography**	- 计算摄影  


## 1.2 Major Applications - 主要应用

计算机图形学的主要应用场景：

**Video games**					- 视屏游戏      
**Cartoons**					- 卡通     
**Visual effects**				- 视觉效果，指在电影里用到的各种特效。  
**Animated films**				- 动画电影   
**CAD/CAM**						- 计算机辅助设计软件  
**Simulation**					- 仿真【飞行模拟器】   
**Medical imaging**				- 医学影像      
**Information visualization**	- 信息可视化【股票行情显示】   


## 1.3 Graphics APIs - 图形接口

无论选择哪种API，基本图形调用将是大致相同的。


## 1.4 Graphics Pipeline - 图形管线

正确的绘制三角形图元 在屏幕上面，比如三角形前后次序，尽管这在以前是个很重要的问题，如今已经全都用一个特殊的存储缓冲器来解决这个问题。
Z-buffer.

事实发现 用4D坐标系 去描述3维世界里面的物体，更加利于 操纵【矩阵运算】。

当然关于4维坐标系的学习 将是 学习计算机图形学中最大的智力门槛障碍。【赤裸裸的刷智商优越感么】

   
## 1.5 Numerical Issues - 数值问题

IEEE 浮点标准，规范化所有计算机在硬件方面处理浮点的细节。

有三个“特殊”的值在 IEEE 浮点数实数：

1. 正无穷 - infinity (∞)
2. 负无穷 - minus infinity (−∞)
3. 不是一个有效数 - not a number (NaN) 【如零除以零的结果】 

P22 这里讲了一堆无穷符合 之间计算后的结果，
比如什么 无穷×无穷，无穷/无穷。


## 1.6 Efficiency - 效率  

这段没看太懂，什么 内存的速度被CPU的速度拉的越来越远，所以以后程序的优化 应该注重的是 什么 内存存储的连贯性？ 【避免在内存里面到处寻址么】

**不要过早开始优化**

谨防旧文本的建议;一些经典的技巧，如使用整数而不是实数可能不再产生速度，因为现代的CPU通常可以执行整数运算与执行浮点运算一样快。

在所有的情况下，分析是必要的，以确保任何优化的优点为特定的机器和编译器。


## 1.7 Designing and Coding Graphics Programs - 设计和编码图形程序

某些常用的策略往往是在图形编程有用。在这节中，我们提供了一些建议。

一个2D向量类，应该支持的运算为：包括向量加法运算，矢量减法，点积，叉积，标量乘法，和标量除法。


还有调试，图形学的调试也很传统的代码调试不太一样。

比如遇到一个 shadow acne 影子痘痘问题。我们要如何解决。

Data Visualization for Debugging - 数据可视化的调试


# C02 Miscellaneous Math - 繁杂的数学

## 2.1 Sets and Mappings - 集和映射

本章跳过，都是些高中和大学的数学知识。


# C03 Raster Images - 光栅图像

光栅图像是一个简单的二维数组存储每个像素通常的彩色象素值存储为三个数字，为红色，绿色和蓝色。

有其他的方法用来描述 图形，而不是用二维数组，比如矢量图的形式。

在本章中，我们将讨论光栅图像和显示的基础知识。

## 3.1 Raster Devices - 光栅设备

3.1.2 Output Devices

透射：液晶显示器（LCD）  
发射：发光二极管（LED）显示屏  
  
当前显示器，包括电视和数字电影放映机，以及显示器和投影仪的计算机，是几乎普遍基于像素的固定阵列。它们可以被分成发光显示器，它使用的像素直接排放可控量的光，和透射型显示器，其中，像素本身不发光，而是改变光线的，它们允许通过它们的量。透射显示器需要光源以照射它们：在直接观看显示这是阵列后面的背光;在投影仪中它是一个灯发射光被后投射到屏幕穿过阵列。一个发射显示器是它自己的光源。

发光二极管（LED）显示器是发射型的例子。每个像素由一个或多个LED，这是半导体器件（基于无机或有机半导体），其发光强度与德未决的电流通过它们（见图3.1）。

【所以LED 才会省电，节能啊，想要什么颜色就哪些部件发光，而不是像LCD，全部发白光，然后前面再有个东西-偏振片 来遮挡，只让想要的光透射过去】

接下来还讲了 激光打印机 的原理。看不下去了。

3.1.3 Input Devices

照相机成像啊，还有扫描仪成像啊，生成图片什么的。

## 3.2 Images, Pixels, and Geometry - 图像，像素， 和几何  

我们知道，一个光栅图像是像素的大阵列，其中每个存储有关图像在其格子点的颜色信息。我们已经看到了各种输出设备做我们发送给他们的图像，以及如何输入设备，它们派生通过光在物理世界中形成的图像。但是在计算机的计算，我们需要一种方便抽象，独立于任何具体的设备，我们就可以用理性如何产生或解释值存储在图像。


### 3.2.1 Pixel Values


### 3.2.2 Monitor Intensities and Gamma - 监测强度和伽玛  
这节完全没有看懂   

什么是 **伽马校正** ?
> 
https://zh.wikipedia.org/wiki/%E4%BC%BD%E7%91%AA%E6%A0%A1%E6%AD%A3  

为图像进行伽马编码的目的是用来对人类视觉的特性进行补偿，从而根据人类对光线或者黑白的感知，最大化地利用表示黑白的数据位或带宽。在通常的照明（既不是漆黑一片，也不是令人目眩的明亮）的情况下，人类的视觉大体有伽马或者是幂函数的性质。如果不将图像进行伽马编码，那么数据位或者带宽的利用就会分布不均匀——会有过多的数据位或者带宽用来表示人类根本无法察觉到的差异，而用于表示人类非常敏感的视觉感知范围的数据位或者带宽又会不足。图像的伽马编码并不是必须的（甚至有的时候会适得其反），浮点数格式的颜色值已经提供了一部分对数曲线的线性估计。


黑白块混合到一起的时候，比如国际象棋那种棋盘，从远处看好像真的是变成 灰色了。

讲解为什么要有 伽马校正 ？  
Color is Broken  
> 
https://www.youtube.com/watch?v=LKnqECcg6Gw

知乎上的讨论
> 
http://www.zhihu.com/question/27467127#answer-10413243

大概懂了点。

【我自己的理解：因为人眼对明暗变化的敏感度不一样，也就是对暗感觉更敏感，对亮感受就差一点（不是线性关系），（这估计是进化导致的这种敏感度，暗处观察更敏感的人 存活的概率比 亮度感受更敏感的人 更高），所以老式的输入设备 本来采样后，能保存的宽带就少，如果是线性存值的话，就是很大的浪费，但是如果对输入值 进行一个 幂运算，然后把输入后保存的值不按线性排布来保存，而是按 幂（2.2）的非线性分布来保存值，这样就可以在 不增加存储容量的同时，使得一张图片能存储更高的精度（相对于人眼感受到的）。然后输出的设备再进行 反向的操作，这样就会使图片输出时接近输入时的图像。】

因为人类感知强度的是本身非线性的，1.5至3的伽马（取决于观看条件）。

一只眼睛里面大约分别有7百万视锥细胞和1亿两千万视杆细胞。




## 3.3 RGB Color - RGB颜色


## 3.4 Alpha Compositing - alpha合成

c = α*c1 + (1−α)*c2

c1 是前置背景。
c2 是后置背景。


# C04 Ray Tracing - 光线追踪



书签  
P85/785  





 




   

	






			

