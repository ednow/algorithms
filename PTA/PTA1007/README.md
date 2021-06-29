# 总结
## 考点
- 动态规划

## 问题重述
![](https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210627125201.png)

## python
### 思路
${\textstyle\unicode{x2460}}$  将一个`[1,-1,2]`(data.json中id=32的测试数据),按照正负拆分为子列表`[[1],[-1],[2]]`。
> $\color{red}{\text{正数列表}}$：`[1]`,`[2]`  
> $\color{green}{\text{负数列表}}$:`[-1]`


${\textstyle\unicode{x2461}}$ 两个$\color{red}{\text{正数列表}}$中间有$\color{green}{\text{负数列表}}$的话肯定会让整个序列减少，但如果这三个列表的和（两个$\color{red}{\text{正数列表}}$中间有$\color{green}{\text{负数列表}}$）等于或大于另外两个$\color{red}{\text{正数列表}}$单独的和，那么合并这三个序列成更大的列表。

${\textstyle\unicode{x2462}}$ 处理完之后，找到最大的序列并,输出题目要求的内容。

将思路翻译成程序,并考虑边界情况。

$\xrightarrow{\text{summit}}$读取输入的字符串,处理成`List[int]`$\xrightarrow{{\textstyle\unicode{x2460}}\text{split\_positive\_negative}}$正负分割完的List$\xrightarrow{{\textstyle\unicode{x2461}}\text{merge\_positive}}$能合并的都合并了$\xrightarrow{{\textstyle\unicode{x2462}}\text{find\_max\_sequence}}$得到符合题目要求的正确结果$\xrightarrow{\text{summit}}$输出

### 第一次提交
![](https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210628210606.png)


### 第二次提交
通过`data.json`的1-6

![](https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210628212537.png)

### 第三次
通过`data.json`的所有测试
![](https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210629003333.png)
### 第四次
![](https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210629004841.png)

### 4
![](https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210629011516.png)

### 5
让merge_positive在result更新之后，记住merge的位置，不再从0开始扫描，不再TLE
![](https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210629150348.png)

### 6
发现原来是题目理解错了，他要求的不是最长的序列。$\color{red}{\text{读题很重要}}$
![](https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210629171544.png)

## 参考文献
[解析](https://blog.csdn.net/qq_43647628/article/details/104930219)

[解析2](https://blog.csdn.net/S_999999/article/details/88043852)

[测试数据参考](https://blog.csdn.net/qq_42672532/article/details/102641396)

[解析3](https://blog.csdn.net/Joyceyang_999/article/details/81872970)