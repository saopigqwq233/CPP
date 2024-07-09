//
// Created by Administrator on 24-7-8.
//

#include "mymap.h"
int main(){
    lwh::map<int,string> s;

    int a[6]={3,7,1,5,4,8};
    s.insert(make_pair(1,string("z")));
    s.insert(make_pair(5,string("a")));
    s.insert(make_pair(2,string("dx")));
    s.insert(make_pair(9,string("ea")));
    s.insert(make_pair(8,string("xa")));
    s.insert(make_pair(3,string("qa")));
    for(auto &e:s){
        cout<<e.first<<':'<<e.second<<endl;
    }
//    cout<<s.Find(9).second<<s.Find(9).first->second<<endl;
    s[10]="aaa";
    s[1]="a";
    cout<<s[1]<<endl;

return 0;
}