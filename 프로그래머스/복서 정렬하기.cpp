#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

bool cmp(const tuple<double, int, int, int> &a, const tuple<double, int, int, int> &b) {
    if(get<0>(a) == get<0>(b)) {
        if(get<1>(a) == get<1>(b)) {
            if(get<2>(a) == get<2>(b)) {
                return get<3>(a) < get<3>(b);
            }
            return get<2>(a) > get<2>(b);
        }
        return get<1>(a) > get<1>(b);
    }
    return get<0>(a) > get<0>(b);
}

vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    int i, j, N = weights.size();
    vector<tuple<double, int, int, int>> record;
    for(i = 0; i < N; i++) {
        int playCount = 0;
        int winCount = 0;
        int heavyWinCount = 0;
        for(j = 0; j < N; j++) {
            switch(head2head[i][j]) {
                case 'W':
                    winCount++;
                    if(weights[i] < weights[j])
                        heavyWinCount++;
                case 'L':
                    playCount++;
                    break;
            }
        }
        double rate = (playCount == 0) ?
                        0.0 :
                        double(winCount) / double(playCount);
        record.push_back(make_tuple(rate, heavyWinCount, weights[i], i + 1));
    }
    sort(record.begin(), record.end(), cmp);
    for(i = 0; i < N; i++) {
        answer.push_back(get<3>(record[i]));
    }
    return answer;
}
