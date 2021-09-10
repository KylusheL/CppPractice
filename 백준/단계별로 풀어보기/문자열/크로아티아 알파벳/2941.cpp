#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    char tmp;
    cin >> input;
    int count = 0;

    for(int i = 0; i < input.length(); i++) {
        char chaerin = input.at(i);
        if(i != (input.length() - 1)) {
            tmp = input.at(i + 1);
            switch (chaerin)
            {
            case 'c':
                if((tmp == '=') || (tmp == '-')) i++;
                break;
            case 'd':
                if(tmp == '-') i++;
                else if((tmp == 'z') && (i < input.length() - 2)) {
                    if(input.at(i + 2) == '=') {
                        i += 2;
                    }
                }
                break;
            case 'l':
                if(tmp == 'j') i++;
                break;
            case 'n':
                if(tmp == 'j') i++;
                break;
            case 's':
                if(tmp == '=') i++;
                break;
            case 'z':
                if(tmp == '=') i++;
                break;
            default:
                break;
            }
        }
        count++;
    }
    cout << count << endl;
    return 0;
}