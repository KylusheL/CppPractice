#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    int n, result, cnt;
    string board;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cnt = 0;
        result = 0;
        cin >> board;
        for(int j = 0; j < board.size(); j++) {
            if(board[j] == 'O') result += ++cnt;
            else    cnt = 0;
        }
        cout << result << endl;
    }

    return 0;
}
