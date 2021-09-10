#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int arr[50][50] = {0};
bool checked[50][50] = {false};
int M, N;
void dfs(int row, int col) {
    checked[row][col] = true;
    //left
    if((col > 0) && arr[row][col - 1] && !checked[row][col - 1])
        dfs(row, col - 1);
    //up
    if((row > 0) && arr[row - 1][col] && !checked[row - 1][col])
        dfs(row - 1, col);
    //right
    if((col < M - 1) && arr[row][col + 1] && !checked[row][col + 1])
        dfs(row, col + 1);
    //down
    if((row < N - 1) && arr[row + 1][col] && !checked[row + 1][col])
        dfs(row + 1, col);
}

int main() {
    int T, K, cnt;
    cin >> T;
    for(int i = 0; i < T; i++) {
        memset(arr, 0, sizeof(arr));
        memset(checked, 0, sizeof(checked));
        cnt = 0;
        cin >> M >> N >> K;
        for(int j = 0; j < K; j++) {
            int row, col;
            cin >> col >> row;
            arr[row][col] = 1;
        }
        for(int row = 0; row < N; row++) {
            for(int col = 0; col < M; col++) {
                if(arr[row][col] && !checked[row][col]) {
                    cnt++;
                    dfs(row, col);
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}