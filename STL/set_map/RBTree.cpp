//
// Created by Administrator on 24-7-7.
//

#include "RBTree.h"
int main(){
    RBTree<int,int>s;
    int a[] = {3,7,1,9,8,0,4};
    for(auto i:a){
        s.insert(make_pair(i,i));
    }
    s.InOrder();
    return 0;


}