#include <iostream>
#include <vector>
#include <algorithm>
#define INF 9876543210

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> row(n, 0);
    vector<int> col(n, 0);
    vector<vector<int>> dp(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        cin >> row[i];
        cin >> col[i];
        dp[i][i] = 0;
    }
    for (int diff = 1; diff < n; diff++) {
        for (int left = 0; left + diff < n; left++) {
            int right = left + diff;
            for (int mid = left + 1; mid <= right; mid++) {
                int n = row[left];
                int m = row[mid];
                int k = col[right];
                dp[left][right] = min(dp[left][right],
                    dp[left][mid - 1] + dp[mid][right] + n * m * k);
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
    return 0;
}

/*
쉬운 2차원 dp 문제
*/
