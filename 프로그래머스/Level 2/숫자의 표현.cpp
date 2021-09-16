#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int i;
    for(i = 1; (1 + i) * i <= 2 * n; i++) {
        if(i % 2 == 0) {
            int k = i / 2;
            if(n % k == 0 && (n / k) % 2 != 0) answer++;
        } else {
            if(n % i == 0) answer++;
        }
    }
    return answer;
}
