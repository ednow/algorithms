# PTA1119总结
## 考点
+ 二叉树


## 问题重述
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210815214409.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210815214409.png';" /></details>

### 要点复述
已知后序和先序，求中序遍历

## 边界点
+ 只有一个节点


## 思路

Q：给定一定数量的节点二叉树的可能性有多少种?
Q：todo

联系前序后序的输出算法，发现也许可以用栈解决问题，前序序列是节点入栈的序列，后序序列是节点入栈的序列

影响入栈顺序的因素有哪些？先压入左孩子，没有左孩子了，出栈，压入右孩子
+ a比b压栈的可能情况:a是b的双亲及以上辈分的节点，a是b的父亲节点的左孩子

影响出栈顺序的因素有哪些？出栈的前提是他在栈顶，当前节点的孩子都不在栈中了


定理1: 栈中任意两个相邻元素一定是父子关系,即模拟出栈至少可以确定一棵树

定理2：如果一个树有两个孩子，出现在前序序列前面一定是左孩子，出现在前序序列后面的是左孩子,如果只有一个孩子，这个孩子是左孩子还是右孩子不确定

定理3：由定理2易得,如果一棵树只有度为0或者度为2的节点那么如果得到任何一个遍历序列，可以唯一确定一颗二叉树

定理4: 由定理3可推，如果节点的个数为偶数必不唯一


<details><summary>推导过程</summary>

易得$n_0 + n_2 = 2n_2 + 1$

即$n_0 = n_2 + 1$

$\text{总节点数} = n_0 + n_2 = 2_n2 + 1$

所以只有度为0或者度为2的节点的树的节点总数为奇数
</details>



<!-- 影响相邻节点之间是左孩子还是右孩子的因素？元素a -->



<!-- 思路1：迷宫探测? -->

## python

### 第一次提交
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210816002621.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210816002621.png';" /></details>

### 语法技术