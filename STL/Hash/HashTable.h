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
        DELETE//这个状态是必须的，否则删除一个点滞空后会导致后面的结点找不到
    };

    template<class K,class V>
    struct HashData{
        std::pair<K,V> _kv;
        Status _s;
    };

    template<class K,class V>
    class HashTable{
    public:
        HashTable():_n(0){
            _tables.resize(10);
        }
        HashData<K,V>*Find(const K&key){
            size_t hashi = key%_tables.size();
            while (_tables[hashi]._s!=EMPTY){
                if(_tables[hashi]._s!=EMPTY&&_tables[hashi]._kv.first==key){
                    return &_tables[hashi];
                }
                ++hashi;
                hashi%=_tables.size();
            }
            return nullptr;
        }
        bool Insert(const std::pair<K,V>&kv){
            if(Find(kv.first))
                return false;
            if(_n*10/_tables.size()>7){
            //扩容不能直接resize，以前的EXIST结点的数据位子是旧的size,
            // 需要重新映射
                int newSize = _tables.size()*2;
                HashTable<K,V> newHT;
                newHT._tables.resize(newSize);
                for(size_t i = 0;i<_tables.size();i++){
                    if(_tables[i]._s==EXIST){
                        newHT.Insert(_tables[i]._kv);
                    }
                }
                _tables.swap(newHT._tables);
            }

            size_t hashi = kv.first%_tables.size();
            while (_tables[hashi]._s==EXIST){
                hashi+=1;
                hashi%=_tables.size();
            }
            _tables[hashi]._kv.first=kv.first;
            _tables[hashi]._kv.second=kv.second;
            _tables[hashi]._s=EXIST;
            ++_n;
            return true;
        }
        bool Erase(const K&key){
            HashData<K,V>* ret = Find(key);
            if(ret){
                ret->_s=DELETE;
                --_n;
                return true;
            }
            else
                return false;
        }


    private:
        std::vector<HashData<K,V>> _tables;
        int _n;//负载因子
    };






}










#endif //HASH_HASHTABLE_H
