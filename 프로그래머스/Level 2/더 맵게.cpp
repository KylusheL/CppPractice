#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> scovilleQueue;
    for(int element : scoville) {
        scovilleQueue.push(element);
    }
    while(scovilleQueue.top() < K) {
        int min = scovilleQueue.top();
        scovilleQueue.pop();
        if(scovilleQueue.empty()) {
            answer = -1;
            break;
        }
        min += 2 * scovilleQueue.top();
        scovilleQueue.pop();
        scovilleQueue.push(min);
        answer++;
    }
    return answer;
}
