#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int cnt = 0;
    char prev = ' ';
    string s;
    getline(cin, s);
    for(int i = 0; i < s.size(); i++) {
        if((prev == ' ') && (s[i] != ' '))  cnt++;
        prev = s[i];
    }

    cout << cnt << endl;

    return 0;
}
