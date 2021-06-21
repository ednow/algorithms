# 题目描述文字版
利用一个栈实现以下递归函数的非递归计算:

$$
P_n(x) = \begin{cases}
1, &n=0  \cr
2x, &n=1  \cr
2xP_{n-1}(x) -2(n-1)P_{n-2}(x), & n>1
\end{cases}
$$

# 题目图片版
![](https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210621124757.png)

# 配套答案
![](https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210621224600.png)

# 测试结果

$\color{yellow}{\text{经测试答案是错的？}}$

|参数|p|recursion|
|----|----|----|
|(1,1)|2|1|
|(3,2)|40|-20|
|(6,5)|717880|-79880|
