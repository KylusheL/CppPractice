#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int k, x = 0, y = 0;
    vector<int> xpos = {0}, ypos = {0};
    cin >> k;
    for (int i = 0; i < 6; i++) {
        int dir, len;
        cin >> dir >> len;
        switch (dir) {
            case 1:
                x += len;
                break;
            case 2:
                x -= len;
                break;
            case 3:
                y -= len;
                break;
            case 4:
                y += len;
                break;
            default:
                break;
        }
        xpos.push_back(x);
        ypos.push_back(y);
    }
    int result = 0;
    for (int i = 0; i < 6; i++) {
        result += xpos[i] * ypos[i + 1];
        result -= xpos[i + 1] * ypos[i];
    }
    if (result < 0) result *= -1;
    cout << result * k / 2 << endl;
    return 0;
}

/*
cpp 감 재활 겸 쉬운 기하문제
*/
