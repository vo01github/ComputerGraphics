
# Lesson2：Point,Vectors,and Meshes

笔记下载地址
>
https://www.udacity.com/wiki/cs291

## Coordinate System

在不同的世界用的是不同的坐标系，比如在地球上，用的是球状坐标系：经度纬度，海拔。

在3D计算机图形学里，我们通常用的是 直角坐标系。

https://www.udacity.com/course/viewer#!/c-cs291/l-90856897/e-96821016/m-97493300


##  Left-Handed vs. Right-Handed
左手坐标系 和 右手坐标系

拇指向X轴，食指指向Y轴，中指指向Z轴。

左手坐标系 和 右手坐标系 只是反转了 Z轴的方向。


## Points and Lines

我们发给图形处理单元 只有3个基本的图元(primitives)

点，线，三角形。

定义点，只需要指定一个3D坐标。

定义线，通过指定2点的坐标，定义一条线。

## Triangles

定义三角形，只需要三个点。

我们通常关心光线遇到物体的表面时，会咋样，但是我们不在乎一个物体的体积是多少。
我们不需要定义任何体积细节。

## Creating Geometry in three.js

终于能开始编程了

3D图像定义需要2种东西，一个是**几何形状**，一个是**材质**。

	// 定义几何
	var triangle = new THREE.Geometry();
	triangle.vertices.push( new THREE.Vector3( 1, 1, 0 ) );
	triangle.vertices.push( new THREE.Vector3( 3, 1, 0 ) );
	triangle.vertices.push( new THREE.Vector3( 3, 3, 0 ) );
	
	triangle.faces.push( new THREE.Face3( 0, 1, 2 ) );

	// 定义材质
	var triangleMaterial = new THREE.MeshBasicMaterial( { color: 0x2685AA, side: THREE.DoubleSide } );

通过把几何和材质传入给一个**网格(mesh)**对象.

	var triangleMesh = new THREE.Mesh( triangleGeometry, triangleMaterial );

然后添加这个网格(mesh)到**场景(scene)**中.

  	scene.add(triangleMesh);


## Minimum Triangulation

一个凸多边形，所需要的最小三角形的个数来拆分它。。

三角形个数 = 边个数 - 2

##  Vertex Ordering and Culling

Backface culling 背面剔除 
GPU 使用 Backface culling 技术来加速 运算。

比如一个盒子，只渲染面向你的表面，背对你的表面就不渲染了，渲染了你也看不到。 ：）

我们把可见部分叫做 "前面"， FrontFace。

但是我们如何确定一个三角形是前面而不是后面？

我们通过顶点的顺序来判断在 WebGL里，一个面是 FrontFace 还是  Backface 。

如果是 **逆时针**，就说这个面是 FrontFace，如果是 **顺时针**，就说这个面是  Backface。

逆时针旋转又被称为 右手规则。

顺时针旋转又被称为 左手规则。

	// 在 js 里面，是通过下面这样设定，来进行 背面剔除 的
	var material = new THREE.MeshBasicMaterial( { color: 0xF6831E, side: THREE.FrontSide } );


## Lesson 2: Problem Set 问题答疑

### 第1道题目 Polygon Creator

用代码画个正多边形，已经开了 Backface culling，所以描述 几何 部分处，要注意需要对点的描述是
逆时针的。

### 第2道题目 Polygon Location

在第1道题目的基础上，函数多获得了一个参数，原点的位置。 要把这个画的多半形 移动到传入的参数那里去。

	geo.vertices.push( new THREE.Vector3( x + location.x, y + location.y, 0.0 ) );

### 第3道题目 Polygon Radius

在上面的基础上加上一个新参数 **半径**

### 第4道题目 Build a Stairway

创建一个 梯子，到达金杯。

### 第5道题目 The Drinking Bird

画一个喝水鸟 【待做这道题目】


### 第6道题目 

【待做这道题目】



## Interview:Modeling in the Real World

专访：在真实世界中的模型

What Is AutoCAD?

游戏，CAD这类软件的区别？

游戏里面，最多你的头像死亡了。CAD这类软件，搞错了，就有可能是人们死掉了。





