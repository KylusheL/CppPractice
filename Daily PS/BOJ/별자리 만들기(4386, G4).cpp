#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> parent(100);

int find_parent(int x) {
    if (parent[x] != x) {
        parent[x] = find_parent(parent[x]);
    }
    return parent[x];
}

bool union_parent(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);
    if (x == y) {
        return false;
    }
    else if (x < y) {
        parent[y] = x;
    } else {
        parent[x] = y;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<pair<float, float>> stars;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        float x, y;
        cin >> x >> y;
        stars.push_back({x, y});
    }
    vector<pair<float, pair<int, int>>> edges;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            float x1, y1, x2, y2;
            x1 = stars[i].first;
            y1 = stars[i].second;
            x2 = stars[j].first;
            y2 = stars[j].second;
            float dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
            edges.push_back({dist, {i, j}});
        }
    }
    sort(edges.begin(), edges.end());
    
    float result = 0.0;
    int edge_cnt = 0;
    for (int i = 0; i < edges.size(); i++) {
        if (edge_cnt == n - 1)
            break;
        float dist = edges[i].first;
        int a, b;
        a = edges[i].second.first;
        b = edges[i].second.second;
        if (union_parent(a, b)) {
            result += dist;
            edge_cnt++;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << result << endl;
    return 0;
}

/*
크루스칼 알고리즘 float 버전
*/
