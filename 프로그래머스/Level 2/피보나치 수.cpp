#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int i;
    int fib[100001];
    fib[0] = 0;
    fib[1] = 1;
    for(i = 2; i <= n; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % 1234567;
    }
    answer = fib[n];
    return answer;
}
