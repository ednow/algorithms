# PTA1098总结
## 考点
+ [堆排序](https://ednow.github.io/2021/03/04/%E7%8E%8B%E9%81%93-%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/#%E5%A0%86%E6%8E%92%E5%BA%8F)
+ [插入排序](https://ednow.github.io/2021/03/04/%E7%8E%8B%E9%81%93-%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/#%E7%9B%B4%E6%8E%A5%E6%8F%92%E5%85%A5%E6%8E%92%E5%BA%8F)


## 问题重述
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210810222228.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210810222228.png';" /></details>

### 要点复述
+ 判断一个被排序好的序列是插入排序还是堆排序的结果


## 坑点
+ 实测结尾有空行

## 思路
堆排序一次排序会让后面的元素处在正确的位置上

直接插入排序一次排序会让前面的元素处在正确的位置上

因为需要升序排序，所以使用大根堆

一份更有意思的实现：[参考文献](https://blog.csdn.net/sinat_29278271/article/details/47939833?utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1.no_search_link&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1.no_search_link)

### 如何判断是什么排序的结果
+ 思路1：直接生成一遍中间结果,一一比较
+ 思路2：找到能够直接判断的特点:这两种排序方法只能让一边排好

## python

### 语法技术
python [swap](https://stackoverflow.com/questions/14836228/is-there-a-standardized-method-to-swap-two-variables-in-python)


### 第一次提交
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210811191721.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210811191721.png';" /></details>

### 第二次提交
如果直接插入排序插入到的位置是0号位需要收尾

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210811193035.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210811193035.png';" /></details>

### 第三次提交

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210811194257.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210811194257.png';" /></details>

### 第四次提交

+ 判断工作指针的地方出错了
+ 双重确认是好方法
+ 也许判断排序方法上还有更好的操作


<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210811203818.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210811203818.png';" /></details>
