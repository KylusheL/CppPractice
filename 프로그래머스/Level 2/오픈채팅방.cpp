#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> nameTable;
    vector<pair<string, bool>> eventTable;
    for(string event : record) {
        string command, id, nickname;
        stringstream ss(event);
        ss >> command;
        ss >> id;
        if(command == "Enter") {
            ss >> nickname;
            if(nameTable.find(id) == nameTable.end()) {
                nameTable.insert(pair<string, string>(id, nickname));
            }
            else nameTable[id] = nickname;
            eventTable.push_back(pair<string, bool>(id, true));
        }
        else if(command == "Leave") {
            eventTable.push_back(pair<string, bool>(id, false));
        }
        else if(command == "Change") {
            ss >> nickname;
            nameTable[id] = nickname;
        }
    }
    for(auto event : eventTable) {
        string notice = "";
        notice += nameTable[event.first];
        if(event.second) notice += "님이 들어왔습니다.";
        else notice += "님이 나갔습니다.";
        answer.push_back(notice);
    }
    return answer;
}
