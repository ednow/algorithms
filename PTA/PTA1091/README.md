# PTA总结
## 考点
+ 


## 问题重述
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210827153516.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210827153516.png';" /></details>

Two pixels are connected and hence belong to the same region if they share a common side, as shown by Figure 1 where all the 6 red pixels are connected to the blue one.

### 要点复述

## 边界点

## 思路
把三位图形降维到一维然后用多次dfs直到节点都被访问为止

## cpp
[参考文献](https://blog.csdn.net/qq_38633884/article/details/102533814)

### 第一次提交
两个超时

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210827195634.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210827195634.png';" /></details>

建图的时候内存超限，不知道为什么没有捕获
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210827195844.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210827195844.png';" /></details>

### 第二次提交
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210827205518.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210827205518.png';" /></details>

本地测试大数据的时候

`Process finished with exit code -1073741571 (0xC00000FD)`

估计是爆栈了?

[参考文献](https://blog.csdn.net/qq_40520596/article/details/107228190)

递归爆栈,必须用bfs