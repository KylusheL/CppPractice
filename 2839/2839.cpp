#include <iostream>

using namespace std;

int main() {
    int N;
    int remain;
    cin >> N;
    remain = N % 5;
    switch(remain) {
        case 0:
            cout << (N / 5) << endl;
            break;
        case 1:
            cout << ((N < 6) ? -1 : ((N / 5) + 1)) << endl;
            break;
        case 2:
            cout << ((N < 12) ? -1 : ((N / 5) + 2)) << endl;
            break;
        case 3:
            cout << (N / 5) + 1 << endl;
            break;
        case 4:
            cout << ((N < 9) ? -1 : ((N / 5) + 2)) << endl;
            break;
    }
    return 0;
}