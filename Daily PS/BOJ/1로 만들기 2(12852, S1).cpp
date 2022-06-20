#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    vector<int> before(n + 1);
    dp[1] = 0;
    before[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        before[i] = i - 1;
        if (i % 3 == 0) {
            if (dp[i / 3] + 1 < dp[i]) {
                dp[i] = dp[i / 3] + 1;
                before[i] = i / 3;
            }
        }
        if (i % 2 == 0) {
            if (dp[i / 2] + 1 < dp[i]) {
                dp[i] = dp[i / 2] + 1;
                before[i] = i / 2;
            }
        }
    }
    cout << dp[n] << endl;
    while (n > 0) {
        cout << n << ' ';
        n = before[n];
    }
    return 0;
}

/*
Cpp로 PS 재활 시작용 문제
pair는 되도록이면 자제하자
*/
