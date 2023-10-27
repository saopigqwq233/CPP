#include "Date.h"
using namespace std;
int main()
{
    Date a(2023,3,15);
    a.print();
    Date b=a;
    b+=17;
    b.print();
    return 0;
}
