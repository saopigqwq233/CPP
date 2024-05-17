## vector 
1. capacity mingw1.5倍扩容，g++2倍扩容
2. reserve让capacity变，resize改变size，字符串默认初始化为\'\0' ，方括号访问--0到size（）间，否则断言 Outofrange，
3. shrink_to_fit 异地缩容


## 实现
### push_back
#### 1.检查扩容
##### 2.更新capacitys
##### 3.异地开空间
##### 4.如果——start不为空，拷贝数据
##### 5.删除原数据空间，更新指针
#### 6.结尾指针=新数据
#### 7.跟新结尾指针

const   
##### 迭代器，const修饰类型T
##### [] 访问也需要实现

reserve

resize 缺省值
内置类型 也有构造  

### 迭代器失效  
#### insert(iterator pos,const T& val)
注意insert内扩容后pos未更新造成野指针问题
一方面，函数内部若pos未更新*pos越界
另一方面，函数外部，实参失效
不需要在实现函数时使用迭代器引用，传值调用会存在零时变量具有常性导致编译不通过  
如  insert(s.begin(),1)  s.begin()返回的是临时变量


#### erase
vs2019强制检查 erase后it失效，访问就报错


