#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<bool>> dp(2000, vector<bool>(2000, false));
vector<int> nums;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
        int left = i - 1, right = i + 1;
        while (left >= 0 && right < n) {
            if (nums[left] != nums[right])
                break;
            dp[left][right] = true;
            left--;
            right++;
        }
        left = i, right = i + 1;
        while (left >= 0 && right < n) {
            if (nums[left] != nums[right])
                break;
            dp[left][right] = true;
            left--;
            right++;
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        cout << int(dp[start - 1][end - 1]) << '\n';
    }
    return 0;
}

/*
출력이 많을 때 빠른 출력에 신경쓸 것
팰린드롬 확인 시 홀/짝 구분할 것
*/
