#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
int arr[25][25];
bool checked[25][25] = {false};
int dfs(int row, int col) {
    checked[row][col] = true;
    int result = 1;
    //left
    if((col > 0) && arr[row][col - 1] && !checked[row][col - 1])
        result += dfs(row, col - 1);
    //up
    if((row > 0) && arr[row - 1][col] && !checked[row - 1][col])
        result += dfs(row - 1, col);
    //right
    if((col < N - 1) && arr[row][col + 1] && !checked[row][col + 1])
        result += dfs(row, col + 1);
    //down
    if((row < N - 1) && arr[row + 1][col] && !checked[row + 1][col])
        result += dfs(row + 1, col);
    return result;
};

int main() {
    cin >> N;
    vector<int> complex;

    for(int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < N; j++)
            arr[i][j] = tmp[j] - '0';
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(arr[i][j] && !checked[i][j]) {
                complex.push_back(dfs(i, j));
            }
        }
    }
    sort(complex.begin(), complex.end());
    cout << complex.size() << endl;
    for(int i = 0; i < complex.size(); i++)
        cout << complex[i] << endl;

    return 0;
}