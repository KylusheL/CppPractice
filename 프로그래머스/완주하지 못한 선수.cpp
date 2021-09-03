#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    int i, N = participant.size();
    for(i = 0; i < N; i++) {
        if(participant[i] != completion[i] || i == N - 1) {
            answer = participant[i];
            break;
        }
    }
    return answer;
}
