#include <vector>
#include <iostream>
using namespace std;

bool isPrime(int num) {
    int i;
    for(i = 2; i * i <= num; i++) {
        if(num % i == 0) return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    int num;
    int i, j, k, N = nums.size();
    for(i = 0; i < N - 2; i++) {
        for(j = i + 1; j < N - 1; j++) {
            for(k = j + 1; k < N; k++) {
                num = nums[i] + nums[j] + nums[k];
                if(isPrime(num)) answer++;
            }
        }
    }
    
    return answer;
}
