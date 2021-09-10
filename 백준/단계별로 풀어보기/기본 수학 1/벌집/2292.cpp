#include <iostream>

using namespace std;

int main() {
    int n, i = 1;
    cin >> n;
    while(n > 1) {
        n -= 6 * i;
        i++;
    }
    cout << i << endl;
    return 0;
}