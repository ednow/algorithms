# PTA1023总结
## 考点
- 输入输出

## 问题重述
![](https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210703191842.png)


## python

+ 不要`k,v in input().split()`,but `k,v in [input().split()]`
+ `AttributeError: 'str' object has no attribute 'copy'`
+ `str.replace`不是inplace，意味着需要`str = str.replace`替换源字符串
+ `dict.items()`可以直接迭代

### pta输出了None？
![](https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20210704212308.png)

