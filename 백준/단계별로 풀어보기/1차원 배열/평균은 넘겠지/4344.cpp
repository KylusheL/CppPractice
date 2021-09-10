#include <iostream>
#include <vector>

using namespace std;

int main() {

    int c, n, cnt;
    int sum;
    double avg;
    vector<int> v;

    cin >> c;

    for(int i = 0; i < c; i++) {
        cin >> n;
        sum = 0;
        cnt = 0;
        for(int j = 0; j < n; j++) {
            int score;
            cin >> score;
            v.push_back(score);
            sum += score;
        }
        avg = (double)(sum/n);
        for(int j = 0; j < n; j++) {
            if(v.at(j) > avg) {
                cnt++;
            }
        }
        cout << fixed;
        cout.precision(3);
        cout << 100.000 * (double)cnt / (double)n << '%' << endl;
        v.clear();
    }


    return 0;
}
