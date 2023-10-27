#include "Date.h"
using namespace std;
int main()
{
    Date a(2023,3,15);
    a.print();
    Date b=a;
    b+=17;
    if(b>a)
    {
        cout<<'s'<<endl;
    }
    cout<<b-a<<endl;
    return 0;
}
