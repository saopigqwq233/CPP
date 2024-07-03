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

    auto it = s.crbegin();
    while (it!=s.crend()){
        cout<<*it<<' ';
        it++;
    }
//    for(auto e:s)
//        cout<<e<<" ";
//    cout<<endl;
//    lwh::list<int> r;
//    r=s;
//    for(auto e:r)
//        cout<<e<<' ';
//    cout<<endl;
//    cout<<r.size()<<endl;

}
int main(){
    test1();
}