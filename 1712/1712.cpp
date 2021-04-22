#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long int a, b, c;
    cin >> a >> b >> c;
    cout << ((c > b) ? (floor((a / (c - b))) + 1) : -1) << endl;

    return 0;
}