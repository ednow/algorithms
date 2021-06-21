# 题目描述
利用一个栈实现以下递归函数的非递归计算:

$$
P_n(x) = \begin{cases}
1, &n=0  \cr
2x, &n=1  \cr
2xP_{n-1}(x) -2(n-1)P_{n-2}(x), & n>1
\end{cases}
$$

![](https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210621124757.png)