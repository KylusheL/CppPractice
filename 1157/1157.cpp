#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> v(26);
    string s;
    int mx = 0;
    bool same = false;

    cin >> s;

    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        if((c >= 'A') && (c <= 'Z')) v[c - 'A']++;
        if((c >= 'a') && (c <= 'z')) v[c - 'a']++;
    }
    for(int i = 1; i < v.size(); i++) {
        if(v[i] > v[mx]) {
            mx = i;
            same = false;
        }
        else if(v[i] == v[mx]) {
            same = true;
        }
    }

    if(same)    cout << '?' << endl;
    else        cout << (char)(mx + 'A') << endl;

    return 0;
}
