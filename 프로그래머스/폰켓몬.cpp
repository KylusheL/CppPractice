#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    int answer = 0;
    int i, N = nums.size();
    for(i = 0; i < N; i++) {
        if(answer >= N / 2) break;
        if(i == 0) answer++;
        else if(nums[i] != nums[i - 1]) answer++;
    }
    return answer;
}
