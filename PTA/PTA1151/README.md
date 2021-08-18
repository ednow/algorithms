# PTA1151总结
## 考点
+ 二叉树


## 问题重述
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210817014841.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210817014841.png';" /></details>


### 要点复述
找最近公共祖先

## 边界点

## 思路
通过中序和前序构建出二叉树

然后找到两个节点，从根节点到其的路径，寻找最长公共前缀

+ 为了加速可以为路径建立一个缓存，就不用再次搜索了

## cpp

### 第一次提交
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210818185140.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210818185140.png';" /></details>

建树的时候就内存超时了 
+ 法1传引用和左右下标
+ 法2：将preorderSeq，inorderSeq,nodes设为全局变量全局变量
+ 不再用递归来插入节点

### 第二次提交
运行超时，加入缓存机制

### 语法技术

#### slice vector
跟python一样是左闭右开

[参考文献](https://stackoverflow.com/questions/50549611/slicing-a-vector-in-c/50549636)

#### 找到某个元素值的index
[参考文献](https://stackoverflow.com/questions/22388204/get-index-of-the-matching-item-from-vector-c)

#### vector.end()指向最后一个元素的下一个元素的位置
[参考文献](https://blog.csdn.net/hzw05103020/article/details/50397115)


#### 释放vector of pointers的内存

[参考文献](https://stackoverflow.com/questions/1361139/how-to-avoid-memory-leaks-when-using-a-vector-of-pointers-to-dynamically-allocat)

#### 不能比较两个指针
[参考文献](https://zhidao.baidu.com/question/1116986869358254139.html)