#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    vector<int> v(26);
    cin >> s;
    for(int i = 0; i < v.size(); i++) {
        v[i] = -1;
    }
    for(int i = 0; i < s.size(); i++) {
        int idx = s.at(i) - 'a';
        if(v[idx] == -1)   v[idx] = i;
    }
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }

    return 0;
}
