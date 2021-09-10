#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
bool isVisited[101] = {false};
int cnt = 0;

void dfs(int x) {
    isVisited[x] = true;
    cnt++;

    for(int i = 0; i < graph[x].size(); i++) {
        int next = graph[x][i];
        if(!isVisited[next])
            dfs(next);
    }
};
int main() {
    int N, E;
    cin >> N >> E;

    graph.resize(N + 1);
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1);

    cout << cnt - 1 << endl;

    return 0;
}