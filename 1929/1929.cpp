#include <iostream>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    int arr[1000001] = {0, };

    arr[1] = 1;

    for(int i = 2; (i * i) <= N; i++) {
        if(!arr[i]) {
            for(int j = i * i; j <= N; j += i) {
                arr[j] = 1;
            }
        }
    }

    for(int i = M; i <= N; i++) {
        if(!arr[i])
            cout << i << endl;
    }


    return 0;
}