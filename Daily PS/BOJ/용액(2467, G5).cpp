#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> data;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        data.push_back(x);
    }
    int left = 0, right = n - 1;
    if (data[0] >= 0) {
        left = 0;
        right = 1;
    } else if (data[n - 1] <= 0) {
        left = n - 2;
        right = n - 1;
    } else {
        int target;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (data[mid] >= 0)
                right = mid - 1;
            else {
                target = mid;
                left = mid + 1;
            }
        }
        left = target;
        right = target + 1;
        int min_sum = data[left] + data[right];
        int tmp_left = left, tmp_right = right;
        while (tmp_left >= 0 && tmp_right <= n - 1 && min_sum != 0) {
            int tmp_sum = data[tmp_left] + data[tmp_right];
            if (abs(tmp_sum) < abs(min_sum)) {
                left = tmp_left;
                right = tmp_right;
                min_sum = tmp_sum;
            }
            if (tmp_sum > 0) {
                tmp_left--;
            } else if (tmp_sum < 0) {
                tmp_right++;
            } else break;
        }
        if (target > 0 && abs(data[target] + data[target - 1]) < abs(min_sum)) {
            left = target - 1;
            right = target;
            min_sum = data[target] + data[target - 1];
        }
        if (target + 2 < n && abs(data[target + 1] + data[target + 2]) < abs(min_sum)) {
            left = target + 1;
            right = target + 2;
            min_sum = data[target + 1] + data[target + 2];
        }
    }
    cout << data[left] << ' ' << data[right] << endl;
    return 0;
}

/*
사이드케이스를 잘 고려해야하는 문제
*/
