#include <iostream>

using namespace std;

#define MAX 10000

int main() {
    bool arr[MAX];
    fill_n(arr, sizeof(arr), true);
    arr[0] = arr[1] = false;
    int i, j;
    for(i = 2; i * i <= MAX + 1; i++) {
        if(arr[i]) {
            for(j = i * i; j <= MAX + 1; j += i) {
                arr[j] = false;
            }
        }
    }

    int T, n;
    cin >> T;
    while(T--) {
        cin >> n;
        i = n/2;
        if(!arr[i] && i%2 == 0) i--;
        while(1) {
            if(arr[i] && arr[n - i]) break;
            if(i != 3) i -= 2;
            else i--;
        }
        cout << i << ' ' << n - i << '\n';
    }
    return 0;
}