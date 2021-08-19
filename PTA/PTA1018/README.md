# PTA1018总结
## 考点
+ 图


## 问题重述
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210819074726.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210819074726.png';" /></details>

### 要点复述
首先保证带权路径最小，然后保证带去的自行车的数量最少，然后保证带回来的自行车的数量最少

Q：必须保证保证那条路径上所有的单车都是只有一半的状态的嘛?还是只需要调整问题节点
A：保证保证那条路径上所有的单车都是只有一半的状态,每一个站点超过就带回去，不够就带过来
+ And more, all the stations on the way will be adjusted as well.
+ 仔细读题。。。。就是要把路途中的都搞一遍

## 边界点

## 思路
变种dijkstra，递归找到所有的路径

在dijkstra存储结构上，
+ 可将已选点集和未选点集划分成两个集合，然后排序已选点集传入到生成路径的函数中，感觉这个更快
+ 直接保存为一个数组一股脑梭哈
+ 为什么不把两个方法合并呢

## python

### 第一次提交
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210819155504.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210819155504.png';" /></details>

### version2
只adjust有问题的station
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210819160737.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210819160737.png';" /></details>

### 第二次提交
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210819202235.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210819202235.png';" /></details>


### 语法技术

[切片与拷贝](https://blog.csdn.net/Vimor/article/details/90816055?utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-3.control&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-3.control)

#### 求最终结果的时候直接使用lambda多关键字min
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210819150256.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210819150256.png';" /></details>

[参考文献](https://stackoverflow.com/questions/58618633/python-min-use-two-keys)

[参考文献](https://stackoverflow.com/questions/47246234/select-between-two-minimum-keys-in-python)

#### 初始化与引用
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210819145045.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210819145045.png';" /></details>

