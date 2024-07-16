//
// Created by Administrator on 24-7-10.
//

#include "HashTable.h"
int main() {
    lwh::HashTable<int,int> h;
    int a[]={4,14,24,8,7,3,2,11,9,0,5,6,42};
    for(auto i:a){
        h.Insert(std::pair<int,int>(i,i));
    }
    return 0;
}
