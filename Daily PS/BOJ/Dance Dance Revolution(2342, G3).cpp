#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#define INF 1000000000

using namespace std;

int get_power(int prev, int cur) {
    if (prev == 0)
        return 2;
    if (prev == cur)
        return 1;
    if (abs(prev - cur) == 2)
        return 4;
    return 3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> panel(100001, 0);
    int n;
    for (int i = 1; ; i++) {
        cin >> panel[i];
        if (panel[i] == 0) {
            n = i - 1;
            break;
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(25, INF));
    dp[1][panel[1] * 5] = 2;
    for (int i = 2; i <= n; i++) {
        int cur = panel[i];
        for (int state = 1; state < 25; state++) {
            int l = state / 5;
            int r = state % 5;
            if (l == r)
                continue;
            if (dp[i - 1][state] == INF)
                continue;
            if (l == cur || r == cur) {
                dp[i][state] = min(dp[i][state], dp[i - 1][state] + 1);
            } else {
                int move_l = cur * 5 + r;
                int move_r = l * 5 + cur;
                
                dp[i][move_l] = min(dp[i][move_l], dp[i - 1][state] + get_power(l, cur));
                dp[i][move_r] = min(dp[i][move_r], dp[i - 1][state] + get_power(r, cur));
            }
        }
    }
    int result_state = 0;
    int result = dp[n][0];
    for (int state = 1; state < 25; state++) {
        result = min(result, dp[n][state]);
    }

    cout << result << endl;
    
    return 0;
}

/*
state별로 저장해야하는 dp
은근 까다로웠다.
*/
