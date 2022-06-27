#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, target;
    cin >> n >> target;
    vector<int> data;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        data.push_back(x);
    }
    int left = 0, right = 0;
    int sum = data[0], result = 1000000;
    while (left < n) {
        if (sum < target) {
            right++;
            if (right == n)
                break;
            sum += data[right];
        } else {
            if (right - left + 1 < result)
                result = right - left + 1;
            sum -= data[left++];
        }
    }
    if (result == 1000000)
        result = 0;
    cout << result << endl;
    return 0;
}
