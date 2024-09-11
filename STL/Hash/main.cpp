#include "myset.h"
#include "mymap.h"
#include "iostream"

using namespace std;
using namespace my;
void test_map()
{
    unordered_map<string, string> dict;
    dict.insert(make_pair("sort", "����"));
    dict.insert(make_pair("string", "�ַ���"));
    dict.insert(make_pair("insert", "����"));

    for (auto& kv : dict)
    {
        kv.second += 'x';

        cout << kv.first << ":" << kv.second << endl;
    }
    cout << endl;
    string arr[] = { "?", "","?", "", "?", "", "?", "?", "", "?", "?", "?", "?" };
    unordered_map<string, int> count_map;
    for (auto& e : arr)
    {
        count_map[e]++;
    }

    for (auto& kv : count_map)
    {
        cout << kv.first << ":" << kv.second << endl;
    }
    cout << endl;
}
//int main(){
//    test_map();
//    return 0;
//}



