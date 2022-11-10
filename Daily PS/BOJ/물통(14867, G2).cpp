#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <algorithm>
#define INF 1000000000

using namespace std;
map<pair<int, int>, int> visited;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int result = -1;

    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[{0, 0}] = 0;
    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        int x = now.first;
        int y = now.second;
        int dist = visited[now];
        if ((x == c) && (y == d)) {
            result = dist;
            break;
        }
        int x_adj[6] = {a, x, 0, x, x - min(x, b - y), x + min(y, a - x)};
        int y_adj[6] = {y, b, y, 0, y + min(x, b - y), y - min(y, a - x)};
        for (int i = 0; i < 6; i++) {
            int nx = x_adj[i];
            int ny = y_adj[i];
            if (visited.find({nx, ny}) == visited.end()) {
                q.push({nx, ny});
                visited[{nx, ny}] = dist + 1;
            }
        }
    }
    cout << result << endl;
    
    return 0;
}

/*
공간 복잡도를 줄이기 위해 방문여부를 map으로 만드는 bfs
발상이 재미있었다.
*/
