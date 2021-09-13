#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int N = numbers.size();
    vector<int> numberStack;
    numberStack.push_back(numbers[0]);
    int sum = numbers[0];
    int prev = 0, curr;
    while(!numberStack.empty() || prev >= 0) {
        int stackSize = numberStack.size();
        if(stackSize == N) {
            if(sum == target) answer++;
            prev = numberStack.back();
            numberStack.pop_back();
            sum -= prev;
        }
        else {
            if(prev < 0) {
                prev = numberStack.back();
                numberStack.pop_back();
                sum -= prev;
            }
            else {
                curr = (prev == 0) ? numbers[stackSize] : -prev;
                numberStack.push_back(curr);
                sum += curr;
                prev = 0;
            }
        }
    }
    return answer;
}
