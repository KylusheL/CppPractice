#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#define INF 1000000000

using namespace std;
vector<int> parent(200001, 0);
vector<int> child(200001, 0);

int find_parent(int x) {
    if (parent[x] != x) {
        parent[x] = find_parent(parent[x]);
    }
    return parent[x];
}

int union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if (a < b) {
        parent[b] = a;
        child[a] += child[b];
        return child[a];
    } else if (a > b) {
        parent[a] = b;
        child[b] += child[a];
        return child[b];
    } else {
        return child[a];
    }
}

void solve() {
    int f;
    cin >> f;
    parent.clear();
    child.clear();
    for (int i = 1; i <= 200000; i++) {
        parent[i] = i;
        child[i] = 1;
    }
    map<string, int> m;
    int cnt = 0;
    for (int i = 0; i < f; i++) {
        string a, b;
        cin >> a >> b;
        int idx_a, idx_b;
        if (m[a] == 0)
            m[a] = ++cnt;
        if (m[b] == 0)
            m[b] = ++cnt;
        cout << union_parent(m[a], m[b]) << "\n";
    }
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
union-find 살짝 응용 문제
*/
