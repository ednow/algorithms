# algorithms
## 题库
## [PTA甲级](https://pintia.cn/problem-sets/994805342720868352): [ac情况](https://github.com/ednow/algorithms/tree/main/PTA/README.md)

## 项目依赖
+ [google test](https://github.com/google/googletest.git)
+ [json for c++](https://github.com/nlohmann/json.git)


## readme中大量使用了latex公式，为确保阅读体验，请保证浏览器正确渲染latex公式
### 在github显示latex公式的建议
[安装这个插件](https://chrome.google.com/webstore/detail/mathjax-plugin-for-github/ioemnmodlmafdkllaclgeombjnmnbima/related)

[参考文献](https://zhuanlan.zhihu.com/p/149281857)

### 测试latex成功渲染

你能看到下方的`二分之一`,而不是`$\dfrac{1}{2}$`

$\dfrac{1}{2}$ 

## config.json的配置
```json
{
  "testCaseId": null,
  "dataPath": null,
  "testData": null,
  "module": "PTA.PTA1061.Dating",
  "moduleEntry": null,
  "excludeTestCaseIds": null,
  "isTakeOverOutput": true
}
```

|配置字段|合法类型|必须字段|描述|支持python|支持c++|支持java|
|----|----|----|----|----|----|----|
|testCaseId|Union[None, str]|:white_check_mark: |指定测试的id|:white_check_mark:|:white_check_mark:|:white_check_mark:|
|dataPath|str| |指定测试用例的路径|:white_check_mark:|||
|module|str|:white_check_mark: |指定需要测试的代码|:white_check_mark:|||
|moduleEntry|Union[None, List[str]]| |需要运行的函数，默认为summit|:white_check_mark:|||
|excludeTestCaseIds|Union[None, List[str]]| |不测试某些测试数据|:white_check_mark:|:white_check_mark:||
|isTakeOverOutput|Union[None, bool]||测试环境想实时看到print调试法的输出，不接管stdout|:white_check_mark:|:white_check_mark:||

## data.json的配置

TODO

### 测试指定的一个数据
+ 使用"testCaseId"指定
+ 使用"testData"指定



### 测试全部
若`config.json`中testCaseId为`null`,则测试全部数据