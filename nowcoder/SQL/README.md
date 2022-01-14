

# SQL

+ [入门](https://www.nowcoder.com/ta/sql-quick-study)
+ [进阶](https://www.nowcoder.com/ta/sql-advanced)
+ [面试题](https://www.nowcoder.com/ta/sql-factory-interview)

## 在线运行sql
+ [网址1](https://www.guofei.site/pictures_for_blog/app/online_sql/online_sql.html)
+ [网址2](https://www.bejson.com/runcode/sql/)

## 基本语法
### UNIQUE 和 DISTINCT的区别

13 . 哪条 SQL 语句可返回唯一不同的值？

    SELECT DIFFERENT
    SELECT DISTINCT
    SELECT UNIQUE

17 . 通过 SQL，您如何向 "Persons" 表中的 "LastName" 列插入 "Wilson" ？

    INSERT INTO Persons (LastName) VALUES ('Wilson')
    INSERT ('Wilson') INTO Persons (LastName)
    INSERT INTO Persons ('Wilson') INTO LastName

18 . 您如何把 "Persons" 表中 "LastName" 列的 "Gates" 改为 "Wilson" ？

    MODIFY Persons SET LastName='Wilson' WHERE LastName='Gates'
    UPDATE Persons SET LastName='Wilson' WHERE LastName='Gates'
    UPDATE Persons SET LastName='Wilson' INTO LastName='Gates'
    MODIFY Persons SET LastName='Wilson' INTO LastName='Gates'

### sql中update，alter，modify，delete，drop
[update，alter，modify](https://zhidao.baidu.com/question/407180215.html)


###  Select count(*)和Count（1）的区别和执行方式


[参考文献](https://www.cnblogs.com/CareySon/p/DifferenceBetweenCountStarAndCount1.html)

### group by和group concat
[参考文献](https://www.cnblogs.com/zhuiluoyu/p/6862673.html)

## 入门

### SQL1 查询多列


题目：现在运营同学想要用户的设备id对应的性别、年龄和学校的数据，请你取出相应数据


示例：user_profile

<details><summary>输入表的结构</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110152227.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110152227.png';" /></details>


<details><summary>输入数据</summary>

```sql
drop table if exists user_profile;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`province` varchar(32)  NOT NULL);
INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学','BeiJing');
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学','Shanghai');
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学','BeiJing');
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学','ZheJiang');
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学','Shandong');
```

</details>

根据示例，你的查询应返回以下结果

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110152154.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110152154.png';" /></details>


<details><summary>代码详情</summary>

```sql
SELECT device_id, gender, age, university FROM user_profile
```

</details>

### SQL2 查询所有列

<details><summary>输入数据</summary>

```sql
drop table if exists user_profile;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`province` varchar(32)  NOT NULL);
INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学','BeiJing');
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学','Shanghai');
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学','BeiJing');
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学','ZheJiang');
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学','Shandong');

```

</details>


根据示例，你的查询应返回以下结果:

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110160839.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110160839.png';" /></details>

<details><summary>我的答案</summary>

```sql 
SELECT * FROM user_profile

```

</details>


### SQL3 查询结果去重
题目：现在运营需要查看用户来自于哪些学校，请从用户信息表中取出学校的去重数据。

<details><summary>输入数据表的结构</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110161759.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110161759.png';" /></details>

<details><summary>输入数据</summary>

```sql
drop table if exists user_profile;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`province` varchar(32)  NOT NULL);
INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学','BeiJing');
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学','Shanghai');
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学','BeiJing');
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学','ZheJiang');
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学','Shandong');

```

</details>

根据示例，你的查询应返回以下结果：

<details><summary>返回结果</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110161622.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110161622.png';" /></details>

<details><summary>我的答案</summary>

```sql 
SELECT DISTINCT university FROM user_profile

-- 法二
-- SELECT university FROM user_profile GROUP BY university

```

</details>



### SQL4 查询结果限制返回行数

题目：现在运营只需要查看前2个用户明细设备ID数据，请你从用户信息表 user_profile 中取出相应结果。


<details><summary>输入表的结构</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110152227.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110152227.png';" /></details>


<details><summary>输入数据</summary>

```sql
drop table if exists user_profile;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`province` varchar(32)  NOT NULL);
INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学','BeiJing');
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学','Shanghai');
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学','BeiJing');
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学','ZheJiang');
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学','Shandong');
```

</details>

根据输入，你的查询应返回以下结果：


<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110162133.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110162133.png';" /></details>


<details><summary>我的答案</summary>

```sql
SELECT device_id FROM user_profile LIMIT 2

-- select device_id FROM user_profile WHERE id in(1,2)  可以使用
-- select device_id FROM user_profile WHERE id <= 2 可以使用
-- select device_id FROM user_profile  limit 2 可以使用
-- select device_id FROM user_profile limit 0,2 可以使用（代表从第0个元素开始，选两个）

```

</details>


### SQL5 将查询后的列重新命名
题目：现在你需要查看前2个用户明细设备ID数据，并将列名改为 'user_infos_example',，请你从用户信息表取出相应结果。


<details><summary>输入表的结构</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110152227.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110152227.png';" /></details>


<details><summary>输入数据</summary>

```sql
drop table if exists user_profile;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`province` varchar(32)  NOT NULL);
INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学','BeiJing');
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学','Shanghai');
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学','BeiJing');
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学','ZheJiang');
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学','Shandong');
```

</details>

根据示例，你的查询应返回以下结果：

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110165622.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110165622.png';" /></details>


<details><summary>我的答案</summary>

```sql
SELECT device_id FROM user_profile AS user_infos_example LIMIT 2
```

</details>

### SQL36 查找后排序
题目：现在运营想要取出用户信息表中的用户年龄，请取出相应数据，并按照年龄升序排序。

示例：user_profile

<details><summary>表的结构</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110170111.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110170111.png';" /></details>

<details><summary>输入数据</summary>

```sql
drop table if exists user_profile;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`gpa` float);
INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学',3.4);
INSERT INTO user_profile VALUES(2,3214,'male',23,'复旦大学',4.0);
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学',3.2);
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学',3.6);
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学',3.8);
INSERT INTO user_profile VALUES(6,2131,'male',28,'北京师范大学',3.3);
```

</details>

根据示例，你的查询应返回以下结果：

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110165914.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110165914.png';" /></details>

<details><summary>我的答案</summary>

```sql

SELECT device_id, age
FROM user_profile
ORDER BY age;

```

</details>

### SQL37 查找后多列排序

题目：现在运营想要取出用户信息表中的年龄和gpa数据，并先按照gpa升序排序，再按照年龄升序排序输出，请取出相应数据。


<details><summary>表的结构</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110170111.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110170111.png';" /></details>

<details><summary>输入数据</summary>

```sql
drop table if exists user_profile;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`gpa` float);
INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学',3.4);
INSERT INTO user_profile VALUES(2,3214,'male',23,'复旦大学',4.0);
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学',3.2);
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学',3.6);
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学',3.8);
INSERT INTO user_profile VALUES(6,2131,'male',28,'北京师范大学',3.3);
```

</details>

你的查询应返回以下结果：

<details><summary>返回结果</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110170222.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110170222.png';" /></details>


<details><summary>我的答案</summary>

```sql
SELECT device_id, gpa, age
FROM user_profile
ORDER BY gpa, age ASC;
```

</details>


### SQL38 查找后降序排列
题目：现在运营想要取出用户信息表中对应的数据，并先按照gpa、年龄降序排序输出，请取出相应数据。


<details><summary>表的结构</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110170111.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110170111.png';" /></details>

<details><summary>输入数据</summary>

```sql
drop table if exists user_profile;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`gpa` float);
INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学',3.4);
INSERT INTO user_profile VALUES(2,3214,'male',23,'复旦大学',4.0);
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学',3.2);
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学',3.6);
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学',3.8);
INSERT INTO user_profile VALUES(6,2131,'male',28,'北京师范大学',3.3);
```

</details>

> 默认为升序，需要对每个字段单独设置升降序

<details><summary>我的答案</summary>

```sql
SELECT device_id, gpa, age
FROM user_profile
ORDER BY gpa DESC, age DESC;
```

</details>

### SQL6 查找学校是北大的学生信息
题目：现在运营想要筛选出所有北京大学的学生进行用户调研，请你从用户信息表中取出满足条件的数据，结果返回设备id和学校。




<details><summary>输入表的结构</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110152227.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110152227.png';" /></details>


<details><summary>输入数据</summary>

```sql
drop table if exists user_profile;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`province` varchar(32)  NOT NULL);
INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学','BeiJing');
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学','Shanghai');
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学','BeiJing');
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学','ZheJiang');
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学','Shandong');
```

</details>

根据示例，你的查询应返回以下结果：

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110171033.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110171033.png';" /></details>


<details><summary>我的答案</summary>

```sql
SELECT device_id, university
FROM user_profile
WHERE university='北京大学';
```

</details>

### SQL7 查找年龄大于24岁的用户信息
题目：现在运营想要针对24岁以上的用户开展分析，请你取出满足条件的设备ID、性别、年龄、学校。

<details><summary>输入表的结构</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110152227.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110152227.png';" /></details>


<details><summary>输入数据</summary>

```sql
drop table if exists user_profile;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`province` varchar(32)  NOT NULL);
INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学','BeiJing');
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学','Shanghai');
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学','BeiJing');
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学','ZheJiang');
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学','Shandong');
```

</details>

根据输入，你的 查询应返回以下结果：

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110171302.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110171302.png';" /></details>




<details><summary>我的答案</summary>

```sql
SELECT device_id, gender, age, university
FROM user_profile
WHERE age > 24;

```

</details>

### SQL8 查找某个年龄段的用户信息
题目：现在运营想要针对20岁及以上且23岁及以下的用户开展分析，请你取出满足条件的设备ID、性别、年龄。

<details><summary>输入表的结构</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110152227.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110152227.png';" /></details>


<details><summary>输入数据</summary>

```sql
drop table if exists user_profile;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`province` varchar(32)  NOT NULL);
INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学','BeiJing');
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学','Shanghai');
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学','BeiJing');
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学','ZheJiang');
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学','Shandong');
```

</details>

根据输入，你的查询应返回以下结果：


<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110172143.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110172143.png';" /></details>

<details><summary>我的答案</summary>

```sql
SELECT device_id, gender, age
FROM user_profile
WHERE age >= 20 AND age <= 23;
```

</details>

### SQL9 查找除复旦大学的用户信息
题目：现在运营想要查看除复旦大学以外的所有用户明细，请你取出相应数据


<details><summary>输入表的结构</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110152227.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110152227.png';" /></details>


<details><summary>输入数据</summary>

```sql
drop table if exists user_profile;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`province` varchar(32)  NOT NULL);
INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学','BeiJing');
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学','Shanghai');
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学','BeiJing');
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学','ZheJiang');
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学','Shandong');
```

</details>

根据输入，你的查询应返回以下结果：

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110173809.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110173809.png';" /></details>


<details><summary>我的答案</summary>

```sql
SELECT device_id, gender, age, university
FROM user_profile
WHERE NOT university='复旦大学';
```

</details>

### SQL10 用where过滤空值练习


题目：现在运营想要对用户的年龄分布开展分析，在分析时想要剔除没有获取到年龄的用户，请你取出所有年龄值不为空的用户的设备ID，性别，年龄，学校的信息。

<details><summary>输入表的结构</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110152227.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110152227.png';" /></details>


<details><summary>输入数据</summary>

```sql
drop table if exists user_profile;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`province` varchar(32)  NOT NULL);
INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学','BeiJing');
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学','Shanghai');
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学','BeiJing');
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学','ZheJiang');
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学','Shandong');
```

</details>

根据输入，你的 查询应返回以下结果：

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110185611.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110185611.png';" /></details>

<details><summary>我的答案</summary>

```sql
SELECT device_id, gender, age, university
FROM user_profile
WHERE age IS NOT NULL;
```

</details>

### SQL11 高级操作符练习(1)

题目：现在运营想要找到男性且GPA在3.5以上(不包括3.5)的用户进行调研，请你取出相关数据。

<details><summary>输入表的结构</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110152227.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110152227.png';" /></details>


<details><summary>输入数据</summary>

```sql
drop table if exists user_profile;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`province` varchar(32)  NOT NULL);
INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学','BeiJing');
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学','Shanghai');
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学','BeiJing');
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学','ZheJiang');
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学','Shandong');
```

</details>

根据输入，你的查询应返回以下结果：


<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110185718.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110185718.png';" /></details>



<details><summary>我的答案</summary>

```sql
SELECT device_id, gender, age, university, gpa
FROM user_profile
WHERE gender='male' AND gpa > 3.5;
```

</details>


### SQL12 高级操作符练习(2）

题目：现在运营想要找到学校为北大或GPA在3.7以上(不包括3.7)的用户进行调研，请你取出相关数据


<details><summary>输入表的结构</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110152227.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110152227.png';" /></details>


<details><summary>输入数据</summary>

```sql
drop table if exists user_profile;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`province` varchar(32)  NOT NULL);
INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学','BeiJing');
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学','Shanghai');
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学','BeiJing');
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学','ZheJiang');
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学','Shandong');
```

</details>

根据输入，你的查询应返回以下结果：

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110190106.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110190106.png';" /></details>

<details><summary>代码详情</summary>

```sql
SELECT device_id, gender, age, university, gpa
FROM user_profile
WHERE university='北京大学' OR gpa > 3.7;
```

</details>


### SQL13 Where in 和Not in

题目：现在运营想要找到学校为北大、复旦和山大的同学进行调研，请你取出相关数据。


<details><summary>输入表的结构</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110152227.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110152227.png';" /></details>


<details><summary>输入数据</summary>

```sql
drop table if exists user_profile;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`province` varchar(32)  NOT NULL);
INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学','BeiJing');
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学','Shanghai');
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学','BeiJing');
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学','ZheJiang');
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学','Shandong');
```

</details>

根据输入，你的查询应返回以下结果：

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110190355.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110190355.png';" /></details>


<details><summary>我的答案</summary>

```sql
SELECT device_id, gender, age, university, gpa
FROM user_profile
WHERE university IN ('北京大学', '复旦大学', '山东大学');
```

</details>

### SQL14 操作符混合运用
题目：现在运营想要找到gpa在3.5以上(不包括3.5)的山东大学用户 或 gpa在3.8以上(不包括3.8)的复旦大学同学进行用户调研，请你取出相应数据


<details><summary>输入表的结构</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110152227.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110152227.png';" /></details>


<details><summary>输入数据</summary>

```sql
drop table if exists user_profile;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`province` varchar(32)  NOT NULL);
INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学','BeiJing');
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学','Shanghai');
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学','BeiJing');
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学','ZheJiang');
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学','Shandong');
```

</details>


根据输入，你的查询应返回以下结果：(该题对于小数点后面的0不需要计算与统计，后台系统会统一输出小数点后面1位)

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110191025.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110191025.png';" /></details>

<details><summary>我的答案</summary>

```sql
SELECT device_id, gender, age, university, gpa
FROM user_profile
WHERE (gpa > 3.5 AND university='山东大学') 
OR (gpa > 3.8 AND university='复旦大学');
```

</details>


### SQL15 查看学校名称中含北京的用户


题目：现在运营想查看所有大学中带有北京的用户的信息，请你取出相应数据。


<details><summary>输入表的结构</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110191334.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110191334.png';" /></details>

<details><summary>输入数据</summary>

```sql
drop table if exists user_profile;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`gpa` float);
INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学',3.4);
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学',4.0);
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学',3.2);
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学',3.6);
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学',3.8);
INSERT INTO user_profile VALUES(6,2131,'male',28,'北京师范大学',3.3);
```

</details>


根据示例，你的查询应返回如下结果：

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110191407.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110191407.png';" /></details>

<details><summary>我的答案</summary>

```sql
SELECT device_id, age, university
FROM user_profile
WHERE university LIKE '%北京%';
```

</details>

<details><summary>SQL 通配符</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110211813.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110211813.png';" /></details>



### SQL16 查找GPA最高值
题目：运营想要知道复旦大学学生gpa最高值是多少，请你取出相应数据


<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110192009.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110192009.png';" /></details>

<details><summary>输入数据</summary>

```sql
drop table if exists user_profile;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`gpa` float);
INSERT INTO user_profile VALUES(1,2234,'male',21,'北京大学',3.2);
INSERT INTO user_profile VALUES(2,2235,'male',null,'复旦大学',3.8);
INSERT INTO user_profile VALUES(3,2236,'female',20,'复旦大学',3.5);
INSERT INTO user_profile VALUES(4,2237,'female',23,'浙江大学',3.3);
INSERT INTO user_profile VALUES(5,2238,'male',25,'复旦大学',3.1);
INSERT INTO user_profile VALUES(6,2239,'male',25,'北京大学',3.6);
INSERT INTO user_profile VALUES(7,2240,'male',null,'清华大学',3.3);
INSERT INTO user_profile VALUES(8,2241,'female',null,'北京大学',3.7);

```

</details>

根据输入，你的查询应返回以下结果，结果保留到小数点后面1位(1位之后的四舍五入):


<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110192027.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110192027.png';" /></details>


<details><summary>我的答案</summary>

```sql
SELECT MAX(gpa)
FROM user_profile
WHERE university='复旦大学';
```

</details>


### SQL17 计算男生人数以及平均GPA
题目：现在运营想要看一下男性用户有多少人以及他们的平均gpa是多少，用以辅助设计相关活动，请你取出相应数据。


<details><summary>输入表的结构</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110191334.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110191334.png';" /></details>

<details><summary>输入数据</summary>

```sql
drop table if exists user_profile;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`gpa` float);
INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学',3.4);
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学',4.0);
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学',3.2);
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学',3.6);
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学',3.8);
INSERT INTO user_profile VALUES(6,2131,'male',28,'北京师范大学',3.3);
```

</details>

根据输入，你的查询应返回以下结果，结果保留到小数点后面1位(1位之后的四舍五入)：

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110192323.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110192323.png';" /></details>


<details><summary>代码详情</summary>

```sql
SELECT COUNT(gender) as male_num, AVG(gpa) as avg_gpa
FROM user_profile
WHERE gender='male';
```

</details>

### SQL18 分组计算练习题
题目：现在运营想要对每个学校不同性别的用户活跃情况和发帖数量进行分析，请分别计算出每个学校每种性别的用户数、30天内平均活跃天数和平均发帖数量。


<details><summary>输入数据</summary>

```sql
drop table if exists user_profile;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`gpa` float,
`active_days_within_30` float,
`question_cnt` float,
`answer_cnt` float
);
INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学',3.4,7,2,12);
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学',4.0,15,5,25);
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学',3.2,12,3,30);
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学',3.6,5,1,2);
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学',3.8,20,15,70);
INSERT INTO user_profile VALUES(6,2131,'male',28,'山东大学',3.3,15,7,13);
INSERT INTO user_profile VALUES(7,4321,'male',28,'复旦大学',3.6,9,6,52);
```

</details>

用户信息表：user_profile

30天内活跃天数字段（active_days_within_30）

发帖数量字段（question_cnt）

回答数量字段（answer_cnt）

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110193318.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110193318.png';" /></details>

第一行表示:id为1的用户的常用信息为使用的设备id为2138，性别为男，年龄21岁，北京大学，gpa为3.4在过去的30天里面活跃了7天，发帖数量为2，回答数量为12


。。。

最后一行表示:id为7的用户的常用信息为使用的设备id为4321，性别为男，年龄26岁，复旦大学，gpa为3.6在过去的30天里面活跃了9天，发帖数量为6，回答数量为52

你的查询返回结果需要对性别和学校分组，示例如下，结果保留1位小数，1位小数之后的四舍五入：

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110193345.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110193345.png';" /></details>

解释:

第一行表示：北京大学的男性用户个数为1，平均活跃天数为7天，平均发帖量为2

。。。

最后一行表示：山东大学的男性用户个数为2，平均活跃天数为17.5天，平均发帖量为11


<details><summary>我的答案</summary>

```sql
SELECT gender, university, COUNT(id) AS user_num, AVG(active_days_within_30) AS avg_active_day, AVG(question_cnt) AS avg_question_cnt
FROM user_profile
GROUP BY gender, university;
```

</details>

### SQL19 分组过滤练习题
题目：现在运营想查看每个学校用户的平均发贴和回帖情况，寻找低活跃度学校进行重点运营，请取出平均发贴数低于5的学校或平均回帖数小于20的学校。

<details><summary>输入数据</summary>

```sql
drop table if exists user_profile;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`gpa` float,
`active_days_within_30` float,
`question_cnt` float,
`answer_cnt` float
);
INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学',3.4,7,2,12);
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学',4.0,15,5,25);
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学',3.2,12,3,30);
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学',3.6,5,1,2);
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学',3.8,20,15,70);
INSERT INTO user_profile VALUES(6,2131,'male',28,'山东大学',3.3,15,7,13);
INSERT INTO user_profile VALUES(7,4321,'male',28,'复旦大学',3.6,9,6,52);
```

</details>

用户信息表：user_profile

30天内活跃天数字段（active_days_within_30）

发帖数量字段（question_cnt）

回答数量字段（answer_cnt）

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110193318.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110193318.png';" /></details>

根据示例，你的查询应返回以下结果：

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110195441.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110195441.png';" /></details>

解释: 平均发贴数低于5的学校或平均回帖数小于20的学校有2个

属于北京大学的用户的平均发帖量为2.5，平均回答数量为21.0

属于浙江大学的用户的平均发帖量为1.0，平均回答数量为2.0

> HAVING关键字

<details><summary>我的答案</summary>

```sql
SELECT university, AVG(question_cnt) AS avg_question_cnt, AVG(answer_cnt) AS avg_answer_cnt
FROM user_profile
GROUP BY university
HAVING AVG(question_cnt) < 5 OR AVG(answer_cnt) < 20;
```

</details>

### SQL20 分组排序练习题


题目：现在运营想要查看不同大学的用户平均发帖情况，并期望结果按照平均发帖情况进行升序排列，请你取出相应数据。


<details><summary>输入数据</summary>

```sql
drop table if exists user_profile;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`gpa` float,
`active_days_within_30` float,
`question_cnt` float,
`answer_cnt` float
);
INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学',3.4,7,2,12);
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学',4.0,15,5,25);
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学',3.2,12,3,30);
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学',3.6,5,1,2);
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学',3.8,20,15,70);
INSERT INTO user_profile VALUES(6,2131,'male',28,'山东大学',3.3,15,7,13);
INSERT INTO user_profile VALUES(7,4321,'male',28,'复旦大学',3.6,9,6,52);
```

</details>

用户信息表：user_profile

30天内活跃天数字段（active_days_within_30）

发帖数量字段（question_cnt）

回答数量字段（answer_cnt）

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110193318.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110193318.png';" /></details>

<details><summary>我的答案</summary>

```sql
SELECT university, AVG(question_cnt) AS avg_question_cnt
FROM user_profile
GROUP BY university
ORDER BY avg_question_cnt;
```

</details>

<details><summary>网友解析</summary>

方法一：需要单独命名avg_question

select university,avg(question_cnt) AS avg_question_cnt from user_profile

group by university 

order by avg_question_cnt

方法二：不需要单独命名

select university,avg(question_cnt) from user_profile

group by university 

order by avg(question_cnt)

这样操作能运行成功的原因是 order by后面可以加聚合函数。但要注意，group by后面不可

有三类后面可以加聚合函数

1、select

2、order by

3、having



</details>

<details><summary>网友讨论-SQL语句执行顺序</summary>

由于SQL语句执行顺序如下：

FROM - ON - JOIN - WHERE - GROUP BY - WITH - HAVING - SELECT - DISTINCT - ORDER BY - LIMIT

因此ORDER BY后应添加avg_qusetion_cnt，而不是聚合函数AVG(question_cnt)

</details>

### SQL21 浙江大学用户题目回答情况


题目：现在运营想要查看所有来自浙江大学的用户题目回答明细情况，请你取出相应数据


<details><summary>question_practice_detail</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110211119.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110211119.png';" /></details>

第一行表示:id为1的用户的常用信息为使用的设备id为2138，在question_id为111的题目上，回答错误

....

最后一行表示:id为7的用户的常用信息为使用的设备id为2135，在question_id为117的题目上，回答错误

<details><summary>user_profile</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110211203.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110211203.png';" /></details>

第一行表示:id为1的用户的常用信息为使用的设备id为2138，性别为男，年龄21岁，北京大学，gpa为3.4在过去的30天里面活跃了7天，发帖数量为2，回答数量为12

。。。

最后一行表示:id为7的用户的常用信息为使用的设备id为4321，性别为男，年龄26岁，复旦大学，gpa为3.6在过去的30天里面活跃了9天，发帖数量为6，回答数量为52

<details><summary>输入数据</summary>

```sql
drop table if exists `user_profile`;
drop table if  exists `question_practice_detail`;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`gpa` float,
`active_days_within_30` int ,
`question_cnt` int ,
`answer_cnt` int 
);
CREATE TABLE `question_practice_detail` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`question_id`int NOT NULL,
`result` varchar(32) NOT NULL
);
INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学',3.4,7,2,12);
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学',4.0,15,5,25);
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学',3.2,12,3,30);
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学',3.6,5,1,2);
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学',3.8,20,15,70);
INSERT INTO user_profile VALUES(6,2131,'male',28,'山东大学',3.3,15,7,13);
INSERT INTO user_profile VALUES(7,4321,'male',28,'复旦大学',3.6,9,6,52);
INSERT INTO question_practice_detail VALUES(1,2138,111,'wrong');
INSERT INTO question_practice_detail VALUES(2,3214,112,'wrong');
INSERT INTO question_practice_detail VALUES(3,3214,113,'wrong');
INSERT INTO question_practice_detail VALUES(4,6543,111,'right');
INSERT INTO question_practice_detail VALUES(5,2315,115,'right');
INSERT INTO question_practice_detail VALUES(6,2315,116,'right');
INSERT INTO question_practice_detail VALUES(7,2315,117,'wrong');
INSERT INTO question_practice_detail VALUES(8,5432,118,'wrong');
INSERT INTO question_practice_detail VALUES(9,5432,112,'wrong');
INSERT INTO question_practice_detail VALUES(10,2131,114,'right');
INSERT INTO question_practice_detail VALUES(11,5432,113,'wrong');
```

</details>

根据示例，你的查询应返回以下结果，查询结果根据question_id升序排序：

<details><summary>结果</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110211232.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110211232.png';" /></details>


解释:

根据题目的数据只有1个浙江大学的用户，那么把浙江大学这个用户所有答题数据查询出来就行


> [关联查询](https://blog.csdn.net/gybshen/article/details/71637656)
> 如果改成Inner join，则不会返回整个Bush所在行。这是Inner Join和Left Join的区别，也是面试中经常会问到的题目。
> [菜鸟教程](https://www.runoob.com/sql/sql-join.html)



子查询：子查询是一种常用计算机语言SELECT-SQL语言中嵌套查询下层的程序模块。当一个查询是另一个查询的条件时，称之为子查询。


<details><summary>代码详情</summary>

```sql
SELECT  question_practice_detail.device_id, question_id, result
FROM question_practice_detail
JOIN user_profile
ON question_practice_detail.device_id=user_profile.device_id
WHERE user_profile.university='浙江大学';
```

</details>

> WHERE 要放在ON的后面

### SQL22 统计每个学校的答过题的用户的平均答题数
题目：运营想要了解每个学校答过题的用户平均答题数量情况，请你取出数据。


示例：用户信息表 user_profile，其中device_id指终端编号（认为每个用户有唯一的一个终端），gender指性别，age指年龄，university指用户所在的学校，gpa是该用户平均学分绩点，active_days_within_30是30天内的活跃天数。

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111095824.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111095824.png';" /></details>

第一行表示:用户的常用信息为使用的设备id为2138，性别为男，年龄21岁，北京大学，gpa为3.4，在过去的30天里面活跃了7天

最后一行表示:用户的常用信息为使用的设备id为4321，性别为男，年龄28岁，复旦大学，gpa为3.6，在过去的30天里面活跃了9天

示例：答题情况明细表 question_practice_detail，其中question_id是题目编号，result是答题结果。

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111095843.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111095843.png';" /></details>

第一行表示用户的常用信息为使用的设备id为2138，在question_id为111的题目上，回答错误
....
最后一行表示用户的常用信息为使用的设备id为5432，在question_id为113的题目上，回答错误

请你写SQL查找每个学校用户的平均答题数目(说明：某学校用户平均答题数量计算方式为该学校用户答题总次数除以答过题的不同用户个数)根据示例，你的查询应返回以下结果（结果保留4位小数），结果按照university升序排序：

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111095857.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111095857.png';" /></details>

解释:

第一行：北京大学总共有2个用户，2138和6543，2个用户在question_practice_detail里面答了2题，平均答题数目为2/2=1.0000

....

最后一行:浙江大学总共有1个用户，2315，这个用户在question_practice_detail里面答了3题，平均答题数目为3/1=3.0000

<details><summary>输入数据</summary>

```sql
drop table if exists `user_profile`;
drop table if  exists `question_practice_detail`;
CREATE TABLE `user_profile` (
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`gpa` float,
`active_days_within_30` int
);
CREATE TABLE `question_practice_detail` (
`device_id` int NOT NULL,
`question_id`int NOT NULL,
`result` varchar(32) NOT NULL
);

INSERT INTO user_profile VALUES(2138,'male',21,'北京大学',3.4,7);
INSERT INTO user_profile VALUES(3214,'male',null,'复旦大学',4.0,15);
INSERT INTO user_profile VALUES(6543,'female',20,'北京大学',3.2,12);
INSERT INTO user_profile VALUES(2315,'female',23,'浙江大学',3.6,5);
INSERT INTO user_profile VALUES(5432,'male',25,'山东大学',3.8,20);
INSERT INTO user_profile VALUES(2131,'male',28,'山东大学',3.3,15);
INSERT INTO user_profile VALUES(4321,'male',28,'复旦大学',3.6,9);
INSERT INTO question_practice_detail VALUES(2138,111,'wrong');
INSERT INTO question_practice_detail VALUES(3214,112,'wrong');
INSERT INTO question_practice_detail VALUES(3214,113,'wrong');
INSERT INTO question_practice_detail VALUES(6543,111,'right');
INSERT INTO question_practice_detail VALUES(2315,115,'right');
INSERT INTO question_practice_detail VALUES(2315,116,'right');
INSERT INTO question_practice_detail VALUES(2315,117,'wrong');
INSERT INTO question_practice_detail VALUES(5432,118,'wrong');
INSERT INTO question_practice_detail VALUES(5432,112,'wrong');
INSERT INTO question_practice_detail VALUES(2131,114,'right');
INSERT INTO question_practice_detail VALUES(5432,113,'wrong');
```

</details>

>  $\color{red}{\text{注意}}$ 

<details><summary>我的答案</summary>

```sql
SELECT university, COUNT(question_id) / COUNT(DISTINCT(up.device_id))
FROM user_profile as up
JOIN question_practice_detail as qpd
ON up.device_id=qpd.device_id
GROUP BY university;
```

</details>

### SQL23 统计每个学校各难度的用户平均刷题数
题目：运营想要计算一些参加了答题的不同学校、不同难度的用户平均答题量，请你写SQL取出相应数据

<details><summary>用户信息表：user_profile
</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111101423.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111101423.png';" /></details>

第一行表示:id为1的用户的常用信息为使用的设备id为2138，性别为男，年龄21岁，北京大学，gpa为3.4，在过去的30天里面活跃了7天，发帖数量为2，回答数量为12

最后一行表示:id为7的用户的常用信息为使用的设备id为4321，性别为男，年龄28岁，复旦大学，gpa为3.6，在过去的30天里面活跃了9天，发帖数量为6，回答数量为52

<details><summary>题库练习明细表：question_practice_detail</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111101643.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111101643.png';" /></details>

第一行表示:id为1的用户的常用信息为使用的设备id为2138，在question_id为111的题目上，回答错误

......

最后一行表示:id为23的用户的常用信息为使用的设备id为5432，在question_id为113的题目上，回答错误




<details><summary>表：question_detail</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111101707.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111101707.png';" /></details>

第一行表示: 题目id为111的难度为hard

....

第一行表示: 题目id为117的难度为easy

<details><summary>输入数据</summary>

```sql
drop table if exists `user_profile`;
drop table if  exists `question_practice_detail`;
drop table if  exists `question_detail`;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`gpa` float,
`active_days_within_30` int ,
`question_cnt` int ,
`answer_cnt` int 
);
CREATE TABLE `question_practice_detail` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`question_id`int NOT NULL,
`result` varchar(32) NOT NULL
);
CREATE TABLE `question_detail` (
`id` int NOT NULL,
`question_id`int NOT NULL,
`difficult_level` varchar(32) NOT NULL
);

INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学',3.4,7,2,12);
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学',4.0,15,5,25);
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学',3.2,12,3,30);
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学',3.6,5,1,2);
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学',3.8,20,15,70);
INSERT INTO user_profile VALUES(6,2131,'male',28,'山东大学',3.3,15,7,13);
INSERT INTO user_profile VALUES(7,4321,'male',28,'复旦大学',3.6,9,6,52);
INSERT INTO question_practice_detail VALUES(1,2138,111,'wrong');
INSERT INTO question_practice_detail VALUES(2,3214,112,'wrong');
INSERT INTO question_practice_detail VALUES(3,3214,113,'wrong');
INSERT INTO question_practice_detail VALUES(4,6543,111,'right');
INSERT INTO question_practice_detail VALUES(5,2315,115,'right');
INSERT INTO question_practice_detail VALUES(6,2315,116,'right');
INSERT INTO question_practice_detail VALUES(7,2315,117,'wrong');
INSERT INTO question_practice_detail VALUES(8,5432,117,'wrong');
INSERT INTO question_practice_detail VALUES(9,5432,112,'wrong');
INSERT INTO question_practice_detail VALUES(10,2131,113,'right');
INSERT INTO question_practice_detail VALUES(11,5432,113,'wrong');
INSERT INTO question_practice_detail VALUES(12,2315,115,'right');
INSERT INTO question_practice_detail VALUES(13,2315,116,'right');
INSERT INTO question_practice_detail VALUES(14,2315,117,'wrong');
INSERT INTO question_practice_detail VALUES(15,5432,117,'wrong');
INSERT INTO question_practice_detail VALUES(16,5432,112,'wrong');
INSERT INTO question_practice_detail VALUES(17,2131,113,'right');
INSERT INTO question_practice_detail VALUES(18,5432,113,'wrong');
INSERT INTO question_practice_detail VALUES(19,2315,117,'wrong');
INSERT INTO question_practice_detail VALUES(20,5432,117,'wrong');
INSERT INTO question_practice_detail VALUES(21,5432,112,'wrong');
INSERT INTO question_practice_detail VALUES(22,2131,113,'right');
INSERT INTO question_practice_detail VALUES(23,5432,113,'wrong');
INSERT INTO question_detail VALUES(1,111,'hard');
INSERT INTO question_detail VALUES(2,112,'medium');
INSERT INTO question_detail VALUES(3,113,'easy');
INSERT INTO question_detail VALUES(4,115,'easy');
INSERT INTO question_detail VALUES(5,116,'medium');
INSERT INTO question_detail VALUES(6,117,'easy');
```

</details>

请你写一个SQL查询，计算不同学校、不同难度的用户平均答题量，根据示例，你的查询应返回以下结果(结果在小数点位数保留4位，4位之后四舍五入)：

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111101740.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111101740.png';" /></details>

解释：

第一行：北京大学只有设备id为2138这1个用户，该用户在question_practice_detail表下只有一条答题记录，且答题题目是111，从question_detail可以知道这个题目是hard，故 北京大学的用户答题为hard的题目平均答题为1/1=1.0000



第二行，第三行：复旦大学有设备id为3214，4321这2个用户，但是在question_practice_detail表只有1个用户(device_id=3214有答题，device_id=4321没有答题，不计入后续计算)有2条答题记录，且答题题目是112，113各1个，从question_detail可以知道题目难度分别是medium和easy，故 复旦大学的用户答题为easy, medium的题目平均答题量都为1(easy=1或medium=1) /1 (device_id=3214)=1.0000



第四行，第五行：山东大学有设备id为5432和2131这2个用户，这2个用户总共在question_practice_detail表下有12条答题记录，且答题题目是112，113，117，且数目分别为3，6，3，从question_detail可以知道题目难度分别为medium,easy,easy，所以，easy共有9个，故easy的题目平均答题量= 9(easy=9)/2 (device_id=3214 or device_id=5432) =4.5000，medium共有3个，medium的答题只有device_id=5432的用户，故medium的题目平均答题量= 3(medium=9)/1 ( device_id=5432) =3.0000

.....




> 多重group by 不是将group by写多次，而是写多列

<details><summary>我的答案</summary>

```sql
SELECT 
    university, 
    difficult_level, 
    COUNT(question_detail.question_id) / COUNT(DISTINCT(device_id))
FROM 
    (
        SELECT university, question_id, up.device_id
        FROM user_profile AS up
        JOIN question_practice_detail AS qpd
        ON up.device_id=qpd.device_id
    ) as num_detail
JOIN question_detail
ON num_detail.question_id = question_detail.question_id
GROUP BY university, difficult_level;

-- 网友答案
-- SELECT
--     university,
--     difficult_level,
--     count(q.question_id )/count(
--     distinct(q.device_id)) avg_answer_cnt 
-- FROM
--     user_profile u
--     JOIN question_practice_detail q ON u.device_id = q.device_id
--     JOIN question_detail qd ON q.question_id = qd.question_id 
-- GROUP BY
--     university,
--     difficult_level;

-- 网友答案：使用笛卡尔积
-- SELECT
--     university,
--     difficult_level,
--     count( q.question_id )/ count(
--     DISTINCT ( q.device_id )) avg_answer_cnt 
-- FROM
--     user_profile u,
--     question_practice_detail q,
--     question_detail qd 
-- WHERE
--     u.device_id = q.device_id 
--     AND q.question_id = qd.question_id 
-- GROUP BY
--     university,
--     difficult_level;
```

</details>

### SQL24 统计每个用户的平均刷题数

题目：运营想要查看参加了答题的山东大学的用户在不同难度下的平均答题题目数，请取出相应数据

<details><summary>用户信息表：user_profile
</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111101423.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111101423.png';" /></details>

第一行表示:id为1的用户的常用信息为使用的设备id为2138，性别为男，年龄21岁，北京大学，gpa为3.4，在过去的30天里面活跃了7天，发帖数量为2，回答数量为12

最后一行表示:id为7的用户的常用信息为使用的设备id为4321，性别为男，年龄28岁，复旦大学，gpa为3.6，在过去的30天里面活跃了9天，发帖数量为6，回答数量为52

<details><summary>题库练习明细表：question_practice_detail</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111101643.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111101643.png';" /></details>

第一行表示:id为1的用户的常用信息为使用的设备id为2138，在question_id为111的题目上，回答错误

......

最后一行表示:id为23的用户的常用信息为使用的设备id为5432，在question_id为113的题目上，回答错误




<details><summary>表：question_detail</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111101707.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111101707.png';" /></details>

第一行表示: 题目id为111的难度为hard

....

第一行表示: 题目id为117的难度为easy

<details><summary>输入数据</summary>

```sql
drop table if exists `user_profile`;
drop table if  exists `question_practice_detail`;
drop table if  exists `question_detail`;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`gpa` float,
`active_days_within_30` int ,
`question_cnt` int ,
`answer_cnt` int 
);
CREATE TABLE `question_practice_detail` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`question_id`int NOT NULL,
`result` varchar(32) NOT NULL
);
CREATE TABLE `question_detail` (
`id` int NOT NULL,
`question_id`int NOT NULL,
`difficult_level` varchar(32) NOT NULL
);

INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学',3.4,7,2,12);
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学',4.0,15,5,25);
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学',3.2,12,3,30);
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学',3.6,5,1,2);
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学',3.8,20,15,70);
INSERT INTO user_profile VALUES(6,2131,'male',28,'山东大学',3.3,15,7,13);
INSERT INTO user_profile VALUES(7,4321,'male',28,'复旦大学',3.6,9,6,52);
INSERT INTO question_practice_detail VALUES(1,2138,111,'wrong');
INSERT INTO question_practice_detail VALUES(2,3214,112,'wrong');
INSERT INTO question_practice_detail VALUES(3,3214,113,'wrong');
INSERT INTO question_practice_detail VALUES(4,6543,111,'right');
INSERT INTO question_practice_detail VALUES(5,2315,115,'right');
INSERT INTO question_practice_detail VALUES(6,2315,116,'right');
INSERT INTO question_practice_detail VALUES(7,2315,117,'wrong');
INSERT INTO question_practice_detail VALUES(8,5432,117,'wrong');
INSERT INTO question_practice_detail VALUES(9,5432,112,'wrong');
INSERT INTO question_practice_detail VALUES(10,2131,113,'right');
INSERT INTO question_practice_detail VALUES(11,5432,113,'wrong');
INSERT INTO question_practice_detail VALUES(12,2315,115,'right');
INSERT INTO question_practice_detail VALUES(13,2315,116,'right');
INSERT INTO question_practice_detail VALUES(14,2315,117,'wrong');
INSERT INTO question_practice_detail VALUES(15,5432,117,'wrong');
INSERT INTO question_practice_detail VALUES(16,5432,112,'wrong');
INSERT INTO question_practice_detail VALUES(17,2131,113,'right');
INSERT INTO question_practice_detail VALUES(18,5432,113,'wrong');
INSERT INTO question_practice_detail VALUES(19,2315,117,'wrong');
INSERT INTO question_practice_detail VALUES(20,5432,117,'wrong');
INSERT INTO question_practice_detail VALUES(21,5432,112,'wrong');
INSERT INTO question_practice_detail VALUES(22,2131,113,'right');
INSERT INTO question_practice_detail VALUES(23,5432,113,'wrong');
INSERT INTO question_detail VALUES(1,111,'hard');
INSERT INTO question_detail VALUES(2,112,'medium');
INSERT INTO question_detail VALUES(3,113,'easy');
INSERT INTO question_detail VALUES(4,115,'easy');
INSERT INTO question_detail VALUES(5,116,'medium');
INSERT INTO question_detail VALUES(6,117,'easy');
```

</details>

请你写一个SQL查询，计算山东、不同难度的用户平均答题量，根据示例，你的查询应返回以下结果(结果在小数点位数保留4位，4位之后四舍五入)：

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111104208.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111104208.png';" /></details>

山东大学有设备id为5432和2131这2个用户，这2个用户总共在question_practice_detail表下有12条答题记录，且答题题目是112，113，117，且数目分别为3，6，3，从question_detail可以知道题目难度分别为medium,easy,easy，所以，easy共有9个，故easy的题目平均答题量= 9(easy=9)/2 (device_id=3214 or device_id=5432) =4.5000，medium共有3个，medium的答题只有device_id=5432的用户，故medium的题目平均答题量= 3(medium=9)/1 ( device_id=5432) =3.0000

> WHERE 的条件之间用AND连接

<details><summary>我的答案</summary>

```sql
SELECT 
    university, 
    difficult_level, 
    COUNT(qpd.question_id) / COUNT(DISTINCT(up.device_id))
FROM 
    user_profile AS up,
    question_practice_detail AS qpd,
    question_detail AS qd
WHERE
    up.device_id=qpd.device_id
    AND qpd.question_id=qd.question_id
    AND university='山东大学'
GROUP BY 
    university,
    difficult_level;
```

</details>

### SQL25 查找山东大学或者性别为男生的信息
题目：现在运营想要分别查看学校为山东大学或者性别为男性的用户的device_id、gender、age和gpa数据，请取出相应结果，结果不去重。

<details><summary>示例：user_profile
</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111182629.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111182629.png';" /></details>

根据示例，你的查询应返回以下结果（注意输出的顺序，先输出学校为山东大学再输出性别为男生的信息）：

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111182644.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111182644.png';" /></details>


<details><summary>代码详情</summary>

```sql
drop table if exists `user_profile`;
drop table if  exists `question_practice_detail`;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`gpa` float,
`active_days_within_30` int ,
`question_cnt` int ,
`answer_cnt` int 
);
CREATE TABLE `question_practice_detail` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`question_id`int NOT NULL,
`result` varchar(32) NOT NULL
);
CREATE TABLE `question_detail` (
`id` int NOT NULL,
`question_id`int NOT NULL,
`difficult_level` varchar(32) NOT NULL
);

INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学',3.4,7,2,12);
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学',4.0,15,5,25);
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学',3.2,12,3,30);
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学',3.6,5,1,2);
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学',3.8,20,15,70);
INSERT INTO user_profile VALUES(6,2131,'male',28,'山东大学',3.3,15,7,13);
INSERT INTO user_profile VALUES(7,4321,'male',28,'复旦大学',3.6,9,6,52);
INSERT INTO question_practice_detail VALUES(1,2138,111,'wrong');
INSERT INTO question_practice_detail VALUES(2,3214,112,'wrong');
INSERT INTO question_practice_detail VALUES(3,3214,113,'wrong');
INSERT INTO question_practice_detail VALUES(4,6543,111,'right');
INSERT INTO question_practice_detail VALUES(5,2315,115,'right');
INSERT INTO question_practice_detail VALUES(6,2315,116,'right');
INSERT INTO question_practice_detail VALUES(7,2315,117,'wrong');
INSERT INTO question_practice_detail VALUES(8,5432,117,'wrong');
INSERT INTO question_practice_detail VALUES(9,5432,112,'wrong');
INSERT INTO question_practice_detail VALUES(10,2131,113,'right');
INSERT INTO question_practice_detail VALUES(11,5432,113,'wrong');
INSERT INTO question_practice_detail VALUES(12,2315,115,'right');
INSERT INTO question_practice_detail VALUES(13,2315,116,'right');
INSERT INTO question_practice_detail VALUES(14,2315,117,'wrong');
INSERT INTO question_practice_detail VALUES(15,5432,117,'wrong');
INSERT INTO question_practice_detail VALUES(16,5432,112,'wrong');
INSERT INTO question_practice_detail VALUES(17,2131,113,'right');
INSERT INTO question_practice_detail VALUES(18,5432,113,'wrong');
INSERT INTO question_practice_detail VALUES(19,2315,117,'wrong');
INSERT INTO question_practice_detail VALUES(20,5432,117,'wrong');
INSERT INTO question_practice_detail VALUES(21,5432,112,'wrong');
INSERT INTO question_practice_detail VALUES(22,2131,113,'right');
INSERT INTO question_practice_detail VALUES(23,5432,113,'wrong');
INSERT INTO question_detail VALUES(1,111,'hard');
INSERT INTO question_detail VALUES(2,112,'medium');
INSERT INTO question_detail VALUES(3,113,'easy');
INSERT INTO question_detail VALUES(4,115,'easy');
INSERT INTO question_detail VALUES(5,116,'medium');
INSERT INTO question_detail VALUES(6,117,'easy');
```

</details>

+ [组合查询](https://segmentfault.com/a/1190000007926959)
+ UNION关键字会自动去重

<details><summary>我的答案</summary>

```sql
SELECT 
    device_id,
    gender,
    age,
    gpa
FROM
    user_profile
WHERE 
    university='山东大学'
UNION ALL
SELECT 
    device_id,
    gender,
    age,
    gpa
FROM
    user_profile
WHERE 
    gender='male';
```

</details>

### SQL26 计算25岁以上和以下的用户数量
题目：现在运营想要将用户划分为25岁以下和25岁及以上两个年龄段，分别查看这两个年龄段用户数量


本题注意：age为null 也记为 25岁以下

<details><summary>user_profile</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111193138.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111193138.png';" /></details>

根据示例，你的查询应返回以下结果：

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111193205.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111193205.png';" /></details>

<details><summary>输入数据</summary>

```sql
drop table if exists `user_profile`;
drop table if  exists `question_practice_detail`;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`gpa` float,
`active_days_within_30` int ,
`question_cnt` int ,
`answer_cnt` int 
);
CREATE TABLE `question_practice_detail` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`question_id`int NOT NULL,
`result` varchar(32) NOT NULL
);
CREATE TABLE `question_detail` (
`id` int NOT NULL,
`question_id`int NOT NULL,
`difficult_level` varchar(32) NOT NULL
);

INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学',3.4,7,2,12);
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学',4.0,15,5,25);
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学',3.2,12,3,30);
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学',3.6,5,1,2);
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学',3.8,20,15,70);
INSERT INTO user_profile VALUES(6,2131,'male',28,'山东大学',3.3,15,7,13);
INSERT INTO user_profile VALUES(7,4321,'male',28,'复旦大学',3.6,9,6,52);
INSERT INTO question_practice_detail VALUES(1,2138,111,'wrong');
INSERT INTO question_practice_detail VALUES(2,3214,112,'wrong');
INSERT INTO question_practice_detail VALUES(3,3214,113,'wrong');
INSERT INTO question_practice_detail VALUES(4,6543,111,'right');
INSERT INTO question_practice_detail VALUES(5,2315,115,'right');
INSERT INTO question_practice_detail VALUES(6,2315,116,'right');
INSERT INTO question_practice_detail VALUES(7,2315,117,'wrong');
INSERT INTO question_practice_detail VALUES(8,5432,117,'wrong');
INSERT INTO question_practice_detail VALUES(9,5432,112,'wrong');
INSERT INTO question_practice_detail VALUES(10,2131,113,'right');
INSERT INTO question_practice_detail VALUES(11,5432,113,'wrong');
INSERT INTO question_practice_detail VALUES(12,2315,115,'right');
INSERT INTO question_practice_detail VALUES(13,2315,116,'right');
INSERT INTO question_practice_detail VALUES(14,2315,117,'wrong');
INSERT INTO question_practice_detail VALUES(15,5432,117,'wrong');
INSERT INTO question_practice_detail VALUES(16,5432,112,'wrong');
INSERT INTO question_practice_detail VALUES(17,2131,113,'right');
INSERT INTO question_practice_detail VALUES(18,5432,113,'wrong');
INSERT INTO question_practice_detail VALUES(19,2315,117,'wrong');
INSERT INTO question_practice_detail VALUES(20,5432,117,'wrong');
INSERT INTO question_practice_detail VALUES(21,5432,112,'wrong');
INSERT INTO question_practice_detail VALUES(22,2131,113,'right');
INSERT INTO question_practice_detail VALUES(23,5432,113,'wrong');
INSERT INTO question_detail VALUES(1,111,'hard');
INSERT INTO question_detail VALUES(2,112,'medium');
INSERT INTO question_detail VALUES(3,113,'easy');
INSERT INTO question_detail VALUES(4,115,'easy');
INSERT INTO question_detail VALUES(5,116,'medium');
INSERT INTO question_detail VALUES(6,117,'easy');
```

</details>

+ [条件函数](https://blog.csdn.net/DialogD/article/details/98981121)


<details><summary>我的答案</summary>

```sql
-- 这样子case只能充当switch
-- SELECT 
--     (
--         CASE age WHEN age>=25 THEN '25岁及以上'
--         ELSE '25岁以下'
--         END
--     ) AS age_cut,
--     COUNT(device_id) AS number
-- FROM user_profile
-- GROUP BY age_cut;

-- case充当if的正确写法
SELECT 
    (
        CASE WHEN age>=25 THEN '25岁及以上'
        ELSE '25岁以下'
        END
    ) AS age_cut,
    COUNT(device_id) AS number
FROM user_profile
GROUP BY age_cut;

-- IF的写法
-- SELECT 
--     IF(age >= 25,'25岁及以上','25岁以下') AS age_cut,
--     COUNT(device_id) AS number
-- FROM user_profile
-- GROUP BY age_cut;

-- 派生表写法
-- select age_cut,count(device_id)as number 
-- from(Select if(age>=25,'25岁及以上','25岁以下' )as age_cut,device_id 
-- From user_profile)u2
-- Group by age_cut
```

</details>


### SQL27 查看不同年龄段的用户明细

题目：现在运营想要将用户划分为20岁以下，20-24岁，25岁及以上三个年龄段，分别查看不同年龄段用户的明细情况，请取出相应数据。（注：若年龄为空请返回其他。）

<details><summary>user_profile</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111193138.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111193138.png';" /></details>

根据示例，你的查询应返回以下结果：

<details><summary>根据示例，你的查询应返回以下结果：
</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111195258.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111195258.png';" /></details>

<details><summary>输入数据</summary>

```sql
drop table if exists `user_profile`;
drop table if  exists `question_practice_detail`;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`gpa` float,
`active_days_within_30` int ,
`question_cnt` int ,
`answer_cnt` int 
);
CREATE TABLE `question_practice_detail` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`question_id`int NOT NULL,
`result` varchar(32) NOT NULL
);
CREATE TABLE `question_detail` (
`id` int NOT NULL,
`question_id`int NOT NULL,
`difficult_level` varchar(32) NOT NULL
);

INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学',3.4,7,2,12);
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学',4.0,15,5,25);
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学',3.2,12,3,30);
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学',3.6,5,1,2);
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学',3.8,20,15,70);
INSERT INTO user_profile VALUES(6,2131,'male',28,'山东大学',3.3,15,7,13);
INSERT INTO user_profile VALUES(7,4321,'male',28,'复旦大学',3.6,9,6,52);
INSERT INTO question_practice_detail VALUES(1,2138,111,'wrong');
INSERT INTO question_practice_detail VALUES(2,3214,112,'wrong');
INSERT INTO question_practice_detail VALUES(3,3214,113,'wrong');
INSERT INTO question_practice_detail VALUES(4,6543,111,'right');
INSERT INTO question_practice_detail VALUES(5,2315,115,'right');
INSERT INTO question_practice_detail VALUES(6,2315,116,'right');
INSERT INTO question_practice_detail VALUES(7,2315,117,'wrong');
INSERT INTO question_practice_detail VALUES(8,5432,117,'wrong');
INSERT INTO question_practice_detail VALUES(9,5432,112,'wrong');
INSERT INTO question_practice_detail VALUES(10,2131,113,'right');
INSERT INTO question_practice_detail VALUES(11,5432,113,'wrong');
INSERT INTO question_practice_detail VALUES(12,2315,115,'right');
INSERT INTO question_practice_detail VALUES(13,2315,116,'right');
INSERT INTO question_practice_detail VALUES(14,2315,117,'wrong');
INSERT INTO question_practice_detail VALUES(15,5432,117,'wrong');
INSERT INTO question_practice_detail VALUES(16,5432,112,'wrong');
INSERT INTO question_practice_detail VALUES(17,2131,113,'right');
INSERT INTO question_practice_detail VALUES(18,5432,113,'wrong');
INSERT INTO question_practice_detail VALUES(19,2315,117,'wrong');
INSERT INTO question_practice_detail VALUES(20,5432,117,'wrong');
INSERT INTO question_practice_detail VALUES(21,5432,112,'wrong');
INSERT INTO question_practice_detail VALUES(22,2131,113,'right');
INSERT INTO question_practice_detail VALUES(23,5432,113,'wrong');
INSERT INTO question_detail VALUES(1,111,'hard');
INSERT INTO question_detail VALUES(2,112,'medium');
INSERT INTO question_detail VALUES(3,113,'easy');
INSERT INTO question_detail VALUES(4,115,'easy');
INSERT INTO question_detail VALUES(5,116,'medium');
INSERT INTO question_detail VALUES(6,117,'easy');
```

</details>


<details><summary>我的答案</summary>

```sql
SELECT 
    device_id, 
    gender,
    (
        CASE 
        WHEN age >= 25 THEN '25岁及以上'
        WHEN age >= 20 THEN '20-24岁'
        WHEN age >= 0 THEN '20岁以下'
        ELSE '其他' END 
    ) AS age_cut
FROM user_profile;
```

</details>

### SQL28 计算用户8月每天的练题数量

题目：现在运营想要计算出2021年8月每天用户练习题目的数量，请取出相应数据。

<details><summary>示例：question_practice_detail
</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111195954.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111195954.png';" /></details>

根据示例，你的查询应返回以下结果：

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111200010.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111200010.png';" /></details>

<details><summary>输入数据</summary>

```sql
drop table if exists `user_profile`;
drop table if  exists `question_practice_detail`;
drop table if  exists `question_detail`;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`gpa` float,
`active_days_within_30` int ,
`question_cnt` int ,
`answer_cnt` int 
);
CREATE TABLE `question_practice_detail` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`question_id`int NOT NULL,
`result` varchar(32) NOT NULL,
`date` date NOT NULL
);
CREATE TABLE `question_detail` (
`id` int NOT NULL,
`question_id`int NOT NULL,
`difficult_level` varchar(32) NOT NULL
);

INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学',3.4,7,2,12);
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学',4.0,15,5,25);
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学',3.2,12,3,30);
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学',3.6,5,1,2);
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学',3.8,20,15,70);
INSERT INTO user_profile VALUES(6,2131,'male',28,'山东大学',3.3,15,7,13);
INSERT INTO user_profile VALUES(7,4321,'male',28,'复旦大学',3.6,9,6,52);
INSERT INTO question_practice_detail VALUES(1,2138,111,'wrong','2021-05-03');
INSERT INTO question_practice_detail VALUES(2,3214,112,'wrong','2021-05-09');
INSERT INTO question_practice_detail VALUES(3,3214,113,'wrong','2021-06-15');
INSERT INTO question_practice_detail VALUES(4,6543,111,'right','2021-08-13');
INSERT INTO question_practice_detail VALUES(5,2315,115,'right','2021-08-13');
INSERT INTO question_practice_detail VALUES(6,2315,116,'right','2021-08-14');
INSERT INTO question_practice_detail VALUES(7,2315,117,'wrong','2021-08-15');
INSERT INTO question_practice_detail VALUES(8,3214,112,'wrong','2021-05-09');
INSERT INTO question_practice_detail VALUES(9,3214,113,'wrong','2021-08-15');
INSERT INTO question_practice_detail VALUES(10,6543,111,'right','2021-08-13');
INSERT INTO question_practice_detail VALUES(11,2315,115,'right','2021-08-13');
INSERT INTO question_practice_detail VALUES(12,2315,116,'right','2021-08-14');
INSERT INTO question_practice_detail VALUES(13,2315,117,'wrong','2021-08-15');
INSERT INTO question_practice_detail VALUES(14,3214,112,'wrong','2021-08-16');
INSERT INTO question_practice_detail VALUES(15,3214,113,'wrong','2021-08-18');
INSERT INTO question_practice_detail VALUES(16,6543,111,'right','2021-08-13');
INSERT INTO question_detail VALUES(1,111,'hard');
INSERT INTO question_detail VALUES(2,112,'medium');
INSERT INTO question_detail VALUES(3,113,'easy');
INSERT INTO question_detail VALUES(4,115,'easy');
INSERT INTO question_detail VALUES(5,116,'medium');
INSERT INTO question_detail VALUES(6,117,'easy');
```

</details>

+ [sql日期函数](https://zhuanlan.zhihu.com/p/149306770)


<details><summary>代码详情</summary>

```sql
SELECT 
    DAY(date) day,
    COUNT(question_id) question_cnt
FROM question_practice_detail
WHERE MONTH(date)=8
GROUP BY day
```

</details>

### SQL29 计算用户的平均次日留存率
题目：现在运营想要查看用户在某天刷题后第二天还会再来刷题的平均概率。请你取出相应数据。


<details><summary>示例：question_practice_detail
</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111195954.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111195954.png';" /></details>

根据示例，你的查询应返回以下结果：

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111200917.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111200917.png';" /></details>


<details><summary>输入数据</summary>

```sql
drop table if exists `user_profile`;
drop table if  exists `question_practice_detail`;
drop table if  exists `question_detail`;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`gpa` float,
`active_days_within_30` int ,
`question_cnt` int ,
`answer_cnt` int 
);
CREATE TABLE `question_practice_detail` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`question_id`int NOT NULL,
`result` varchar(32) NOT NULL,
`date` date NOT NULL
);
CREATE TABLE `question_detail` (
`id` int NOT NULL,
`question_id`int NOT NULL,
`difficult_level` varchar(32) NOT NULL
);

INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学',3.4,7,2,12);
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学',4.0,15,5,25);
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学',3.2,12,3,30);
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学',3.6,5,1,2);
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学',3.8,20,15,70);
INSERT INTO user_profile VALUES(6,2131,'male',28,'山东大学',3.3,15,7,13);
INSERT INTO user_profile VALUES(7,4321,'male',28,'复旦大学',3.6,9,6,52);
INSERT INTO question_practice_detail VALUES(1,2138,111,'wrong','2021-05-03');
INSERT INTO question_practice_detail VALUES(2,3214,112,'wrong','2021-05-09');
INSERT INTO question_practice_detail VALUES(3,3214,113,'wrong','2021-06-15');
INSERT INTO question_practice_detail VALUES(4,6543,111,'right','2021-08-13');
INSERT INTO question_practice_detail VALUES(5,2315,115,'right','2021-08-13');
INSERT INTO question_practice_detail VALUES(6,2315,116,'right','2021-08-14');
INSERT INTO question_practice_detail VALUES(7,2315,117,'wrong','2021-08-15');
INSERT INTO question_practice_detail VALUES(8,3214,112,'wrong','2021-05-09');
INSERT INTO question_practice_detail VALUES(9,3214,113,'wrong','2021-08-15');
INSERT INTO question_practice_detail VALUES(10,6543,111,'right','2021-08-13');
INSERT INTO question_practice_detail VALUES(11,2315,115,'right','2021-08-13');
INSERT INTO question_practice_detail VALUES(12,2315,116,'right','2021-08-14');
INSERT INTO question_practice_detail VALUES(13,2315,117,'wrong','2021-08-15');
INSERT INTO question_practice_detail VALUES(14,3214,112,'wrong','2021-08-16');
INSERT INTO question_practice_detail VALUES(15,3214,113,'wrong','2021-08-18');
INSERT INTO question_practice_detail VALUES(16,6543,111,'right','2021-08-13');
INSERT INTO question_detail VALUES(1,111,'hard');
INSERT INTO question_detail VALUES(2,112,'medium');
INSERT INTO question_detail VALUES(3,113,'easy');
INSERT INTO question_detail VALUES(4,115,'easy');
INSERT INTO question_detail VALUES(5,116,'medium');
INSERT INTO question_detail VALUES(6,117,'easy');
```

</details>

> [left join和left outer join](https://blog.csdn.net/weixin_42379136/article/details/83422970)是一个作用
> date_sub(date,interval expr type)，函数从日期减去指定的时间间隔，
> [DATE_ADD](https://www.w3school.com.cn/sql/func_date_add.asp)



<details><summary>我的答案</summary>

```sql
-- SELECT /visitors.visitors_num
-- FROM question_practice_detail
-- JOIN 
--     (
--         SELECT SUM(each_date) AS visitors_num, device_id FROM
--         (
--             SELECT COUNT(DISTINCT device_id) AS each_date FROM question_practice_detail
--             GROUP BY date
--         )a
--     ) visitors,
--     (SELECT DATE_ADD(date, INTERVAL 1 DAY) AS retention, device_id FROM question_practice_detail) day_two



-- SELECT (SUM(IF(retention IS NULL, 0, 1))/SUM(COUNT(DISTINCT qpd.device_id))) AS avg_ret
-- FROM question_practice_detail AS qpd
-- JOIN (SELECT DATE_ADD(date, INTERVAL 2 DAY) AS retention, device_id FROM question_practice_detail) day_two
--     ON qpd.device_id=day_two.device_id
-- GROUP BY date;

-- 已经快解出来了
-- SELECT retention_num/visitors.visitors_num
-- FROM
--     (
--         SELECT SUM(each_date) AS visitors_num, device_id FROM
--         (
--             SELECT COUNT(DISTINCT device_id) AS each_date FROM question_practice_detail
--             GROUP BY date
--         )a
--     ) visitors,
--     (
--         SELECT COUNT(*) AS retention_num FROM
--         (
--             SELECT 
--             date AS day_one, 
--             device_id 
--             FROM question_practice_detail
--             GROUP BY date, device_id
--         ) day_one_table,
--         (
--             SELECT 
--                 DATE_ADD(date, INTERVAL 1 DAY) AS day_two, 
--                 device_id 
--             FROM question_practice_detail
--             GROUP BY date, device_id
--         ) day_two_table
--     WHERE day_one_table.day_one=day_two_table.day_two 
--           AND day_one_table.device_id=day_two_table.device_id
--     ) retention

-- SQL_ERROR_INFO: "Unknown column 'device_id' in 'field list'"

-- v1
SELECT retention_num/visitors.visitors_num AS avg_ret
FROM
    (
        SELECT SUM(each_date) AS visitors_num FROM
        (
            SELECT COUNT(DISTINCT device_id) AS each_date FROM question_practice_detail
            GROUP BY date
        )a
    ) visitors,
    (
        SELECT COUNT(*) AS retention_num FROM
        (
            SELECT 
                date AS day_one, 
                device_id 
            FROM question_practice_detail
            GROUP BY date, device_id
        ) day_one_table,
        (
            SELECT 
                DATE_ADD(date, INTERVAL 1 DAY) AS day_two, 
                device_id 
            FROM question_practice_detail
            GROUP BY date, device_id
        ) day_two_table
        WHERE day_one_table.day_one=day_two_table.day_two 
            AND day_one_table.device_id=day_two_table.device_id
    ) retention

-- v2:错误答案
-- 错误原因：https://blog.csdn.net/qq_45065975/article/details/108075970
-- SELECT retention_num/visitors.visitors_num AS avg_ret
-- FROM
--     (
        -- SELECT 
        --     SUM(COUNT(DISTINCT device_id)) AS visitors_num
        -- FROM question_practice_detail
        -- GROUP BY date
--     ) visitors,
--     (
--         SELECT COUNT(*) AS retention_num FROM
--         (
--             SELECT 
--                 date AS day_one, 
--                 device_id 
--             FROM question_practice_detail
--             GROUP BY date, device_id
--         ) day_one_table,
--         (
--             SELECT 
--                 DATE_ADD(date, INTERVAL 1 DAY) AS day_two, 
--                 device_id 
--             FROM question_practice_detail
--             GROUP BY date, device_id
--         ) day_two_table
--     WHERE day_one_table.day_one=day_two_table.day_two 
--           AND day_one_table.device_id=day_two_table.device_id
--     ) retention


-- SQL_ERROR_INFO: 'Invalid use of group function'

    
```

group by两次，有行数就是出现过，反之就是没有出现过

</details>



#### 思路分析

对于这道题，由于题目没有给公式，题意也比较模糊，我们需要先猜出计算式，突破点是题目的**示例数据**，以及**示例答案0.3**。

题目是这样描述的:

> 现在运营想要查看用户在某天刷题后第二天还会再来刷题的平均概率

我们可以用用频率（次数）代替概率，我们先猜测这个平均概率的计算式为

$avg\_ret=\dfrac{第二天仍然上线天数的次数}{所有人总共出现的天数的和}$

用形式化的语言表示即为

$avg\_ret=\dfrac{\displaystyle\sum_{i=0}^n\sum_{j=0}^n A_i{用户在第}B_j\text{天出现过}\cap A_i\text{用户在第}B_j+1\text{天出现过}}{\displaystyle\sum_{i=0}^n A_i\text{用户出现过的总天数}}$

根据这个思路，我们如何手动做这道题呢？

观察算式，很容易发现结果和**日期**和**当时出现过的人**有关，很容易想到用二维表辅助分析。我们可以先把每一个人在哪一天出现过标记出来。为了方便我们作表，我们可以对原始表按照**日期**排序。

<details><summary>排序表的sql语句</summary>

```sql
--看一下整张表的结构
SELECT * FROM question_practice_detail
ORDER BY date,device_id;
```

</details>

<details><summary>排序后的表</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220114174535.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220114174535.png';" /></details>

最终我们画出下面的表：

<details><summary>中间分析表</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220114154757.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220114154757.png';" /></details>

> 注：红色单元格代表当天出现，第二天仍然上线；蓝色代表当天出现，第二天没有上线

> 注：虽然5.9和6.15在中间分析表中黏在一起，但他们不是相邻的两天

红色出现过的那一天代表该用户第二天留了下来，数一下我们发现第二天仍然上线的次数为3次（红色块的数量），所有人总共出现的天数的和为10次（颜色块的数量），结果即为0.3，那么我们的想法大概是八九不离十了。

#### 将思路转为sql代码
接下来我们可以将我们的思路逐步转为sql代码，再整合一下就能得到答案了。

##### 求分母：所有人总共出现的天数的和
很明显，求用户出现的总天数，也就是分母部分会比较简单，我们先从这里下手。

第一步，每日客户去重。如果当天一个客户访问了多次网站，那么只计算为一次有效访问次数。比如5.9那天3214用户的记录出现了两次，但是应该计数为1。

我们先按日期分组，然后求某一天去重之后的人数(COUNT DISTINCT)，再把每一天去重后的人数加起来(SUM)。即：

```sql
-- 求所有人总共出现的天数的和
SELECT SUM(each_date) AS visitors_num FROM
(
    SELECT COUNT(DISTINCT device_id) AS each_date FROM question_practice_detail
    GROUP BY date
)a

```

<details><summary>输出：所有人总共出现的天数的和</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220114230611.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220114230611.png';" /></details>

##### 求分子：第二天仍然上线天数的次数

这里的难点在于，如何**表示**出**一个用户相邻相邻的两天上线**这个特性，并**数**出来**一个用户相邻相邻的两天上线**个数。

首先考虑如何得到一张一个用户上线过的日期的记录表。通过对日期和时间聚合达到这一目的。

```sql
-- 求用户上线过的日期的记录表
SELECT 
    date AS day_one, 
    device_id 
FROM question_practice_detail
GROUP BY date, device_id
```

<details><summary>输出：用户上线过的日期的记录表</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220114230509.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220114230509.png';" /></details>

如果我们手工做的话，我们的思路相当于`遍历` `用户上线过的日期的记录表`的每一个条目，然后看这个条目日期的第二条，该用户有没有上线。比如我们以8.13日的2315那条为例子，我们又从第一条开始匹配，`匹配`最后一条，发现8.14日的2315也上线了，那么就把这条`选`出来。

<details><summary>想象的两份表</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220114230929.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220114230929.png';" /></details>

思维稍微转换一下，我们可以通过`用户上线过的日期的记录表`创造一张`假想第二天上线表`,将`用户上线过的日期的记录表`的时间都推迟一天，我们`遍历` `假想第二天上线表`的每一个条目，如果`用户上线过的日期的记录表`中存在一条一样的条目，那么就计数。

```sql
-- 创造假想的表
SELECT 
    DATE_ADD(date, INTERVAL 1 DAY) AS day_two, 
    device_id 
FROM question_practice_detail
GROUP BY date, device_id;
```

<details><summary>通过假想的表来求</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220114232204.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220114232204.png';" /></details>

我们的遍历过程相当于求一次两张表的笛卡尔积，然后可以用WHERE筛选出我们想要的条目计数即可。

```sql
-- 求分子
SELECT retention_num
FROM
    (
        SELECT COUNT(*) AS retention_num FROM
        (
            SELECT 
                date AS day_one, 
                device_id 
            FROM question_practice_detail
            GROUP BY date, device_id
        ) day_one_table,
        (
            SELECT 
                DATE_ADD(date, INTERVAL 1 DAY) AS day_two, 
                device_id 
            FROM question_practice_detail
            GROUP BY date, device_id
        ) day_two_table
        WHERE day_one_table.day_one=day_two_table.day_two 
          AND day_one_table.device_id=day_two_table.device_id
    ) retention
```

#### 完整代码
接下来，分子除分母即可。

```sql
SELECT retention_num/visitors.visitors_num AS avg_ret
FROM
    (
        SELECT SUM(each_date) AS visitors_num FROM
        (
            SELECT COUNT(DISTINCT device_id) AS each_date FROM question_practice_detail
            GROUP BY date
        )a
    ) visitors,
    (
        SELECT COUNT(*) AS retention_num FROM
        (
            SELECT 
                date AS day_one, 
                device_id 
            FROM question_practice_detail
            GROUP BY date, device_id
        ) day_one_table,
        (
            SELECT 
                DATE_ADD(date, INTERVAL 1 DAY) AS day_two, 
                device_id 
            FROM question_practice_detail
            GROUP BY date, device_id
        ) day_two_table
        WHERE day_one_table.day_one=day_two_table.day_two 
            AND day_one_table.device_id=day_two_table.device_id
    ) retention
```


### SQL30 统计每种性别的人数
题目：现在运营举办了一场比赛，收到了一些参赛申请，表数据记录形式如下所示，现在运营想要统计每个性别的用户分别有多少参赛者，请取出相应结果

<details><summary>示例：user_submit
</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111215259.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111215259.png';" /></details>


<details><summary>根据示例，你的查询应返回以下结果：
</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111215310.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111215310.png';" /></details>

<details><summary>输入数据</summary>

```sql
drop table if exists user_submit;
CREATE TABLE `user_submit` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`profile` varchar(100) NOT NULL,
`blog_url` varchar(100) NOT NULL
);
INSERT INTO user_submit VALUES(1,2138,'180cm,75kg,27,male','http:/url/bisdgboy777');
INSERT INTO user_submit VALUES(1,3214,'165cm,45kg,26,female','http:/url/dkittycc');
INSERT INTO user_submit VALUES(1,6543,'178cm,65kg,25,male','http:/url/tigaer');
INSERT INTO user_submit VALUES(1,4321,'171cm,55kg,23,female','http:/url/uhsksd');
INSERT INTO user_submit VALUES(1,2131,'168cm,45kg,22,female','http:/url/sysdney');
```

</details>

+ [SQL的文本函数](https://zhuanlan.zhihu.com/p/361411815)
+ [substring](https://www.1keydata.com/cn/sql/sql-substring.php)
  + SUBSTR (str, pos)，SUBSTR (str, pos, len)
+ [LOCATE](https://www.cnblogs.com/mr-wuxiansheng/p/6531315.html)
  + LOCATE(substr,str), LOCATE(substr,str,pos)

<details><summary>我的答案</summary>

```sql
SELECT 
    SUBSTRING(profile, 15) AS gender,
    COUNT(device_id) AS number
FROM user_submit
GROUP BY gender;
```

</details>

### SQL31 提取博客URL中的用户名
题目：对于申请参与比赛的用户，blog_url字段中url字符后的字符串为用户个人博客的用户名，现在运营想要把用户的个人博客用户字段提取出单独记录为一个新的字段，请取出所需数据。


<details><summary>示例：user_submit
</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111215259.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111215259.png';" /></details>

<details><summary>输入数据</summary>

```sql
drop table if exists user_submit;
CREATE TABLE `user_submit` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`profile` varchar(100) NOT NULL,
`blog_url` varchar(100) NOT NULL
);
INSERT INTO user_submit VALUES(1,2138,'180cm,75kg,27,male','http:/url/bisdgboy777');
INSERT INTO user_submit VALUES(1,3214,'165cm,45kg,26,female','http:/url/dkittycc');
INSERT INTO user_submit VALUES(1,6543,'178cm,65kg,25,male','http:/url/tigaer');
INSERT INTO user_submit VALUES(1,4321,'171cm,55kg,23,female','http:/url/uhsksd');
INSERT INTO user_submit VALUES(1,2131,'168cm,45kg,22,female','http:/url/sysdney');
```

</details>

根据示例，你的查询应返回以下结果：

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111220805.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111220805.png';" /></details>


<details><summary>我的答案</summary>

```sql
SELECT
    device_id,
    SUBSTRING(blog_url, 11) user_name
FROM
    user_submit;
```

</details>

### SQL32 截取出年龄

题目：现在运营举办了一场比赛，收到了一些参赛申请，表数据记录形式如下所示，现在运营想要统计每个年龄的用户分别有多少参赛者，请取出相应结果

<details><summary>示例：user_submit
</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111215259.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111215259.png';" /></details>

<details><summary>输入数据</summary>

```sql
drop table if exists user_submit;
CREATE TABLE `user_submit` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`profile` varchar(100) NOT NULL,
`blog_url` varchar(100) NOT NULL
);
INSERT INTO user_submit VALUES(1,2138,'180cm,75kg,27,male','http:/url/bisdgboy777');
INSERT INTO user_submit VALUES(1,3214,'165cm,45kg,26,female','http:/url/dkittycc');
INSERT INTO user_submit VALUES(1,6543,'178cm,65kg,25,male','http:/url/tigaer');
INSERT INTO user_submit VALUES(1,4321,'171cm,55kg,23,female','http:/url/uhsksd');
INSERT INTO user_submit VALUES(1,2131,'168cm,45kg,22,female','http:/url/sysdney');
```

</details>

根据示例，你的查询应返回以下结果：

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111221202.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111221202.png';" /></details>

<details><summary>我的答案</summary>

```sql
SELECT
    SUBSTRING(profile, 12, 2) age,
    COUNT(device_id)
FROM user_submit
GROUP BY age;
```

</details>

### SQL33 找出每个学校GPA最低的同学

题目：现在运营想要找到每个学校gpa最低的同学来做调研，请你取出每个学校的最低gpa。



<details><summary>user_profile</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110193318.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110193318.png';" /></details>

<details><summary>输入数据</summary>

```sql
drop table if exists user_profile;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`gpa` float,
`active_days_within_30` float,
`question_cnt` float,
`answer_cnt` float
);
INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学',3.4,7,2,12);
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学',4.0,15,5,25);
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学',3.2,12,3,30);
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学',3.6,5,1,2);
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学',3.8,20,15,70);
INSERT INTO user_profile VALUES(6,2131,'male',28,'山东大学',3.3,15,7,13);
INSERT INTO user_profile VALUES(7,4321,'male',28,'复旦大学',3.6,9,6,52);
```

</details>

根据示例，你的查询结果应参考以下格式，输出结果按university升序排序：

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220113191819.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220113191819.png';" /></details>



+ [窗口函数](https://zhuanlan.zhihu.com/p/92654574)
+ [参考文献](https://blog.nowcoder.net/n/f9fbef0ee33348f7b01b092249b5ed2c?f=comment)
+ [参考文献](https://blog.csdn.net/qq_34069667/article/details/107173779)窗口函数与执行顺序：窗口函数是在where之后执行的

<details><summary>我的答案</summary>

```sql
-- SELECT 
--     device_id,
--     university,
--     gpa
-- FROM user_profile
-- WHERE gpa=MIN(gpa)
-- GROUP BY university;
-- SQL_ERROR_INFO: 'Invalid use of group function'



-- SELECT 
--     device_id,
--     university,
--     gpa
-- FROM user_profile
-- GROUP BY university
-- HAVING gpa=MIN(gpa);

-- SQL_ERROR_INFO: "Expression #1 of SELECT list is not in GROUP BY clause and contains nonaggregated column 'user_profile.device_id' which is not functionally dependent on columns in GROUP BY clause; this is incompatible with sql_mode=only_full_group_by"


-- SELECT device_id, university,gpa
-- FROM
-- (
--     SELECT 
--         device_id,
--         university,
--         gpa,
--         RANK() OVER (PARTITION BY university order by gpa) AS gpa_rank
--     FROM user_profile
--     WHERE gpa=MIN(gpa_rank)
-- )a;

-- SQL_ERROR_INFO: 'Invalid use of group function'


-- SELECT device_id, university,gpa
-- FROM
-- (
--     SELECT 
--         device_id,
--         university,
--         gpa,
--         RANK() OVER (PARTITION BY university order by gpa) AS gpa_rank
--     FROM user_profile
--     WHERE gpa_rank=1
-- )a;

-- SQL_ERROR_INFO: "Unknown column 'gpa_rank' in 'where clause'"


SELECT device_id, university,gpa
FROM
(
    SELECT 
        device_id,
        university,
        gpa,
        RANK() OVER (PARTITION BY university order by gpa) AS gpa_rank
    FROM user_profile
)a
WHERE a.gpa_rank=1;

```

</details>


### SQL34 统计复旦用户8月练题情况

题目： 现在运营想要了解复旦大学的每个用户在8月份练习的总题目数和回答正确的题目数情况，请取出相应明细数据，对于在8月份没有练习过的用户，答题数结果返回0.


<details><summary>user_profile</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111193138.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111193138.png';" /></details>

<details><summary>题库练习明细表：question_practice_detail</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111101643.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111101643.png';" /></details>

<details><summary>输入数据</summary>

```sql
drop table if exists `user_profile`;
drop table if  exists `question_practice_detail`;
drop table if  exists `question_detail`;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`gpa` float,
`active_days_within_30` int ,
`question_cnt` int ,
`answer_cnt` int 
);
CREATE TABLE `question_practice_detail` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`question_id`int NOT NULL,
`result` varchar(32) NOT NULL,
`date` date NOT NULL
);
CREATE TABLE `question_detail` (
`id` int NOT NULL,
`question_id`int NOT NULL,
`difficult_level` varchar(32) NOT NULL
);

INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学',3.4,7,2,12);
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学',4.0,15,5,25);
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学',3.2,12,3,30);
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学',3.6,5,1,2);
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学',3.8,20,15,70);
INSERT INTO user_profile VALUES(6,2131,'male',28,'山东大学',3.3,15,7,13);
INSERT INTO user_profile VALUES(7,4321,'male',28,'复旦大学',3.6,9,6,52);
INSERT INTO question_practice_detail VALUES(1,2138,111,'wrong','2021-05-03');
INSERT INTO question_practice_detail VALUES(2,3214,112,'wrong','2021-05-09');
INSERT INTO question_practice_detail VALUES(3,3214,113,'wrong','2021-06-15');
INSERT INTO question_practice_detail VALUES(4,6543,111,'right','2021-08-13');
INSERT INTO question_practice_detail VALUES(5,2315,115,'right','2021-08-13');
INSERT INTO question_practice_detail VALUES(6,2315,116,'right','2021-08-14');
INSERT INTO question_practice_detail VALUES(7,2315,117,'wrong','2021-08-15');
INSERT INTO question_practice_detail VALUES(8,3214,112,'wrong','2021-05-09');
INSERT INTO question_practice_detail VALUES(9,3214,113,'wrong','2021-08-15');
INSERT INTO question_practice_detail VALUES(10,6543,111,'right','2021-08-13');
INSERT INTO question_practice_detail VALUES(11,2315,115,'right','2021-08-13');
INSERT INTO question_practice_detail VALUES(12,2315,116,'right','2021-08-14');
INSERT INTO question_practice_detail VALUES(13,2315,117,'wrong','2021-08-15');
INSERT INTO question_practice_detail VALUES(14,3214,112,'wrong','2021-08-16');
INSERT INTO question_practice_detail VALUES(15,3214,113,'wrong','2021-08-18');
INSERT INTO question_practice_detail VALUES(16,6543,111,'right','2021-08-13');
INSERT INTO question_detail VALUES(1,111,'hard');
INSERT INTO question_detail VALUES(2,112,'medium');
INSERT INTO question_detail VALUES(3,113,'easy');
INSERT INTO question_detail VALUES(4,115,'easy');
INSERT INTO question_detail VALUES(5,116,'medium');
INSERT INTO question_detail VALUES(6,117,'easy');
```

</details>


根据示例，你的查询应返回以下结果：



<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220113194758.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220113194758.png';" /></details>

<details><summary>我的答案</summary>

```sql
-- SELECT 
--     device_id,
--     university,
--     COUNT question_id AS question_cnt,
--     (COUNT IF(result='right', 1, 0)) AS right_question_cnt
-- FROM user_profile
-- JOIN question_practice_detail
-- WHERE university='复旦大学'
-- GROUP BY device_id;

-- SQL_ERROR_INFO: "You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'AS question_cnt,\n (COUNT IF(result='right', 1, 0)) AS right_question_cnt\nFROM' at line 4"

-- 缺了ON
-- SELECT 
--     user_profile.device_id,
--     university,
--     COUNT(question_id) AS question_cnt,
--     IF(result='right', 1, 0) AS question_cnt_a
-- FROM user_profile
-- LEFT JOIN question_practice_detail
-- WHERE university='复旦大学';

-- SQL_ERROR_INFO: "You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'WHERE university='复旦大学'' at line 8"

-- 使用了聚合函数需要用group by
-- https://blog.csdn.net/lubxx/article/details/107871766
-- SELECT
--     up.device_id,
--     university,
--     COUNT(question_id) AS question_cnt,
--     IF(result='right', 1, 0) AS question_cnt_a
-- FROM user_profile up
-- LEFT JOIN question_practice_detail pqd
-- ON up.device_id=pqd.device_id
-- WHERE university='复旦大学';

-- SQL_ERROR_INFO: "In aggregated query without GROUP BY, expression #1 of SELECT list contains nonaggregated column 'up.device_id'; this is incompatible with sql_mode=only_full_group_by"

-- 答案错误,需要处理NULL的情况
-- SELECT
--     device_id,
--     university,
--     COUNT(question_id),
--     SUM(binary_result)
-- FROM(
-- SELECT
--     up.device_id,
--     university,
--     question_id,
--     IF(result='right', 1, 0) AS binary_result
-- FROM user_profile up
-- LEFT JOIN question_practice_detail pqd
-- ON up.device_id=pqd.device_id
-- WHERE university='复旦大学' AND MONTH(date)=8
-- ) a
-- GROUP BY device_id


SELECT
    device_id,
    university,
    COUNT(question_id),
    SUM(binary_result)
FROM(
SELECT
    up.device_id,
    university,
    question_id,
#     IF(result='right', 1, 0) AS binary_result
    (
        CASE result 
        WHEN 'right' THEN 1
        WHEN 'wrong' THEN 0
        ELSE 0 END
    ) AS binary_result
FROM user_profile up
LEFT JOIN (
    SELECT *
    FROM question_practice_detail
    WHERE MONTH(date)=8
) pqd
ON up.device_id=pqd.device_id
WHERE university='复旦大学'
) a
GROUP BY device_id;

-- 网友的答案
-- 为什么没有WHERE也可以用AND，line 9
-- MONTH(q.`date`) = "08"，MONTH不是返回int类型吗
-- SELECT
--     u.device_id,
--     university,
--     SUM(IF(result IS NOT NULL, 1, 0)) AS questino_cnt,
--     SUM(IF(result = "right", 1, 0)) AS right_question_cnt
-- FROM
--     user_profile u
--     LEFT JOIN question_practice_detail q ON u.device_id = q.device_id
--     AND MONTH(q.`date`) = "08"
-- WHERE 
--     university = "复旦大学"
-- GROUP BY
--     u.device_id;
```

</details>


### SQL35 浙大不同难度题目的正确率
题目：现在运营想要了解浙江大学的用户在不同难度题目下答题的正确率情况，请取出相应数据，并按照准确率升序输出。

<details><summary>user_profile</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220110193318.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220110193318.png';" /></details>

<details><summary>示例：question_practice_detail
</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111195954.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111195954.png';" /></details>


<details><summary>表：question_detail</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220111101707.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220111101707.png';" /></details>

<details><summary>输入数据</summary>

```sql
drop table if exists `user_profile`;
drop table if  exists `question_practice_detail`;
drop table if  exists `question_detail`;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`gpa` float,
`active_days_within_30` int ,
`question_cnt` int ,
`answer_cnt` int 
);
CREATE TABLE `question_practice_detail` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`question_id`int NOT NULL,
`result` varchar(32) NOT NULL,
`date` date NOT NULL
);
CREATE TABLE `question_detail` (
`id` int NOT NULL,
`question_id`int NOT NULL,
`difficult_level` varchar(32) NOT NULL
);

INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学',3.4,7,2,12);
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学',4.0,15,5,25);
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学',3.2,12,3,30);
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学',3.6,5,1,2);
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学',3.8,20,15,70);
INSERT INTO user_profile VALUES(6,2131,'male',28,'山东大学',3.3,15,7,13);
INSERT INTO user_profile VALUES(7,4321,'male',28,'复旦大学',3.6,9,6,52);
INSERT INTO question_practice_detail VALUES(1,2138,111,'wrong','2021-05-03');
INSERT INTO question_practice_detail VALUES(2,3214,112,'wrong','2021-05-09');
INSERT INTO question_practice_detail VALUES(3,3214,113,'wrong','2021-06-15');
INSERT INTO question_practice_detail VALUES(4,6543,111,'right','2021-08-13');
INSERT INTO question_practice_detail VALUES(5,2315,115,'right','2021-08-13');
INSERT INTO question_practice_detail VALUES(6,2315,116,'right','2021-08-14');
INSERT INTO question_practice_detail VALUES(7,2315,117,'wrong','2021-08-15');
INSERT INTO question_practice_detail VALUES(8,3214,112,'wrong','2021-05-09');
INSERT INTO question_practice_detail VALUES(9,3214,113,'wrong','2021-08-15');
INSERT INTO question_practice_detail VALUES(10,6543,111,'right','2021-08-13');
INSERT INTO question_practice_detail VALUES(11,2315,115,'right','2021-08-13');
INSERT INTO question_practice_detail VALUES(12,2315,116,'right','2021-08-14');
INSERT INTO question_practice_detail VALUES(13,2315,117,'wrong','2021-08-15');
INSERT INTO question_practice_detail VALUES(14,3214,112,'wrong','2021-08-16');
INSERT INTO question_practice_detail VALUES(15,3214,113,'wrong','2021-08-18');
INSERT INTO question_practice_detail VALUES(16,6543,111,'right','2021-08-13');
INSERT INTO question_detail VALUES(1,111,'hard');
INSERT INTO question_detail VALUES(2,112,'medium');
INSERT INTO question_detail VALUES(3,113,'easy');
INSERT INTO question_detail VALUES(4,115,'easy');
INSERT INTO question_detail VALUES(5,116,'medium');
INSERT INTO question_detail VALUES(6,117,'easy');
```

</details>

根据示例，你的查询应返回以下结果：

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220113213416.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220113213416.png';" /></details>

 
<details><summary>我的答案</summary>

```sql
SELECT
    difficult_level,
    (SUM(IF(result='right', 1, 0)) / COUNT(qpd.question_id)) AS correct_rate
FROM user_profile AS up
JOIN question_practice_detail AS qpd ON up.device_id=qpd.device_id
JOIN question_detail AS qd ON qpd.question_id=qd.question_id
WHERE university='浙江大学'
GROUP BY difficult_level
ORDER BY correct_rate;

```

</details>

### SQL39 21年8月份练题总数
题目： 现在运营想要了解2021年8月份所有练习过题目的总用户数和练习过题目的总次数，请取出相应结果

<details><summary>question_practice_detail</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220114150431.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220114150431.png';" /></details>

根据的示例，你的查询应返回以下结果：

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220114150447.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220114150447.png';" /></details>



<details><summary>输入数据</summary>

```sql
drop table if exists `user_profile`;
drop table if  exists `question_practice_detail`;
CREATE TABLE `user_profile` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`gender` varchar(14) NOT NULL,
`age` int ,
`university` varchar(32) NOT NULL,
`gpa` float,
`active_days_within_30` int ,
`question_cnt` int ,
`answer_cnt` int 
);
CREATE TABLE `question_practice_detail` (
`id` int NOT NULL,
`device_id` int NOT NULL,
`question_id`int NOT NULL,
`result` varchar(32) NOT NULL,
`date` date NOT NULL
);

INSERT INTO user_profile VALUES(1,2138,'male',21,'北京大学',3.4,7,2,12);
INSERT INTO user_profile VALUES(2,3214,'male',null,'复旦大学',4.0,15,5,25);
INSERT INTO user_profile VALUES(3,6543,'female',20,'北京大学',3.2,12,3,30);
INSERT INTO user_profile VALUES(4,2315,'female',23,'浙江大学',3.6,5,1,2);
INSERT INTO user_profile VALUES(5,5432,'male',25,'山东大学',3.8,20,15,70);
INSERT INTO user_profile VALUES(6,2131,'male',28,'山东大学',3.3,15,7,13);
INSERT INTO user_profile VALUES(7,4321,'male',28,'复旦大学',3.6,9,6,52);
INSERT INTO question_practice_detail VALUES(1,2138,111,'wrong','2021-05-03');
INSERT INTO question_practice_detail VALUES(2,3214,112,'wrong','2021-05-09');
INSERT INTO question_practice_detail VALUES(3,3214,113,'wrong','2021-06-15');
INSERT INTO question_practice_detail VALUES(4,6543,111,'right','2021-08-13');
INSERT INTO question_practice_detail VALUES(5,2315,115,'right','2021-08-13');
INSERT INTO question_practice_detail VALUES(6,2315,116,'right','2021-08-14');
INSERT INTO question_practice_detail VALUES(7,2315,117,'wrong','2021-08-15');
INSERT INTO question_practice_detail VALUES(8,3214,112,'wrong','2021-05-09');
INSERT INTO question_practice_detail VALUES(9,3214,113,'wrong','2021-08-15');
INSERT INTO question_practice_detail VALUES(10,6543,111,'right','2021-08-13');
INSERT INTO question_practice_detail VALUES(11,2315,115,'right','2021-08-13');
INSERT INTO question_practice_detail VALUES(12,2315,116,'right','2021-08-14');
INSERT INTO question_practice_detail VALUES(13,2315,117,'wrong','2021-08-15');
INSERT INTO question_practice_detail VALUES(14,3214,112,'wrong','2021-08-16');
INSERT INTO question_practice_detail VALUES(15,3214,113,'wrong','2021-08-18');
INSERT INTO question_practice_detail VALUES(16,6543,111,'right','2021-08-13');
```

</details>

<details><summary>我的答案</summary>

```sql
SELECT COUNT(DISTINCT device_id) AS did_cnt, COUNT(question_id) AS question_cnt
FROM question_practice_detail
WHERE MONTH(date)=8
```

</details>

## 进阶
牛客后台会记录每个用户的试卷作答记录到exam_record表，现在有两个用户的作答记录详情如下：



用户1001在2021年9月1日晚上10点11分12秒开始作答试卷9001，并在50分钟后提交，得了90分；

用户1002在2021年9月4日上午7点1分2秒开始作答试卷9002，并在10分钟后退出了平台。

试卷作答记录表exam_record中，表已建好，其结构如下，请用一条语句将这两条记录插入表中。

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220114234348.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220114234348.png';" /></details>

该题最后会通过执行SELECT uid, exam_id, start_time, submit_time, score FROM exam_record;来对比结果


<details><summary>输入</summary>

```sql
drop table if EXISTS exam_record;
CREATE TABLE IF NOT EXISTS exam_record (
id int PRIMARY KEY AUTO_INCREMENT COMMENT '自增ID',
uid int NOT NULL COMMENT '用户ID',
exam_id int NOT NULL COMMENT '试卷ID',
start_time datetime NOT NULL COMMENT '开始时间',
submit_time datetime COMMENT '提交时间',
score tinyint COMMENT '得分'
)CHARACTER SET utf8 COLLATE utf8_general_ci;
TRUNCATE exam_record;


```

</details>

```输出
1001|9001|2021-09-01 22:11:12|2021-09-01 23:01:12|90
1002|9002|2021-09-04 07:01:02|None|None

```