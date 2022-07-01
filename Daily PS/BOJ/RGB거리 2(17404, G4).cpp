#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define INF 1000000000

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> graph;
    for (int i = 0; i < n; i++) {
        int r, g, b;
        cin >> r >> g >> b;
        graph.push_back({r, g, b});
    }
    vector<vector<int>> r_dp(n, vector<int>(3, INF));
    vector<vector<int>> g_dp(n, vector<int>(3, INF));
    vector<vector<int>> b_dp(n, vector<int>(3, INF));
    r_dp[0][0] = graph[0][0];
    g_dp[0][1] = graph[0][1];
    b_dp[0][2] = graph[0][2];
    for (int i = 1; i < n; i++) {
        r_dp[i][0] = min(r_dp[i - 1][1], r_dp[i - 1][2]) + graph[i][0];
        r_dp[i][1] = min(r_dp[i - 1][0], r_dp[i - 1][2]) + graph[i][1];
        r_dp[i][2] = min(r_dp[i - 1][0], r_dp[i - 1][1]) + graph[i][2];
        g_dp[i][0] = min(g_dp[i - 1][1], g_dp[i - 1][2]) + graph[i][0];
        g_dp[i][1] = min(g_dp[i - 1][0], g_dp[i - 1][2]) + graph[i][1];
        g_dp[i][2] = min(g_dp[i - 1][0], g_dp[i - 1][1]) + graph[i][2];
        b_dp[i][0] = min(b_dp[i - 1][1], b_dp[i - 1][2]) + graph[i][0];
        b_dp[i][1] = min(b_dp[i - 1][0], b_dp[i - 1][2]) + graph[i][1];
        b_dp[i][2] = min(b_dp[i - 1][0], b_dp[i - 1][1]) + graph[i][2];
    }
    
    int r_min = min(r_dp[n - 1][1], r_dp[n - 1][2]);
    int g_min = min(g_dp[n - 1][0], g_dp[n - 1][2]);
    int b_min = min(b_dp[n - 1][0], b_dp[n - 1][1]);
    int result = min(r_min, g_min);
    result = min(result, b_min);
    cout << result << endl;
    
    return 0;
}
