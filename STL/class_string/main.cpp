#include <iostream>
#include "string"
using namespace std;

//void test1(){
//    string s1("It's not a tough task for you to accomplish it");
//    int index = s1.find_last_not_of("aeiou");
//    while (index!=s1.npos)
//    {
//        s1[index] = '&';
//        index = index = s1.find_first_not_of("aeiou");
//    }
//    cout<<s1<<endl;
//}
//void test2(){
//    string s1("abcdefg");
//    string s2(s1);
//    s2[2] = '1';
//    cout<<s1<<endl;
//}
class KMP{
private:
    int** next;
    string pattern;
public:
    KMP(string pat):pattern(pat){
        //next[状态][字符] = 目标状态
        //pattern有从0到n共pattern.size()个状态，0为开始，n为匹配成功
        next = new int* [pattern.size()];
        for (int i = 0; i < pattern.size(); ++i) {
            next[i] = new int[256]{0};
        }
        next[0][pattern[0]] = 1;
        //X记忆相似状态
        int X = 0;
        //构建状态转移
        for (int i = 1; i < pat.size(); ++i) {
            //从状态i=1开始，直到状态n，找到每一个状态跳转到下一个状态的目标字符
            for (int c = 0; c < 256; ++c) {
                next[i][c] = next[X][c];
            }
            next[i][pattern[i]] = i+1;
            //更新X，搜索和本状态相似转移状态
            X = next[X][pattern[i]];
        }
    }
    int search(const string& txt){
        int N = txt.size();
        int M = pattern.size();
        int j = 0;
        for (int i = 0; i < N; ++i)
        {
            j = next[j][txt[i]];
            if(j == M)
                return i-M+1;
        }
        return -1;
    }
};
//int main() {
//    KMP kmp("ABABC");
//    string txt("AABABABBABCABABCAB");
//    int index = kmp.search(txt);
//    cout<<index<<endl;
//    return 0;
//}
void test1(){
    //空构造
    string s1;
    //拷贝构造
    string s2(s1);
    string s3 = s1;
    //数组构造
    string s4("abcdefg");
    //子串构造
    string s5(s4,3,4);
    //填充构造
    string s6(10,'a');
}
void test2(){
    string s1("abcdefg");
    cout<<"s1:"<<s1<<endl;
    string s2;
    cin>>s2;
    cout<<"s2:"<<s2<<endl;
}
void test3(){
    string s1;
    cin>>s1;
    cout<<s1;
    cout<<s1.size();
}
void test4(){
    string s1;
    getline(cin,s1);
    cout<<s1<<endl;
}
void test5(){
    string s1("abcdefgh");
    for(auto i = s1.begin();i!=s1.end();i++){
        cout<<*i<<'&';
    }
    cout<<endl;
    for (auto i = s1.end(); i != s1.begin() ; --i) {
        cout<<*i<<'*';
    }
    cout<<endl;
}
void test6(){
    string s1("abcdefgh");
    for(auto i = s1.rbegin();i!=s1.rend();i++){
        cout<<*i<<"&";
    }
    cout<<endl;
    for(auto i = s1.rend();i!=s1.rbegin();i--){
        cout<<*i<<"*";
    }
    cout<<endl;
}
void test7(){
    string s1("abcdefgh");
    for (int i = 0; i < s1.length(); ++i) {
        cout<<s1[i]<<' ';
    }
    cout<<endl;
}
void test8(){
    string s1("hello");
    string s2 = s1 + ' ' + "world";
    cout<<s2<<endl;
    s2 += "233";
    cout<<s2<<endl;
}
void test9(){
//    以字符串为参数
    string s1("hello");
    s1.append(" world");
    cout<<"s1:"+s1<<endl;

//    以string类为参数
    string s2;
    s2.append(s1);
    cout<<"s2:"+s2<<endl;

//    以字符串为参数，并声明长度
    string s3("hello");
    s3.append(" world",4);
    cout<<"s3:"+s3<<endl;

//    以string类为参数，并声明开始位置和长度
    string s4;
    s4.append(s2,6,5);
    cout<<"s4:"+s4<<endl;
//    指定拼接字符个数，拼接字符
    string s5;
    s5.append(10,'c');
    cout<<"s5:"+s5<<endl;
//    以string迭代器区间为参数
    string s6;
    s6.append(++s5.begin(),--s5.end());
    cout<<"s6:"+s6<<endl;
}
void test10(){
    char str[] = "hello world";
    string s1(str);
    s1.erase(3);//从下表3开始删到最后
    cout<<"s1:"+s1<<endl;

    string s2(str);
    s2.erase(3,4);//从下标3开始删4个字符
    cout<<"s2:"+s2<<endl;

    string s3(str);
    s3.erase(++s3.begin());//删掉第二个元素
    cout<<"s3:"+s3<<endl;
    s3.erase(--s3.end());//删掉最后一个元素
    cout<<"s3:"+s3<<endl;

    string s4(str);
    s4.erase(++(s4.begin()),--s4.end());//删掉左闭右开的区间
    cout<<"s4:"+s4<<endl;
}
void test11(){
    
}
int main(){
    test10();
    return 0;
}
