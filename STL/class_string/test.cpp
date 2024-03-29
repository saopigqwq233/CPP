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
//#include "iostream"
//using namespace std;
//typedef int ListDataType;
//typedef struct Node{
//    ListDataType data;
//    Node* next;
//}Node;
////带头结点的链表
//typedef struct List{
//    Node *head;
//    Node *tail;
//    int size;
//}List;
//void init_list(List*list){
//    list->head = (Node*) malloc(sizeof(Node));
//    list->head->data=-1;
//    list->head->next= nullptr;
//    list->tail = list->head;
//    list->size = 0;
//}
//Node* buyNode(ListDataType val){
//    Node *NewNode =  (Node*) malloc(sizeof(Node));
//    NewNode->data = val;
//    NewNode->next = nullptr;
//    return NewNode;
//}
////链表尾插
//void push_back(List* list,ListDataType val){
//    list->tail->next = buyNode(val);
//    list->tail = list->tail->next;
//    list->size++;
//}
////根据数组构建列表
//List *creat_list(ListDataType arr[],size_t n){
//    List *ret = (List*) malloc(sizeof (List));
//    init_list(ret);
//
//    for (int i = 0; i < n; ++i) {
//        push_back(ret,arr[i]);
//    }
//    return ret;
//}
////销毁链表
//void destroy_list(List*l){
//    if(l == nullptr)return;
//    Node *p=l->head->next;
//    Node *tmp=l->head;
//    while (tmp!= nullptr){
//        free(tmp);
//        tmp = p;
//        if(p!= nullptr)
//        p=p->next;
//    }
//    l->head=l->tail= nullptr;
//    l->size=0;
//}
////打印
//void print_list(List*l){
//    Node *tmp = l->head->next;
//    while (tmp!= nullptr) {
//        printf("%d ", tmp->data);
//        tmp = tmp->next;
//    }
//    cout<<endl;
//}
////合并同项
//void merge_list(List*l1,List*l2){
//    cout<<"合并前:"<<endl;
//    cout<<"l1:";
//    print_list(l1);
//    cout<<"l2:";
//    print_list(l2);
//
//    List tmp;
//    init_list(&tmp);
//
//    Node *p1 = l1->head->next;
//    Node *p2 = l2->head->next;
//    while (p1!= nullptr&&p2!= nullptr){
//        if(p1->data>p2->data)p2 = p2->next;
//        else if(p1->data<p2->data)p1 = p1->next;
//        else {
//            push_back(&tmp, p1->data);
//            p1 = p1->next;
//        }
//    }
//    destroy_list(l1);
//    *l1 = tmp;
//
//    cout<<"合并后："<<endl;
//    print_list(l1);
//}
//int main(){
//    ListDataType arr1[5]={1,3,4,6,7};
//    ListDataType arr2[5]={2,3,4,5,6};
//    List *l1 = creat_list(arr1,5);
//    List *l2 = creat_list(arr2,5);
//    merge_list(l1,l2);
//    return 0;
//}
#include "iostream"
using namespace std;
struct SeqL{
    int *data;
    int size;
    int capacity;
};
void init_S(SeqL *s){
    s->data = (int*) malloc(sizeof(int )*10);
    s->capacity = 10;
    s->size = 0;
}
void push_back(SeqL *s,int val){
    if(s->size==s->capacity) {
        s->data = (int *) realloc(s->data, s->capacity * 2);
        s->capacity*=2;
    }
    s->data[s->size] = val;
    s->size++;
}
SeqL* creat_list(int arr[],size_t n){
    SeqL* ret = (SeqL*) malloc(sizeof (SeqL));
    init_S(ret);
    for (int i = 0; i < n; ++i) {
        push_back(ret,arr[i]);
    }
    return ret;
}
//升序排序后取第7个数
int small_k(SeqL s,int k){
    int end = s.size-1;
    while (k--){
        int i = 0;//i指向最小的索引
        for (int j = 0; j <= end; ++j) {
            if(s.data[i]>s.data[j])i=j;
        }
        int tmp = s.data[end];
        s.data[end] = s.data[i];
        s.data[i] = tmp;
        end--;
    }
    return s.data[end+1];
}
void print_sl(SeqL s){
    cout<<"arr:";
    for (int i = 0; i < s.size; ++i) {
        cout<<s.data[i]<<' ';
    }
    cout<<endl;
}
int main(){
    int arr1[10]={10,8,3,4,7,9,1,5,6,2};
    SeqL *s = creat_list(arr1,10);
    print_sl(*s);
    int k = 2;
    cout<<"第"<<k<<"小:"<<small_k(*s,k);
    return 0;
}


