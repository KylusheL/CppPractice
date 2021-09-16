#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
    int i, N = A.size();
    for(i = 0; i < N; i++)
        answer += A[i] * B[i];

    return answer;
}
