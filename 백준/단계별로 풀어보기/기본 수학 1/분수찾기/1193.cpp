#include <iostream>

using namespace std;

int main() {
    int x, line = 1;
    cin >> x;
    while(x > line) {
        x -= line;
        line++;
    }
    if(line%2) cout << (line + 1 - x) << '/' << x << endl;
    else cout << x << '/' << (line + 1 - x) << endl;

    return 0;
}