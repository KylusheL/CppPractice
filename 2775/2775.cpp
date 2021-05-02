#include <iostream>

using namespace std;
int howmany(int k, int n);
int main() {
    int T, k, n;
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> k >> n;
        cout << howmany(k, n) << endl;
    }
    return 0;
}

int howmany(int k, int n) {
    if((k == 0) || (n == 1))  return n;
    else return (howmany(k - 1, n) + howmany(k, n - 1));
}