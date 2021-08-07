# PTA1108总结
## 考点
- 排序

## 问题重述

<details>
    <summary>Details</summary>

![](https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210706234627.png)
</details>

### 要点复述
+ 排名需要根据总成绩来排，
+ 总成绩相同，按照笔试成绩排，如果笔试也相同那么他们的排名一致
+ 对于个人，根据志愿一所一所学校比对，看一下志愿学校还有没有容量，有容量就接受
+ 对于学校，如果容量不足但是排名都是一致的那么学校需要全接受


### 坑点
实测结尾有空行

每一行是每一个学校接受的申请书，数字就是申请书的序号，

学校的序号和申请书的序号都是从0开始数


## cpp
### 思路
+ 法1：先排名，用队列(也可以用vector)解决，排名一致的人需要同时考虑的问题


[comment]: <> (+ 法2：排名的时候)

+ 法2：多线程？排名的同时丢给队列，另一个线程收到进行排序

### 语法技术
+ 向量之间做减法，[参考文献](https://stackoverflow.com/questions/14175858/c-subtract-vectors)

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210807165828.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210807165828.png';" /></details>

为什么结果是-2?

上面多减了，改了之后还是不对
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210807170544.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210807170544.png';" /></details>


不知道为什么少了个1
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210807171045.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210807171045.png';" /></details>

## python
### 语法技术
+ map可以被unpack

