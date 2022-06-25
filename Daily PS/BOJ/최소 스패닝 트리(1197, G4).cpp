#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent(10001);

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
    int v, e, result = 0;
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
        }
    }
    cout << result;
    return 0;
}

/*
최소신장 트리를 만드는 크루스칼 알고리즘 기초문제
C++의 경우 그래프를 vector<pair<int, pair<int, int>>> 형태로 만들고
make_pair 대신 {c, {a, b}}를 벡터에 push_back 가능
*/
