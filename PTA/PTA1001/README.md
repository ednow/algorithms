# 总结

## python
[一个正确答案](https://blog.csdn.net/weixin_44575329/article/details/104362066)

### 坑点1:
需要考虑到多项式的值为0的时候,输出为`"0"`不能有空格`"0 "`

测试数据中的`某个测试点的输出格式错误的测试数据`
### 坑点2:
记得考虑到所有的值都被`round`了

对应到我的代码中:这个地方也需要round
![](https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210624124308.png)

测试数据中的`测试点1`

### 思路
$\xrightarrow{\text{summit}}$读取输入的字符串$\xrightarrow{\text{rectify\_data}}$得到的中间数据结构$\xrightarrow{\text{cal\_poly}}$得到中间数据结构表示的计算的结果$\xrightarrow{\text{rectify\_str}}$得到符合题目要求的正确结果$\xrightarrow{\text{summit}}$输出

### 语法技术
#### keys()不能进行+运算

#### [sum的特殊用法](https://ednow.github.io/2021/02/01/python%E6%8A%80%E6%B3%95%E6%80%BB%E7%BB%93/#%E4%BA%A4%E6%9B%BF%E7%A9%BF%E6%8F%92%E4%B8%A4%E4%B8%AA%E7%AD%89%E9%95%BF%E7%9A%84list)

#### range() takes no keyword arguments

### 拓展阅读
#### 四舍五入
[python中四舍五入的特殊情况](https://zhuanlan.zhihu.com/p/93363837)

[参考文献2](https://zhuanlan.zhihu.com/p/115431517)