# PTA1053总结
## 考点
+ 树


## 问题重述
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210811171851.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210811171851.png';" /></details>

note用来输出的时候排序吗，翻译一下Note:
> 两个序列，前面都相等,但是后面存在一个$A_i$ > $B_i$那么，A大于B

### 要点复述
给定带权路径，找所有对应的值

输出的时候是输出路径上的权值

## 边界点
+ 树只有一个节点:测试点2
+ 路径的最后一个节点一定是叶子节点
+ 输出的结尾有空行

## 思路
+ dfs + 剪枝


## python

### 第一次提交
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210811220652.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210811220652.png';" /></details>

### 第二次提交
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210811222727.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210811222727.png';" /></details>

