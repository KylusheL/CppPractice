#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int r, c, result = 1;
vector<string> graph;
vector<vector<bool>> visited;
vector<bool> stack(26, false);
vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};

void dfs(int x, int y, int dist) {
    if (dist > result) {
        result = dist;
    }
    
    for (int i = 0; i < 4; i++) {
        int nx, ny;
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c)
            continue;
        int idx = int(graph[nx][ny] - 'A');
        if (stack[idx])
            continue;
        if (visited[nx][ny])
            continue;
        visited[nx][ny] = true;
        stack[idx] = true;
        dfs(nx, ny, dist + 1);
        stack[idx] = false;
        visited[nx][ny] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        graph.push_back(s);
    }
    for (int i = 0; i < r; i++) {
        vector<bool> line(c, false);
        visited.push_back(line);
    }
    visited[0][0] = true;
    stack[int(graph[0][0] - 'A')] = true;
    dfs(0, 0, 1);
    cout << result << endl;
    return 0;
}

/*
재귀함수에서 vector의 초기화는 치명적인 overhead
전역변수로 설정한다.
*/
