# PTA1075总结

## 问题重述
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210806213828.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210806213828.png';" /></details>

要点重述:
+ 需要按照总得分排名
+ 总得分一致，按照满分的题目数排序 
+ 如果满分的题目数一致，按照ID递增排序
+ 没有提交成绩，或者所有答案没有通过编译器，不会出现在排名列表里面
+ `实测有换行`

Q： ?为什么要给每一题的满分是多少
A: 一个人满分的个数用来排序

坑点
+ 如果一个人在列表里面并且提交过对应的题目那么他的分数应该是0



## 考点
+ 排序

## cpp
+ 动态确定结构体里面vector的长度
+ 判断vector中的值是否相等:`(std::equal(records[i].scores.begin(), records[i].scores.end(), -1))` 不管用
+ 判断相等的元素有多少个:[参考文献](https://stackoverflow.com/questions/57037696/how-to-count-the-equal-elements-of-2-different-vectors-in-c)

### 编译相关
struct初始化online-judge编译不通过，本地编译通过

编译不通过？（g++不行，clang ok




<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210807001920.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210807001920.png';" /></details>

#### clang
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210807002544.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210807002544.png';" /></details>
> clang++ -DONLINE_JUDGE -O2 -Wall -std=c++14 -pipe $src -lm -o $exe


#### g++
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210807002453.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210807002453.png';" /></details>
> g++ -DONLINE_JUDGE -fno-tree-ch -O2 -Wall -std=c++14 -pipe $src -lm -o $exe


### 第一次提交
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210807002612.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210807002612.png';" /></details>