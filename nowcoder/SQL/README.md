

# SQL
## 牛客sql题库
+ [入门](https://www.nowcoder.com/ta/sql-quick-study)
+ [进阶](https://www.nowcoder.com/ta/sql-advanced)
+ [面试题](https://www.nowcoder.com/ta/sql-factory-interview)

## 在线运行sql
+ [网址1](https://www.guofei.site/pictures_for_blog/app/online_sql/online_sql.html)
+ [网址2](https://www.bejson.com/runcode/sql/)

## 数据类型
[参考文献](https://www.w3school.com.cn/sql/sql_datatypes.asp)


## 基本语法
### UNIQUE 和 DISTINCT的区别

### 13 . 哪条 SQL 语句可返回唯一不同的值？

    SELECT DIFFERENT
    SELECT DISTINCT
    SELECT UNIQUE

unique和distinct都是去重的意思，但是他们所用的语句不同

a、unique可以用在创建表时或修改表的结构时使用

b、distinct用于对select语句使用

### 17 . 通过 SQL，您如何向 "Persons" 表中的 "LastName" 列插入 "Wilson" ？

    INSERT INTO Persons (LastName) VALUES ('Wilson')
    INSERT ('Wilson') INTO Persons (LastName)
    INSERT INTO Persons ('Wilson') INTO LastName


insert into的用法

#### 最简单的搞法

<details><summary>代码详情</summary>

```sql
create table test(
  keyid int identity,
  sort varchar(10),
  qty int
) 
insert into test (qty2,sort2) values (1,'e') 

```

</details>


#### 插入多个值，插入多条记录这个写法还是好些的
`insert into test(qty,sort) values (1,'a') ,(2,'a'),(3,'b'),(8,'c'),(9,'c') `

#### 3，赋值其他表中的值，注意类型和大小
<details><summary>代码详情</summary>

```sql
insert into  test(qty,sort)  select  qty2,sort2 from test2  --不加条件是全部复制，
语法：  insert into  表(字段,字段)  select  字段,字段 from 表 

```

</details>

18 . 您如何把 "Persons" 表中 "LastName" 列的 "Gates" 改为 "Wilson" ？

    MODIFY Persons SET LastName='Wilson' WHERE LastName='Gates'
    UPDATE Persons SET LastName='Wilson' WHERE LastName='Gates'
    UPDATE Persons SET LastName='Wilson' INTO LastName='Gates'
    MODIFY Persons SET LastName='Wilson' INTO LastName='Gates'

`UPDATE Persons SET LastName='Wilson' WHERE LastName='Gates' `

### sql中update，alter，modify，delete，drop
[update，alter，modify](https://zhidao.baidu.com/question/407180215.html)


###  Select count(*)和Count（1）的区别和执行方式


[参考文献](https://www.cnblogs.com/CareySon/p/DifferenceBetweenCountStarAndCount1.html)

### group by和group concat
[参考文献](https://www.cnblogs.com/zhuiluoyu/p/6862673.html)

[参考文献](https://baijiahao.baidu.com/s?id=1595349117525189591&wfr=spider&for=pc)

### primary key与unique的区别

> 简单的说，primary key = unique +  not null 

[参考文献](https://blog.csdn.net/zm2714/article/details/8482625)

### MYSQL中顿号的作用
mysql关键字的转义，因为password是mysql的关键字，如果要作为字段的话，必须加上"顿号",例如：

<details><summary>用来转义</summary>

```sql
insert into users(name,`password`,adds,sex,email,age,times) values('李','123','123','男','123','123','2010-10-10')
```

</details>

[参考文献](https://chartio.com/learn/sql-tips/single-double-quote-and-backticks-in-mysql-queries/)

### INT(10)和INT(11)的区别

显示宽度不同

[参考文献](https://blog.csdn.net/qq_44802992/article/details/113915517)

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
### SQL1 插入记录（一）

牛客后台会记录每个用户的试卷作答记录到exam_record表，现在有两个用户的作答记录详情如下：



用户1001在2021年9月1日晚上10点11分12秒开始作答试卷9001，并在50分钟后提交，得了90分；

用户1002在2021年9月4日上午7点1分2秒开始作答试卷9002，并在10分钟后退出了平台。

试卷作答记录表exam_record中，表已建好，其结构如下，请用一条语句将这两条记录插入表中。

<details><summary>exam_record</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220114234348.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220114234348.png';" /></details>

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

+ [INSERT参考文献](https://www.w3school.com.cn/sql/sql_insert.asp)
+ 一条语句插入多条记录，用逗号隔开即可

> INSERT INTO Persons VALUES ('Gates', 'Bill', 'Xuanwumen 10', 'Beijing')
> INSERT INTO Persons (LastName, Address) VALUES ('Wilson', 'Champs-Elysees')

<details><summary>我的答案</summary>

```sql
INSERT INTO exam_record (uid, exam_id, start_time, submit_time, score)
VALUES 
    (1001, 9001, '2021-09-01 22:11:12', '2021-09-01 23:01:12', 90),
    (1002, 9002, '2021-09-04 07:01:02', NULL, NULL);

-- 应该提供列名
-- https://blog.csdn.net/hi__study/article/details/92669938
-- INSERT INTO exam_record
-- VALUES 
--     (1001, 9001, '2021-09-01 22:11:12', '2021-09-01 23:01:12', 90),
--     (1002, 9002, '2021-09-04 07:01:02', NULL, NULL);

-- SQL_ERROR_INFO: "Column count doesn't match value count at row 1
```

</details>

### SQL2 插入记录（二）

现有一张试卷作答记录表exam_record，结构如下表，其中包含多年来的用户作答试卷记录，由于数据越来越多，维护难度越来越大，需要对数据表内容做精简，历史数据做备份。


<details><summary>exam_record</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220114234348.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220114234348.png';" /></details>

我们已经创建了一张新表exam_record_before_2021用来备份2021年之前的试题作答记录，结构和exam_record表一致，请将2021年之前的已完成了的试题作答纪录导入到该表。


后台会通过执行"SELECT * FROM exam_record_before_2021;"语句来对比结果

<details><summary>代码详情</summary>

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
CREATE TABLE IF NOT EXISTS exam_record_before_2021 (
id int PRIMARY KEY AUTO_INCREMENT COMMENT '自增ID',
uid int NOT NULL COMMENT '用户ID',
exam_id int NOT NULL COMMENT '试卷ID',
start_time datetime NOT NULL COMMENT '开始时间',
submit_time datetime COMMENT '提交时间',
score tinyint COMMENT '得分'
)CHARACTER SET utf8 COLLATE utf8_general_ci;
TRUNCATE exam_record;
TRUNCATE exam_record_before_2021;
INSERT INTO exam_record(uid,exam_id,start_time,submit_time,score) VALUES
(1001, 9001, '2020-01-01 09:00:01', null, null),
(1001, 9002, '2020-01-02 09:01:01', '2020-01-02 09:21:01', 70),
(1001, 9002, '2020-09-02 09:00:01', null, null),
(1002, 9001, '2021-05-02 10:01:01', '2021-05-02 10:30:01', 81),
(1002, 9002, '2021-09-02 12:01:01', null, null);

-- 1|1001|9002|2020-01-02 09:01:01|2020-01-02 09:21:01|70


```

</details>



<details><summary>我的答案</summary>

```sql
INSERT INTO exam_record_before_2021 (uid, exam_id, start_time, submit_time, score)
SELECT uid, exam_id, start_time, submit_time, score FROM exam_record
WHERE (YEAR(start_time) < 2021 OR YEAR(submit_time) < 2021) AND submit_time IS NOT NULL;
```

</details>


### SQL3 插入记录（三）
现在有一套ID为9003的高难度SQL试卷，时长为一个半小时，请你将 2021-01-01 00:00:00 作为发布时间插入到试题信息表examination_info（其表结构如下图），不管该ID试卷是否存在，都要插入成功，请尝试插入它。

<details><summary>examination_info</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220117000532.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220117000532.png';" /></details>

后台会通过执行 SELECT exam_id,tag,difficulty,duration,release_time FROM examination_info 语句来对比结果。

<details><summary>我的答案</summary>

```sql
drop table if EXISTS examination_info;
CREATE TABLE IF NOT EXISTS examination_info (
id int PRIMARY KEY AUTO_INCREMENT COMMENT '自增ID',
exam_id int UNIQUE NOT NULL COMMENT '试卷ID',
tag varchar(32) COMMENT '类别标签',
difficulty varchar(8) COMMENT '难度',
duration int NOT NULL COMMENT '时长(分钟数)',
release_time datetime COMMENT '发布时间'
)CHARACTER SET utf8 COLLATE utf8_bin;
TRUNCATE examination_info;
INSERT INTO examination_info(exam_id,tag,difficulty,duration,release_time) VALUES
(9001, 'SQL', 'hard', 60, '2020-01-01 10:00:00'),
(9002, '算法', 'easy', 60, '2020-01-01 10:00:00'),
(9003, 'SQL', 'medium', 60, '2020-01-02 10:00:00'),
(9004, '算法', 'hard', 80, '2020-01-01 10:00:00');

```

</details>

+ 插入当没有的时候更新：[参考文献](https://stackoverflow.com/questions/6030071/mysql-table-insert-if-not-exist-otherwise-update)：`INSERT ... ON DUPLICATE KEY UPDATE`
+ REPLACE INTO [参考文献](https://chartio.com/resources/tutorials/how-to-insert-if-row-does-not-exist-upsert-in-mysql/#using-replace)



<details><summary>我的答案</summary>
REPLACE INTO examination_info (exam_id, tag, difficulty, duration, release_time)
VALUES (9003, 'SQL', 'hard', 90, '2021-01-01 00:00:00');


```sql
-- ALTER TABLE examination_info ADD UNIQUE (exam_id)
-- UNION ALL
-- INSERT INTO examination_info (exam_id, tag, difficulty, duration, release_time)
-- VALUES (9003, 'SQL', 'hard', 90, '2021-01-01 00:00:00')
-- ON DUPLICATE KEY UPDATE
--     exam_id=VALUES(exam_id)

-- SQL_ERROR_INFO: "You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'UNION ALL\nINSERT INTO examination_info (exam_id, tag, difficulty, duration, rele' at line 2"


-- INSERT INTO examination_info (exam_id, tag, difficulty, duration, release_time)
-- VALUES (9003, 'SQL', 'hard', 90, '2021-01-01 00:00:00')
-- ON DUPLICATE KEY UPDATE
--     tag='SQL',
--     difficulty='hard',
--     duration=90,
--     release_time='2021-01-01 00:00:00';

-- 期望输出
-- 9001|SQL|hard|60|2020-01-01 10:00:00
-- 9002|算法|easy|60|2020-01-01 10:00:00
-- 9004|算法|hard|80|2020-01-01 10:00:00
-- 9003|SQL|hard|90|2021-01-01 00:00:00

-- 我的输出
-- 9001|SQL|hard|60|2020-01-01 10:00:00
-- 9002|算法|easy|60|2020-01-01 10:00:00
-- 9003|SQL|hard|90|2021-01-01 00:00:00
-- 9004|算法|hard|80|2020-01-01 10:00:00

```

</details>

### SQL4 更新记录（一）
现有一张试卷信息表examination_info，表结构如下图所示：

<details><summary>exam_record</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220117152555.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220117152555.png';" /></details>

请把examination_info表中tag为PYTHON的tag字段全部修改为Python。



后台会通过执行'SELECT exam_id,tag,difficulty,duration,release_time FROM examination_info;'语句来对比结果。

<details><summary>输入数据</summary>

```sql
drop table if EXISTS examination_info;
CREATE TABLE IF NOT EXISTS examination_info (
id int PRIMARY KEY AUTO_INCREMENT COMMENT '自增ID',
exam_id int UNIQUE NOT NULL COMMENT '试卷ID',
tag varchar(32) COMMENT '类别标签',
difficulty varchar(8) COMMENT '难度',
duration int NOT NULL COMMENT '时长',
release_time datetime COMMENT '发布时间'
)CHARACTER SET utf8 COLLATE utf8_bin;
TRUNCATE examination_info;
INSERT INTO examination_info(exam_id,tag,difficulty,duration,release_time) VALUES
(9001, 'SQL', 'hard', 60, '2020-01-01 10:00:00'),
(9002, 'python', 'easy', 60, '2020-01-01 10:00:00'),
(9003, 'Python', 'medium', 80, '2020-01-01 10:00:00'),
(9004, 'PYTHON', 'hard', 80, '2020-01-01 10:00:00');

```

</details>

<details><summary>我的答案</summary>

```sql
UPDATE examination_info SET tag='Python' WHERE tag='PYTHON'

-- UPDATE examination_info SET tag=python WHERE tag=PYTHON
-- SQL_ERROR_INFO: "Unknown column 'PYTHON' in 'where clause'"


```

</details>

### SQL5 更新记录（二）

现有一张试卷作答记录表exam_record，其中包含多年来的用户作答试卷记录，结构如下表：
作答记录表exam_record：

<details><summary>exam_record</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220117152555.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220117152555.png';" /></details>


请把exam_record表中2021年9月1日之前开始作答的未完成记录全部改为被动完成，即：将完成时间改为'2099-01-01 00:00:00'，分数改为0。


<details><summary>输入数据</summary>

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
INSERT INTO exam_record(uid,exam_id,start_time,submit_time,score) VALUES
(1001, 9001, '2020-01-02 09:01:01', '2020-01-02 09:21:01', 80),
(1001, 9002, '2021-09-01 09:01:01', '2021-09-01 09:21:01', 90),
(1002, 9001, '2021-08-02 19:01:01', null, null),
(1002, 9002, '2021-09-05 19:01:01', '2021-09-05 19:40:01', 89),
(1003, 9001, '2021-09-02 12:01:01', null, null),
(1003, 9002, '2021-09-01 12:01:01', null, null);

```

</details>

日期比较：[参考文献](https://blog.csdn.net/weixin_30722589/article/details/101080893)

<details><summary>我的答案</summary>

```sql
UPDATE exam_record SET submit_time='2099-01-01 00:00:00', score=0
WHERE submit_time IS NULL AND start_time < '2021-09-01 00:00:00';
```

</details>

### SQL6 删除记录（一）
现有一张试卷作答记录表exam_record，其中包含多年来的用户作答试卷记录，结构如下表：
<details><summary>exam_record</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220117152555.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220117152555.png';" /></details>

<details><summary>输入数据
</summary>

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
INSERT INTO exam_record(uid, exam_id, start_time, submit_time, score) VALUES
(1001, 9001, '2020-01-01 22:11:12', '2020-01-01 23:16:12', 50),
(1001, 9002, '2020-01-02 09:01:01', '2020-01-02 09:06:00', 58),
(1002, 9001, '2021-05-02 10:01:01', '2021-05-02 10:05:58', 60),
(1002, 9002, '2021-06-02 19:01:01', '2021-06-02 19:05:01', 54),
(1003, 9001, '2021-09-05 19:01:01', '2021-09-05 19:40:01', 49),
(1003, 9001, '2021-09-05 19:01:01', '2021-09-05 19:15:01', 70),
(1003, 9001, '2021-09-06 19:01:01', '2021-09-06 19:05:01', 80),
(1003, 9002, '2021-09-09 07:01:02', null, null);


```

</details>

请删除exam_record表中作答时间小于5分钟整且分数不及格（及格线为60分）的记录；

后台会通过 SELECT * FROM exam_record; 语句来对比结果。

+ [DELETE语句](https://www.w3school.com.cn/sql/sql_delete.asp)：`DELETE FROM 表名称 WHERE 列名称 = 值`
+ 计算minute时间差：[参考文献](https://stackoverflow.com/questions/7636599/calculating-time-difference-between-2-dates-in-minutes)，`A-B,TIMESTAMPDIFF(MINUTE, B, A)`


<details><summary>我的答案</summary>

```sql
DELETE FROM exam_record 
WHERE 
    TIMESTAMPDIFF(MINUTE, start_time, submit_time) < 5 AND score < 60;

-- 减数和被减数传参的顺序反了
-- DELETE FROM exam_record 
-- WHERE 
--     TIMESTAMPDIFF(MINUTE, submit_time, start_time) < 5 AND score < 60;

-- 目标输出
-- 1|1001|9001|2020-01-01 22:11:12|2020-01-01 23:16:12|50
-- 3|1002|9001|2021-05-02 10:01:01|2021-05-02 10:05:58|60
-- 5|1003|9001|2021-09-05 19:01:01|2021-09-05 19:40:01|49
-- 6|1003|9001|2021-09-05 19:01:01|2021-09-05 19:15:01|70
-- 7|1003|9001|2021-09-06 19:01:01|2021-09-06 19:05:01|80
-- 8|1003|9002|2021-09-09 07:01:02|None|None

-- 我的输出
-- 3|1002|9001|2021-05-02 10:01:01|2021-05-02 10:05:58|60
-- 6|1003|9001|2021-09-05 19:01:01|2021-09-05 19:15:01|70
-- 7|1003|9001|2021-09-06 19:01:01|2021-09-06 19:05:01|80
-- 8|1003|9002|2021-09-09 07:01:02|None|None


    
    
```

</details>

### SQL7 删除记录（二）
现有一张试卷作答记录表exam_record，其中包含多年来的用户作答试卷记录，结构如下表：

作答记录表exam_record：

start_time是试卷开始时间

submit_time 是交卷时间，即结束时间，如果未完成的话，则为空


<details><summary>exam_record</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220117152555.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220117152555.png';" /></details>

<details><summary>输入数据
</summary>

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
INSERT INTO exam_record(uid, exam_id, start_time, submit_time, score) VALUES
(1001, 9001, '2020-01-01 22:11:12', '2020-01-01 23:16:12', 50),
(1001, 9002, '2020-01-02 09:01:01', '2020-01-02 09:06:00', 58),
(1001, 9002, '2020-01-02 09:01:01', '2020-01-02 09:05:01', 58),
(1002, 9001, '2021-05-02 10:01:01', '2021-05-02 10:06:58', 60),
(1002, 9002, '2021-06-02 19:01:01', null, null),
(1003, 9001, '2021-09-05 19:01:01', null, null),
(1003, 9001, '2021-09-05 19:01:01', null, null),
(1003, 9002, '2021-09-09 07:01:02', null, null);



```

</details>

请删除exam_record表中未完成作答或作答时间小于5分钟整的记录中，开始作答时间最早的3条记录。

后台会通过 SELECT * FROM exam_record 语句来对比结果。

<details><summary>我的答案</summary>

```sql
DELETE FROM exam_record
WHERE 
    submit_time IS NULL 
    OR TIMESTAMPDIFF(MINUTE, start_time, submit_time) < 5
ORDER BY start_time
LIMIT 3;
```

</details>

### SQL8 删除记录（三）
现有一张试卷作答记录表exam_record，其中包含多年来的用户作答试卷记录，结构如下表：

<details><summary>exam_record</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220117152555.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220117152555.png';" /></details>

请删除exam_record表中所有记录，并重置自增主键。

后台会通过SELECT table_rows, auto_increment FROM information_schema.tables WHERE table_name=\'exam_record\'   语句来对比输出结果

<details><summary>输入数据</summary>

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
INSERT INTO exam_record(uid, exam_id, start_time, submit_time, score) VALUES
(1001, 9001, '2020-01-01 22:11:12', '2020-01-01 23:16:12', 50),
(1001, 9002, '2020-01-02 09:01:01', '2020-01-02 09:06:00', 58);

```

</details>


+ [mysql里面alter的用法](https://www.cnblogs.com/Daniel-c-h-e-n/p/10819075.html) 
+ [删除表并且重置自增主键](https://stackoverflow.com/questions/8923114/how-to-reset-auto-increment-in-mysql#:~:text=ALTER%20TABLE%20news_feed%20DROP%20id)

网友的答案：`truncate table exam_record`

DROP TABLE, TRUNCATE TABLE, DELETE TABLE三种删除语句的区别：DROP是把表的Scheme都删了，而TRUNCATE和DELETE是只删除表的行，但表是如何定义的没有删除（即不删除Scheme）。

1.DROP TABLE：清除数据并且销毁表，是一种数据库定义语言(DDL Data Definition Language), 执行后不能撤销，被删除表格的关系，索引，权限等等都会被永久删除。

2.TRUNCATE TABLE：只清除数据，保留表结构，列，权限，索引，视图，关系等等，相当于清零数据，是一种数据库定义语言(DDL Data Definition Language)，执行后不能撤销。

3.DELETE TABLE：删除（符合某些条件的）数据，是一种数据操纵语言(DML Data Manipulation Language)，执行后可以撤销。DELETE比较安全指的是在事务中可以回滚（ROLLBACK）。

运行速度一般DROP最快，DELETE最慢，但是DELETE最安全。




<details><summary>我的答案</summary>

```sql

ALTER TABLE exam_record DROP id;

-- DELETE FROM exam_record;
-- ALTER TABLE exam_record AUTO_INCREMENT = NULL;

-- SQL_ERROR_INFO: "You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'NULL' at line 1"
```

</details>


### SQL9 创建一张新表
原来的用户信息表：


<details><summary>user_info_vip</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220119220246.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220119220246.png';" /></details>

作为数据分析师，请创建一张优质用户信息表user_info_vip，表结构和用户信息表一致。


备注：

1.后台会通过 SHOW FULL FIELDS FROM user_info_vip 语句，来对比输出结果

2.如果该表已经被其他分析师创建过了，正常返回即可

<details><summary>输入数据</summary>

```sql
drop table if EXISTS user_info_vip;
```

</details>


+ MySQL中的[约束](https://blog.csdn.net/w_linux/article/details/79655073)
+ [菜鸟教程](https://www.runoob.com/sql/sql-constraints.html)：mysql中的约束
+ mysql[创建表](https://www.runoob.com/mysql/mysql-create-tables.html)


<details><summary>我的答案</summary>

```sql
CREATE TABLE IF NOT EXISTS user_info_vip (
    id INT(11) NOT NULL PRIMARY KEY AUTO_INCREMENT COMMENT '自增ID',
    uid INT(11) NOT NULL UNIQUE COMMENT '用户ID',
    nick_name VARCHAR(64) COMMENT '昵称',
    achievement INT(11) DEFAULT 0 COMMENT '成就值',
    `level` INT(11) COMMENT '用户等级',
    job VARCHAR(32) COMMENT '职业方向',
    register_time DATETIME DEFAULT CURRENT_TIMESTAMP COMMENT '注册时间'
) 

-- 不用顿号包裹也是可以的
-- CREATE TABLE IF NOT EXISTS user_info_vip (
--     id INT(11) NOT NULL PRIMARY KEY AUTO_INCREMENT COMMENT '自增ID',
--     uid INT(11) NOT NULL UNIQUE COMMENT '用户ID',
--     nick_name VARCHAR(64) COMMENT '昵称',
--     achievement INT(11) DEFAULT 0 COMMENT '成就值',
--     level INT(11) COMMENT '用户等级',
--     job VARCHAR(32) COMMENT '职业方向',
--     register_time DATETIME DEFAULT CURRENT_TIMESTAMP COMMENT '注册时间'
-- ) 
```

</details>

### SQL10 修改表
现有一张用户信息表user_info，其中包含多年来在平台注册过的用户信息。


<details><summary>user_info_vip</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220119220246.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220119220246.png';" /></details>

请在用户信息表，字段level的后面增加一列最多可保存15个汉字的字段school；并将表中job列名改为profession，同时varchar字段长度变为10；achievement的默认值设置为0。

备注：建表时限制的字符集为utf8，MySQL版本为8.*

后台会通过SHOW FULL FIELDS FROM user_info 来对比输出结果。

+ 修改[多个字段](https://www.jianshu.com/p/dd7585398137)
+ 在指定列后增加一列：[参考文献](https://www.cnblogs.com/ichimoku/p/7880959.html)

`alter table 表名 add column 列名 varchar(20) not null after user1;`

+ [添加约束](https://jingyan.baidu.com/article/59a015e3f2c5d5b795886562.html)

`ALTER TABLE <数据表名> CHANGE COLUMN <字段名> <数据类型> DEFAULT <默认值>;`

<details><summary>我的答案</summary>

```sql
ALTER TABLE user_info 
    CHANGE job profession VARCHAR(10),
    ADD COLUMN school VARCHAR(15) AFTER `level`,
    CHANGE COLUMN achievement achievement INT(11) DEFAULT 0;
```

</details>

### SQL11 删除表
现有一张试卷作答记录表exam_record，其中包含多年来的用户作答试卷记录。一般每年都会为exam_record表建立一张备份表exam_record_{YEAR}，{YEAR}为对应年份。

现在随着数据越来越多，存储告急，请你把很久前的（2011到2014年）备份表都删掉（如果存在的话）。


备注:后台会通过SELECT TABLE_NAME FROM information_schema.TABLES WHERE TABLE_NAME LIKE \'exam\_record\_201_\'  来对比输出结果。


<details><summary>输入数据</summary>

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
CREATE TABLE IF NOT EXISTS exam_record_2010 (LIKE exam_record); 
CREATE TABLE IF NOT EXISTS exam_record_2012 (LIKE exam_record); 
CREATE TABLE IF NOT EXISTS exam_record_2013 (LIKE exam_record); 
CREATE TABLE IF NOT EXISTS exam_record_2014 (LIKE exam_record); 
CREATE TABLE IF NOT EXISTS exam_record_2015 (LIKE exam_record); 

```

</details>

+ [删除不在列表中的list](https://stackoverflow.com/questions/5875293/drop-tables-that-are-not-in-a-list)
+ [INFORMATION_SCHEMA](https://blog.csdn.net/kikajack/article/details/80065753)数据库
+ 字符串使用单引号和双引号拼接都可以：[参考文献](https://blog.csdn.net/qq_42889294/article/details/105353639)

<details><summary>删除不在列表中的list的代码</summary>

```sql
SELECT CONCAT("DROP TABLE ", table_name, ";") 
FROM information_schema.TABLES 
WHERE table_schema = <whatever your db name is> 
AND table_name NOT IN (<your list>);
```

</details>

<details><summary>我的答案</summary>

```sql
DROP TABLE IF EXISTS exam_record_2011, exam_record_2012, exam_record_2013, exam_record_2014;


-- 一张表都没有删除
-- SELECT CONCAT('DROP TABLE ', TABLE_NAME, ';')
-- FROM INFORMATION_SCHEMA.TABLES
-- WHERE TABLE_NAME IN 
--     (
--         'exam_record_2011', 
--         'exam_record_2012',
--         'exam_record_2013',
--         'exam_record_2014'
--     )
```

</details>

### SQL12 创建索引
现有一张试卷信息表examination_info，其中包含各种类型试卷的信息。为了对表更方便快捷地查询，需要在examination_info表创建以下索引，规则如下：

在duration列创建普通索引idx_duration、在exam_id列创建唯一性索引uniq_idx_exam_id、在tag列创建全文索引full_idx_tag。

根据题意，将返回如下结果：


<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220120161920.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220120161920.png';" /></details>

备注：后台会通过 SHOW INDEX FROM examination_info 语句来对比输出结果


<details><summary>输入数据</summary>

```sql
drop table if exists examination_info;
CREATE TABLE IF NOT EXISTS examination_info (
id int PRIMARY KEY AUTO_INCREMENT COMMENT '自增ID',
exam_id int UNIQUE NOT NULL COMMENT '试卷ID',
tag varchar(32) COMMENT '类别标签',
difficulty varchar(8) COMMENT '难度',
duration int NOT NULL COMMENT '时长',
release_time datetime COMMENT '发布时间'
)CHARACTER SET utf8 COLLATE utf8_bin;

```

</details>


+ 为字段[添加索引](https://blog.csdn.net/qq_41904362/article/details/108198961)

<details><summary>代码详情</summary>

```sql
ALTER TABLE `table_name` ADD INDEX index_name ( `column` )
```

</details>

<details><summary>我的答案</summary>

```sql
ALTER TABLE examination_info 
    ADD INDEX idx_duration(`duration`),
    ADD UNIQUE uniq_idx_exam_id(`exam_id`),
    ADD FULLTEXT full_idx_tag(`tag`);
    
```

</details>

### SQL13 删除索引
请删除examination_info表上的唯一索引uniq_idx_exam_id和全文索引full_idx_tag。

后台会通过 SHOW INDEX FROM examination_info 来对比输出结果。


+ 删除索引：` DROP INDEX <索引名> ON <表名>`，[参考文献](http://c.biancheng.net/view/2607.html)，

<details><summary>输入数据</summary>

```sql
drop table if exists examination_info;
CREATE TABLE IF NOT EXISTS examination_info (
id int PRIMARY KEY AUTO_INCREMENT COMMENT '自增ID',
exam_id int COMMENT '试卷ID',
tag varchar(32) COMMENT '类别标签',
difficulty varchar(8) COMMENT '难度',
duration int NOT NULL COMMENT '时长(分钟数)',
release_time datetime COMMENT '发布时间'
)CHARACTER SET utf8 COLLATE utf8_bin;
CREATE INDEX idx_duration ON examination_info(duration);
CREATE UNIQUE INDEX uniq_idx_exam_id ON examination_info(exam_id);
ALTER TABLE examination_info ADD FULLTEXT full_idx_tag(tag);

```

</details>

<details><summary>我的答案</summary>

```sql
ALTER TABLE examination_info 
DROP INDEX uniq_idx_exam_id, 
DROP INDEX full_idx_tag;
```

</details>

### SQL14 SQL类别高难度试卷得分的截断平均值
牛客的运营同学想要查看大家在SQL类别中高难度试卷的得分情况。


请你帮她从exam_record数据表中计算所有用户完成SQL类别高难度试卷得分的截断平均值（去掉一个最大值和一个最小值后的平均值）。
示例数据：examination_info（exam_id试卷ID, tag试卷类别, difficulty试卷难度, duration考试时长, release_time发布时间）

<details><summary>exam_record数据表</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220120163118.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220120163118.png';" /></details>

示例数据：exam_record（uid用户ID, exam_id试卷ID, start_time开始作答时间, submit_time交卷时间, score得分）

<details><summary>exam_record</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220120163132.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220120163132.png';" /></details>


根据输入你的查询结果如下：


<details><summary>查询结果</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220120163148.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220120163148.png';" /></details>

从examination_info表可知，试卷9001为高难度SQL试卷，该试卷被作答的得分有[80,81,84,90,50]，去除最高分和最低分后为[80,81,84]，平均分为81.6666667，保留一位小数后为81.7

**输入描述：**


输入数据中至少有3个有效分数

<details><summary>输入数据</summary>

```sql

drop table if exists examination_info;
CREATE TABLE  examination_info (
    id int PRIMARY KEY AUTO_INCREMENT COMMENT '自增ID',
    exam_id int UNIQUE NOT NULL COMMENT '试卷ID',
    tag varchar(32) COMMENT '类别标签',
    difficulty varchar(8) COMMENT '难度',
    duration int NOT NULL COMMENT '时长',
    release_time datetime COMMENT '发布时间'
)CHARACTER SET utf8 COLLATE utf8_general_ci;

drop table if exists exam_record;
CREATE TABLE exam_record (
    id int PRIMARY KEY AUTO_INCREMENT COMMENT '自增ID',
    uid int NOT NULL COMMENT '用户ID',
    exam_id int NOT NULL COMMENT '试卷ID',
    start_time datetime NOT NULL COMMENT '开始时间',
    submit_time datetime COMMENT '提交时间',
    score tinyint COMMENT '得分'
)CHARACTER SET utf8 COLLATE utf8_general_ci;

INSERT INTO examination_info(exam_id,tag,difficulty,duration,release_time) VALUES
  (9001, 'SQL', 'hard', 60, '2020-01-01 10:00:00'),
  (9002, '算法', 'medium', 80, '2020-08-02 10:00:00');

INSERT INTO exam_record(uid,exam_id,start_time,submit_time,score) VALUES
(1001, 9001, '2020-01-02 09:01:01', '2020-01-02 09:21:01', 80),
(1001, 9001, '2021-05-02 10:01:01', '2021-05-02 10:30:01', 81),
(1001, 9001, '2021-06-02 19:01:01', '2021-06-02 19:31:01', 84),
(1001, 9002, '2021-09-05 19:01:01', '2021-09-05 19:40:01', 89),
(1001, 9001, '2021-09-02 12:01:01', null, null),
(1001, 9002, '2021-09-01 12:01:01', null, null),
(1002, 9002, '2021-02-02 19:01:01', '2021-02-02 19:30:01', 87),
(1002, 9001, '2021-05-05 18:01:01', '2021-05-05 18:59:02', 90),
(1003, 9001, '2021-02-06 12:01:01', null, null),
(1003, 9001, '2021-09-07 10:01:01', '2021-09-07 10:31:01', 50);

-- 输出
-- SQL|hard|81.7
```

</details>

+ mysql中的[不等于](https://blog.csdn.net/qq_41946557/article/details/103466057)：在<>和！=是等价的。在某字段不等于某值（非空的值）时，输出的结果此字段为空不输出。is 和 is not 用于和 null 结合，我称它为不是，不是空
+ MYSQL中保留小数`ROUND(33.33,1)`

<details><summary>代码详情</summary>

```sql
SELECT tag, difficulty,ROUND(AVG(a.score), 1) AS clip_avg_score
FROM
    (
        SELECT 
            tag, 
            difficulty, 
            score
        FROM examination_info
        JOIN exam_record
        ON examination_info.exam_id = exam_record.exam_id
        WHERE score IS NOT NULL 
            AND difficulty='hard' 
            AND tag='SQL' 
    )a,
    (
        SELECT
            MAX(score) AS max_score, 
            MIN(score) AS min_score
        FROM examination_info
        JOIN exam_record
        ON examination_info.exam_id = exam_record.exam_id
        WHERE score IS NOT NULL 
            AND difficulty='hard' 
            AND tag='SQL' 
    )b
WHERE score != max_score AND score != min_score;

-- （总-大-小）/（数-2）
-- SELECT ei.tag,
--        ei.difficulty,
--        ROUND((SUM(er.score)-MIN(er.score)-MAX(er.score)) / (COUNT(er.score)-2),1) AS clip_avg_score
-- FROM examination_info ei,exam_record er
-- WHERE ei.exam_id = er.exam_id
--   AND ei.tag = "SQL"
--   AND ei.difficulty = "hard"; 
/** 
MYSQL 的 ROUND()函数
ROUND(X),返回参数 X 最近似的整数
ROUND(X,D),返回 X ,其值保留到小数点后 D 位,第 D 位的保留方式为四舍五入
**/

-- SELECT tag, difficulty, AVG(score) AS clip_avg_score
-- FROM 
-- (
--     SELECT 
--         tag, 
--         difficulty, 
--         score, 
--         MAX(score) AS max_score, 
--         MIN(score) AS min_score
--     FROM examination_info
--     JOIN exam_record
--     ON examination_info.exam_id = exam_record.exam_id
--     WHERE score IS NOT NULL 
--         AND difficulty='hard' 
--         AND tag='SQL' 
-- )a
-- WHERE score NOT IN (min_score, max_score);

-- SQL|hard|80.0000
```

</details>

### SQL15 统计作答次数
有一个试卷作答记录表exam_record，请从中统计出总作答次数total_pv、试卷已完成作答数complete_pv、已完成的试卷数complete_exam_cnt。

示例数据 exam_record表（uid用户ID, exam_id试卷ID, start_time开始作答时间, submit_time交卷时间, score得分）：

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220120170436.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220120170436.png';" /></details>

示例输出：

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220120170449.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220120170449.png';" /></details>

解释：表示截止当前，有11次试卷作答记录，已完成的作答次数为7次（中途退出的为未完成状态，其交卷时间和份数为NULL），已完成的试卷有9001和9002两份。

<details><summary>输入数据</summary>

```sql
drop table if exists exam_record;
CREATE TABLE exam_record (
    id int PRIMARY KEY AUTO_INCREMENT COMMENT '自增ID',
    uid int NOT NULL COMMENT '用户ID',
    exam_id int NOT NULL COMMENT '试卷ID',
    start_time datetime NOT NULL COMMENT '开始时间',
    submit_time datetime COMMENT '提交时间',
    score tinyint COMMENT '得分'
)CHARACTER SET utf8 COLLATE utf8_general_ci;

INSERT INTO exam_record(uid,exam_id,start_time,submit_time,score) VALUES
(1001, 9001, '2020-01-02 09:01:01', '2020-01-02 09:21:01', 80),
(1001, 9001, '2021-05-02 10:01:01', '2021-05-02 10:30:01', 81),
(1001, 9001, '2021-06-02 19:01:01', '2021-06-02 19:31:01', 84),
(1001, 9002, '2021-09-05 19:01:01', '2021-09-05 19:40:01', 89),
(1001, 9001, '2021-09-02 12:01:01', null, null),
(1001, 9002, '2021-09-01 12:01:01', null, null),
(1002, 9002, '2021-02-02 19:01:01', '2021-02-02 19:30:01', 87),
(1002, 9001, '2021-05-05 18:01:01', '2021-05-05 18:59:02', 90),
(1003, 9001, '2021-02-06 12:01:01', null, null),
(1003, 9001, '2021-09-07 10:01:01', '2021-09-07 10:31:01', 89),
(1004, 9001, '2021-09-06 12:01:01', null, null);
```

</details>



<details><summary>我的答案</summary>

```sql
SELECT 
    COUNT(exam_id) AS total_pv, 
    SUM(IF(submit_time IS NULL, 0, 1)) AS complete_pv, 
    MAX(complete_exam_cnt)
FROM 
    exam_record,
    (
        SELECT COUNT(DISTINCT exam_id) AS complete_exam_cnt
        FROM exam_record
        WHERE submit_time IS NOT NULL
    )a
    ;


-- https://blog.csdn.net/smallnine9/article/details/87857852
-- complete_exam_cnt加上聚合函数就好了
-- SELECT 
--     COUNT(exam_id) AS total_pv, 
--     SUM(IF(submit_time IS NULL, 0, 1)) AS complete_pv, 
--     complete_exam_cnt
-- FROM 
--     exam_record,
--     (
--         SELECT COUNT(DISTINCT exam_id) AS complete_exam_cnt
--         FROM exam_record
--         WHERE submit_time IS NOT NULL
--     )a
--     ;
-- SQL_ERROR_INFO: "In aggregated query without GROUP BY, expression #3 of SELECT list contains nonaggregated column 'a.complete_exam_cnt'; this is incompatible with sql_mode=only_full_group_by"

-- 法一：
-- SELECT
--     COUNT(start_time) AS total_pv,
--     COUNT(submit_time) AS complete_pv,
--     COUNT(DISTINCT exam_id AND score IS NOT NULL) AS complete_exam_cnt
-- FROM exam_record
-- 法二：
-- SELECT
--     COUNT(start_time) AS total_pv,
--     COUNT(submit_time) AS complete_pv,
--     COUNT(DISTINCT IF(score IS NOT NULL,exam_id,NULL)) AS complete_exam_cnt
--     FROM exam_record

```

</details>


### SQL16 得分不小于平均分的最低分


请从试卷作答记录表中找到SQL试卷得分不小于该类试卷平均得分的用户最低得分。

示例数据 exam_record表（uid用户ID, exam_id试卷ID, start_time开始作答时间, submit_time交卷时间, score得分）：

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220120204256.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220120204256.png';" /></details>

examination_info表（exam_id试卷ID, tag试卷类别, difficulty试卷难度, duration考试时长, release_time发布时间）

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220120204306.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220120204306.png';" /></details>

示例输出数据：

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220120204316.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220120204316.png';" /></details>

解释：试卷9001和9002为SQL类别，作答这两份试卷的得分有[80,89,87,90]，平均分为86.5，不小于平均分的最小分数为87

<details><summary>输入数据</summary>

```sql
drop table if exists examination_info;
CREATE TABLE  examination_info (
    id int PRIMARY KEY AUTO_INCREMENT COMMENT '自增ID',
    exam_id int UNIQUE NOT NULL COMMENT '试卷ID',
    tag varchar(32) COMMENT '类别标签',
    difficulty varchar(8) COMMENT '难度',
    duration int NOT NULL COMMENT '时长',
    release_time datetime COMMENT '发布时间'
)CHARACTER SET utf8 COLLATE utf8_general_ci;

drop table if exists exam_record;
CREATE TABLE  exam_record (
    id int PRIMARY KEY AUTO_INCREMENT COMMENT '自增ID',
    uid int NOT NULL COMMENT '用户ID',
    exam_id int NOT NULL COMMENT '试卷ID',
    start_time datetime NOT NULL COMMENT '开始时间',
    submit_time datetime COMMENT '提交时间',
    score tinyint COMMENT '得分'
)CHARACTER SET utf8 COLLATE utf8_general_ci;

INSERT INTO examination_info(exam_id,tag,difficulty,duration,release_time) VALUES
  (9001, 'SQL', 'hard', 60, '2020-01-01 10:00:00'),
  (9002, 'SQL', 'easy', 60, '2020-02-01 10:00:00'),
  (9003, '算法', 'medium', 80, '2020-08-02 10:00:00');

INSERT INTO exam_record(uid,exam_id,start_time,submit_time,score) VALUES
(1001, 9001, '2020-01-02 09:01:01', '2020-01-02 09:21:01', 80),
(1002, 9001, '2021-09-05 19:01:01', '2021-09-05 19:40:01', 89),
(1002, 9002, '2021-09-02 12:01:01', null, null),
(1002, 9003, '2021-09-01 12:01:01', null, null),
(1002, 9001, '2021-02-02 19:01:01', '2021-02-02 19:30:01', 87),
(1002, 9002, '2021-05-05 18:01:01', '2021-05-05 18:59:02', 90),
(1003, 9002, '2021-02-06 12:01:01', null, null),
(1003, 9003, '2021-09-07 10:01:01', '2021-09-07 10:31:01', 86),
(1004, 9003, '2021-09-06 12:01:01', null, null);

-- 输出
-- 87
```

</details>


<details><summary>我的答案</summary>

```sql
SELECT MIN(score) AS min_score_over_avg
FROM
(
    SELECT score
    FROM exam_record
    JOIN examination_info
    ON exam_record.exam_id = examination_info.exam_id
    WHERE tag='SQL' AND score IS NOT NULL
)a, 
(
    SELECT AVG(score) AS avg_score
    FROM exam_record
    JOIN examination_info
    ON exam_record.exam_id = examination_info.exam_id
    WHERE tag='SQL' AND score IS NOT NULL
)b
WHERE score >= avg_score;
```

</details>

### SQL17 平均活跃天数和月活人数
用户在牛客试卷作答区作答记录存储在表exam_record中，内容如下：

exam_record表（uid用户ID, exam_id试卷ID, start_time开始作答时间, submit_time交卷时间, score得分）

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220120212047.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220120212047.png';" /></details>

请计算2021年每个月里试卷作答区用户平均月活跃天数avg_active_days和月度活跃人数mau，上面数据的示例输出如下：

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220120212143.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220120212143.png';" /></details>

解释：2021年7月有2人活跃，共活跃了3天（1001活跃1天，1002活跃2天），平均活跃天数1.5；2021年9月有4人活跃，共活跃了5天，平均活跃天数1.25，结果保留2位小数。

注：此处活跃指有交卷行为。


<details><summary>输入数据</summary>

```sql
drop table if exists exam_record;
CREATE TABLE exam_record (
    id int PRIMARY KEY AUTO_INCREMENT COMMENT '自增ID',
    uid int NOT NULL COMMENT '用户ID',
    exam_id int NOT NULL COMMENT '试卷ID',
    start_time datetime NOT NULL COMMENT '开始时间',
    submit_time datetime COMMENT '提交时间',
    score tinyint COMMENT '得分'
)CHARACTER SET utf8 COLLATE utf8_general_ci;

INSERT INTO exam_record(uid,exam_id,start_time,submit_time,score) VALUES
(1001, 9001, '2021-07-02 09:01:01', '2021-07-02 09:21:01', 80),
(1002, 9001, '2021-09-05 19:01:01', '2021-09-05 19:40:01', 81),
(1002, 9002, '2021-09-02 12:01:01', null, null),
(1002, 9003, '2021-09-01 12:01:01', null, null),
(1002, 9001, '2021-07-02 19:01:01', '2021-07-02 19:30:01', 82),
(1002, 9002, '2021-07-05 18:01:01', '2021-07-05 18:59:02', 90),
(1003, 9002, '2021-07-06 12:01:01', null, null),
(1003, 9003, '2021-09-07 10:01:01', '2021-09-07 10:31:01', 86),
(1004, 9003, '2021-09-06 12:01:01', null, null),
(1002, 9003, '2021-09-01 12:01:01', '2021-09-01 12:31:01', 81),
(1005, 9001, '2021-09-01 12:01:01', '2021-09-01 12:31:01', 88),
(1006, 9002, '2021-09-02 12:11:01', '2021-09-02 12:31:01', 89);
```

</details>

### SQL17 平均活跃天数和月活人数
用户在牛客试卷作答区作答记录存储在表exam_record中，内容如下：

exam_record表（uid用户ID, exam_id试卷ID, start_time开始作答时间, submit_time交卷时间, score得分）

<details><summary>exam_record</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220120220609.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220120220609.png';" /></details>

请计算2021年每个月里试卷作答区用户平均月活跃天数avg_active_days和月度活跃人数mau，上面数据的示例输出如下：

<details><summary>图片详情</summary><img src="https://raw.githubusercontent.com/ednow/cloudimg/main/githubio/20220120220724.png" alt="找不到图片(Image not found)" onerror="this.onerror=null;this.src='https://gitee.com/ednow/cloudimg/raw/main/githubio/20220120220724.png';" /></details>

解释：2021年7月有2人活跃，共活跃了3天（1001活跃1天，1002活跃2天），平均活跃天数1.5；2021年9月有4人活跃，共活跃了5天，平均活跃天数1.25，结果保留2位小数。

注：此处活跃指有交卷行为。

<details><summary>输入数据</summary>

```sql
drop table if exists exam_record;
CREATE TABLE exam_record (
    id int PRIMARY KEY AUTO_INCREMENT COMMENT '自增ID',
    uid int NOT NULL COMMENT '用户ID',
    exam_id int NOT NULL COMMENT '试卷ID',
    start_time datetime NOT NULL COMMENT '开始时间',
    submit_time datetime COMMENT '提交时间',
    score tinyint COMMENT '得分'
)CHARACTER SET utf8 COLLATE utf8_general_ci;

INSERT INTO exam_record(uid,exam_id,start_time,submit_time,score) VALUES
(1001, 9001, '2021-07-02 09:01:01', '2021-07-02 09:21:01', 80),
(1002, 9001, '2021-09-05 19:01:01', '2021-09-05 19:40:01', 81),
(1002, 9002, '2021-09-02 12:01:01', null, null),
(1002, 9003, '2021-09-01 12:01:01', null, null),
(1002, 9001, '2021-07-02 19:01:01', '2021-07-02 19:30:01', 82),
(1002, 9002, '2021-07-05 18:01:01', '2021-07-05 18:59:02', 90),
(1003, 9002, '2021-07-06 12:01:01', null, null),
(1003, 9003, '2021-09-07 10:01:01', '2021-09-07 10:31:01', 86),
(1004, 9003, '2021-09-06 12:01:01', null, null),
(1002, 9003, '2021-09-01 12:01:01', '2021-09-01 12:31:01', 81),
(1005, 9001, '2021-09-01 12:01:01', '2021-09-01 12:31:01', 88),
(1006, 9002, '2021-09-02 12:11:01', '2021-09-02 12:31:01', 89);


-- drop table if exists exam_record;
-- CREATE TABLE  exam_record (
-- id int PRIMARY KEY AUTO_INCREMENT COMMENT '自增ID',
-- uid int NOT NULL COMMENT '用户ID',
-- exam_id int NOT NULL COMMENT '试卷ID',
-- start_time datetime NOT NULL COMMENT '开始时间',
-- submit_time datetime COMMENT '提交时间',
-- score tinyint COMMENT '得分'
-- )CHARACTER SET utf8 COLLATE utf8_general_ci;


-- INSERT INTO exam_record(uid,exam_id,start_time,submit_time,score) VALUES
-- (1001, 9001, '2021-07-02 09:01:01', '2021-07-02 09:21:01', 80),
-- (1002, 9001, '2021-09-05 19:01:01', '2021-09-05 19:40:01', 81),
-- (1002, 9002, '2021-09-02 12:01:01', null, null),
-- (1002, 9003, '2021-09-01 12:01:01', null, null),
-- (1002, 9001, '2021-07-02 19:01:01', '2021-07-02 19:30:01', 82),
-- (1002, 9002, '2021-07-05 18:01:01', '2021-07-05 18:59:02', 90),
-- (1003, 9002, '2021-07-06 12:01:01', null, null),
-- (1003, 9003, '2021-09-07 10:01:01', '2021-09-07 10:31:01', 86),
-- (1004, 9003, '2021-09-06 12:01:01', null, null),
-- (1002, 9003, '2021-09-01 12:01:01', '2021-09-01 12:31:01', 81),
-- (1005, 9001, '2021-09-01 12:01:01', '2021-09-01 12:31:01', 88),
-- (1005, 9002, '2021-09-01 12:01:01', '2021-09-01 12:31:01', 88),
-- (1006, 9002, '2021-08-02 12:11:01', '2021-08-02 12:31:01', 89);

-- SELECT * FROM exam_record
-- WHERE submit_time IS NOT NULL
-- 	AND MONTH(start_time) = 9
-- ;
```

</details>



<details><summary>我的答案</summary>

```sql
-- SELECT 
--     `month`,
--     ROUND(MAX(active) / COUNT(DISTINCT a.uid), 2) AS avg_active_days,
--     COUNT(DISTINCT a.uid) AS mau
-- FROM (
--     SELECT
--     DATE_FORMAT(start_time, '%Y%m') AS `month`,
--     start_time,
--     uid
--     FROM exam_record
--     WHERE submit_time IS NOT NULL
-- ) a
-- JOIN
-- (
--     SELECT 
--         COUNT(DISTINCT DAY(start_time)) AS active,
--         uid
--     FROM exam_record
--     WHERE submit_time IS NOT NULL
--     GROUP BY MONTH(submit_time), uid
-- ) b
-- ON a.uid = b.uid
-- GROUP BY `month`;

-- SELECT 
--     `month`,
--     ROUND(COUNT(DISTINCT DAY(start_time)) OVER (PARTITION BY uid) / COUNT(DISTINCT uid), 2) AS avg_active_days,
--     COUNT(DISTINCT uid) AS mau
-- FROM (
--     SELECT
--     DATE_FORMAT(start_time, '%Y%m') AS `month`,
--     start_time,
--     uid,
--     id
--     FROM exam_record
--     WHERE submit_time IS NOT NULL
-- ) a
-- GROUP BY `month`;

-- SQL_ERROR_INFO: "This version of MySQL doesn't yet support '<window function>(DISTINCT ..)'"


-- 范例过了，过不了测试用例，一个人可能在一天内上线多次，但只计算一次
-- SELECT 
--     `month`,
--     ROUND(COUNT(start_time) / COUNT(DISTINCT uid), 2) AS avg_active_days,
--     COUNT(DISTINCT uid) AS mau
-- FROM (
--     SELECT
--     DATE_FORMAT(start_time, '%Y%m') AS `month`,
--     start_time,
--     uid,
--     id
--     FROM exam_record
--     WHERE submit_time IS NOT NULL
-- ) a
-- GROUP BY `month`;

-- 参考文献
-- https://stackoverflow.com/questions/41887460/select-list-is-not-in-group-by-clause-and-contains-nonaggregated-column-inc#:~:text=then%20you%20can,any%20other%20column
-- 只能选择group by的列和其他列配合聚合函数
-- SELECT 
--     DATE_FORMAT(start_time, '%Y%m') AS `month`,
--     COUNT(start_time) / COUNT(DISTINCT uid) AS avg_active_days,
--     COUNT(DISTINCT uid) AS mau
-- FROM exam_record
-- GROUP BY MONTH(start_time);

-- SQL_ERROR_INFO: "Expression #1 of SELECT list is not in GROUP BY clause and contains nonaggregated column 'exam_record.start_time' which is not functionally dependent on columns in GROUP BY clause; this is incompatible with sql_mode=only_full_group_by"
```

</details>