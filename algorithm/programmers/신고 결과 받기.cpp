#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vstring;

int n;
int reportCount[1001];
int adjlist[1001][1001];
map<string, int> id;

vstring split(string s, char delim) {
    vector<string> retval;
    stringstream os(s);
    string tmp;

    while (getline(os, tmp, delim)) {
        retval.push_back(tmp);
    }

    return retval;
}

void init(vstring idList, vstring reportList) {
    n = (int)idList.size();
    for (int i = 1; i <= n; i++) {
        id[idList[i - 1]] = i;
    }
    for (string& s : reportList) {
        vstring ret = split(s, ' ');
        adjlist[id[ret[0]]][id[ret[1]]] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (adjlist[i][j])
                reportCount[j]++;
        }
    }
}

vector<int> solution(vstring id_list, vstring report, int k) {
    init(id_list, report);

    vector<int> ans; 
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (adjlist[i][j] && reportCount[j] >= k)
                cnt++;
        }
        ans.push_back(cnt);
    }
    return ans;
}