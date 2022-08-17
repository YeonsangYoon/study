#include <bits/stdc++.h>
using namespace std;

int parkTime[10000];
int accTime[10000];
bool isIn[10000];
set<int> idList;

vector<string> split(string s, char delim) {
    vector<string> ret;
    stringstream os(s);
    string tmp;

    while (getline(os, tmp, delim))
        ret.push_back(tmp);
    return ret;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    memset(isIn, false, sizeof(isIn));

    for (string& record : records) {
        vector<string> tmp = split(record, ' ');
        vector<string> t = split(tmp[0], ':');

        int curTime = stoi(t[0]) * 60 + stoi(t[1]);
        int id = stoi(tmp[1]);
        idList.insert(id);

        if (tmp[2] == "IN") {
            parkTime[id] = curTime;
            isIn[id] = true;
        }
        else {
            accTime[id] += (curTime - parkTime[id]);
            isIn[id] = false;
        }
    }
    
    vector<int> ans;
    set<int>::iterator iter;
    for (iter = idList.begin(); iter != idList.end(); iter++) {
        int id = *iter;
        if (isIn[id]) {
            accTime[id] += (1439 - parkTime[id]);
        }

        int charge = fees[1];
        if (accTime[id] > fees[0])
            charge += ((accTime[id] - 1 - fees[0]) / fees[2] + 1) * fees[3];
        ans.push_back(charge);
    }
    return ans;
}