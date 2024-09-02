//
// Created by Administrator on 24-7-10.
//

#include "HashTable.h"
#include "mymap.h"

int main() {
//    hash_bucket::HashTable<int,int> h;
//    int a[]={4,14,24,8,7,3,2,11,9,0,5,6,42};
//    for(auto i:a){
//        h.Insert(std::pair<int,int>(i,i));
//    }
//    h.Print();
    my::unordered_map<string,int> mm;
    mm.insert(std::make_pair("刘文淏",2));
    mm.insert(std::make_pair("张三",2));
    my::unordered_map<string,int>::iterator it = mm.begin();
    for(;it!=mm.end();++it){
        std::cout<<it->first<<" "<<it->second<<endl;
    }

    return 0;
}
