#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define INF 1000000000
#define MAX 10000000

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> data(n, {0, 0});
    vector<int> dp(MAX + 1, INF);

    for (int i = 0; i < n; i++) {
        cin >> data[i].first;
    }
    
    for (int i = 0; i < n; i++) {
        cin >> data[i].second;
    }

    sort(data.begin(), data.end());
    dp[0] = 0;
    int max_num = 0;
    for (int i = 0; i < n; i++) {
        int mem = data[i].first;
        int cost = data[i].second;
        int j = max_num;
        
        // INF 처리
        if (mem > max_num) {
            for (j = mem; j > max_num; j--) {
                dp[j] = cost;
            }
        }
        max_num = min(m, max_num + mem);
        while (j >= 0) {
            if (j + mem <= m)
                dp[j + mem] = min(dp[j + mem], dp[j] + cost);
            if (j <= mem)
                dp[j] = min(dp[j], cost);
            j--;
        }
    }

    cout << dp[m] << endl;
    
    return 0;
}

/*
아이디어로 푸는 dp문제
어려웠다...
*/
