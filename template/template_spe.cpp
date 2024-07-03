//
// Created by Administrator on 24-7-3.
//
#include "iostream"
using namespace std;


template<typename A,typename B>
class Test{
public:
    Test(){
        cout<<"A  and  B"<<endl;
    }
};
//全特化
template<>
class Test<double,int>{
public:
    Test(){
        cout<<"double  and  int"<<endl;
    }
};
//偏特化
template<typename B>
class Test<int,B>{
public:
    Test(){
        cout<<"int  and  B"<<endl;
    }
};
template<typename B>
class Test<double,B>{
public:
    Test(){
        cout<<"double  and  B"<<endl;
    }
};
//范围特化
template<typename A,typename B>
class Test<A*,B*>{
public:
    Test(){
        cout<<"APtr  and  BPtr"<<endl;
    }
};
void test(){
    Test<char,double>t1;
    Test<double,int>t2;
    Test<double*,int*>t3;
}

template<typename T>
T Add(const T&a,const T&b);

template<>
int Add<int>(const int&a,const int&b){
    return a+b;
}


int main(){
    Add(1,1);


    return 0;
}



