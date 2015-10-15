# 学习路线

知乎文章：如何开始用 C++ 写一个光栅化渲染器？
>
http://www.zhihu.com/question/24786878

## 学习顺序

 - 01    
什么版本都不用管 先实现一遍底层的光栅化的3D渲染算法，只用一个画像素的功能，把插值，zbuffer，alpha，阴影，三角形的光栅化，全自己底层实现一遍，之后进阶挑nvidia 的sdk里的例子逐句看，siggraph早期的gpgpu的论文挑自己觉得有趣的去实现，shaderX，gpu gems里头拿感兴趣的实现，我就是这么过来的，后来去了皮克斯做R&D，现在在Weta Digital做R&D

 - 02   
2D部分：
光栅化2D点（就是在二维数组上画点，了解色彩基本原理，并解决影像输出问题）  
光栅化2D直线（布雷森漢姆直線演算法、吴小林直线算法等）  
2D直线的剪切算法（见Line clipping）  
光栅化2D三角形（scan conversion）。避免重复光栅化相邻三角形边界的像素（edge equation）。  
光栅化简单／复杂多边形  
3D部分：  
把顶点从三维世界空间变换至二维屏幕空间，绘画顶点（如银河星系数据），操控摄像机旋转模型。  
在剪切空间进行3D直线的剪切算法，把顶点连线（如各种三维正多面体）光栅化成wire frame模型  
以多边形来定义三维模型。使用画家算法来光栅化那些多边形。  
改为使用深度缓冲。  
实现简单的纹理映射，先做屏幕空间的插值，然后实现简单的perspective-correct texture mapping。  
实现简单的顶点光照，使用顶点颜色插值实现Gouraud shading。  
通过顶点法线插值，实现Phong shading。   
实现其他贴图技术，如mipmapping（也可试Summed area table）、bilinear/trilinear filtering、bump mapping、normal mapping、environment mapping等。  


 - 05  
最经典的是《3D游戏编程大师》，不卖弄，纯干货，从零教你写软3D引擎，当然包括光栅化。我的观点一直是，当你迈出第一步，所有的东西都会水到渠成。

## 推荐书籍

《3D游戏编程大师》  
《计算机图形学——几何工具算法详解》

## 矩阵基础

所谓变换，其实就是空间里从一个点（元素/对象）到另一个点（元素/对象）的跃迁。比如说，拓扑变换，就是在拓扑空间里从一个点到另一个点的跃迁。再比如说，仿射变换，就是在仿射空间里从一个点到另一个点的跃迁。附带说一下，这个仿射空间跟向量空间是亲兄弟。做计算机图形学的朋友都知道，尽管描述一个三维对象只需要三维向量，但所有的计算机图形学变换矩阵都是4 x 4的。说其原因，很多书上都写着“为了使用中方便”，这在我看来简直就是企图蒙混过关。真正的原因，是因为在计算机图形学里应用的图形变换，实际上是在仿射空间而不是向量空间中进行的。想想看，在向量空间里相一个向量平行移动以后仍是相同的那个向量，而现实世界等长的两个平行线段当然不能被认为同一个东西，所以计算机图形学的生存空间实际上是仿射空间。而仿射变换的矩阵表示根本就是4 x 4的。又扯远了，有兴趣的读者可以去看《计算机图形学——几何工具算法详解》。


## 具体问题

因为今天基本上是直接用 D3D 或者 OGL，真正光栅化的部分不了解也不影响使用，所以大部分教材都直接跳过了一大段，
摄像机坐标系如何转换？  
三角形如何生成？  
CVV边缘如何检测？  
四维坐标如何裁剪？  
边缘及步长如何计算？   
扫描线该如何绘制？  
透视纹理映射具体代码该怎么写？  
framebuffer zbuffer 到底该怎么用？  
z-test 到底是该 test z 还是 w 还是 1/z 还是 1/w ？  
这些都没讲。

## 系列教学文章

图形学基础教程 1～10  
用来复习的时候看好。  
>  
http://www.cnblogs.com/luming1979





## 文章

图形学杂谈
>
http://blog.csdn.net/zxx43/article/category/5617159

如何写一个软件渲染器？
>
http://www.skywind.me/blog/archives/1498

如何实现robust和高效的软件光栅化?
>
https://software.intel.com/en-us/articles/rasterization-on-larrabee


How to write a simple software rasterizer
>
http://www.cnblogs.com/hust-ruan/archive/2013/03/16/2962077.html


用JavaScript玩转计算机图形学(一)光线追踪入门[Milo Yip博客]
>
http://www.cnblogs.com/miloyip/archive/2010/03/29/1698953.html

开源光栅化渲染器SALVIA的漫长五年（准·干货）[空明流转-博客]
>
http://www.cnblogs.com/lingjingqiu/archive/2013/01/13/2858177.html

**光栅化***   
http://www.lxway.com/14496616.htm   
2D三角形光栅化算法   
http://www.lxway.com/58886441.htm  
基本图形的光栅化算法  
http://www.lxway.com/92529802.htm    
使用Barycentric Coordinates算法进行三角形光栅化  
http://blog.atelier39.org/cg/533.html  

## 开源项目

一个opengl的开源实现，代码很清晰，也比较容易懂。我记得它是很多平台上opengl的最初实现。
当时看的时候还不是很复杂的项目，记得还没有硬件加速的部分，或者我特地下了个老版本也说不定。觉得新版本太庞大也可以找老版本看看。
>
http://www.mesa3d.org/

SoftRenderer v0.2，一个软件渲染器，该项目为学习目的开发。
>
http://sr.codeplex.com/releases/view/97609

学习论坛
>
http://www.opengpu.org/bbs/forum.php?mod=forumdisplay&fid=15

