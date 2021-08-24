# PTA1103总结
## 考点
+ 


## 问题重述

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210823212539.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210823212539.png';" /></details>

### 要点复述

## 边界点

## 思路
<!-- 求通项? -->
dfs+减枝

[对数运算法则](https://baike.baidu.com/item/%E5%AF%B9%E6%95%B0%E8%BF%90%E7%AE%97%E6%B3%95%E5%88%99/18881641?fr=aladdin)

应该是开n次方

[参考文献](https://blog.csdn.net/sunshine_critical/article/details/84940105)

[vector之间可以直接比较](https://blog.csdn.net/sunshine_critical/article/details/84940105)
## cpp
关键点：每一次向下搜索的值都小于等于此次搜索的值

vector直接比较

other1103不用恢复栈的内容的合理性在于当到达那处代码的时候每一个元素都被更新成了答案的值了
### 第一次提交
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210823225520.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210823225520.png';" /></details>

看样子是死循环了

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210823225849.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210823225849.png';" /></details>

#### version2
缩小了基数的范围,缩小了递归的深度

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210824143007.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210824143007.png';" /></details>

### 第二次提交

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210824153942.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210824153942.png';" /></details>

#### 直接使用vector的比较
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210824174308.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210824174308.png';" /></details>

### 第三次提交
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210824175212.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210824175212.png';" /></details>

### 第四次提交
剪枝

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210824184200.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210824184200.png';" /></details>

### 第5次提交
终于ac了

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210824190653.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210824190653.png';" /></details>

### 语法技术

#### python + c++
[参考文献](https://stackoverflow.com/questions/33799933/fast-logarithm-calculation)

#### pow, log

#### vector中的等于赋值
[参考文献](https://blog.csdn.net/u013992365/article/details/74276103)

[参考文献](http://www.cplusplus.com/reference/vector/vector/operator=/)

#### gdb显示vector
一用就退出

[参考文献](https://stackoverflow.com/questions/29587400/accessing-vector-items-in-gdb)

#### debugger 不能显示二维数组
[参考文献](https://stackoverflow.com/questions/33829684/c-2d-vector-declaration-and-element-access-from-debugger)

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210824212027.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210824212027.png';" /></details>

##### toochain

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210824212250.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210824212250.png';" /></details>

#### vector不是一个type


<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210824214531.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210824214531.png';" /></details>

#### 可能是我接管了input和output的原因,新建一个project就ok了

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210824215315.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210824215315.png';" /></details>

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210824215331.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210824215331.png';" /></details>


[参考文献](https://stackoverflow.com/questions/24130093/gdb-could-not-find-operator)