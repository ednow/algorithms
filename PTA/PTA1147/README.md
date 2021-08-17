# PTA1147总结
## 考点
+ 堆
+ 二叉树


## 问题重述
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210816222514.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210816222514.png';" /></details>

### 要点复述
给定层次遍历，判断其是不是堆，并且输出后序遍历

（用python可能会超时？为了加快速度，直接用非递归的后序遍历

## 边界点

## 思路
后序遍历的非递归实现 王立波有一版，感觉思路跟我不一样，感觉他为了配合这个空节点写的很丑。
+ 我的思路不会压入空节点（尽管在实际的函数调用栈会压入空节点

Q: 递归和非递归谁更快？虽然都是O（n）# todo

Q:[为什么/2是父亲节点？](https://blog.csdn.net/weixin_33901843/article/details/91457366)

## python

### 第一次提交
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210817013644.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210817013644.png';" /></details>

### 语法技术


## cpp
看到[一个人](https://blog.csdn.net/birdmanqin/article/details/104110628)直接设置一个全局变量数组，将这个数组的index作为“地址”索引node哈哈哈

记得using name space

### 关于结构体
c++中结构体需不需要typedef，[不需要](https://ask.csdn.net/questions/768441)



### 思路1：
复刻python代码

#### cpp没有引用数组，如何实现python中的nodes？
1. 使用指针数组
2. 使用对象数组

#### 如何传递指针数组中的值？
思路1：间接寻址再传递引用
思路2：传递指针的引用，

#### 重载关系运算符
Method 'operator<' can be made const

[const函数](https://www.cnblogs.com/fan-0802-WHU/p/10961279.html)

#### cpp对递归栈有深度限制吗？
一般来说看系统

[参考文献](https://stackoverflow.com/questions/2630054/does-c-limit-recursion-depth)

#### 如何实现python中某个函数的默认赋值?
函数的重载

#### vector推导式？
cpp中貌似没有这样的语法糖

[参考文献](https://stackoverflow.com/questions/36339533/how-to-generate-vector-like-list-comprehension)

#### 关于构造函数中出现形参成员变量
[参考文献](https://www.zhihu.com/question/54031505)

[参考文献](https://stackoverflow.com/questions/268587/can-i-use-identical-names-for-fields-and-constructor-parameters)

[参考文献](https://stackoverflow.com/questions/34959703/what-happens-when-constructors-parameter-has-same-name-as-member-variable)

#### c++中的this指针

[参考文献](http://c.biancheng.net/view/2226.html)

#### c++中的智能指针与垃圾回收
[参考文献](https://www.jianshu.com/p/a70565441745)

#### vector对象的生命周期
[参考文献](https://zhuanlan.zhihu.com/p/35002132)

#### explicit关键字

[参考文献](https://www.cnblogs.com/rednodel/p/9299251.html)


#### 关于取地址
为什么不能直接对nodes[0]取地址？传给后序遍历

#### reinterpret_cast
[参考文献](http://c.biancheng.net/view/410.html)

#### 关于递归栈的深度
[参考文献](https://stackoverflow.com/questions/2630054/does-c-limit-recursion-depth)

### 第一次提交

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210817154346.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210817154346.png';" /></details>

使用了读入加速，居然在小数据上还慢了?
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210817154553.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210817154553.png';" /></details>