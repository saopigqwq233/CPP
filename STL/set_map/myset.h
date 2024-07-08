//
// Created by Administrator on 24-7-8.
//

#ifndef SET_MAP_MYSET_H
#define SET_MAP_MYSET_H

#include "RBTree.h"
namespace lwh {
    template<class K>
    class set{
        struct KeyofT{
            const K& operator()(const K&k){
                return k;
            }//提取仿函数

        };


        typedef set<K> Self;
        typedef RBTree<K,K,KeyofT> Base;



    public:
        typedef typename Base::iterator iterator;
        iterator begin(){
            return _tree.begin();
        }
        iterator end(){
            return _tree.end();
        }
        bool insert(const K&k){
            return _tree.insert(k);
        }
        void InOrder(){
            _tree.InOrder();
        }
    private:

        Base _tree;


    };

}

#endif //SET_MAP_MYSET_H
