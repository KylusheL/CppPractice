#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#define INF 1000000000

using namespace std;

void move(int x, vector<string>& board, int rx, int ry, int bx, int by);
vector<string>& left(int x, vector<string>& board, int rx, int ry, int bx, int by);
vector<string>& right(int x, vector<string>& board, int rx, int ry, int bx, int by);
vector<string>& up(int x, vector<string>& board, int rx, int ry, int bx, int by);
vector<string>& down(int x, vector<string>& board, int rx, int ry, int bx, int by);
int result = 100;
int n, m;
int cnt = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    vector<string> graph(n);
    int rx, ry, bx, by;
    for (int i = 0; i < n; i++) {
        cin >> graph[i];
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 'R') {
                rx = i;
                ry = j;
            } else if (graph[i][j] == 'B') {
                bx = i;
                by = j;
            }
        }
    }
    move(0, graph, rx, ry, bx, by);
    if (result == 100)
        result = -1;
    cout << result << endl;
    
    return 0;
}

void move(int x, vector<string>& board, int rx, int ry, int bx, int by) {
    if (x == 10)
        return;
    board = left(x, board, rx, ry, bx, by);
    board = right(x, board, rx, ry, bx, by);
    board = up(x, board, rx, ry, bx, by);
    board = down(x, board, rx, ry, bx, by);
}
vector<string>& left(int x, vector<string>& board, int rx, int ry, int bx, int by) {
    vector<string> tmp = board;
    bool retry = false;
    bool goal = false;
    while (ry > 1) {
        ry--;
        if (tmp[rx][ry] == '.') {
            tmp[rx][ry + 1] = '.';
            tmp[rx][ry] = 'R';
        } else if (tmp[rx][ry] == '#') {
            ry++;
            break;
        } else if (tmp[rx][ry] == 'B') {
            retry = true;
            ry++;
            break;
        } else if (tmp[rx][ry] == 'O') {
            tmp[rx][ry + 1] = '.';
            goal = true;
            break;
        }
    }
    while (by > 1) {
        by--;
        if (tmp[bx][by] == '.') {
            tmp[bx][by + 1] = '.';
            tmp[bx][by] = 'B';
        } else if (tmp[bx][by] == '#' || tmp[bx][by] == 'R') {
            by++;
            break;
        } else if (tmp[bx][by] == 'O') {
            return board;
        }
    }
    if (retry) {
        while (ry > 1) {
            ry--;
            if (tmp[rx][ry] == '.') {
                tmp[rx][ry + 1] = '.';
                tmp[rx][ry] = 'R';
            } else if (tmp[rx][ry] == 'B') {
                ry++;
                break;
            } else if (tmp[rx][ry] == 'O') {
                tmp[rx][ry + 1] = '.';
                goal = true;
                break;
            }
        }
    }

    if (goal) {
        result = min(result, x + 1);
    }
    else
        move(x + 1, tmp, rx, ry, bx, by);
    return board;
}
vector<string>& right(int x, vector<string>& board, int rx, int ry, int bx, int by) {
    vector<string> tmp = board;
    bool retry = false;
    bool goal = false;
    while (ry < m - 2) {
        ry++;
        if (tmp[rx][ry] == '.') {
            tmp[rx][ry - 1] = '.';
            tmp[rx][ry] = 'R';
        } else if (tmp[rx][ry] == '#') {
            ry--;
            break;
        } else if (tmp[rx][ry] == 'B') {
            retry = true;
            ry--;
            break;
        } else if (tmp[rx][ry] == 'O') {
            tmp[rx][ry - 1] = '.';
            goal = true;
            break;
        }
    }
    while (by < m - 2) {
        by++;
        if (tmp[bx][by] == '.') {
            tmp[bx][by - 1] = '.';
            tmp[bx][by] = 'B';
        } else if (tmp[bx][by] == '#' || tmp[bx][by] == 'R') {
            by--;
            break;
        } else if (tmp[bx][by] == 'O') {
            return board;
        }
    }
    if (retry) {
        while (ry < m - 2) {
            ry++;
            if (tmp[rx][ry] == '.') {
                tmp[rx][ry - 1] = '.';
                tmp[rx][ry] = 'R';
            } else if (tmp[rx][ry] == 'B') {
                ry--;
                break;
            } else if (tmp[rx][ry] == 'O') {
                tmp[rx][ry - 1] = '.';
                goal = true;
                break;
            }
        }
    }
    
    if (goal) {
        result = min(result, x + 1);
    }
    else
        move(x + 1, tmp, rx, ry, bx, by);
    return board;
}
vector<string>& up(int x, vector<string>& board, int rx, int ry, int bx, int by) {
    vector<string> tmp = board;
    bool retry = false;
    bool goal = false;
    while (rx > 1) {
        rx--;
        if (tmp[rx][ry] == '.') {
            tmp[rx + 1][ry] = '.';
            tmp[rx][ry] = 'R';
        } else if (tmp[rx][ry] == '#') {
            rx++;
            break;
        } else if (tmp[rx][ry] == 'B') {
            retry = true;
            rx++;
            break;
        } else if (tmp[rx][ry] == 'O') {
            tmp[rx + 1][ry] = '.';
            goal = true;
            break;
        }
    }
    while (bx > 1) {
        bx--;
        if (tmp[bx][by] == '.') {
            tmp[bx + 1][by] = '.';
            tmp[bx][by] = 'B';
        } else if (tmp[bx][by] == '#' || tmp[bx][by] == 'R') {
            bx++;
            break;
        } else if (tmp[bx][by] == 'O') {
            return board;
        }
    }
    if (retry) {
        while (rx > 1) {
            rx--;
            if (tmp[rx][ry] == '.') {
                tmp[rx + 1][ry] = '.';
                tmp[rx][ry] = 'R';
            } else if (tmp[rx][ry] == 'B') {
                rx++;
                break;
            } else if (tmp[rx][ry] == 'O') {
                tmp[rx + 1][ry] = '.';
                goal = true;
                break;
            }
        }
    }

    if (goal) {
        result = min(result, x + 1);
    }
    else
        move(x + 1, tmp, rx, ry, bx, by);
    return board;
}
vector<string>& down(int x, vector<string>& board, int rx, int ry, int bx, int by) {
    vector<string> tmp = board;
    bool retry = false;
    bool goal = false;
    while (rx < n - 2) {
        rx++;
        if (tmp[rx][ry] == '.') {
            tmp[rx - 1][ry] = '.';
            tmp[rx][ry] = 'R';
        } else if (tmp[rx][ry] == '#') {
            rx--;
            break;
        } else if (tmp[rx][ry] == 'B') {
            retry = true;
            rx--;
            break;
        } else if (tmp[rx][ry] == 'O') {
            tmp[rx - 1][ry] = '.';
            goal = true;
            break;
        }
    }
    while (bx < n - 2) {
        bx++;
        if (tmp[bx][by] == '.') {
            tmp[bx - 1][by] = '.';
            tmp[bx][by] = 'B';
        } else if (tmp[bx][by] == '#' || tmp[bx][by] == 'R') {
            bx--;
            break;
        } else if (tmp[bx][by] == 'O') {
            return board;
        }
    }
    if (retry) {
        while (rx < n - 2) {
            rx++;
            if (tmp[rx][ry] == '.') {
                tmp[rx - 1][ry] = '.';
                tmp[rx][ry] = 'R';
            } else if (tmp[rx][ry] == 'B') {
                rx--;
                break;
            } else if (tmp[rx][ry] == 'O') {
                tmp[rx - 1][ry] = '.';
                goal = true;
                break;
            }
        }
    }
    
    if (goal) {
        result = min(result, x + 1);
    }
    else
        move(x + 1, tmp, rx, ry, bx, by);
    return board;
}

/*
엄청난 노가다 문제
*/
