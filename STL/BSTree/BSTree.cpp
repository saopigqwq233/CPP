//
// Created by Administrator on 24-7-4.
//

#include "BSTree.h"
int main(){
    lwh1::BSTree<int> s;
    s.insert(1);

    s.insert(4);

    s.insert(7);
    s.insert(6);
    s.insert(3);
    s.insert(10);
    s.insert(14);
    s.insert(13);
    s.insert(8);

    s.InOrder();
    auto p (s);
//    cout<<s.Find(10)<<' ';

//    s.erase(10);
//    s.InOrder();
//
//    s.erase(1);
//    s.InOrder();

    s.erase(8);
    s.InOrder();

    s.erase(13);
    s.InOrder();

    s.erase(6);
    s.InOrder();

    s.erase(7);
    s.InOrder();
    p=s;
    p.InOrder();
    return 0;

}