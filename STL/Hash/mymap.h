//
// Created by Administrator on 24-7-30.
//

#ifndef HASH_MYMAP_H
#define HASH_MYMAP_H
#include "HashTable.h"
namespace my{
    template<class K, class V, class Hash = hash_bucket::HashFunc<K>>
    class unordered_map
    {
        struct MapKeyOfT
        {
            const K& operator()(const pair<K, V>& kv)
            {
                return kv.first;
            }
        };
    public:
        typedef typename hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT, Hash>::iterator iterator;

        iterator begin()
        {
            return _ht.begin();
        }

        iterator end()
        {
            return _ht.end();
        }

        pair<iterator, bool> insert(const pair<K, V>& kv)
        {
            return _ht.Insert(kv);
        }

        V& operator[](const K& key)
        {
            pair<iterator, bool> ret = _ht.Insert(make_pair(key, V()));
            return ret.first->second;
        }

        const V& operator[](const K& key) const
        {
            pair<iterator, bool> ret = _ht.Insert(make_pair(key, V()));
            return ret.first->second;
        }

        iterator find(const K& key)
        {
            return _ht.Find(key);
        }

        bool erase(const K& key)
        {
            return _ht.Erase(key);
        }

    private:
        hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT, Hash> _ht;
    };
}
#endif //HASH_MYMAP_H
