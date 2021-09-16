#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool isHead = true;
    for(char c : s) {
        if(isHead) {
            if(c >= 'a' && c <= 'z')
                answer += c -'a' + 'A';
            else {
                answer += c;
                if(c == ' ') continue;
            }
            isHead = false;
        } else {
            if(c >= 'A' && c <= 'Z')
                answer += c -'A' + 'a';
            else {
                if(c == ' ')
                    isHead = true;
                answer += c;
            }
        }
    }
    return answer;
}
