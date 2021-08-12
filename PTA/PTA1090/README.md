# PTA1090总结
## 考点
+ 树


## 问题重述
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210812094512.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210812094512.png';" /></details>

### 要点复述
<!-- + 层次遍历找最深的 -->
+ 题目的第三行其实就是给的树的[双亲表示法](https://ednow.github.io/2021/03/04/%E7%8E%8B%E9%81%93-%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84#%E5%8F%8C%E4%BA%B2%E8%A1%A8%E7%A4%BA%E6%B3%95)

## 边界点
+ 实测输出结尾有空行


## 思路
+ 法1：层次遍历找最深的节点
+ 法2：用双亲表示法找父亲，找到父亲前level++

## cpp

### 语法技术
找一个vector中最大的元素，[参考文献](https://stackoverflow.com/questions/9874802/how-can-i-get-the-maximum-or-minimum-value-in-a-vector)

### 第一次提交
10有89是进入死循环了？
<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210812110754.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210812110754.png';" /></details>

### 第二次提交
层次遍历

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210812155905.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20210812155905.png';" /></details>