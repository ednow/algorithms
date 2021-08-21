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

### 第一次提交
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210821151613.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210821151613.png';" /></details>

### 第二次提交
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210821152009.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210821152009.png';" /></details>

### 第三次提交
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210821152358.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210821152358.png';" /></details>

### bug

#### dijkstra:节点6的weight好像求错了
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210821144335.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210821144335.png';" /></details>

原来是我自己算错了，那没事了

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210821144830.jpg" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210821144830.png';" /></details>


#### setprecision(1) << fixed
还是没有保留位数：*1.0

#### 

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

###### debug不会用鸭
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210821085235.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210821085235.png';" /></details>

[参考文献：好像都是空的构造器，他也出问题了](https://segmentfault.com/q/1010000040305430)

解决方法：关闭GNU C++ Library Renderers option,[参考文献](https://youtrack.jetbrains.com/issue/CPP-22342)

###### 会指向同一个对象
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210821092616.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210821092616.png';" /></details>

###### ？删一个而动全身？
我试图。。。用一个实例的迭代器删除另外一个实例中的内容，导致出了这样的bug，我还查了那么多资料，btw 记得

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210821100021.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210821100021.png';" /></details>

使用原生指针也是会出现同样的问题

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210821141235.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210821141235.png';" /></details>

参考文献

+ https://stackoverflow.com/questions/6353149/does-vectorerase-on-a-vector-of-object-pointers-destroy-the-object-itself
+ https://stackoverflow.com/questions/30156670/copy-items-from-one-vector-to-another-vector
+ https://stackoverflow.com/questions/5253169/why-cant-i-perform-a-stdcopy-on-a-vector-of-stdshared-ptrs-in-c0x
+ https://stackoverflow.com/questions/49321107/how-to-make-a-copy-of-vector-of-shared-ptrs
+ https://stackoverflow.com/questions/23716018/deep-copy-constructor-with-stdvector-of-smart-pointers

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