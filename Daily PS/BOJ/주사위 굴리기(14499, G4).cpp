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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<int, int> dice;
    for (int i = 1; i <= 6; i++) dice[i] = 0;

    int n, m;
    int x, y;
    int k;
    cin >> n >> m >> x >> y >> k;

    vector<vector<int>> graph(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    int u = 1, f = 5, r = 3;

    // 1, 2, 3, 4 -> 동, 서, 북, 남
    int dx[5] = {0, 0, 0, -1, 1};
    int dy[5] = {0, 1, -1, 0, 0};
    while (k--) {
        int cmd;
        int tmp;
        cin >> cmd;
        int nx = x + dx[cmd];
        int ny = y + dy[cmd];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        switch(cmd) {
            case 1:
                tmp = r;
                r = u;
                u = 7 - tmp;
            break;
            case 2:
                tmp = u;
                u = r;
                r = 7 - tmp;
            break;
            case 3:
                tmp = u;
                u = f;
                f = 7 - tmp;
            break;
            case 4:
                tmp = f;
                f = u;
                u = 7 - tmp;
            break;
            default:
            break;
        }
        if (graph[nx][ny] == 0) graph[nx][ny] = dice[7 - u];
        else {
            dice[7 - u] = graph[nx][ny];
            graph[nx][ny] = 0;
        }
        cout << dice[u] << '\n';
        x = nx;
        y = ny;
    }
    return 0;
}

/*
문제를 꼼꼼히 읽어야 하는 시뮬레이션 문제
*/
