#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int>> dp(1001, vector<int>(1001, 0));
string s1, s2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    vector<char> stack;
    while (n > 0 && m > 0) {
        if (s1[n - 1] == s2[m - 1]) {
            stack.push_back(s1[n - 1]);
            n--;
            m--;
        } else if (dp[n - 1][m] > dp[n][m - 1]) {
            n--;
        } else {
            m--;
        }
    }
    cout << stack.size() << endl;
    if (stack.size() != 0) {
        for (int i = stack.size() - 1; i >= 0; i--) {
            cout << stack[i];
        }
        cout << endl;
    }
    return 0;
}

/*
string을 전부 저장하면 시간초과
*/
