# PTA1043总结
## 考点
+ 二叉树
+ 二叉搜素树


## 问题重述
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210813084726.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210813084726.png';" /></details>


### 要点复述
已知前序判断是不是二叉搜索树，或者镜像二叉搜索树

## 边界点

## 思路
+ 根据前序序列可以把二叉搜索树构建出来，再求其前序，前序和原序列相等就是二叉搜索树，否则就不是(也许还有优化空间？)
+ 根据的出来的二叉树求后序


## python
todo:可将递归算法改成非递归实现，就不同修改递归栈深度了

### 第一次提交
测试点6只有一个节点

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210813101924.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210813101924.png';" /></details>

### 第二次提交
测试点：超过递归栈最大深度

重设递归栈深度（[参考文献](https://blog.csdn.net/weixin_38091140/article/details/84845979)）

<details><summary>重设递归栈深度代码详情</summary>

```python
# 重设递归栈深度
import sys
sys.setrecursionlimit(3000)
```

</details>



<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210813103539.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210813103539.png';" /></details>
