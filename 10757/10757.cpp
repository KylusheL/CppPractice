#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string addStr(string, string);
int main() {
    string a, b, res;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    res = addStr(a, b);
    reverse(res.begin(), res.end());
    cout << res << endl;
    return 0;
}

string addStr(string a, string b) {
    string result = "";
    int p, q, r = 0;
    int len = max(a.length(), b.length());
    for(int i = 0; i < len; i++) {
        p = (a.length() < (i + 1)) ? 0 : a.at(i) - '0';
        q = (b.length() < (i + 1)) ? 0 : b.at(i) - '0';
        result += ((p + q + r) % 10) + '0';
        r = (p + q + r) / 10;
    }
    if(r != 0)  result += r + '0';
    return result;
}