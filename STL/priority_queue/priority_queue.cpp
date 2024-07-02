//
// Created by Administrator on 24-7-2.
//
#include "priority_queue.h"
#include "iostream"
#include "deque"


void test(){
    lwh::priority_queue<int> p;
    p.push(1);
    p.push(4);
    p.push(7);
    p.push(9);
    p.push(2);

    while (!p.empty()){
        std::cout<<p.top()<<' ';
        p.pop();
    }


}
int main(){
    test();
    return 0;
}