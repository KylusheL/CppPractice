#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    int curr;
    int i, length = absolutes.size();
    for(i = 0; i < length; i++) {
        curr = absolutes[i];
        if(signs[i]) answer += curr;
        else answer -= curr;
    }
    return answer;
}
