#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int matrix[100][100];
    int i, j;
    // initialize
    for(i = 0; i < rows; i++) {
        for(j = 0; j < columns; j++) {
            matrix[i][j] = i * columns + j + 1;
        }
    }
    
    for(auto query : queries) {
        int x1 = query[0] - 1;
        int y1 = query[1] - 1;
        int x2 = query[2] - 1;
        int y2 = query[3] - 1;
        int curr, temp = matrix[x1][y1];
        int min = temp;
        for(i = x1; i < x2; i++) {
            curr = matrix[i + 1][y1];
            matrix[i][y1] = curr;
            if(min > curr) min = curr;
        }
        for(i = y1; i < y2; i++) {
            curr = matrix[x2][i + 1];
            matrix[x2][i] = curr;
            if(min > curr) min = curr;
        }
        for(i = x2; i > x1; i--) {
            curr = matrix[i - 1][y2];
            matrix[i][y2]  = curr;
            if(min > curr) min = curr;
        }
        for(i = y2; i > y1 + 1; i--) {
            curr = matrix[x1][i - 1];
            matrix[x1][i] = curr;
            if(min > curr) min = curr;
        }
        matrix[x1][y1 + 1] = temp;
        answer.push_back(min);
    }
    return answer;
}
