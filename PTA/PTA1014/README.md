# PTA1014总结
## 考点
+ 队列


## 问题重述
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210809000228.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210809000228.png';" /></details>


### 要点复述
+ 输入的最后一行的quries的含义是，题目假设了这样一个场景，客户可以查询自己的服务什么时候能被解决完


### 坑点
+ 需要明确一点，如果一个人的请求被受理了，但解决完已经下班了，那么应不应该print sorry，这里需要仔细都题目，17点被前台服务的都要服务完
<!-- +  -->

## 思路
+ 思路1：for 一下，模拟每一秒钟的变化，直到下班
+ 思路2：每次选择最小的时间++

8：00时候的时间戳为0，之后每一分钟时间戳+1


## python
<!-- 最好选一种能初始化的变量技术（直接用init好了 -->

### 语法技术
按值删除元素`list.remove`

### 第一次提交
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210809145520.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210809145520.png';" /></details>

### 第二次提交
神坑：17点被前台服务的都要服务完

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210809205202.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210809205202.png';" /></details>


## cpp
### 语法技术