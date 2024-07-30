//
// Created by Administrator on 24-7-10.
//

#ifndef HASH_HASHTABLE_H
#define HASH_HASHTABLE_H
#pragma once
#include "iostream"
#include "vector"

using namespace std;
//线性探测法
//namespace lwh{
//    enum Status{
//        EMPTY,
//        EXIST,
//        DELETE//这个状态是必须的，否则删除一个点滞空后会导致后面的结点找不到
//    };
//
//    template<class K,class V>
//    struct HashData{
//        std::pair<K,V> _kv;
//        Status _s;
//    };
//
//    template<class K,class V>
//    class HashTable{
//    public:
//        HashTable():_n(0){
//            _tables.resize(10);
//        }
//        HashData<K,V>*Find(const K&key){
//            size_t hashi = key%_tables.size();
//            while (_tables[hashi]._s!=EMPTY){
//                if(_tables[hashi]._s!=EMPTY&&_tables[hashi]._kv.first==key){
//                    return &_tables[hashi];
//                }
//                ++hashi;
//                hashi%=_tables.size();
//            }
//            return nullptr;
//        }
//        bool Insert(const std::pair<K,V>&kv){
//            if(Find(kv.first))
//                return false;
//            if(_n*10/_tables.size()>7){
//            //扩容不能直接resize，以前的EXIST结点的数据位子是旧的size,
//            // 需要重新映射
//                int newSize = _tables.size()*2;
//                HashTable<K,V> newHT;
//                newHT._tables.resize(newSize);
//                for(size_t i = 0;i<_tables.size();i++){
//                    if(_tables[i]._s==EXIST){
//                        newHT.Insert(_tables[i]._kv);
//                    }
//                }
//                _tables.swap(newHT._tables);
//            }
//
//            size_t hashi = kv.first%_tables.size();
//            while (_tables[hashi]._s==EXIST){
//                hashi+=1;
//                hashi%=_tables.size();
//            }
//            _tables[hashi]._kv.first=kv.first;
//            _tables[hashi]._kv.second=kv.second;
//            _tables[hashi]._s=EXIST;
//            ++_n;
//            return true;
//        }
//        bool Erase(const K&key){
//            HashData<K,V>* ret = Find(key);
//            if(ret){
//                ret->_s=DELETE;
//                --_n;
//                return true;
//            }
//            else
//                return false;
//        }
//    void Print(){
//            for(int i=0;i<_tables.size();++i){
//                if(_tables[i]._s!=EXIST){
//                    std::cout<<'['<<i<<"] "<<std::endl;
//                }
//                else{
//                    std::cout<<'['<<i<<"] "<<_tables[i]._kv.first<<std::endl;
//                }
//            }
//        }
//
//    private:
//        std::vector<HashData<K,V>> _tables;
//        int _n;//负载因子
//    };
//}
namespace hash_bucket{
    template<class K>
    struct HashFunc
    {
        size_t operator()(const K& key)
        {
            return (size_t)key;
        }
    };
    template<>
    struct HashFunc<string>
    {
        size_t operator()(const string& key)
        {
            size_t hash = 0;
            for (auto e : key)
            {
                hash *= 31;
                hash += e;
            }

            return hash;
        }
    };
    template<class T>
    struct HashNode
    {
        HashNode<T>* _next;
        T _data;

        HashNode(const T& data)
                :_data(data)
                ,_next(nullptr)
        {}
    };

    // 前置声明
    template<class K, class T, class KeyOfT, class Hash>
    class HashTable;

    template<class K, class T, class Ref, class Ptr, class KeyOfT, class Hash>
    struct __HTIterator
    {
        typedef HashNode<T> Node;
        typedef __HTIterator<K, T, Ref, Ptr, KeyOfT, Hash> Self;
        //本质属性是结点+hashi桶序列号
        Node* _node;
        size_t _hashi;
        //_pht用来作为自己所在HashTable对象的指针
        const HashTable<K, T, KeyOfT, Hash>* _pht;
        __HTIterator(Node* node, HashTable<K, T, KeyOfT, Hash>* pht, size_t hashi)
                :_node(node)
                ,_pht(pht)
                ,_hashi(hashi)
        {}

        __HTIterator(Node* node, const HashTable<K, T, KeyOfT, Hash>* pht, size_t hashi)
                :_node(node)
                , _pht(pht)
                , _hashi(hashi)
        {}

