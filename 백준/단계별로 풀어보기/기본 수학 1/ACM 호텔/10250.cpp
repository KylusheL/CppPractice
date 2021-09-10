#include <iostream>

using namespace std;

int main() {
    int t;
    int h, w, n;

    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> h >> w >> n;
        cout << 100 * ((n - 1) % h + 1) + ((n - 1) / h) + 1 << endl;
    }

    return 0;
}