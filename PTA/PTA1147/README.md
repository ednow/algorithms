# PTA1147总结
## 考点
+ 堆
+ 二叉树


## 问题重述
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210816222514.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210816222514.png';" /></details>

### 要点复述
给定层次遍历，判断其是不是堆，并且输出后序遍历

（用python可能会超时？为了加快速度，直接用非递归的后序遍历

## 边界点

## 思路
后序遍历的非递归实现 王立波有一版，感觉思路跟我不一样，感觉他为了配合这个空节点写的很丑。
+ 我的思路不会压入空节点（尽管在实际的函数调用栈会压入空节点

Q: 递归和非递归谁更快？虽然都是O（n）# todo

Q:[为什么/2是父亲节点？](https://blog.csdn.net/weixin_33901843/article/details/91457366)

## python

### 第一次提交
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210817013644.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210817013644.png';" /></details>

### 语法技术