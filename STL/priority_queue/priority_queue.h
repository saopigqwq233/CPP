//
// Created by Administrator on 24-7-2.
//
#ifndef PRIORITY_QUEUE_PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_PRIORITY_QUEUE_H
#include "vector"

using namespace std;
namespace lwh {
    template<typename T>
    class Less{
    public:
        bool operator()(T x,T y){
            return x<y;
        }
    };
    template<typename T>
    class Greater{
    public:
        bool operator()(T x,T y){
            return x>y;
        }
    };


    template<typename T, class Container=vector<T>,class Com=Greater<T>>
    class priority_queue{
    private:
        Container _con;
    public:
        void adjust_down(int parent){
            Com com;
            int child = parent*2+1;
            while (child<_con.size()){
                if(child+1<_con.size()&&com(_con[child],_con[child+1])){
                    ++child;
                }
                if(com(_con[parent],_con[child])){
                    swap(_con[child],_con[parent]);
                    parent = child;
                    child = parent*2+1;
                }
                else
                    break;
            }
        }
        void adjust_up(int child){
            Com com;
            int parent = (child-1)/2;
            while (child>0){
                if(com(_con[parent],_con[child]))
                {
                    swap(_con[child],_con[parent]);
                    child = parent;
                    parent = (child-1)/2;
                }
                else
                    break;
            }
        }
        void push(const T& val ){
            _con.push_back(val);
            adjust_up(_con.size()-1);
        }
        const T& top(){
            return _con[0];
        }
        void pop(){
            swap(_con[0],_con[_con.size()-1]);
            _con.pop_back();
            adjust_down(0);
        }
        bool empty(){
            return _con.empty();
        }

        size_t size(){
            return _con.size();
        }
    };
}








#endif //PRIORITY_QUEUE_PRIORITY_QUEUE_H
