#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int r;
        string s, result = "";
        cin >> r >> s;
        for(int j = 0; j < s.size(); j++) {
            for(int k = 0; k < r; k++) {
                result.push_back(s[j]);
            }
        }
        cout << result << endl;
    }

    return 0;
}
