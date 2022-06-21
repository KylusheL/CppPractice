#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> xpos;
    vector<int> ypos;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        xpos.push_back(x);
        ypos.push_back(y);
    }
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += double(xpos[i]) * double(ypos[(i + 1) % n]);
        result -= double(xpos[(i + 1) % n]) * double(ypos[i]);
    }
    result *= 0.5;
    if (result < 0) {
        result *= -1.0;
    }
    cout << fixed;
    cout.precision(1);
    cout << result;
    return 0;
}

/*
소위 말하는 신발끈 공식을 모르면 못 푸는 문제
*/
