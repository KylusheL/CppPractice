#include <iostream>

using namespace std;

int main() {
    long long int a, b, c;
    cin >> a >> b >> c;
    cout << ((c > b) ? ((a / (c - b)) + 1) : -1) << endl;

    return 0;
}