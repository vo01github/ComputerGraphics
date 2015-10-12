# 学习路线

知乎文章：如何开始用 C++ 写一个光栅化渲染器？
>
http://www.zhihu.com/question/24786878

## 学习顺序

 - 01  
什么版本都不用管 先实现一遍底层的光栅化的3D渲染算法，只用一个画像素的功能，把插值，zbuffer，alpha，阴影，三角形的光栅化，全自己底层实现一遍，之后进阶挑nvidia 的sdk里的例子逐句看，siggraph早期的gpgpu的论文挑自己觉得有趣的去实现，shaderX，gpu gems里头拿感兴趣的实现，我就是这么过来的，后来去了皮克斯做R&D，现在在Weta Digital做R&D



 - 05  
最经典的是《3D游戏编程大师》，不卖弄，纯干货，从零教你写软3D引擎，当然包括光栅化。我的观点一直是，当你迈出第一步，所有的东西都会水到渠成。

## 推荐书籍

《3D游戏编程大师》


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

