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
    int M, N, sum = 0, min = -1;
    cin >> M >> N;

    for(int i = M; i <= N; i++) {
        if(isPrime(i)) {
            sum += i;
            if(min == -1)
                min = i;
        }
    }
    if(sum) cout << sum << endl;
    cout << min << endl;
    return 0;
}