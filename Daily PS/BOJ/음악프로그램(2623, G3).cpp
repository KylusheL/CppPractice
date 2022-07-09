#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>());
    vector<int> indegree(n + 1);
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        int prev, now;
        cin >> now;
        for (int j = 1; j < t; j++) {
            prev = now;
            cin >> now;
            adj[prev].push_back(now);
            indegree[now]++;
        }
    }
    vector<int> result;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty()) {
        int now = q.front();
        result.push_back(now);
        q.pop();
        for (int x : adj[now]) {
            indegree[x]--;
            if (indegree[x] == 0)
                q.push(x);
        }
    }
    if (result.size() != n)
        cout << 0 << endl;
    else {
        for (int elem : result)
            cout << elem << endl;
    }
    return 0;
}

/*
위상정렬 기초 문제
*/
