#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int N = s.size();
    answer = s.substr((N + 1) / 2 - 1, 2 - N % 2);
    return answer;
}
