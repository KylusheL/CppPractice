#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
vector<vector<int>> graph(500, vector<int>(500, 0));
vector<vector<int>> dp(500, vector<int>(500, -1));
int n, m;
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

int solve(int x, int y) {
    if (dp[x][y] >= 0)
        return dp[x][y];
    dp[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= n || nx < 0 || ny >= m || ny < 0)
            continue;
        if (graph[nx][ny] <= graph[x][y])
            continue;
        dp[x][y] += solve(nx, ny);
    }
    return dp[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    dp[0][0] = 1;
    
    cout << solve(n - 1, m - 1) << endl;
    
    return 0;
}

/*
Top-down으로 풀어야 하는 dp문제
*/
