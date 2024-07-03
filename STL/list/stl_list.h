#ifndef LIST_STL_LIST_H
#define LIST_STL_LIST_H
#include "iostream"
#include "cassert"
using namespace std;

namespace lwh{
//    template<class T>
//    struct list_node{
//        T data;
//        list_node<T>* prev;
//        list_node<T>* next;
//        list_node(const T&val = T())
//        :data(val),
//        prev(nullptr),
//        next(nullptr)
//        {}
//    };
//
//    template<class T>
//    struct __list_iterator{
//        typedef list_node<T> Node;
//        typedef __list_iterator<T> self;
//        Node *_node;
//
//        __list_iterator(Node *node):_node(node){}
//        //访问
//        T& operator*(){
//            return _node->data;
//        }
//        //下一个
//        self& operator++(){
//            _node = _node->next;
//            return *this;
//        }
//        self& operator--(){
//            _node = _node->prev;
//            return *this;
//        }
//        self operator++(int){
//            self tmp(*this);
//            _node = _node->next;
//            return tmp;
//        }
//        self operator--(int){
//            self tmp(*this);
//            _node = _node->prev;
//            return tmp;
//        }
//        T* operator->(){
//            return &_node->data;
//        }
//        bool operator==(const self&s){
//            return _node==s._node;
//        }
//        bool operator!=(const self&s){
//            return _node!=s._node;
//        }
//    };
//
//    template<class T>
//    class list{
//        typedef list_node<T> Node;
//    public:
//        typedef __list_iterator<T> iterator;
//        iterator begin(){return _head->next;}
//        iterator end(){return _head;}
//        void empty_init(){
//            _head = new Node;
//            _head->prev = _head;
//            _head->next = _head;
//            _size=0;
//        }
//        list(){
//            empty_init();
//        }
//        list(list<T>&lt){
//            empty_init();
//            for(auto e:lt){
//                push_back(e);
//            }
//        }
//        ~list(){
//            clear();
//            delete _head;
//            _head = nullptr;
//            _size = 0;
//        }
//        size_t size()const{return _size;}
//        void swap(list<T>& lt)
//        {
//            std::swap(_head, lt._head);
//            std::swap(_size, lt._size);
//        }
//        list<int>& operator=(list<int> lt)
//        {
//            swap(lt);
//
//            return *this;
//        }
//        iterator insert(iterator pos,const T& val){
//            Node*tmp = new Node(val);
//
//            Node* cur = pos._node;
//            Node*pre = cur->prev;
//
//            tmp->next = pre->next;
//            tmp->prev = cur;
//
//            pre->next = tmp;
//            cur->prev = tmp;
//            ++_size;
//            return iterator(tmp);
//        }
//        iterator erase(iterator pos){
//
//            Node *cur = pos._node;
//            Node *pre = cur->prev;
//            Node *next = cur->next;
//
//            pre->next = cur->next;
//            next->prev = cur->prev;
//            delete cur;
//            --_size;
//            return iterator(next);
//        }
//        void clear(){
//            iterator it = begin();
//            while (it != end()){
//                it = erase(it);
//            }
//        }
//        void push_back(const T&val = T()){
//            insert(end(),val);
//        }
//        void push_front(const T&val = T()){
//            insert(begin(),val);
//        }
//        void pop_back(){
//            erase(--end());
//        }
//        void pop_front(){
//            erase(begin());
//        }
//
//
//    private:
//
//        Node* _head;
//        size_t _size;
//
//    };
template<class T>
    struct list_node{
        T _data;
        list_node* _prev;
        list_node* _next;
        list_node(const T&val = T())
        :_data(val),
        _prev(nullptr),
        _next(nullptr){}
    };
template<class T,class Ptr,class Ref>
    struct __list_iterator{
        typedef list_node<T> Node;
        typedef __list_iterator<T,Ptr,Ref> self;
        Node* _node;
        __list_iterator(Node*node):_node(node){}

        Ref operator*()const{
            return _node->_data;
        }
        Ptr operator->()const{
            return &(_node->_data);
        }
        self& operator++(){
            _node = _node->_next;
            return *this;
        }
        self& operator--(){
            _node = _node->_prev;
            return *this;
        }
        self operator++(int){
            self tmp(_node);
            _node = _node->_next;
            return tmp;
        }
        self operator--(int){
            self tmp(_node);
            _node = _node->_prev;
            return tmp;
        }
        bool operator==(const self& x)const{
            return _node==x._node;
        }
        bool operator!=(const self& x)const{
            return _node!=x._node;
        }
    };
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
template<class T>
    class list{
        typedef list_node<T> Node;
    public:
        typedef __list_iterator<T,T*,T&> iterator;
        typedef __list_iterator<T,const T*,const T&> const_iterator;

        typedef Reverseiterator<iterator,T*,T&> reverse_iterator;
        typedef Reverseiterator<const_iterator,const T*,const T&> const_reverse_iterator;
        void empty_init(){
            _head = new Node;
            _head->_prev = _head->_next = _head;
            _size = 0;
        }
        list(){empty_init();}
        list(const list<T>&rt){
            empty_init();
            for(auto& e:rt){
                push_back(e);
            }
        }
        ~list(){
            clear();
            delete _head;
            _head = nullptr;
            _size = 0;
        }
        void swap(list<T>&rt){
            std::swap(_head,rt._head);
            std::swap(_size,rt._size);
        }
        list<T>& operator=(list<T>rt){
            swap(rt);
            return *this;
        }
        iterator begin(){return _head->_next;}
        iterator end(){return _head;}
        const_iterator cbegin()const{return _head->_next;}
        const_iterator cend()const{return _head;}

        reverse_iterator rbegin(){return reverse_iterator(--end());}
        reverse_iterator rend(){return reverse_iterator(end());}
        const_reverse_iterator crbegin()const{return const_reverse_iterator(--cend());}
        const_reverse_iterator crend()const{return const_reverse_iterator(cend());}

        iterator insert(const iterator& pos,const T& val){
            Node* new_node = new Node(val);
            Node* cur = pos._node;
            Node* pre = cur->_prev;

            new_node->_next = cur;
            new_node->_prev = pre;
            pre->_next = new_node;
            cur->_prev = new_node;
            _size++;
            return new_node;
        }
        iterator erase(iterator& pos){
            Node* cur = pos._node;
            Node* pre = cur->_prev;
            Node*next = cur->_next;

            pre->_next = next;
            next->_prev = pre;
            --_size;
            delete cur;
            return next;
        }
        void clear(){
            list<T>::iterator it = begin();
            while (it!=end()){
                it = erase(it);
            }
        }
        size_t size()const{return _size;}
        void push_back(const T& val = T()){
            insert(end(),val);
        }
        void push_front(const T& val = T()){
            insert(begin(),val);
        }
        void pop_back(){
            erase(--end());
        }
        void pop_front(){
            erase(begin());
        }

    private:
        Node *_head;
        size_t _size;
    };
}
#endif //LIST_STL_LIST_H
