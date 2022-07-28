#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <algorithm>
#define INF 1000000000

using namespace std;
vector<vector<pair<int, int>>> graph;
vector<pair<int, int>> cand;
vector<int> dist(2001, INF);

void dijkstra(int start) {
    dist.assign(2001, INF);
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    while(!pq.empty()) {
        int now = pq.top().second;
        int d = -pq.top().first;
        pq.pop();
        if (dist[now] < d)
            continue;
        for (int i = 0; i < graph[now].size(); i++) {
            int cost = d + graph[now][i].second;
            if (cost < dist[graph[now][i].first]) {
                dist[graph[now][i].first] = cost;
                pq.push({-cost, graph[now][i].first});
            }
        }
    }
}

void solve() {
    int n, m, t;
    cin >> n >> m >> t;
    graph.assign(n + 1, vector<pair<int, int>>());
    cand.assign(t, {0, 0});
    int s, g, h;
    int mid;
    cin >> s >> g >> h;
    for (int i = 0; i < m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        if ((a == g && b == h) || (a == h && b == g))
            mid = d;
        graph[a].push_back({b, d});
        graph[b].push_back({a, d});
    }
    set<int> result;
    dijkstra(s);
    int pass_gh = dist[g] + mid;
    int pass_hg = dist[h] + mid;
    for (int i = 0; i < t; i++) {
        int x;
        cin >> x;
        cand[i] = {x, dist[x]};
    }
    dijkstra(h);
    for (int i = 0; i < t; i++) {
        int x = cand[i].first;
        int goal = cand[i].second;
        if (pass_gh + dist[x] == goal)
            result.insert(x);
    }
    dijkstra(g);
    for (int i = 0; i < t; i++) {
        int x = cand[i].first;
        int goal = cand[i].second;
        if (pass_hg + dist[x] == goal)
            result.insert(x);
    }
    for (auto it = result.begin(); it != result.end(); it++) {
        cout << *it << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        solve();
    }
    
    return 0;
}

/*
다익스트라 응용 문제
*/
