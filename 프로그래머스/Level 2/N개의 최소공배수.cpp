#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    answer = *min_element(arr.begin(), arr.end());
    for(int curr : arr) {
        int temp = answer;
        while(answer % curr != 0) {
            answer += temp;
        }
    }
    return answer;
}
