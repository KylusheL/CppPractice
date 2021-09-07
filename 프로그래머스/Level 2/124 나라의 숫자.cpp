#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    vector<int> stack;
    n--;
    while(n >= 0) {
        stack.push_back(n % 3);
        n -= 3;
        if(n < 0) break;
        n /= 3;
    }
    while(!stack.empty()) {
        switch(stack.back()) {
            case 0:
                answer.push_back('1');
                break;
            case 1:
                answer.push_back('2');
                break;
            case 2:
                answer.push_back('4');
                break;
        }
        stack.pop_back();
    }
    return answer;
}
