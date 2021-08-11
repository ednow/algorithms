# PTA1098总结
## 考点
+ [堆排序](https://ednow.github.io/2021/03/04/%E7%8E%8B%E9%81%93-%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/#%E5%A0%86%E6%8E%92%E5%BA%8F)
+ [插入排序](https://ednow.github.io/2021/03/04/%E7%8E%8B%E9%81%93-%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/#%E7%9B%B4%E6%8E%A5%E6%8F%92%E5%85%A5%E6%8E%92%E5%BA%8F)


## 问题重述
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210810222228.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210810222228.png';" /></details>

### 要点复述
+ 判断一个被排序好的序列是插入排序还是堆排序的结果


## 坑点

## 思路
堆排序一次排序会让后面的元素处在正确的位置上

直接插入排序一次排序会让前面的元素处在正确的位置上

因为需要升序排序，所以使用大根堆


### 如何判断是什么排序的结果
+ 思路1：直接生成一遍中间结果,一一比较
+ 思路2：找到能够直接判断的特点:这两种排序方法只能让一边排好

## python

### 语法技术
python [swap](https://stackoverflow.com/questions/14836228/is-there-a-standardized-method-to-swap-two-variables-in-python)
