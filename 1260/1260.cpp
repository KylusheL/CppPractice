#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, V;
vector<vector<int>> graph;
vector<bool> visited(1001, false);

void dfs(int root);
void bfs(int root);
int main() {
    cin >> N >> M >> V;
    for(int i = 0; i <= N; i++) {
        vector<int> tmp(N + 1, 0);
        graph.push_back(tmp);
    }
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    dfs(V);
    cout << endl;
    for(int i = 0; i < visited.size(); i++) {
        visited[i] = false;
    }
    bfs(V);
    return 0;
}

void dfs(int root) {
    visited[root] = true;
    cout << root << ' ';
    for(int i = 1; i <= N; i++) {
        if(graph[root][i] && !visited[i])
            dfs(i);
    }
}

void bfs(int root) {
    queue<int> q;
    visited[root] = true;
    cout << root << ' ';
    q.push(root);
    while(!q.empty()) {
        int i = q.front();
        q.pop();
        for(int j = 1; j <= N; j++) {
            if(graph[i][j] && !visited[j]) {
                visited[j] = true;
                cout << j << ' ';
                q.push(j);
            }
        }
    }
}