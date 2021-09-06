#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.size();
    int cut, i, N = s.size();
    for(cut = 1; cut <= N / 2; cut++) {
        string candidate = "";
        string comparing = s.substr(0, cut);
        int match = 1;
        for(i = cut; i < N - cut + 1; i += cut) {
            string curr = s.substr(i, cut);
            if(comparing.compare(curr) == 0) match++;
            else {
                if(match >= 2)
                    candidate += to_string(match);
                candidate += comparing;
                comparing = curr;
                match = 1;
            }
        }
        if(match >= 2)
            candidate += to_string(match);
        candidate += comparing;
        if(i < N)
            candidate += s.substr(i);
        if(candidate.size() < answer) answer = candidate.size();
    }
    return answer;
}
