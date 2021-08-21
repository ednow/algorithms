# PTA1072总结
## 考点
+ 


## 问题重述
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210819132653.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210819132653.png';" /></details>

+ the minimum distance between the station and any of the residential housing is as far away as possible
+ ？？？最小距离要尽可能大？？

### 要点复述

## 边界点

## 思路

对每一个station求最短路径，

输出优先级

+ 输出最短路径中距离最小的最小的，
+ 输出最短路径中平均路径最小的
+ 输出stationNum最小的


## cpp

### 语法技术

#### 初始化二维vector数组
[参考文献](https://stackoverflow.com/questions/17663186/initializing-a-two-dimensional-stdvector)

#### 关于读取边的时候节点处理的问题
[参考文献](https://stackoverflow.com/questions/1878001/how-do-i-check-if-a-c-stdstring-starts-with-a-certain-string-and-convert-a)

##### string.at

比较：[参考文献](https://stackoverflow.com/questions/47706633/find-first-character-of-string-then-compare-it-with-a-symbol-c)

[参考文献](https://www.cplusplus.com/reference/string/string/at/)

##### strtol

##### 智能指针
[参考文献](https://www.cyhone.com/articles/right-way-to-use-cpp-smart-pointer/)

###### 智能指针指向数组
[参考文献](https://blog.csdn.net/weixin_43705457/article/details/97617676)

###### makeshare
[参考文献](https://www.jianshu.com/p/03eea8262c11)

###### 不会用鸭
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210821085235.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210821085235.png';" /></details>

[参考文献：好像都是空的构造器，他也出问题了](https://segmentfault.com/q/1010000040305430)

#### move和copy

`<utility>`

关于move：知乎[参考文献](https://www.zhihu.com/question/64205844)

[参考文献](https://stackoverflow.com/questions/36827900/what-makes-moving-objects-faster-than-copying)

[参考文献](https://blog.csdn.net/weixin_29973493/article/details/112124672)

#### min和匿名函数
[参考文献](https://blog.csdn.net/Awesomewan/article/details/108654058)

#### 通过值删除元素
[参考文献](https://stackoverflow.com/questions/3385229/c-erase-vector-element-by-value-rather-than-by-position)

#### accumulate with lambda
[参考文献](https://stackoverflow.com/questions/29685003/how-can-i-use-stdaccumulate-and-a-lambda-to-calculate-a-mean)

#### back_inserter