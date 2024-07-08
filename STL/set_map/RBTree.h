//
// Created by Administrator on 24-7-7.
//
//插入节点父亲是黑色，不用管
//1.cur为红,p为红，g为黑，u存在为红---》p、u改黑，g改红，把g作为cur往上继续检查
//2.cur为红,p为红,g为黑，u存在为黑
#ifndef SET_MAP_RBTREE_H
#define SET_MAP_RBTREE_H
#include "iostream"
#include "string"

using namespace std;

enum COLOR{RED,BLACK};


template<class T>
struct RBNode{
    typedef RBNode<T> Self;

    Self *_parent,*_left,*_right;
    T _data;
    COLOR _color;

    RBNode(const T& x):
            _data(x),_parent(nullptr),
            _left(nullptr),_right(nullptr),
            _color(RED){}
};



template<class T>
struct __TreeIterator{

    typedef RBNode<T> Node;
    typedef __TreeIterator<T> Self;
    __TreeIterator(Node* node):_node(node){}

    Self& operator++(){
        //左子树、根、右子树

        if(_node->_right){
            Node*cur = _node->_right;;
            while (cur->_left){
                cur = cur->_left;
            }
            _node = cur;
        }
        else{
            Node *cur = _node;
            Node *parent = cur->_parent;

            while (parent&&cur==parent->_right){
                cur = parent;
                parent = cur->_parent;
            }
            _node = parent;
        }
        return *this;
    }
    T& operator*(){
        return _node->_data;
    }
    T* operator->(){
        return &_node->_data;
    }
    bool operator!=(const Self& s)
    {
        return _node != s._node;
    }

    bool operator==(const Self& s)
    {
        return _node == s._node;
    }



private:
    Node* _node;

};





template<class Key,class T,class KeyofT>
class RBTree{
    typedef RBNode<T> Node;
    KeyofT kot;

public:
    typedef __TreeIterator<T> iterator;
    bool insert(const T&data){
        if(_root== nullptr) { _root = new Node(data);
            _root->_color=BLACK;
            return true;}
        Node* cur = _root;
        Node* parent = nullptr;
        while (cur){
            parent = cur;
            if(kot(cur->_data) > kot(data))
                cur = cur->_left;
            else if(kot(cur->_data) < kot(data))
                cur = cur->_right;
            else{
                return false;
            }
        }
        cur = new Node(data);
        cur->_parent=parent;
        if(kot(data) < kot(parent->_data))
            parent->_left = cur;
        else
            parent->_right = cur;
        while (parent&&parent->_color!=BLACK){
            Node* g = parent->_parent;
            if(parent==g->_left){//父亲是爷的左子树
                Node* u = g->_right;
                if(u&&u->_color==RED) {
                    parent->_color = BLACK;
                    u->_color = BLACK;
                    g->_color = RED;
                    cur = g;
                    parent = cur->_parent;
                    continue;
                }
                else{
                    if(cur==parent->_left){
                        parent->_color=BLACK;
                        g->_color = RED;
                        RotatoR(g);
                    }
                    else{
                        RotatoL(parent);
                        RotatoR(g);
                        g->_color = RED;
                        cur->_color = BLACK;
                    }
                    break;
                }

            }
            else{//parent==g->_right
                Node* u = g->_left;
                if(u&&u->_color==RED){
                    parent->_color = BLACK;
                    u->_color = BLACK;
                    g->_color = RED;
                    cur = g;
                    parent = cur->_parent;
                    continue;
                }
                else{
                    if(cur==parent->_right){
                        parent->_color=BLACK;
                        g->_color = RED;
                        RotatoL(g);
                    }
                    else{
                        RotatoR(parent);
                        RotatoL(g);
                        g->_color = RED;
                        cur->_color = BLACK;
                    }
                    break;
                }
            }
        }
        _root->_color=BLACK;
        return true;

    }
    void InOrder()
    {
        _InOrder(_root);
        cout << endl;
    }
    iterator begin()
    {
        Node* cur = _root;
        while (cur && cur->_left)
        {
            cur = cur->_left;
        }

        return iterator(cur);
    }

    iterator end()
    {
        return nullptr;
    }

private:
    void _InOrder(Node* root)
    {
        if (root == nullptr)
            return;

        _InOrder(root->_left);

        cout << kot(root->_data) << " ";
        _InOrder(root->_right);
    }
    void RotatoL(Node* parent){
        Node* subR = parent->_right;
        Node* subRL = subR->_left;
        Node* pp = parent->_parent;

        parent->_right = subRL;
        if(subRL)
            subRL->_parent = parent;

        subR->_left = parent;
        parent->_parent = subR;

        subR->_parent = pp;
        if(_root==parent)
            _root = subR;
        else{
            if(pp->_left==parent)
                pp->_left = subR;
            else
                pp->_right = subR;
        }
    }
    void RotatoR(Node* parent){
        Node* subL = parent->_left;
        Node* subLR = subL->_right;
        Node* pp = parent->_parent;

        parent->_left = subLR;
        if(subLR)
            subLR->_parent = parent;

        subL->_right = parent;
        parent->_parent = subL;

        subL->_parent = pp;
        if(_root==parent)
            _root=subL;
        else{
            if(pp->_left==parent)
                pp->_left = subL;
            else
                pp->_right = subL;
        }

    }
    Node* _root= nullptr;

};


#endif //SET_MAP_RBTREE_H
