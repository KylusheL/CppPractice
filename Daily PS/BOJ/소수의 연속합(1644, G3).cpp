#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<int> dp(4000001, 1);

vector<int> set_prime(int n) {
    dp[0] = 0;
    dp[1] = 0;
    vector<int> result;
    for (int i = 2; i <= n; i++) {
        if (dp[i] > 0) {
            result.push_back(i);
            for (int j = 2 * i; j <= n; j += i) {
                dp[j] = 0;
            }
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> prime = set_prime(n);
    if (prime.size() > 0) {
        for (int i = 0; i < prime.size() - 1; i++) {
            int acc = prime[i];
            for (int j = i + 1; j < prime.size(); j++) {
                acc += prime[j];
                if (acc > n)
                    break;
                dp[acc]++;
            }
        }
    }
    cout << dp[n] << endl;
    
    return 0;
}
