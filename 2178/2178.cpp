#include <iostream>
#include <string>
#include <queue>

using namespace std;

int maze[100][100] = {0};
int dist[100][100];
bool visited[100][100] = {false};
int N, M;

void bfs(int x, int y) {

}
int main() {
    cin >> N >> M;
    fill(dist[0], dist[99], 1000);
    for(int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < M; j++) {
            maze[i][j] = tmp[j];
        }
    }
    dist[0][0] = 1;
    bfs(0, 0);
    cout << maze[N - 1][M - 1] << endl;
    return 0;
}