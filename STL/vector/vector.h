//
// Created by Administrator on 2024/5/16.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <cstddef>
#include <cassert>
#include <cstring>

namespace lwh{
    template<typename T>
    class vector{
    public:
        typedef T* iterator;
        typedef const T* const_iterator;
        //构造后，数据空间均为空
        vector():
        _start(nullptr),
        _finish(nullptr),
        _endofstorage(nullptr){}

        ~vector(){
            delete[] _start;
            _start = _finish = _endofstorage = nullptr;
        }
        //基本信息函数
        size_t size(){ return _finish - _start;}
        size_t capacity(){ return _endofstorage - _start; }
        T& operator[](size_t pos){
            assert(pos<size());
            return _start[pos];
        }
        const T& operator[](size_t pos)const{
            assert(pos<size());
            return _start[pos];
        }
        void push_back(const T& val){
            if(_finish==_endofstorage){
                size_t sz = size();
                size_t capacity = this->capacity() == 0?4: this->capacity()*2;
                T* tmp = new T[capacity];
                if(_start){//插入数据过
                    memcpy(tmp,_start,sz*sizeof (T));
                    delete[] _start;
                }
                _start = tmp;
                _finish = _start+sz;
                _endofstorage = _start+capacity;
            }
            *_finish = val;
            ++_finish;
        }
//迭代器
        iterator& begin(){return _start;}
        iterator& end(){return _finish;}
        const_iterator cbegin()const{return _start;}
        const_iterator cend()const{return _finish;}

    private:
        iterator _start;
        iterator _finish;
        iterator _endofstorage;
    };
}





#endif //VECTOR_VECTOR_H
