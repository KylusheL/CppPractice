#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> jewel(n);
    multiset<int> bag;
    
    for (int i = 0; i < n; i++) {
        cin >> jewel[i].second >> jewel[i].first;
    }
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        bag.insert(x);
    }
    sort(jewel.rbegin(), jewel.rend());
    
    int cnt = 0;
    long long result = 0;
    for (int i = 0; i < n; i++) {
        int value = jewel[i].first;
        int target = jewel[i].second;

        auto it = bag.lower_bound(target);
        if (it == bag.end())
            continue;
        result += value;
        bag.erase(it);
    }
    
    cout << result << endl;
    
    return 0;
}

/*
multiset, lower_bound, iterator를 적극 활용할 
*/
