#include <iostream>

using namespace std;

int isPrime(int x) {
    if(x == 1) return 0;
    for(int i = 2; (i * i) <= x; i++) {
        if(!(x % i)) return 0;
    }
    return 1;
}
int main() {
    int N, cnt = 0;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        cnt += isPrime(x);
    }
    cout << cnt << endl;
    return 0;
}