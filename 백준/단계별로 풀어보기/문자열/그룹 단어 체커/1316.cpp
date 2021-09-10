#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, count = 0;
    string str;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> str;
        bool gr = true;
        for(int j = 0; j < str.length(); j++) {
            char c = str.at(j);
            for(int k = j + 1; k < str.length(); k++) {
                char next = str.at(k);
                if(c == next) {
                    if(gr) j = k;
                    else {
                        gr = true;
                        break;
                    }
                }
                else gr = false;
            }
            if(gr && (j != (str.length() - 1))) {
                gr = false;
                break;
            }
            gr = true;
        }
        if(gr)  count++;
    }
    cout << count << endl;
    return 0;
}