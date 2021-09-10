#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    int answer = n - lost.size();
    int i;
    for(i = 0; i < lost.size(); i++) {
        int student = lost[i];
        auto itr = find(reserve.begin(), reserve.end(), student);
        // has reserve
        if(itr != reserve.end()) {
            reserve.erase(itr);
            answer++;
        }
        else {
            // previous student has reserve
            itr = find(reserve.begin(), reserve.end(), student - 1);
            if(itr != reserve.end()) {
                reserve.erase(itr);
                answer++;
            }
            else {
                // next student is lostone
                itr = find(lost.begin(), lost.end(), student + 1);
                if(itr != lost.end()) continue;
                else {
                    itr = find(reserve.begin(), reserve.end(), student + 1);
                    if(itr != reserve.end()) {
                        reserve.erase(itr);
                        answer++;
                    }
                }
            }
        }
    }
    return answer;
}
