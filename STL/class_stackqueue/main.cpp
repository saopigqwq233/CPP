#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ���������Ľڵ�ṹ
struct Node {
    char ch; // �ַ�������Ҷ�ӽڵ�����Ч��
    int weight;
    Node *left;
    Node *right;
    Node(int w) : weight(w), left(nullptr), right(nullptr) {}
    Node(char c, int w) : ch(c), weight(w), left(nullptr), right(nullptr) {}
};

// �ȽϺ������������ȶ���
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->weight > r->weight;
    }
};

// ������������
Node* buildHuffmanTree(vector<Node*>& nodes) {
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (Node* node : nodes) {
        pq.push(node);
    }
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
        Node* parent = new Node(left->weight + right->weight);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }
    return pq.top();
}

// �����Ȩ·������
int calculateWPL(Node* root, int depth) {
    if (!root) {
        return 0;
    }
    if (!root->left && !root->right) {
        return root->weight * depth;
    }
    return calculateWPL(root->left, depth + 1) + calculateWPL(root->right, depth + 1);
}

// ��ӡ���������Ľṹ
void printHuffmanTree(Node* root, string code = "") {
    if (!root) return;
    if (root->left) printHuffmanTree(root->left, code + "0");
    if (root->right) printHuffmanTree(root->right, code + "1");
    if (!root->left && !root->right) {
        cout << root->ch << " : " << code << endl;
    }
}

int main() {
//    vector<Node*> nodes;
//    nodes.push_back(new Node('A', 16));
//    nodes.push_back(new Node('B', 5));
//    nodes.push_back(new Node('C', 9));
//    nodes.push_back(new Node('D', 3));
//    nodes.push_back(new Node('E', 30));
//    nodes.push_back(new Node('F', 1));
//
//    Node* root = buildHuffmanTree(nodes);
//    int wpl = calculateWPL(root, 0);
//
//    cout << "���������Ľṹ��" << endl;
//    printHuffmanTree(root);
//    cout << "��Ȩ·������WPL: " << wpl << endl;
    int n = 12;
    cout<<(n+=n-=n*=n)<<endl;
    return 0;
}
