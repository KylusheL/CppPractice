#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto place : places) {
        int i, j;
        bool ok = true;
        for(i = 0; i < 5; i++) {
            for(j = 0; j < 5; j++) {
                if(place[i][j] == 'P') {
                    if(j < 4 && place[i][j + 1] == 'P')
                        ok = false;
                    if(j < 3 && place[i][j + 2] == 'P' && place[i][j + 1] != 'X')
                        ok = false;
                    if(i < 4 && j < 4 && place[i + 1][j + 1] == 'P' &&
                      (place[i + 1][j] != 'X' || place[i][j + 1] != 'X'))
                        ok = false;
                    if(i < 4 && place[i + 1][j] == 'P')
                        ok = false;
                    if(i < 3 && place[i + 2][j] == 'P' && place[i + 1][j] != 'X')
                        ok = false;
                    if(i < 4 && j > 0 && place[i + 1][j - 1] == 'P' &&
                      (place[i + 1][j] != 'X' || place[i][j - 1] != 'X'))
                        ok = false;
                    if(!ok) break;
                }
            }
            if(!ok) break;
        }
        answer.push_back(ok ? 1 : 0);
    }
    return answer;
}
