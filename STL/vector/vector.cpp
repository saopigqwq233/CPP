//
// Created by Administrator on 2024/5/16.
//
#include "vector.h"
#include "iostream"

using namespace std;

int main(){
    lwh::vector<int> s;
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);
    s.push_back(4);
    s.push_back(5);
    s.push_back(6);
    for(int i = 0;i<s.size();i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
    lwh::vector<int>::iterator it = s.begin();
    while (it!=s.end()){
        *it *=10;
        cout<<*it++<<" ";
    }
    cout<<endl;
    for(auto ch:s)
        cout<<ch<<" ";
    cout<<endl;
    return 0;
}