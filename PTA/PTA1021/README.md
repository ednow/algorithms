# PTA1021总结
## 考点
+ 


## 问题重述
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210822170034.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210822170034.png';" /></details>

+ acyclic

### 要点复述
判断一个图中存不存在环，通过[顶点数和边数可以判断](https://ednow.github.io/2021/06/17/%E4%B9%A0%E9%A2%98-%E7%8E%8B%E9%81%93-%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84-ch6-%E5%9B%BE/#%E4%B8%80%E4%B8%AA%E6%9C%89n%E4%B8%AA%E9%A1%B6%E7%82%B9%E5%92%8Cn%E6%9D%A1%E8%BE%B9%E7%9A%84%E6%97%A0%E5%90%91%E5%9B%BE%E4%B8%80%E5%AE%9A%E6%98%AF)

## 边界点
测试点2小于1000个,大于500个点
测试点3等于10000个点



## 思路
+ 思路1:深度优先遍历出所有的路径，初始化结果集合为空，取路径两两组合合并加入已选集合，可以合并则:超时
+ 思路2:对每个叶子节点进行dfs



<!-- + 思路1:深度优先遍历出所有的路径，初始化结果集合为空，每加入一条路径看首元素和里面元素的首元素一不一致，一致则取最长的，相同则加入 -->

## cpp

### 第一次提交
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210823144153.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210823144153.png';" /></details>

#### 关于死循环的更多线索
没研究明白
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210823155047.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210823155047.png';" /></details>

### 第二次提交
比较的变量错了

fix测试点0

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210823160600.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210823160600.png';" /></details>


### 语法技术

#### 是否可以切换share_ptr指向的对象吗?

#### c++切片最后一个元素
*(iter.end() - 1)