#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define INF 9876543210

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<long long int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    sort(data.begin(), data.end());
    
    vector<int> result(3);
    long long int sum = INF;
    int left, mid, right;
    long long int target;
    left = 0;
    right = n - 1;
    vector<long long int>::iterator start, end;
    if (data[0] >= 0) {
        result = {data[0], data[1], data[2]};
    } else if (data[n - 1] <= 0) {
        result = {data[n - 3], data[n - 2], data[n - 1]};
    } else {
        for (left = 0; left < n - 2; left++) {
            for (right = left + 2; right < n; right++) {
                start = data.begin() + left + 1;
                end = data.begin() + right;
                target = -(data[left] + data[right]);
                mid = lower_bound(start, end, target) - data.begin();
                if (right == mid)
                    mid--;
                else if (mid != left + 1 && data[mid] != target) {
                    if (abs(target - data[mid - 1]) < abs(target - data[mid]))
                        mid--;
                }
                if (labs(sum) > labs(data[mid] - target)) {
                    sum = data[mid] - target;
                    result = {data[left], data[mid], data[right]};
                    if (sum == 0)
                        break;
                }
            }
            if (sum == 0)
                break;
        }
    }
    cout << result[0] << ' ' << result[1] << ' ' << result[2] << endl;
    return 0;
}

/*
사이드케이스 처리, lower_bound의 end 위치에 주의할 것
*/
