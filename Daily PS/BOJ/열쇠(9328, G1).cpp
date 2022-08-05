#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#define INF 1000000000

using namespace std;

vector<string> graph;
vector<vector<bool>> visited;
vector<vector<pair<int, int>>> door;
vector<bool> open;
int result;
int n, m;

void bfs(int x, int y) {
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    queue<pair<int, int>> q;

    // mark start point
    visited[x][y] = true;
    q.push({x, y});
    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        x = now.first;
        y = now.second;

        // get score
        if (graph[x][y] == '$') {
            result++;
        }
        // get key
        else if (graph[x][y] >= 'a' && graph[x][y] <= 'z') {
            int idx = graph[x][y] - 'a';
            if (!open[idx]) {
                // open doors
                for (auto pos : door[idx]) {
                    int tmp_x = pos.first;
                    int tmp_y = pos.second;
                    graph[tmp_x][tmp_y] = '.';
                    // edge
                    if (tmp_x == 0 || tmp_x == n - 1 || tmp_y == 0 || tmp_y == m - 1) {
                        visited[tmp_x][tmp_y] = true;
                        q.push({tmp_x, tmp_y});
                        continue;
                    }
                    // check uldr
                    for (int i = 0; i < 4; i++) {
                        int tmp_nx = tmp_x + dx[i];
                        int tmp_ny = tmp_y + dy[i];
                        // can connect with adj
                        if (visited[tmp_nx][tmp_ny]) {
                            visited[tmp_x][tmp_y] = true;
                            q.push({tmp_x, tmp_y});
                            break;
                        }
                    }
                }
            }
        }
        // check uldr
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // out of range
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            // cannot move
            if (graph[nx][ny] == '*' || (graph[nx][ny] >= 'A' && graph[nx][ny] <= 'Z'))
                continue;
            // already visited
            if (visited[nx][ny])
                continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

void solve() {
    cin >> n >> m;
    // Initialize global variables
    graph.assign(n, "");
    visited.assign(n, vector<bool>(m, false));
    door.assign(26, vector<pair<int, int>>());
    open.assign(26, false);
    result = 0;

    // input graph, key
    for (int i = 0; i < n; i++)
        cin >> graph[i];
    string key;
    cin >> key;

    // save door positions
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] >= 'A' && graph[i][j] <= 'Z') {
                door[graph[i][j] - 'A'].push_back({i, j});
            }
        }
    }
    
    if (key != "0") {
        for (char c : key) {
            int idx = c - 'a';
            if (open[idx])
                continue;
            // open doors by key
            open[idx] = true;
            for (auto pos : door[idx]) {
                graph[pos.first][pos.second] = '.';
            }
        }
    }
    for (int j = 0; j < m; j++) {
        // check top line
        if (graph[0][j] != '*' && !(graph[0][j] >= 'A' && graph[0][j] <= 'Z') && !visited[0][j])
            bfs(0, j);

        // check bottom line
        if (graph[n - 1][j] != '*' && !(graph[n - 1][j] >= 'A' && graph[n - 1][j] <= 'Z') && !visited[n - 1][j])
            bfs(n - 1, j);
    }
    for (int i = 1; i < n - 1; i++) {
        // check left line
        if (graph[i][0] != '*' && !(graph[i][0] >= 'A' && graph[i][0] <= 'Z') && !visited[i][0])
            bfs(i, 0);

        // check right line
        if (graph[i][m - 1] != '*' && !(graph[i][m - 1] >= 'A' && graph[i][m - 1] <= 'Z') && !visited[i][m - 1])
            bfs(i, m - 1);
    }
    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}

/*
빡구현 디버깅지옥
온갖 예외처리에 주의할 것
*/
