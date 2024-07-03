//
// Created by Administrator on 2024/5/16.
//
#include "vector.h"
#include "iostream"

using namespace std;
void test_vector1(){
    lwh::vector<int> s;
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);
    s.push_back(4);
    s.push_back(5);
    s.push_back(6);
    for(int i = 0;i<s.size();i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
    lwh::vector<int>::iterator it = s.begin();
    while (it!=s.end()){
//        *it *=10;
        cout<<*it++<<" ";
    }
    cout<<endl;
    for(auto ch:s)
        cout<<ch<<" ";
    cout<<endl;


//    for(auto its=s.begin();its!=s.end();its++){
//        if(*it%2==0){
//            s.erase(its);
//        }
//    }
//    for(auto ch:s)
//        cout<<ch<<" ";
//    cout<<endl;
}
void test_vector2(){
    lwh::vector<int> s;
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);
    s.push_back(4);
    s.push_back(5);
    s.push_back(6);

    for(auto ch:s){
        cout<<ch<<" ";
    }
    cout<<endl;

    for(auto it=s.begin();it!=s.end();it++){
        if(*it%2==0)
            it = s.erase(it)-1;
    }
//    s.erase(s.begin()+2);
    for(auto ch:s){
        cout<<ch<<" ";
    }
    cout<<endl;
}
void test_vector3(){
    lwh::vector<int> s;
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);
    s.push_back(4);
    s.push_back(5);
    auto it = s.crbegin();
    while (it!=s.crend()){
        cout<<*it<<' ';
        it++;
    }

}
int main(){
    test_vector3();
    return 0;
}