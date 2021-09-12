#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> leftDays;
    int i, N = progresses.size();
    for(i = 0; i < N; i++) {
        double left = 100.0 - progresses[i];
        left = ceil(left / speeds[i]);
        leftDays.push_back((int)left);
    }
    int curr = leftDays[0], count = 0;
    for(int left : leftDays) {
        if(curr >= left) {
            count++;
        }
        else {
            answer.push_back(count);
            count = 1;
            curr = left;
        }
    }
    answer.push_back(count);
    
    return answer;
}
