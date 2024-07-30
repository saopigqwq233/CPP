//
// Created by Administrator on 2024/5/16.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <cstddef>
#include <cassert>
#include <string>
template<typename Iterator,class Ptr,class Ref>
struct Reverseiterator{
public:
    typedef Reverseiterator<Iterator,Ptr,Ref> Self;
    Reverseiterator(Iterator it):_it(it){}
    Self& operator++(){
        return --_it;
    }
    Self& operator--(){
        return ++_it;
    }
    Self operator++(int){
        Self tmp(_it);
        --_it;
        return tmp;
    }
    Self operator--(int){
        Self tmp(_it);
        ++_it;
        return tmp;
    }
    Ref operator*()const{
        return *_it;
    }
    Ptr operator->()const{
        return _it.operator->();
    }
    bool operator==(const Self&it){
        return _it==it._it;
    }
    bool operator!=(const Self&it){
        return _it!=it._it;
    }
private:
    Iterator _it;
};
namespace lwh{
    template<typename T>
    class vector{
    public:
        typedef T* iterator;
        typedef const T* const_iterator;

        typedef Reverseiterator<iterator,T*,T&> reverse_iterator;
        typedef Reverseiterator<const_iterator ,const T*,const T&> const_reverse_iterator;
        //构造后，数据空间均为空
        vector():
        _start(nullptr),
        _finish(nullptr),
        _endofstorage(nullptr){}
        //拷贝构造
        vector(const vector<T>&v):
                _start(nullptr),
                _finish(nullptr),
                _endofstorage(nullptr){
            reserve(v.capacity());
            for(auto &e:v){
                push_back(e);
            }
        }
        vector<T>& operator=(vector<T>tmp){
            swap(tmp);
            return *this;
        }
        //迭代器区间构造
        template<class InputIterator>
        vector(InputIterator first,InputIterator last):_start(nullptr),
                                                       _finish(nullptr),
                                                       _endofstorage(nullptr)
        {
            if(capacity()==0)
                reserve(4);
            while (first!=last){
                push_back(*first);
                ++first;
            }
        }
        //n值构造
        vector(size_t n,const T& val=T()){
            reserve(n);
            for (int i = 0; i < n; ++i) {
                push_back(val);
            }
        }
        vector(int n,const T& val=T()){
            reserve(n);
            for (int i = 0; i < n; ++i) {
                push_back(val);
            }
        }
        vector(std::initializer_list<T>il):
            _start(nullptr),
            _finish(nullptr),
            _endofstorage(nullptr){
            reserve(il.size());
            for(auto&e:il){
                push_back(e);
            }
        }
        void swap(vector<T>&v){
            std::swap(_start,v._start);
            std::swap(_finish,v._finish);
            std::swap(_endofstorage,v._endofstorage);
        }
        ~vector(){
            delete[] _start;
            _start = _finish = _endofstorage = nullptr;
        }
        //基本信息函数
        size_t size(){ return _finish - _start;}
        size_t capacity()const{ return _endofstorage - _start; }
        T& operator[](size_t pos){
            assert(pos<size());
            return _start[pos];
        }
        const T& operator[](size_t pos)const{
            assert(pos<size());
            return _start[pos];
        }
        void push_back(const T& val){
//            if(_finish==_endofstorage){
//                reserve(capacity()==0?4:capacity()*2);
//            }
//            *_finish = val;
//            ++_finish;
            insert(_finish,val);
        }
        void reserve(size_t n){
            if(n>capacity()){
                T* tmp = new T[n];
                size_t sz = size();
                if(_start){
//                    memcpy(tmp,_start,sz*sizeof (T));
                    for (int i = 0; i < size(); ++i) {
                        tmp[i] = _start[i];
                    }
                    delete[] _start;
                }
                _start = tmp;
                _finish = _start+sz;
                _endofstorage = _start+n;
            }
        }
        void resize(size_t n,const T& val=T()){
            if(n<size())
                _finish = _start+n;
            else{
                reserve(n);
                while (_finish!=_start+n){
                    *_finish = val;
                    ++_finish;
                }
            }
        }
        iterator insert(iterator pos,const T& val){
            assert(pos>=_start);
            assert(pos<=_finish);
            size_t len = pos-_start;
            //移动
            if(_finish == _endofstorage)
                reserve(capacity()==0?4:capacity()*2);

            pos = _start+len;
            iterator end = _finish-1;
            while (end>=pos){
                *(end+1) = *end;
                --end;
            }
            *pos = val;
            ++_finish;
            return pos;
        }
        iterator erase(iterator it){
            assert(it<_finish);
            assert(it>=_start);
            iterator ret = it;
            ++it;

            while (it!=_finish){
                *(it-1) = *it;
                ++it;
            }
            --_finish;
            return ret;
        }
//迭代器
        iterator& begin(){return _start;}
        iterator& end(){return _finish;}

        const_iterator cbegin()const{return _start;}
        const_iterator cend()const{return _finish;}

        reverse_iterator rbegin(){return reverse_iterator(end()-1);}
        reverse_iterator rend(){return reverse_iterator(begin()-1);}
        const_reverse_iterator crbegin()const{return const_reverse_iterator(cend()-1);}
        const_reverse_iterator crend()const{return const_reverse_iterator (cbegin()-1);}
    private:
        iterator _start;
        iterator _finish;
        iterator _endofstorage;
    };
}


#endif //VECTOR_VECTOR_H
