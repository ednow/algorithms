# PTA1135总结
## 考点
+ 二叉树
+ 红黑树


## 问题重述
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210816132243.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210816132243.png';" /></details>

### figure2:

违反了规则4：2的孩子7应该是黑色

### figure3:
违反了规则5：10-11(两个红色节点)，10-17(3个黑色节点)，到叶子节点的黑色节点数不相等

### 要点复述
判断一棵树是不是红黑树

## 边界点

需要将空节点进行显示设置

## 思路

红黑树[参考文献](https://www.jianshu.com/p/e136ec79235c)

[红黑树在线演示](https://www.cs.usfca.edu/~galles/visualization/RedBlack.html)

红黑树首先是一颗二叉排序树，前序遍历就可以把这个二叉排序树构建出来，


+ 检查根节点是不是黑色的
+ 检查红色节点的孩子是不是都是黑色的
+ 用双亲表示法，快速找到路径上的父亲，用孩子表示法可以快速找孩子(确定是不是叶子节点)

<!-- + 然后再深度优先搜索每一个叶子节点的路径，看一下满不满足第5点 -->


## python

### 第一次提交

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210816201655.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210816201655.png';" /></details>

<!-- #### 重载小于很奇怪
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210816194958.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210816194958.png';" /></details> -->

### 第二次提交
可以看到第二个和第三个测试数据出错了

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210818232425.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210818232425.png';" /></details>

需要给所有的空节点添加上nil节点

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210818233003.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210818233003.png';" /></details>

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210819001711.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210819001711.png';" /></details>

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210819001147.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210819001147.png';" /></details>