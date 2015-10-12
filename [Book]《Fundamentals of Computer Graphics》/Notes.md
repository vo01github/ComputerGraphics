

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

P70


 




   

	






			

