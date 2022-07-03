#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void solve() {
    int n, k, i;
    cin >> n >> k;
    vector<vector<int>> edge(n + 1, vector<int>());
    vector<int> cost(n + 1, 0);
    vector<int> dp(n + 1, 0);
    vector<int> indegree(n + 1, 0);
    for (i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    for (i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        indegree[b]++;
    }
    int target;
    cin >> target;
    queue<int> q;
    for (i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            dp[i] += cost[i];
        }
    }
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for (i = 0; i < edge[now].size(); i++) {
            int adj = edge[now][i];
            indegree[adj]--;
            dp[adj] = max(dp[adj], dp[now]);
            if (indegree[adj] == 0) {
                q.push(adj);
                dp[adj] += cost[adj];
            }
        }
    }
    cout << dp[target] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
    return 0;
}

/*
위상정렬 기초 문제
*/
