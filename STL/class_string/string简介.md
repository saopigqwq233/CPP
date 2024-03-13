# C++ string类简介
C++ string类存储一个字符串，并包含多种方法
## 一、初始化

- C++ string类有多种初始化方法：
- 空初始化
- 复制构造
- 子串构造（下标+长度型）
- 数组构造（接受字符数组）
- 填充构造  
```c++
void test1(){
    //空构造
    string s1;
    //拷贝构造
    string s2(s1);
    string s3 = s1;
    //数组构造
    string s4("abcdefg");
    //子串构造
    string s5(s4,3,4);
    //填充构造
    string s6(10,'a');
}
```
## 二、流插入提取操作
string类已经实现流插入和提取操作
```c++
void test2(){
    string s1("abcdefg");
    cout<<"s1:"<<s1<<endl;
    string s2;
    cin>>s2;
    cout<<"s2:"<<s2<<endl;
}
int main(){
    test2();
    return 0;
}
```
运行结果：
```shell
s1:abcdefg
asd
s2:asd
进程已结束，退出代码为 0
```
- 需要注意的是，cin默认输入到空格和换行结束
```c++
void test3(){
    string s1;
    cin>>s1;
    cout<<s1;
}
int main(){
    test3();
    return 0;
}
```
运行结果：
```shell
abc def g
abc
进程已结束，退出代码为 0
```
可以看出，如果输入的有空格，那么cin将停止读取，只保存空格之前的字符（不包含空格）  
如果想要保存整个一行的内容，需要用到方法getline  
```c++
void test4(){
    string s1;
    getline(cin,s1);
    cout<<s1<<endl;
}
int main(){
    test4();
    return 0;
}
```
运行结果：
```shell
abc def g
abc def g
进程已结束，退出代码为 0
```
## 二、迭代器
string类，以及C++其它容器，都具有迭代器  。
可以把迭代器想象是指向容器单个元素的指针，并且可以顺序得遍历容器元素。
迭代器可以分为以下4类：
- 正向迭代器
- 逆向迭代器
- 常正向迭代器
- 常逆向迭代器
### 1.正向迭代器
```c++
void test5(){
    string s1("abcdefgh");
    for(auto i = s1.begin();i!=s1.end();i++){
        cout<<*i<<'&';
    }
    cout<<endl;
    for (auto i = s1.end(); i != s1.begin() ; --i) {
        cout<<*i<<'*';
    }
    cout<<endl;
}
int main(){
    test5();
    return 0;
}
```
运行结果：
```shell
a&b&c&d&e&f&g&h&
 *h*g*f*e*d*c*b*

进程已结束，退出代码为 0
```
从上可以看出，正向迭代器从begin到end是一个左闭右开的范围，且迭代器之间最好不要写大于小于号，
因为除了string这样可能是连续存储，其它容器可能是非连续存储，大于小于无法用于判别谁先谁后
### 2.逆向迭代器
```c++
void test6(){
    string s1("abcdefgh");
    for(auto i = s1.rbegin();i!=s1.rend();i++){
        cout<<*i<<"&";
    }
    cout<<endl;
    for(auto i = s1.rend();i!=s1.rbegin();i--){
        cout<<*i<<"*";
    }
    cout<<endl;
}
int main(){
    test6();
    return 0;
}
```
运行结果：
```shell
h&g&f&e&d&c&b&a&
 *a*b*c*d*e*f*g*

进程已结束，退出代码为 0
```
同样是左闭右开
### 3.常迭代器
常迭代器类似于迭代器，只不过不能常迭代器修改指向元素
## 三、内存空间操作

## 四、取值操作
## 五、增、删、查、改操作
## 六、兼容C部分