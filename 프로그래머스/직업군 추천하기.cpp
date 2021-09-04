#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    int i, j, N = languages.size();
    map<string, int> prefMap;
    for(i = 0; i < N; i++)
        prefMap.insert(pair<string, int>(languages[i], preference[i]));
    
    int max = 0;
    for(i = 0; i < table.size(); i++) {
        int score = 0;
        istringstream ss(table[i]);
        string stringBuffer;
        vector<string> tableColumn;
        while(getline(ss, stringBuffer, ' '))
            tableColumn.push_back(stringBuffer);
        for(j = 1; j < tableColumn.size(); j++) {
            string language = tableColumn[j];
            auto itr = prefMap.find(language);
            if(itr != prefMap.end())
                score += (6 - j) * prefMap[language];
        }
        if(score > max) {
            max = score;
            answer = tableColumn[0];
        }
        else if(score == max) {
            if(tableColumn[0] < answer)
                answer = tableColumn[0];
        }
    }
    return answer;
}
