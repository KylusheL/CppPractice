#include <iostream>

using namespace std;
int main() {
    int T, x, y, dist, n;
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> x >> y;
        dist = y - x;
        n = 0;
        for(int j = 1; dist > 0; j++) {
            dist -= (((j - 1) / 2) + 1);
            n++;
        }
        cout << n << endl;
    }
    return 0;
}