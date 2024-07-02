//
// Created by Administrator on 2024/5/18.
//
#include "stl_list.h"
#include "vector"
#include "deque"
template<typename Container>
void print_container(const Container container1){
    typename Container::const_iterator it = container1.begin();
    while (it!= container1.end()){
        cout<<*it<<' ';
        ++it;
    }
    cout<<endl;
}


void test1(){
    lwh::list<int> s;
    s.push_back(12);
    s.push_back(20);
    s.push_back(30);
    s.push_back(100);
//    for(auto e:s)
//        cout<<e<<" ";
//    cout<<endl;
//    lwh::list<int> r;
//    r=s;
//    for(auto e:r)
//        cout<<e<<' ';
//    cout<<endl;
//    cout<<r.size()<<endl;
    print_container(s);
    vector<string> s1;
    s1.push_back("111111");
    s1.push_back("222222");
    s1.push_back("333333");
    s1.push_back("444444");
    s1.push_back("555555");
    print_container(s1);
}
int main(){
    test1();
}