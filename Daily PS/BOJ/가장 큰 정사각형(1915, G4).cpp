#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n, vector<int>(m, 0));
    vector<vector<int>> row_dp(n, vector<int>(m, 0));
    vector<vector<int>> col_dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '1') {
                int left = (j > 0) ? row_dp[i][j - 1] : 0;
                int up = (i > 0) ? col_dp[i - 1][j] : 0;
                row_dp[i][j] = left + 1;
                col_dp[i][j] = up + 1;
                dp[i][j] = 1;
            }
        }
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i][0] == 1) {
            result = 1;
            break;
        }
    }
    if (result == 0) {
        for (int j = 0; j < m; j++) {
            if (dp[0][j] == 1) {
                result = 1;
                break;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (dp[i][j] == 0)
                continue;
            int cand = dp[i - 1][j - 1] + 1;
            cand = min({cand, col_dp[i][j], row_dp[i][j]});
            dp[i][j] = cand;
            result = max(result, cand);
        }
    }

    cout << result * result << endl;
    
    return 0;
}

/*
예외 처리에 주의해야 하는 dp 문제
*/
