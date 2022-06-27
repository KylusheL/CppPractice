#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent(100001);

int find_parent(int x) {
    if (parent[x] != x)
        parent[x] = find_parent(parent[x]);
    return parent[x];
}

void union_parent(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);
    if (x < y) {
        parent[y] = x;
    } else {
        parent[x] = y;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int v, e, result = 0, max_edge = 0;
    cin >> v >> e;
    vector<pair<int, pair<int, int>>> graph;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back({c, {a, b}});
    }
    sort(graph.begin(), graph.end());
    for (int i = 1; i <= v; i++)
        parent[i] = i;
    for (int i = 0; i < graph.size(); i++) {
        int a = find_parent(graph[i].second.first);
        int b = find_parent(graph[i].second.second);
        if (a != b) {
            union_parent(graph[i].second.first, graph[i].second.second);
            result += graph[i].first;
            if (graph[i].first > max_edge) max_edge = graph[i].first;
        }
    }
    cout << result - max_edge << endl;
    return 0;
}

/*
최소 스패닝트리 기본 문제
*/
