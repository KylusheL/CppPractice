#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int i, length = s.size();
    for(i = 0; i < length; i++) {
        char curr = s[i];
        char next = s[i + 1];
        answer *= 10;
        if((curr >= '0') && (curr <= '9')) {
            answer += curr - '0';
        }
        else {
            switch(curr) {
                case 'z':
                    i += 3;
                    break;
                case 'o':
                    answer += 1;
                    i += 2;
                    break;
                case 't':
                    if(next == 'w') {
                        answer += 2;
                        i += 2;
                    }
                    else {
                        answer += 3;
                        i += 4;
                    }
                    break;
                case 'f':
                    if(next == 'o') answer += 4;
                    else answer += 5;
                    i += 3;
                    break;
                case 's':
                    if(next == 'i') {
                        answer += 6;
                        i += 2;
                    }
                    else {
                        answer += 7;
                        i += 4;
                    }
                    break;
                case 'e':
                    answer += 8;
                    i += 4;
                    break;
                case 'n':
                    answer += 9;
                    i += 3;
                    break;
            }
        }
    }
    return answer;
}
