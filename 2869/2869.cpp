#include <iostream>
using namespace std;

int main() {
    int a, b, v, result;
    cin >> a >> b >> v;
    cout << ((v - b) / (a - b)) + 1 << endl;
    return 0;
}