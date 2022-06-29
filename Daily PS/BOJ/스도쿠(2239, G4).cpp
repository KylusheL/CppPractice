#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> graph;
vector<pair<int, int>> blanks;

bool check_row(int r, int n) {
    for (int c = 0; c < 9; c++) {
        if (graph[r][c] == n + '0')
            return false;
    }
    return true;
}

bool check_col(int c, int n) {
    for (int r = 0; r < 9; r++) {
        if (graph[r][c] == n + '0')
            return false;
    }
    return true;
}

bool check_sq(int x, int n) {
    for (int r = (x / 3) * 3; r < (x / 3) * 3 + 3; r++) {
        for (int c = (x % 3) * 3; c < (x % 3) * 3 + 3; c++)
            if (graph[r][c] == n + '0')
                return false;
    }
    return true;
}

bool dfs(int depth) {
    if (depth == blanks.size())
        return true;
    int r, c, x;
    r = blanks[depth].first;
    c = blanks[depth].second;
    x = (r / 3) * 3 + c / 3;
    char prev = graph[r][c];
    for (int n = 1; n <= 9; n++) {
        if (check_row(r, n) && check_col(c, n) && check_sq(x, n)) {
            graph[r][c] = n + '0';
            if (dfs(depth + 1))
                return true;
            graph[r][c] = prev;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 9; i++) {
        string s;
        cin >> s;
        graph.push_back(s);
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (graph[i][j] == '0')
                blanks.push_back({i, j});
        }
    }
    dfs(0);
    for (auto s : graph) {
        cout << s << endl;
    }
    return 0;
}

/*
백트래킹 탈출조건에 주의할 것
*/
