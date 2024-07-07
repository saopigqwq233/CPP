//
// Created by Administrator on 24-7-5.
//

#ifndef BSTREE_KVBSTREE_H
#define BSTREE_KVBSTREE_H

#include "iostream"

using namespace std;
namespace kv{
    template<class Key,class Value>
    struct BSTNode{
        typedef BSTNode<Key,Value> Self;
        Self *_left;
        Self *_right;
        Key _key;
        Value _value;
        BSTNode(const Key&key,const Value value)
        :_left(nullptr),
        _right(nullptr),
        _key(key),_value(value){}
        };

    template<class Key,class Value>
    class KVBSTree{
        typedef BSTNode<Key,Value> Node;
        typedef KVBSTree<Key,Value> Self;
        Node *Copy(Node *root) {
            if (root == nullptr)
                return nullptr;
            Node *newRoot = new Node(root->_key);
            newRoot->_left = Copy(root->_left);
            newRoot->_right = Copy(root->_right);
            return newRoot;
        }
        void Destroy(Node *&root) {
            if (root == nullptr)
                return;

            Destroy(root->_left);
            Destroy(root->_right);
            delete root;
            root = nullptr;
        }
    public:
        KVBSTree() = default;
        KVBSTree(const Self&t){
            Copy(t._root);
        }
        ~KVBSTree() {
            Destroy(_root);
        }
        bool insert(const Key &key,const Value&value) {
            if(!_root){
                _root = new Node(key,value);
                return true;
            }
            Node *cur = _root;
            Node *parent=cur;
            while (cur!= nullptr){
                parent = cur;
                if(key<cur->_key){
                    cur = cur->_left;
                }
                else if(key>cur->_key){
                    cur = cur->_right;
                }
                else//存在此节点
                    return false;
            }
            if(key<parent->_key)
                parent->_left = new Node(key,value);
            else if(key>parent->_key)
                parent->_right = new Node(key,value);
            return true;
        }

        void _InOrder(Node *root) {
            if (!root)
                return;
            Node *cur = root;
            _InOrder(root->_left);
            cout << root->_key << ':'<<root->_value<<' ';
            _InOrder(root->_right);
        }

        void InOrder() {
            _InOrder(_root);
            cout << endl;
        }


        Node* Find(const Key &key) {
            Node* cur = _root;
            while (cur){
                if(key<cur->_key)
                    cur = cur->_left;
                else if(key>cur->_key)
                    cur = cur->_right;
                else
                    return cur;
            }
            return nullptr;
        }

        bool erase(const Key& key){
            Node *cur = _root;
            Node *parent = cur;
            while (cur){

                if(key<cur->_key){
                    parent = cur;
                    cur = cur->_left;
                }
                else if(key>cur->_key){
                    parent = cur;
                    cur = cur->_right;
                }
                else{//找到目标了

                    if(cur->_left== nullptr){//左子树为空
                        if(cur==_root)
                            _root = cur->_right;
                        if(cur==parent->_left)
                            parent->_left = cur->_right;
                        else{
                            parent->_right = cur->_right;
                        }
                        return true;
                    }

                    else if(cur->_right== nullptr){//右子树为空
                        if(cur==_root)
                            _root = cur->_left;
                        if(cur==parent->_left)
                            parent->_left = cur->_left;
                        else{
                            parent->_right = cur->_left;
                        }
                        return true;
                    }

                    else{//左右子树都不为空
                        Node* subleft = cur->_right;
                        parent = cur;
                        while (subleft->_left){
                            parent = subleft;
                            subleft = subleft->_left;
                        }
                        swap(cur->_key,subleft->_key);

                        //最左结点的右子树还需要连接到父节点的左子树上
//                    parent->_left = subleft->_right;

                        if(parent->_left == subleft)
                            parent->_left = subleft->_right;
                        else
                            parent->_right = subleft->_right;
                    }
                    return true;
                }
            }
            return false;
        }
        Self &operator=(Self t) {
            swap(_root, t._root);
            return *this;
        }

    private:
        Node *_root= nullptr;
    };

}
















#endif //BSTREE_KVBSTREE_H
