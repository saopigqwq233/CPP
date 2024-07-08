//
// Created by Administrator on 24-7-8.
//

#include "mymap.h"
int main(){
    lwh::map<int,string> s;

    int a[6]={3,7,1,5,4,8};
    s.insert(make_pair(1,"z"));
    s.insert(make_pair(5,"a"));
    s.insert(make_pair(2,"dx"));
    s.insert(make_pair(9,"ea"));
    s.insert(make_pair(8,"xa"));
    s.insert(make_pair(3,"qa"));
    for(auto e:a){
        s.insert(make_pair(e,"w"));
    }
    for(auto &e:s){
        cout<<e.first<<':'<<e.second<<endl;
    }
    return 0;

}