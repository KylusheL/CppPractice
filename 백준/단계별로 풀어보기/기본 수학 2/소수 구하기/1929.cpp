#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int M, N, i, j;
    cin >> M >> N;

    bool arr[1000001];
    for(i = 2; i < 1000001; i++) arr[i] = true;
    arr[0] = arr[1] = false;

    for(i = 2; (i * i) <= N; i++) {
        if(arr[i]) {
            for(j = i * i; j <= N; j += i) {
                arr[j] = false;
            }
        }
    }

    for(i = M; i <= N; i++) {
        if(arr[i])
            cout << i << '\n';
    }

    return 0;
}