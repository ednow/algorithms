# PTA1141总结
## 考点
+ 排序


## 问题重述
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210807220441.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210807220441.png';" /></details>


### 要点复述
+ 每个学校的代码要全部转为小写
+ 按照TWS(total weighted score)加权总分排序
+ 加权总分一致排名一致
+ 排名一致输出，按照做对的题数递增排序
+ 仍旧无法区分，按照学校代码升序



### 坑点
+ 结尾有空行


## cpp

### 思路

### 第一次提交
测试点不通过
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210808100417.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210808100417.png';" /></details>

### 第二次提交
使用读入加速技术大概能快50ms在大数据集的情况下10^5

运算的前后顺序会造成精度上的差距，严格按照题目意思走

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210808101143.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210808101143.png';" /></details>

### 语法技术
tolower()

### clion
报错？

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210808085527.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210808085527.png';" /></details>

