#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
vector<int> stone(30, 0);
vector<vector<int>> dp(30, vector<int>(30001, 0));

int solve(int i, int target) {
    int j = target + 15000;
    if (i < 0 || j >= dp[0].size())
        return -1;
    if (dp[i][j] != 0)
        return dp[i][j];
    int st = stone[i];
    int mid = solve(i - 1, target);
    int down = solve(i - 1, target - st);
    int up = solve(i - 1, target + st);
    if (mid == 1 || down == 1 || up == 1 || target == 0)
        dp[i][j] = 1;
    else
        dp[i][j] = -1;
    return dp[i][j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> stone[i];
        dp[i][15000] = 1;
        dp[i][15000 + stone[i]] = 1;
        dp[i][15000 - stone[i]] = 1;
    }
    // dp[i][j] : i번째 구슬까지 써서 j 측정 가능한지 여부 -> 미방문 0 가능 1 불가능 -1
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int target;
        cin >> target;
        // cout << solve(n - 1, target) << endl;
        if (solve(n - 1, target) > 0)
            cout << "Y ";
        else
            cout << "N ";
    }
    cout << endl;
    return 0;
}

/*
냅색 응용 문제
*/
