#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int score = 0, unknown = 0;
    int i, num;
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    for(i = 0; i < 6; i++) {
        num = lottos[i];
        if(num == 0) unknown++;
        else {
            auto it = find(win_nums.begin(), win_nums.end(), num);
            if(it == win_nums.end()) continue;
            else score++;
        }
    }
    answer.push_back((score + unknown) >= 1 ? 7 - (score + unknown) : 6);
    answer.push_back(score >= 1 ? 7 - score : 6);
    
    return answer;
}
