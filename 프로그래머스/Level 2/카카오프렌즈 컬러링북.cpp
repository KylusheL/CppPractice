#include <vector>
#include <iostream>

using namespace std;

bool isVisited[100][100];
int globalPicture[100][100];
int M, N;
int dx[4];
int dy[4];

int dfs(int row, int col, int color) {
    isVisited[row][col] = true;
    int result = 1;
    int i;
    int rowNext, colNext;
    for(i = 0; i < 4; i++) {
        rowNext = row + dy[i];
        colNext = col + dx[i];
        if((rowNext >= 0 && rowNext < M) && (colNext >= 0 && colNext < N)) {
            if((!isVisited[rowNext][colNext]) && globalPicture[rowNext][colNext] == color) {
                result += dfs(rowNext, colNext, color);
            }
        }
    }
    return result;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int row, col;
    M = m;
    N = n;
    dx[0] = -1; dx[1] = 0;  dx[2] = 1;  dx[3] = 0;
    dy[0] = 0;  dy[1] = 1;  dy[2] = 0;  dy[3] = -1;
    for(row = 0; row < m; row++) {
        for(col = 0; col < n; col++) {
            isVisited[row][col] = picture[row][col] ? false : true;
            globalPicture[row][col] = picture[row][col];
        }
    }
    
    for(row = 0; row < m; row++) {
        for(col = 0; col < n; col++) {
            if(!isVisited[row][col]) {
                int color = picture[row][col];
                int size_of_area = dfs(row, col, color);
                number_of_area++;
                if(size_of_area > max_size_of_one_area)
                    max_size_of_one_area = size_of_area;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
