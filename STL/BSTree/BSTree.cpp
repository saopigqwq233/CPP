//
// Created by Administrator on 24-7-4.
//

#include "BSTree.h"
#include "KVBSTree.h"
#include "string"
int main(){
    kv::KVBSTree<string,int> s;
    s.insert("���ĜB",1);
    s.insert("���ĜB",1);
    s.insert("����",5);
    s.insert("����",3);
    s.InOrder();

    cout<<s.Find("���ĜB")->_value<<endl;

    s.erase("����");
    s.InOrder();
}