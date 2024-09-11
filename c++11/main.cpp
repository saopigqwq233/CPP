#include <iostream>
<<<<<<< HEAD

using namespace std;

double multi(int a,int b){
    if(b==0){
        throw "��0����";
    }
    else{
        return (double )a/b;
    }
}

void test(){
    int x,y;
    cin>>x>>y;
    try {
        cout<<multi(x,y);
    }
    catch(const char *str) {
        cout<<str<<endl;
    }

}

int main() {
    test();
    return 0;

=======
#include "vector"
using namespace std;
void test1(){
//获取类型
//1
    //获取类型的字符串形式
    int i = 2;
    double j = 3.14;
    auto ret = i*j;
    cout<<typeid(i).name()<<endl;
    cout<<typeid(j).name()<<endl;
    cout<<typeid(ret).name()<<endl;
//2
    //获取类型
    vector<decltype(ret)> v;

}

//void test2(){
//    //能取地址是左值
//    //不能取地址是右值
//}

class Test{
public:
    Test(){
        cout<<"空构造"<<endl;
    }
    Test(const Test& t){
        cout<<"拷贝构造"<<endl;
    }

};
int main() {

    test1();
    return 0;
>>>>>>> 3703c73099b2d9959226cbf0002ac7e8caecf0c3
}
