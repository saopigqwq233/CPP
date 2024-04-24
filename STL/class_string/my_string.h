//
// Created by Administrator on 2024/3/29.
//

#ifndef CLASS_STRING_MY_STRING_H
#define CLASS_STRING_MY_STRING_H
#include "errno.h"
#include <cstring>
#include <cassert>
namespace my{
    class string{
    public:
//        迭代器
    typedef char* iterator;
    typedef const char* const_iterator;
    iterator begin(){return _str;}
    iterator end(){return _str+_size;}
    const_iterator begin()const{return _str;}
    const_iterator end()const{return _str+_size;}
//         成员
    private:
        char *_str;
        size_t _size;
        size_t _capacity;
    public:
        string(const char* str="")
        :_size(strlen(str)),
        _capacity(_size+1){
            _str = new char[_capacity+1];
            strcpy(_str,str);
        }
        ~string(){
            delete[] _str;
            _str = nullptr;
            _size = _capacity = 0;
        }
        const char*  c_str()const{
            return _str;
        }
        size_t size()const{ return _size;}
        size_t capacity()const{return _capacity;}
        void reserve(size_t n){
            if(n>_capacity){
                char *temp = new char[n+1];
                strcpy(temp,_str);
                delete[] _str;
                _str = temp;
                _capacity = n;
            }
        }


//        elements access
        char &operator[](size_t pos){
            assert(pos<_size);
            return _str[pos];
        }
        const char &operator[](size_t pos)const{
            assert(pos<_size);
            return _str[pos];
        }
//        modify
        void push_back(char ch){
            if(_size==_capacity){
                reserve(_capacity*2);
            }
            _str[_size++] = ch;
            _str[_size] = '\0';
        }
        void append(const char* str){
            size_t len = strlen(str);
            if(_size + len>_capacity){
                reserve(_size+len);
            }
            strcpy(_str+_size,str);
            _size += len;
        }
        string&operator+=(char ch){
            push_back(ch);
            return *this;
        }
        string&operator+=(const char*str){
            append(str);
            return *this;
        }
        bool operator<(const string &s)const{
            return strcmp(_str,s.c_str())<0;
        }
        bool operator==(const string &s)const{
            return strcmp(_str,s.c_str())==0;
        }
        bool operator<=(const string &s)const{
            return *this<s||*this==s;
        }
        bool operator>(const string &s)const{
            return !(*this<=s);
        }
        bool operator>=(const string &s)const{
            return !(*this<s);
        }
        bool operator!=(const string &s)const{
            return !(*this==s);
        }



    };
//        io
    ostream& operator<<(ostream&out,const string&s){
        for (char i : s) {
            out<<i;
        }
        return out;
    }
    istream& operator>>(istream&in,string&s){
        char c;
        cin>>c;
        while (c!=' '&&c!='\n'){
            s+=c;
            in>>c;
        }
        return in;
    }




    void test_string(){
        string s("hello world");
//        cout<<s.c_str()<<endl;
//        cout<<s.size()<<endl;
//        cout<<s.capacity()<<endl;
//
//        for (int i = 0; i < s.size(); ++i) {
//            cout<<s[i]<<" ";
//        }
//        cout<<endl;
//
//
//        my::string::iterator it = s.begin();
//        while (it!=s.end())
//            cout<<*it++<<" ";
//        cout<<endl;
//        for(auto i:s){
//            cout<<i<<" ";
//        }
//        cout<<endl;
        string s1;
        s1+='^';
        s1+="kkkkkk";
        s1 = s;
        cout<<s<<endl;
        cout<<s1<<endl;
        cout<<(s>=s1)<<endl;


    }
    void test2(){
        string s;
        cin>>s;
        cout<<s;
    }
}


#endif //CLASS_STRING_MY_STRING_H
