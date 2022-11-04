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

typedef pair<int, int> pii;

double get_distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pii> store(n, {0, 0});
    for (int i = 0; i < n; i++)
        cin >> store[i].first >> store[i].second;

    double max_dist = 40000.0;
    double x = store[0].first;
    double y = store[0].second;

    for (int i = 0; i < n; i++) {
        double tx = (double)store[i].first;
        double ty = (double)store[i].second;
        double tmax_dist = 0.0;
        for (int j = 0; j < n; j++) {
            double ttx = (double)store[j].first;
            double tty = (double)store[j].second;
            tmax_dist = max(tmax_dist, get_distance(tx, ty, ttx, tty));
        }
        if (tmax_dist < max_dist) {
            max_dist = tmax_dist;
            x = tx;
            y = ty;
        }
    }

    cout << x << ' ' << y << endl;
    
    return 0;
}

/*
문제에서 요구하는 조건을 정확하게 파악할 것
일단 부딪혀볼 것
*/
