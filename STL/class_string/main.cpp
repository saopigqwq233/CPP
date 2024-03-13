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
}
int main(){
    test6();
    return 0;
}
