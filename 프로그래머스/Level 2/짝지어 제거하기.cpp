#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = -1;
    vector<int> stack;
    for(char c : s) {
        if(!stack.empty() && c == stack.back())
            stack.pop_back();
        else
            stack.push_back(c);
    }
    
    answer = stack.empty() ? 1 : 0;

    return answer;
}
