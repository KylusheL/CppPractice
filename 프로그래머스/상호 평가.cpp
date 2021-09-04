#include <string>
#include <vector>

using namespace std;

string solution(vector<vector<int>> scores) {
    int size = scores.size();
    int i, j;
    string answer = "";
    
    
    for(j = 0; j < size; j++) {
        int min = 101;
        int max = -1;
        int self = scores[j][j];
        int sum = 0;
        for(i = 0; i < size; i++) {
            if(i != j) {
                int curr = scores[i][j];
                min = (min > curr) ? curr : min;
                max = (max < curr) ? curr : max;
                sum += curr;
            }
        }
        float avg;
        if((self > max) || (self < min)) {
            avg = sum / (size - 1);
        }
        else {
            avg = (sum + self) / size;
        }
        if(avg >= 90.0) answer.push_back('A');
        else if(avg >= 80.0) answer.push_back('B');
        else if(avg >= 70.0) answer.push_back('C');
        else if(avg >= 50.0) answer.push_back('D');
        else answer.push_back('F');
    }
    return answer;
}
