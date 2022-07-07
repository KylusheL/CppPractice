#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>());
    vector<int> indegree(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        cout << now << ' ';
        for (auto adj : graph[now]) {
            indegree[adj]--;
            if (indegree[adj] == 0)
                q.push(adj);
        }
    }
    cout << endl;
    return 0;
}

/*
위상정렬 기초 문제
*/
