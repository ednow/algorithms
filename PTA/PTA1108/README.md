# PTA1108总结
## 考点
- 排序

## 问题重述

<details>
    <summary>Details</summary>

![](https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210707213717.png)
</details>

+ decimal 还有小数的意思，题目中的2 decimal places表示两位小数

## python
### 语法技术
+ 匹配题目要求中字符串的正则表达式：`r"^[-]?[1]?\d{1,3}(\.\d{0,2})?$"`
  + 用()来限定子表达式
  + 注意要转义`.`
+ 格式化浮点数`f"{2.2222:.2f}"`
+ 主要有小数不要用`int()`转型，用`float()`转型

#### 与正则勾心斗角

+ 第二种bug：匹配了`2.3.4`

<details>
    <summary>Details</summary>


![](https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210707222848.png)

</details>


+ 第二种bug：`r"^[-]?(1000|\d{1,2})?\d(\.\d{0,2})?$"`,`re.compile(r"^[-]?((1000)|\d{1,2})?\d(\.\d{0,2})?$")`匹配不了`1000`
+ 原因多了一个`\d`

<details>
    <summary>Details</summary>

![](https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210707230713.png)

</details>



### 第一次提交
<details>
    <summary>Details</summary>

![](https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210707222149.png)
</details>

测试点2，3未过

