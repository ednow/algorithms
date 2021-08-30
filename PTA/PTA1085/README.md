# PTA总结
## 考点
+ 


## 问题重述
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210830140040.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210830140040.png';" /></details>

### 要点复述
从一堆数中挑出满足

## 边界点

卡内存，
int最大表示10位10进制位

## 思路
<!-- 删掉最小的元素，或者删掉最大的元素 -->

直接查找遍历：[文献](https://blog.csdn.net/whutshiliu/article/details/82913133)


## cpp
### 第一次提交
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210830142702.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210830142702.png';" /></details>

#### 为什么23行没有被执行？
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210830144048.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210830144048.png';" /></details>

### 第二次提交
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210830144603.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210830144603.png';" /></details>

### 第三次提交
bfs+二分

答案错误+内存超限
+ 答案错误是因为数据类型的大小

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210830182928.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210830182928.png';" /></details>

### 第四次提交
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210830184955.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210830184955.png';" /></details>

### 语法技术
#### 得到集合中最后一个元素
*a.rbegin()

[参考文献](https://stackoverflow.com/questions/41302441/c-iterator-to-last-element-of-a-set)

