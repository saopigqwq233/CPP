迭代器有区别，和底层实现有关系
#### 性质分类
##### 单向
1.只支持 ++  
单链表、哈希表
##### 双向 Bidirectional
支持++和--  
双向链表、红黑树(map\set)
##### 随机  RandomAccessIterator
支持++   --  +  -  
顺序容器一般都支持



##### 迭代器无需析构
不需要释放迭代器指向空间  
不需要深拷贝
##### ->运算符重载
调用时隐藏了一个->


### const 迭代器
#### const iterator 不可以
这样修饰的是迭代器本身，it++是不被允许的



