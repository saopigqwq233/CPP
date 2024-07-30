//
// Created by Administrator on 24-7-30.
//

#ifndef HASH_MYSET_H
#define HASH_MYSET_H
#include "HashTable.h"
namespace my {
    template<class K, class Hash = hash_bucket::HashFunc<K>>
    class unordered_set {
        struct SetKeyOfT {
            const K &operator()(const K &key) {
                return key;
            }
        };

    public:
        typedef typename hash_bucket::HashTable<K, K, SetKeyOfT, Hash>::const_iterator iterator;
        typedef typename hash_bucket::HashTable<K, K, SetKeyOfT, Hash>::const_iterator const_iterator;

        //set不能修改k值
        const_iterator begin() const {
            return _ht.begin();
        }

        const_iterator end() const {
            return _ht.end();
        }

        pair<const_iterator, bool> insert(const K &key) {
            auto ret = _ht.Insert(key);
            return pair<const_iterator, bool>(const_iterator(ret.first._node, ret.first._pht, ret.first._hashi),
                                              ret.second);
        }

        iterator find(const K &key) {
            return _ht.Find(key);
        }

        bool erase(const K &key) {
            return _ht.Erase(key);
        }

    private:
        hash_bucket::HashTable<K, K, SetKeyOfT, Hash> _ht;
    };
}
#endif //HASH_MYSET_H
