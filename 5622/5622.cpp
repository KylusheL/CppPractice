#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {
    string str;
    cin >> str;
    int result = 0;
    for(int i = 0; i < str.size(); i++) {
        char c = str[i];
        if(c >= 'A' && c <= 'C') result += 3;
        else if(c <= 'F')   result += 4;
        else if(c <= 'I')   result += 5;
        else if(c <= 'L')   result += 6;
        else if(c <= 'O')   result += 7;
        else if(c <= 'S')   result += 8;
        else if(c <= 'V')   result += 9;
        else if(c <= 'Z')   result += 10;
    }
    cout << result << endl;

    return 0;
}
