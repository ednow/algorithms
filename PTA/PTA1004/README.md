# 总结
## 问题重述

![](https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210625231516.png)
`The input ends with N being 0. That case must NOT be processed.`?

## 考点
+ 树
+ 树的遍历
+ 层次遍历
+ [孩子表示法](https://ednow.github.io/2021/03/04/%E7%8E%8B%E9%81%93-%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/#%E5%AD%A9%E5%AD%90%E8%A1%A8%E7%A4%BA%E6%B3%95)

## c++
相较于java的动态特性，以及对c++的不熟悉，在设计树的数据结构的时候束手束脚的，加上pta1002超时的教训，意味着作为一种算法考试，为了规避超时，在延展性，设计性，优雅性上做出牺牲

在commit(#f2270f5)中进行了不好的设计(但貌似可以用时间换空间)，应该让栈去记录层数信息而不是让树这个数据结构本身去记录层数信息

## 结果
![](https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210627010059.png)

### 改进
只生成空vector

![](https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210627011114.png)

生成整个树的结构，不进行队列的操作

![](https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210627011239.png)

## python
### 第一次提交
![](https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210627212423.png)

同样的思路,python好好的

果然没能好好掌握c++呢
