# PTA1113总结
## 考点
+ 排序


## 问题重述
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210807184735.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210807184735.png';" /></details>


### 要点复述
+ 怎么感觉这道题很经典了，集合划分，而且好像做过？
+ 之前是有负数的，这次只有正数
+ 排序之后求和的差就好，极度简单


### 坑点
实测有空行

## python
### 思路
要想长度的差最小，就是均分两段列表，只有两种情况，原始列表为奇数或者偶数

如果是奇数，长度差必为1

如果是偶数，长度差必为0

要想两段的和最大，那么就是按照大小排序，在划分等长的两段即可

### 第一次提交

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210807190428.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210807190428.png';" /></details>

