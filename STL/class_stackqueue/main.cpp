#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 哈夫曼树的节点结构
struct Node {
    char ch; // 字符（仅在叶子节点中有效）
    int weight;
    Node *left;
    Node *right;
    Node(int w) : weight(w), left(nullptr), right(nullptr) {}
    Node(char c, int w) : ch(c), weight(w), left(nullptr), right(nullptr) {}
};

// 比较函数，用于优先队列
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->weight > r->weight;
    }
};

// 构建哈夫曼树
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

// 计算带权路径长度
int calculateWPL(Node* root, int depth) {
    if (!root) {
        return 0;
    }
    if (!root->left && !root->right) {
        return root->weight * depth;
    }
    return calculateWPL(root->left, depth + 1) + calculateWPL(root->right, depth + 1);
}

// 打印哈夫曼树的结构
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
//    cout << "哈夫曼树的结构：" << endl;
//    printHuffmanTree(root);
//    cout << "带权路径长度WPL: " << wpl << endl;
    int n = 12;
    cout<<(n+=n-=n*=n)<<endl;
    return 0;
}
