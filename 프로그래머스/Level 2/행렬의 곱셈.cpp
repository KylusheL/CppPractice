#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int i, j, k;
    int A = arr1.size(), B = arr2.size(), C = arr2[0].size();
    for(i = 0; i < A; i++) {
        vector<int> line;
        for(k = 0; k < C; k++) {
            int sum = 0;
            for(j = 0; j < B; j++) {
                sum += arr1[i][j] * arr2[j][k];
            }
            line.push_back(sum);
        }
        answer.push_back(line);
    }
    return answer;
}
