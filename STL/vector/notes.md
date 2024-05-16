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