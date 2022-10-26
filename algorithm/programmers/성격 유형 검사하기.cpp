#include <bits/stdc++.h>
using namespace std;

map<char, int> score;

void init() {
    score['R'] = 0; score['T'] = 0;
    score['C'] = 0; score['F'] = 0;
    score['J'] = 0; score['M'] = 0;
    score['A'] = 0; score['N'] = 0;
}

string solution(vector<string> survey, vector<int> choices) {
    init();

    int n = survey.size();
    for (int i = 0; i < n; i++) {
        if (choices[i] >= 1 && choices[i] <= 3)
            score[survey[i][0]] += (4 - choices[i]);
        else if (choices[i] >= 5)
            score[survey[i][1]] += (choices[i] - 4);
    }

    string ans;
    ans.push_back((score['R'] >= score['T']) ? 'R' : 'T');
    ans.push_back((score['C'] >= score['F']) ? 'C' : 'F');
    ans.push_back((score['J'] >= score['M']) ? 'J' : 'M');
    ans.push_back((score['A'] >= score['N']) ? 'A' : 'N');
    return ans;
}