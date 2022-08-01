#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
int n, s;
vector<int> num(40, 0);

void backtracking(long long total, int idx, const int end, vector<long long>& dest) {
    if (idx == end) {
        dest.push_back(total);
    } else {
        backtracking(total + num[idx], idx + 1, end, dest);
        backtracking(total, idx + 1, end, dest);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> num[i];

    int mid = (n + 1) / 2;
    vector<long long> front_vec;
    vector<long long> back_vec;
    backtracking(0, 0, mid, front_vec);
    backtracking(0, mid, n, back_vec);

    long long result = 0;
    sort(back_vec.begin(), back_vec.end());
    for (auto x : front_vec) {
        result += upper_bound(back_vec.begin(), back_vec.end(), s - x) - lower_bound(back_vec.begin(), back_vec.end(), s - x);
    }
    if (s == 0)
        result--;
    cout << result << endl;
    
    return 0;
}

/*
Meet in the middle 알고리즘 입문용
*/
