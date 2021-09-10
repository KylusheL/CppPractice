#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    int i, length = a.size();
    for(i = 0; i < length; i++) answer += a[i] * b[i];
    return answer;
}
