#include <iostream>
#include <vector>
#include <string>

using namespace std;

string reverse_string(string str) {
    string result = "";
    for(int i = (str.size() - 1); i >= 0; i--) {
        result.push_back(str[i]);
    }
    return result;
}

string compare_string(string s1, string s2) {
    for(int i = 0; i < s1.size(); i++) {
        int a = s1[i] - '0';
        int b = s2[i] - '0';
        if(a > b)   return s1;
        if(a < b)   return s2;
    }
}

int main() {

    string s1, s2;
    cin >> s1 >> s2;

    cout << compare_string(reverse_string(s1), reverse_string(s2)) << endl;

    return 0;
}
