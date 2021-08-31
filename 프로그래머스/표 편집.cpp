#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    set<int> table;
    vector<int> deleted;
    int i, j, X, cut, recover;
    // initialize table
    for(i = 0; i < n; i++) table.insert(i);
    
    // read command
    int len = cmd.size();
    string command;
    set<int>::iterator curr = table.find(k);
    for(i = 0; i < len; i++) {
        command = cmd[i];
        switch(command[0]) {
            case 'U':
                X = stoi(command.substr(2));
                for(j = 0; j < X; j++)
                    curr--;
                break;
            case 'D':
                X = stoi(command.substr(2));
                for(j = 0; j < X; j++)
                    curr++;
                break;
            case 'C':
                cut = *curr;
                curr++;
                // last row
                if(curr == table.end()) {
                    curr--;
                    curr--;
                }
                table.erase(table.find(cut));
                deleted.push_back(cut);
                break;
            case 'Z':
                recover = deleted.back();
                deleted.pop_back();
                table.insert(recover);
                break;
            default:
                break;
        }
    }
    for(i = 0; i < n; i++) {
        if(table.find(i) != table.end())
            answer.push_back('O');
        else
            answer.push_back('X');
    }
    
    return answer;
}
