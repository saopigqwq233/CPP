#include <iostream>

using namespace std;

double multi(int a,int b){
    if(b==0){
        throw "³ý0´íÎó";
    }
    else{
        return (double )a/b;
    }
}

void test(){
    int x,y;
    cin>>x>>y;
    try {
        cout<<multi(x,y);
    }
    catch(const char *str) {
        cout<<str<<endl;
    }

}

int main() {
    test();
    return 0;

}
