---
title: vps+Jellyfin+onedrive打造个人影视库
tags: A-技术笔记
mathjax: true
mathjax_autoNumber: true
key: vps+Jellyfin+onedrive打造个人影视库
sharing: true
typora-root-url: ..
---

> vps+Jellyfin+onedrive打造个人影视库，大致步骤：用rclone在vps中挂载onedrive，然后在vps中安装Jellyfin，设置好媒体库就可以用了。

<!--more-->

# 搭建个人影视库

这个最麻烦的应该是网盘挂载，网上有不少教程，我当时参考的这一篇：[https://post.smzdm.com/p/a4wm7zmw/](https://post.smzdm.com/p/a4wm7zmw/)。

顺便提一下，我之所以采用Onedrive，是因为它能白嫖5TB的网盘，用起来很爽hhhh。网上倒是有不少白嫖教程，一搜就能搜到了。

我的影视库地址：[http://144.34.247.62:8096](http://144.34.247.62:8096)。游客账号名tourist，无密码。如果想长期使用的话，可以联系我为你单独开一个账号（Jellyfin好像只能管理员在后台开账号，不能自助注册）。开好账号之后自己修改密码，谁也无法知道你的密码，包括管理员。

# 如何向影视库中上传资源？

这个我目前还没有找到好的解决方式（蹲一个优秀的前端大佬😣）。现有的解决方式有：

1. 联系我，我们共享onedrive文件夹，你通过共享文件夹上传资源。
2. 通过`scp`命令上传：

``` shell
#上传单个文件
scp {要上传的文件名} guest@144.34.247.62:/library/{category}
#上传文件夹
scp -r {要上传的文件夹名} guest@144.34.247.62:/library/{category}
```

其中`{category}`是具体某个分类对应的文件夹名称，便于整理。分类有这些：

![Jellyfin1](/assets/images/VPS/Jellyfin1.png)

例如，如果你要上传电影"The Martian.mkv"，那你应该在该电影所在的文件夹下输入下面的命令：

```shell
scp "./The Martian.mkv" guest@144.34.247.62:/library/Movies
```

随后会要求你输入密码。密码是123。输入之后应该就能看到上传任务了。

我个人建议采用第二种方式，因为它快，毕竟国内访问onedrive比较慢，服务器又恰好在国外，用scp命令上传会快一些。

资源库会定时更新，所以不会立即看到自己所上传的资源。如果想立即看到，请在媒体库下点击“刷新元数据”，等一段时间就会自己刷新了。

# 好像有的视频不能在浏览器网页播放？

我的vps的配置比较一般（蹲一个有钱的大佬😣），所以我关闭了服务器端视频转码的功能，不然CPU占用会立刻飙到100%，vps服务商就会设限。

如果想观看这一类视频，目前只能通过安装客户端本地解码的方式来实现：

**windows/linux**：安装[Jellyfin Media Player](https://github.com/jellyfin/jellyfin-media-player/releases)。

**安卓**：应用商店安装Jellyfin之后，再安装VLC，然后在Jellyfin的客户端设置中选择本地VLC播放器播放。

**iOS**：安装infuse，然后添加Jellyfin。

如果要填写服务器地址，就是144.34.247.62，端口是8096。