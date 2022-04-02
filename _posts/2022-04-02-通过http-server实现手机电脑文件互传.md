---
title: 通过http-server实现手机电脑文件互传
tags: A-技术笔记 http-server Termux shell
mathjax: true
mathjax_autoNumber: true
key: 通过http-server实现手机电脑文件互传
sharing: true
typora-root-url: ..
---

> 搞个有意思的文件传输，基于http-server实现。请保证手机和电脑处于同一局域网中。

<!--more-->

如果要基于http-server实现功能，就必须要有shell，电脑上直接用cmd来搞就可以，手机上得有能支持shell的平台，我们这里选用Termux。教程参考此处：[Termux 入门教程：架设手机 Server 下载文件](https://www.ruanyifeng.com/blog/2019/07/termux-tutorial.html#comment-412342)

# 用Termux实现手机向电脑传输文件

Termux在安卓手机上模拟了Linux平台。这里分为三步走：安装Termux，安装Node.js，通过Node.js运行http-server。

## 1. 安装Termux

Google Play商店因为技术原因已经停止更新Termux，故我们从GitHub上直接下载，地址为：[https://github.com/termux/termux-app/releases](https://github.com/termux/termux-app/releases)。[^1]

选择一个apk文件下载安装后直接打开应用，可以看到这样的界面：

<center><img src="/assets/images/http-server/1.jpg" alt="1" style="zoom: 25%;" /></center>

做一下简单的环境准备：

执行下面两条命令更新系统：

``` shell
# 连接远程仓库，获取软件包信息
$ apt update

# 更新本地已经安装的软件包
$ apt upgrade
```

可以安装运行sl软件包测试系统是否正常：

``` shell
# 安装 sl 软件包
$ apt install sl

# 运行
$ sl
```

如果一切正常，会显示一个火车的命令行动画。

然后让手机能访问本地存储（重要）：

``` shell
$ termux-setup-storage
```

执行完之后手机会询问是否允许Termux访问本地存储，选择“始终允许”。

这样的话键入`ls`会看到本地目录下多了一个`storage`目录：

<center><img src="/assets/images/http-server/2.png" alt="2" style="zoom: 50%;" /></center>

[^1]: 更多Termux app相关内容可见[此处](https://github.com/termux/termux-app#github)。

## 2. 安装Node.js

执行命令

``` shell
$ apt install nodejs
```

即可安装Node.js

## 3. 架设Server

现在，通过 Node.js 运行 HTTP Server。

首先，安装 npm 模块http-server。

``` shell
$ npm install -g http-server
```

然后，运行 Server。

``` shell
$ http-server
```

正常情况下，命令行会提示 Server 已经在 8080 端口运行了，并且还会提示外部可以访问的 IP 地址。

<center><img src="/assets/images/http-server/3.png" alt="3" style="zoom: 50%;" /></center>

这时，在电脑浏览器地址栏输入"Available on"后面的某个ip地址就能访问了（第一个不是，可能是第二个也可能是第三个，都试试肯定有一个能行），如下图：

<center><img src="/assets/images/http-server/4.png" alt="4" style="zoom: 60%;" /></center>

可以看到，`storage`文件夹下面保存了手机中的图片、视频等文件：

<center><img src="/assets/images/http-server/5.png" alt="5" style="zoom: 60%;" /></center>

# 实现电脑向手机传输文件

与手机端类似，不过这次我们可以直接用命令行窗口来搞了。

## 安装配置Node.js

参考这则教程：[nodejs本地环境配置(windows10)](https://blog.csdn.net/github_38585431/article/details/105362502)

## 安装http-server

直接在cmd窗口中执行

``` shell
npm install http-server
```

安装http-server。安装完毕后找到本地Node.js的目录，将其中`node-global`的路径放入环境变量中：

右键此电脑 - 属性 - 高级系统设置 - 环境变量，出现窗口：

<center><img src="/assets/images/http-server/6.png" alt="6" style="zoom: 60%;" /></center>

找到系统变量中的Path，双击打开，然后新建环境变量并将`node-global`的路径放入其中，如图所示：

<center><img src="/assets/images/http-server/7.png" alt="7" style="zoom: 60%;" /></center>

这时候到你想要分享的文件夹下，打开cmd，执行命令

``` shell
http-server
```

看到如下窗口：

<center><img src="/assets/images/http-server/8.png" alt="8" style="zoom: 80%;" /></center>

有了手机端的经验，我们直接在手机浏览器地址栏输入之前输入的ip地址，比如我的就是`https://10.204.26.21:8080`，就能得到如下的界面：

<center><img src="/assets/images/http-server/9.jpg" alt="9" style="zoom: 30%;" /></center>

这些文件就可以下载到手机中了。

# 关于Termux，多说两句

Termux可以在手机上模拟Linux，那就可以写一些简单的C程序或者python程序了，比如我们可以用下面的命令安装clang包，支持C程序编译和运行

``` shell
pkg install clang
```

再安装文本编辑器vim

``` shell
pkg install vim
```

这时候就可以像在电脑端linux的终端那样编写C代码了。当然也可以活学活用，比如把电脑上的C程序通过http-server传到手机上，再用Termux打开并保存。比如我在电脑上写了一个多项式求导的C程序，保存到手机上:

<center><img src="/assets/images/http-server/10.jpg" alt="10" style="zoom: 30%;" /></center>

用gcc编译运行这个程序，就和电脑运行一模一样：

<center><img src="/assets/images/http-server/11.png" alt="11" style="zoom: 40%;" /></center>