//
// Created by Administrator on 24-7-4.
//

#ifndef BSTREE_BSTREE_H
#define BSTREE_BSTREE_H

#include <iostream>

using namespace std;
namespace lwh1
{
template<class Key>
struct BSTreeNode {

    typedef BSTreeNode<Key> Self;
    Self *_left;
    Self *_right;
    Key _key;
    BSTreeNode(const Key &key)
            : _key(key),
              _left(nullptr),
              _right(nullptr) {}
};

template<class Key>
class BSTree {
    typedef BSTreeNode<Key> Node;
    typedef BSTree<Key> Self;

    Node *Copy(Node *root) {
        if (root == nullptr)
            return nullptr;
        Node *newRoot = new Node(root->_key);
        newRoot->_left = Copy(root->_left);
        newRoot->_right = Copy(root->_right);
        return newRoot;
    }

public:
    BSTree() {}

    BSTree(const Self &t) {//拷贝构造
        _root = Copy(t._root);
    }


    void Destroy(Node *&root) {
        if (root == nullptr)
            return;

        Destroy(root->_left);
        Destroy(root->_right);
        delete root;
        root = nullptr;
    }

    ~BSTree() {
        Destroy(_root);
    }


    bool _insertR(Node *&root, const Key &key) {
        if (root == nullptr) {
            root = new Node(key);
            return true;
        }

        if (key < root->_key)
            _insertR(root->_left, key);
        else if (key > root->_key)
            _insertR(root->_right, key);
        else
            return false;

        return true;
    }

    bool insert(const Key &key) {
//        if(!_root){
//            _root = new Node(key);
//            return true;
//        }
//        Node *cur = _root;
//        Node *parent=cur;
//        while (cur!= nullptr){
//            parent = cur;
//            if(key<cur->_key){
//                cur = cur->_left;
//            }
//            else if(key>cur->_key){
//                cur = cur->_right;
//            }
//            else
//                return false;
//        }
//        if(key<parent->_key)
//            parent->_left = new Node(key);
//        else if(key>parent->_key)
//            parent->_right = new Node(key);
//        return true;
        return _insertR(_root, key);
    }

    void _InOrder(Node *root) {
        if (!root)
            return;
        Node *cur = root;
        _InOrder(root->_left);
        cout << root->_key << ' ';
        _InOrder(root->_right);
    }

    void InOrder() {
        _InOrder(_root);
        cout << endl;
    }

    bool Find(const Key &key) {
//        Node* cur = _root;
//        while (cur){
//            if(key<cur->_key)
//                cur = cur->_left;
//            else if(key>cur->_key)
//                cur = cur->_right;
//            else
//                return true;
//        }
//        return false;
        return _FindR(_root, key);
    }

    bool _FindR(Node *root, const Key &key) {
        if (root == nullptr)
            return false;
        if (root->_key == key)
            return true;
        else {
            return _FindR(root->_left, key) || _FindR(root->_right, key);
        }
    }

    bool _eraseR(Node *&root, const Key &key) {
        if (root == nullptr)
            return false;
        else if (key < root->_key) {
            return _eraseR(root->_left, key);
        } else if (key > root->_key) {
            return _eraseR(root->_right, key);
        } else {
            if (root->_left == nullptr) {
                Node *del = root;
                root = root->_right;
                delete del;
            } else if (root->_right == nullptr) {
                Node *del = root;
                root = root->_left;
                delete del;
            } else {
                Node *parent = root;
                Node *subleft = root->_right;
                while (subleft->_left) {
                    parent = subleft;
                    subleft = subleft->_left;
                }
                swap(subleft->_key, root->_key);
//                 if(parent->_left==subleft){
//                     parent->_left = subleft->_right;
//                 }
//                 else{
//                     parent->_right = subleft->_right;
//                 }
//                 delete subleft;
                _eraseR(root->_right, key);
            }
            return true;
        }
    }


    bool erase(const Key &key) {
//        Node *cur = _root;
//        Node *parent = cur;
//        while (cur){
//
//            if(key<cur->_key){
//                parent = cur;
//                cur = cur->_left;
//            }
//            else if(key>cur->_key){
//                parent = cur;
//                cur = cur->_right;
//            }
//            else{//找到目标了
//
//                if(cur->_left== nullptr){//左子树为空
//                    if(cur==_root)
//                        _root = cur->_right;
//                    if(cur==parent->_left)
//                        parent->_left = cur->_right;
//                    else{
//                        parent->_right = cur->_right;
//                    }
//                    return true;
//                }
//
//                else if(cur->_right== nullptr){//右子树为空
//                    if(cur==_root)
//                        _root = cur->_left;
//                    if(cur==parent->_left)
//                        parent->_left = cur->_left;
//                    else{
//                        parent->_right = cur->_left;
//                    }
//                    return true;
//                }
//
//                else{//左右子树都不为空
//                    Node* subleft = cur->_right;
//                    parent = cur;
//                    while (subleft->_left){
//                        parent = subleft;
//                        subleft = subleft->_left;
//                    }
//                    swap(cur->_key,subleft->_key);
//
//                    //最左结点的右子树还需要连接到父节点的左子树上
////                    parent->_left = subleft->_right;
//
//                    if(parent->_left == subleft)
//                        parent->_left = subleft->_right;
//                    else
//                        parent->_right = subleft->_right;
//                }
//                return true;
//            }
//        }
//        return false;
        return _eraseR(_root, key);
    }

    Self &operator=(Self t) {
        swap(_root, t._root);
        return *this;
    }


private:

    Node *_root = nullptr;

};
}

namespace key_value{



}





#endif //BSTREE_BSTREE_H