        Self& operator++()
        {
            if (_node->_next)
            {
                // 当前桶还有节点，走到下一个节点
                _node = _node->_next;
            }
            else
            {
                // 当前桶已经走完了，找下一个桶开始
                ++_hashi;
                while (_hashi < _pht->_tables.size())
                {
                    if (_pht->_tables[_hashi])
                    {
                        _node = _pht->_tables[_hashi];
                        break;
                    }

                    ++_hashi;
                }

                if (_hashi == _pht->_tables.size())
                {
                    _node = nullptr;
                }
            }

            return *this;
        }

        Ref operator*()
        {
            return _node->_data;
        }

        Ptr operator->()
        {
            return &_node->_data;
        }

        bool operator!=(const Self& s)
        {
            return _node != s._node;
        }
    };

    // unordered_set -> Hashtable<K, K>
    // unordered_map -> Hashtable<K, pair<K, V>>
    template<class K, class T, class KeyOfT, class Hash>
    class HashTable
    {
        typedef HashNode<T> Node;

        template<class Kk, class Tt, class Ref, class Ptr, class KeyOfTt, class Hashf>
        friend struct __HTIterator;
    public:
        typedef __HTIterator<K, T, T&, T*, KeyOfT, Hash> iterator;
        typedef __HTIterator<K, T, const T&, const T*, KeyOfT, Hash> const_iterator;

        iterator begin()
        {
            for (size_t i = 0; i < _tables.size(); i++)
            {
                if (_tables[i])
                {
                    return iterator(_tables[i], this, i);
                }
            }

            return end();
        }

        iterator end()
        {
            return iterator(nullptr, this, -1);
        }
        const_iterator begin() const
        {
            for (size_t i = 0; i < _tables.size(); i++)
            {
                if (_tables[i])
                {
                    return const_iterator(_tables[i], this, i);
                }
            }

            return end();
        }

        const_iterator end() const
        {
            return const_iterator(nullptr, this, -1);
        }

        HashTable()
        {
            _tables.resize(10);
        }

        ~HashTable()
        {
            for (size_t i = 0; i < _tables.size(); i++)
            {
                Node* cur = _tables[i];
                while (cur)
                {
                    Node* next = cur->_next;
                    delete cur;
                    cur = next;
                }
                _tables[i] = nullptr;
            }
        }

        pair<iterator, bool> Insert(const T& data)
        {
            Hash hf;
            KeyOfT kot;

            iterator it = Find(kot(data));
            if (it != end())
                return make_pair(it, false);

            // 负载因子最大到1
            if (_n == _tables.size())
            {
                vector<Node*> newTables;
                newTables.resize(_tables.size() * 2, nullptr);
                // 遍历旧表
                for (size_t i = 0; i < _tables.size(); i++)
                {
                    Node* cur = _tables[i];
                    while(cur)
                    {
                        Node* next = cur->_next;

                        // 挪动到映射的新表
                        size_t hashi = hf(kot(cur->_data)) % newTables.size();
                        cur->_next = newTables[hashi];
                        newTables[hashi] = cur;

                        cur = next;
                    }
                    _tables[i] = nullptr;
                }
                _tables.swap(newTables);
            }

            size_t hashi = hf(kot(data)) % _tables.size();
            Node* newnode = new Node(data);

            // 头插
            newnode->_next = _tables[hashi];
            _tables[hashi] = newnode;
            ++_n;

            return make_pair(iterator(newnode, this, hashi), true);
        }

        iterator Find(const K& key)
        {
            Hash hf;
            KeyOfT kot;
            size_t hashi = hf(key) % _tables.size();
            Node* cur = _tables[hashi];
            while (cur)
            {
                if (kot(cur->_data) == key)
                {
                    return iterator(cur, this, hashi);
                }

                cur = cur->_next;
            }

            return end();
        }
        bool Erase(const K& key)
        {
            Hash hf;
            KeyOfT kot;

            size_t hashi = hf(key) % _tables.size();
            Node* prev = nullptr;
            Node* cur = _tables[hashi];
            while (cur)
            {
                if (kot(cur->_data) == key)
                {
                    if (prev == nullptr)
                    {
                        _tables[hashi] = cur->_next;
                    }
                    else
                    {
                        prev->_next = cur->_next;
                    }
                    delete cur;

                    return true;
                }

                prev = cur;
                cur = cur->_next;
            }

            return false;
        }
    private:
        vector<Node*> _tables;
        size_t _n = 0;
    };
}


#endif //HASH_HASHTABLE_H
