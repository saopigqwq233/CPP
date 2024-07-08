//
// Created by Administrator on 24-7-8.
//

#ifndef SET_MAP_MYMAP_H
#define SET_MAP_MYMAP_H
#include "RBTree.h"

namespace lwh{
    template<class K,class V>
    class map{
        struct KeyofT{
            const K& operator()(const pair<K,V>&kv){
                return kv.first;
            }
        };
        typedef map<K,V> Self;
        typedef pair<const K,V> data_type;
        typedef RBTree<K,data_type ,KeyofT> Base;
    public:
        typedef typename Base::iterator iterator;
        iterator begin()
        {
            return _tree.begin();
        }

        iterator end()
        {
            return _tree.end();
        }
        bool insert(const pair<K,V>&d){
            return _tree.insert(d);
        }
        void InOrder(){
            _tree.InOrder();
        }

    private:
        Base _tree;
    };





}
#endif //SET_MAP_MYMAP_H
