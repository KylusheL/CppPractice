#include <iostream>

using namespace std;

int main() {
    int a[2] = {0, 0};
    int b[2] = {0, 0};
    int x, y;
    cin >> x >> y;
    a[0]= x; b[0] = y;
    cin >> x >> y;
    if(x != a[0]) a[1] = x;
    if(y != b[0]) b[1] = y;
    cin >> x >> y;
    if(x == a[0]) cout << a[1];
    else if(!a[1]) cout << x;
    else cout << a[0];
    cout << ' ';
    if(y == b[0]) cout << b[1];
    else if(!b[1]) cout << y;
    else cout << b[0];
    return 0;
}