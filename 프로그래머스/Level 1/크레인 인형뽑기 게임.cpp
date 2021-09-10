#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int row, col, N = board.size();
    int i, length = moves.size();
    int curr;
    vector<int> stack;
    for(i = 0; i < length; i++) {
        col = moves[i] - 1;
        for(row = 0; row < N; row++) {
            curr = board[row][col];
            if(curr != 0) {
                board[row][col] = 0;
                if(!stack.empty() && (stack.back() == curr)) {
                    stack.pop_back();
                    answer += 2;
                }
                else stack.push_back(curr);
                break;
            }
        }
    }
    return answer;
}
