#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> scores(3);
    int i, N = answers.size();
    int curr;
    for(int i = 0; i < N; i++) {
        curr = answers[i];
        // No. 1
        if((i % 5) == (curr - 1)) scores[0]++;
        // No. 2
        if((i % 2) == 0) scores[1] = (curr == 2) ? scores[1] + 1 : scores[1];
        else {
            switch(i % 8) {
                case 1:
                    if(curr == 1) scores[1]++;
                    break;
                case 3:
                    if(curr == 3) scores[1]++;
                    break;
                case 5:
                    if(curr == 4) scores[1]++;
                    break;
                case 7:
                    if(curr == 5) scores[1]++;
                    break;
            }
        }
        // No. 3
        switch(i % 10) {
            case 0:
            case 1:
                if(curr == 3) scores[2]++;
                break;
            case 2:
            case 3:
                if(curr == 1) scores[2]++;
                break;
            case 4:
            case 5:
                if(curr == 2) scores[2]++;
                break;
            case 6:
            case 7:
                if(curr == 4) scores[2]++;
                break;
            case 8:
            case 9:
                if(curr == 5) scores[2]++;
                break;
        }
    }
    if(scores[0] >= scores[1]) {
        if(scores[0] >= scores[2]) {
            answer.push_back(1);
            if(scores[0] == scores[1]) answer.push_back(2);
            if(scores[0] == scores[2]) answer.push_back(3);
        }
        else answer.push_back(3);
    }
    else {
        if(scores[1] >= scores[2]) {
            answer.push_back(2);
            if(scores[1] == scores[2]) answer.push_back(3);
        }
        else answer.push_back(3);
    }
    return answer;
}
