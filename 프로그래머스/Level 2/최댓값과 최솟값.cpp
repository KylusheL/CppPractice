#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    string delim = " ";
    vector<int> numbers;
    int pos = 0;
    while((pos = s.find(delim)) != string::npos) {
        numbers.push_back(stoi(s.substr(0, pos)));
        s.erase(0, pos + delim.length());
    }
    numbers.push_back(stoi(s.substr(0, pos)));
    int min = *min_element(numbers.begin(), numbers.end());
    int max = *max_element(numbers.begin(), numbers.end());
    answer += to_string(min);
    answer += ' ';
    answer += to_string(max);
    return answer;
}
