//template<typename T>
//void merge_list(list<T>& l1,list<T>& l2){
//    if(l1.empty()||l2.empty())return;
//
//    list<T> tmp;
//    auto p1 = l1.begin();
//    auto p2 = l2.begin();
//    while (p1!=l1.end()&&p2!=l2.end()){
//        //p1p2遍历两个链表，谁小谁
//        if(*p1<*p2)
//            p1++;
//        else if(*p1>*p2)
//            p2++;
//        else
//            tmp.push_back(*p1);
//    }
//}
#include "iostream"
using namespace std;
typedef int ListDataType;
typedef struct Node{
    ListDataType data;
    Node* next;
}Node;
//带头结点的链表
typedef struct List{
    Node *head;
    Node *tail;
    int size;
}List;
void init_list(List*list){
    list->head = (Node*) malloc(sizeof(Node));
    list->head->data=-1;
    list->head->next= nullptr;
    list->tail = list->head;
    list->size = 0;
}
Node* buyNode(ListDataType val){
    Node *NewNode =  (Node*) malloc(sizeof(Node));
    NewNode->data = val;
    NewNode->next = nullptr;
    return NewNode;
}
//链表尾插
void push_back(List* list,ListDataType val){
    list->tail->next = buyNode(val);
    list->tail = list->tail->next;
    list->size++;
}
List *creat_list(ListDataType arr[],size_t n){
    List *ret = (List*) malloc(sizeof (List));
    init_list(ret);

    for (int i = 0; i < n; ++i) {
        push_back(ret,arr[i]);
    }
    return ret;
}
void destroy_list(List*l){
    if(l == nullptr)return;
    Node *p=l->head->next;
    Node *tmp=l->head;
    while (tmp!= nullptr){
        free(tmp);
        tmp = p;
        if(p!= nullptr)
        p=p->next;
    }
    l->head=l->tail= nullptr;
    l->size=0;
}
void print_list(List*l){
    Node *tmp = l->head->next;
    while (tmp!= nullptr) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    cout<<endl;
}
void merge_list(List*l1,List*l2){
    cout<<"合并前:"<<endl;
    cout<<"l1:";
    print_list(l1);
    cout<<"l2:";
    print_list(l2);

    List tmp;
    init_list(&tmp);

    Node *p1 = l1->head->next;
    Node *p2 = l2->head->next;
    while (p1!= nullptr&&p2!= nullptr){
        if(p1->data>p2->data)p2 = p2->next;
        else if(p1->data<p2->data)p1 = p1->next;
        else {
            push_back(&tmp, p1->data);
            p1 = p1->next;
        }
    }
    destroy_list(l1);
    *l1 = tmp;

    cout<<"合并后："<<endl;
    print_list(l1);
}
int main(){
    ListDataType arr1[5]={1,3,4,6,7};
    ListDataType arr2[5]={2,3,4,5,6};
    List *l1 = creat_list(arr1,5);
    List *l2 = creat_list(arr2,5);
    merge_list(l1,l2);
    return 0;
}