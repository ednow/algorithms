# PTA1056总结
## 考点
+ 队列
+ 排序

## 问题重述
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210809210146.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210809210146.png';" /></details>

题目看了好久都没看懂


### 要点复述
> 一共有$N_P$个参赛人员，每$N_G$个参赛人员会被分到一组进行比赛  
> 这个英文描述就离谱，`playing order`他应该是想讲，比如题目给定的案例,那么`6 0 8`号被划分到一起比赛  
> 第二行是每个参赛选手老鼠的重量，第i个数字，对应第i个选手的老鼠的重量  
> 第三行是进场的顺序，每进3个，这三个就比赛  


### 坑点
读题

如果最后一轮最高分打平怎么办，如果前面几轮打平怎么办

为什么案例没有第四名？排名居然是group+1不是有多少层就排多少名[参考文献](https://my.oschina.net/u/4374940/blog/3391190)
> 其实和以前做排名题的时候思路是一置的，前面有n个人，后面的就是n+1名，据此可修正之前的思路(待做)，而直接求group的方法其实较为巧妙


## python
### 语法技术
dict.items 不能 subscription

### 先交再说
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210809221927.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210809221927.png';" /></details>

### 第二次提交
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210809223744.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210809223744.png';" /></details>



## cpp

### 思路

### 语法技术