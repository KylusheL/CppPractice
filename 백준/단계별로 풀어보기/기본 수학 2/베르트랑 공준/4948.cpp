#include <iostream>

using namespace std;

#define MAX 123456

int main() {
    bool arr[2*MAX + 1];
    fill_n(arr, sizeof(arr), true);
    int i, j, n;
    arr[0] = arr[1] = false;
    for(i = 2; i * i <= 2*MAX; i++) {
        if(arr[i]) {
            for(j = i * i; j <= 2*MAX + 1; j += i) {
                arr[j] = false;
            }
        }
    }
    while(1) {
        cin >> n;
        if(n == 0) break;
        int cnt = 0;
        for(i = n + 1; i <= 2 * n; i++) {
            if(arr[i]) cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}