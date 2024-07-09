//
// Created by Administrator on 24-7-10.
//

#ifndef HASH_HASHTABLE_H
#define HASH_HASHTABLE_H
#include "iostream"
#include "vector"


namespace lwh{
    enum Status{
        EMPTY,
        EXIST,
        DELETE
    };

    template<class K,class V>
    struct HashData{
        std::pair<K,V> _kv;
        Status _s;
    };

    template<class K,class V>
    class HashTable{
    public:
        HashTable(){
            _tables.resize(10);
        }
        bool Insert(const std::pair<K,V>&kv){
            if(_n*7/_tables.size()<0.7){
            //扩容不能直接resize，以前的EXIST结点的数据位子是旧的size,
            // 需要重新映射
                int newSize = _tables.size();
                HashTable<K,V> newHT;
                newHT._tables.resize(newSize);
                for(size_t i = 0;i<_tables.size();i++){
                    if(_tables[i]._s==EXIST){
                        newHT._tables.insert(_tables[i]._kv);
                    }
                }
                _tables.swap(newHT._tables);
            }

            size_t hashi = kv.first%_tables.size();
            while (_tables[hashi]._s==EXIST){
                hashi+=1;
                hashi%=_tables.size();
            }
            _tables[hashi]._kv=kv;
            _tables[hashi]._s=EXIST;
            ++_n;
            return true;
        }



    private:
        std::vector<HashData<K,V>> _tables;
        int _n;//负载因子
    };






}










#endif //HASH_HASHTABLE_H
