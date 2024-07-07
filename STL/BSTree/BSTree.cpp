//
// Created by Administrator on 24-7-4.
//

#include "BSTree.h"
#include "KVBSTree.h"
#include "string"
int main(){
    kv::KVBSTree<string,int> s;
    s.insert("刘文淏",1);
    s.insert("刘文淏",1);
    s.insert("张三",5);
    s.insert("李四",3);
    s.InOrder();

    cout<<s.Find("刘文淏")->_value<<endl;

    s.erase("李四");
    s.InOrder();
}