//
// Created by Administrator on 24-7-6.
//

#ifndef SET_MAP_AVL_H
#define SET_MAP_AVL_H

#include <cassert>
#include "iostream"


using namespace std;
template<class Key,class Value>
struct AVLNode{
    typedef AVLNode<Key,Value> Self;

    Self *_parent,*_left,*_right;
    pair<Key,Value> _kv;
    int _bf;

    AVLNode(const pair<Key,Value>& x):
    _kv(x),_parent(nullptr),
    _left(nullptr),_right(nullptr),
    _bf(0){}
};
template<class Key,class Value>
class AVLTree{
    typedef AVLTree<Key,Value> Self;
    typedef AVLNode<Key,Value> Node;
public:
    bool insert(const pair<Key,Value>&x){
        if(_root== nullptr) { _root = new Node(x);
            return true;}
        Node* cur = _root;
        Node* parent = nullptr;
        while (cur){
            parent = cur;
            if(cur->_kv.first > x.first)
                cur = cur->_left;
            else if(cur->_kv.first < x.first)
                cur = cur->_right;
            else{
                return false;
            }
        }
        cur = new Node(x);
        cur->_parent=parent;
        if(x.first<parent->_kv.first)
            parent->_left = cur;
        else
            parent->_right = cur;

        while (parent){
            //改平衡因子
            if(parent->_left==cur){
                parent->_bf-=1;
            }
            else
                parent->_bf+=1;

            //当父节点——bf为0，不需要再变动
            if(parent->_bf==0)
                break;
            else if(parent->_bf==-1||parent->_bf==1) {
                //向上检查
                cur = cur->_parent;
                parent = cur->_parent;
            }
            else if(parent->_bf==-2||parent->_bf==2){
                //旋转
                if(parent->_bf==-2&&cur->_bf==-1)//左边特别长,cur的左边也长
                    RotatoR(parent);//右旋
                else if(parent->_bf==2&&cur->_bf==1)//右边特别长，cur的右边也长
                    RotatoL(parent);//左旋
                else if(parent->_bf==2&&cur->_bf==-1)//右边特别长,cur的左边长
                    RotatoRL(parent);
                else if(parent->_bf==-2&&cur->_bf==1)
                    RotatoLR(parent);

                    break;
            }
            else{
                assert(false);
            }
        }
        return true;
    }
    void InOrder(){
        _InOrder(_root);
    }
    bool isBalanced(){
        return _isBalanced(_root);
    }
private:
    bool _isBalanced(Node*root){
        if(root== nullptr)
            return true;

        return abs(_Height(_root->_left)- _Height(_root->_right))<2
               && _isBalanced(root->_left)&& _isBalanced(root->_right);
    }
    int _Height(Node*root){
        if(root== nullptr)
            return 0;
        return 1+ max(_Height(root->_left), _Height(root->_right));
    }
    void _InOrder(Node*root){
        if(root== nullptr)
            return;
        _InOrder(root->_left);
        cout<<root->_kv.first<<':'<<root->_kv.second<<endl;
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
        parent->_bf=subR->_bf=0;
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
        parent->_bf = subL->_bf = 0;
    }
    void RotatoRL(Node*parent){
        Node* subR = parent->_right;
        Node* subRL = subR->_left;
        int bf = subRL->_bf;
        RotatoR(subR);
        RotatoL(parent);
        if(bf==0){//subrl自己就是新增
            parent->_bf= subR->_bf = subRL->_bf = 0;
        }
        else if(bf==-1){//subrl左子树新增
            parent->_bf = 0;
            subRL = 0;
            subR->_bf = 1;
        }
        else if(bf==1){
            parent->_bf = -1;
            subRL->_bf=0;
            subR->_bf=0;
        }
        else
            assert(false);
    }
    void RotatoLR(Node*parent){
        Node* subL = parent->_left;
        Node* subLR = subL->_right;
        int bf = subLR->_bf;
        RotatoL(subL);
        RotatoR(parent);
        if(bf==0){//subrl自己就是新增
            parent->_bf= subL->_bf = subLR->_bf = 0;
        }
        else if(bf==-1){//subrl左子树新增
            parent->_bf = 0;
            subLR = 0;
            subL->_bf = 1;
        }
        else if(bf==1){
            parent->_bf = -1;
            subLR->_bf=0;
            subL->_bf=0;
        }
        else
            assert(false);

    }
    Node* _root= nullptr;
};








#endif //SET_MAP_AVL_H
