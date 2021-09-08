# PTA总结
## 考点
+ 


## 问题重述
This time your job is to fill a sequence of $N$ positive integers into a **spiral matrix** in non-increasing order. A spiral matrix is filled in from the first element at the upper-left corner, then move in a clockwise spiral. The matrix has $m$ rows and $n$ columns, where $m$ and $n$ satisfy the following: $m\times n$ must be equal to $N$; $m\ge n$; and $m-n$ is the minimum of all the possible values.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer $N$. Then the next line contains $N$ positive integers to be filled into the spiral matrix. All the numbers are no more than $10^4$. The numbers in a line are separated by spaces.

### Output Specification:

For each test case, output the resulting matrix in $m$ lines, each contains $n$ numbers. There must be exactly 1 space between two adjacent numbers, and no extra space at the end of each line.

### Sample Input:

```
12
37 76 20 98 76 42 53 95 60 81 58 93
```

### Sample Output:

```
98 95 93
42 37 81
53 20 76
58 60 76
```

### 要点复述
螺旋矩阵:[参考文献](https://www.cnblogs.com/grandyang/p/4362675.html)

## 边界点

## 思路

## cpp

### 第一次提交
一超时,两错误
超时是因为3*3这种情况
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210908214520.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210908214520.png';" /></details>

### 第二次提交

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210908224329.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210908224329.png';" /></details>

### 语法技术
#### 循环迭代器
[参考文献](https://stackoverflow.com/questions/2616643/is-there-a-standard-cyclic-iterator-in-c)