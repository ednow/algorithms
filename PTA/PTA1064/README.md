# PTA1064总结
## 考点
+ 完全二叉树


## 问题重述
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210813103931.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210813103931.png';" /></details>

### 要点复述
给定节点变成一个完全二叉排序树，然后输出层次排序序列

## 边界点

## 思路
<!-- 常见考研选择题，先排序再从中间开始构建二叉排序树 -->

观察满足排序二叉树的完全二叉树给出如下定理

给定一个升序的序列L: List[int]

${\textstyle\unicode{x2460}}$ 根据完全二叉树的定义可以很轻易的得到，最后一层不满的话往先保证先往左边填，最后一层是不是大于最后一层应该有的个数的$\dfrac{1}{2}$如果是那么右子树最后一层有元素,

${\textstyle\unicode{x2461}}$ 如果确定了右子树的元素的个数为k，根节点为L[-k-1],左子树的根节点为L[-k-2],右子树的根节点为L[-k]

## python

### 第一次提交
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210813164659.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210813164659.png';" /></details>
