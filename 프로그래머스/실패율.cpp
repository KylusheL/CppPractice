#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(const pair<int, float> &a, const pair<int, float> &b) {
    if(a.second == b.second) return a.first < b.first;
    else return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> arrived(N + 2);
    vector<int> failed(N + 2);
    vector<pair<int, float>> failRate;
    
    arrived[0] = stages.size();
    int i;
    for(int stage : stages) failed[stage]++;
    for(i = 1; i <= N; i++) {
        arrived[i] = arrived[i - 1] - failed[i - 1];
    }
    for(i = 1; i <= N; i++) {
        failRate.push_back(pair<int, float>(i, arrived[i] == 0 ? 0.0 : float(failed[i]) / float(arrived[i])));
    }
    sort(failRate.begin(), failRate.end(), cmp);
    for(i = 0; i < N; i++) {
        answer.push_back(failRate[i].first);
    }
    return answer;
}
