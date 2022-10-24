#include <bits/stdc++.h>

using namespace std;
typedef deque<deque<int>> matrix;

void rotate(matrix& m) {
    deque<int> line = m.front();
    m.pop_front();
    m.push_back(line);
}
void shiftRow(matrix& m) {

}

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    matrix cur;
    for (auto& a : rc) {
        deque<int> dq;
        for (int& i : a)
            dq.push_back(i);
        cur.push_back(dq);
    }

    for (string& op : operations) {
        if (op == "Rotate")
            rotate(cur);
        else
            shiftRow(cur);
    }

    vector<vector<int>> ret;
    for (auto& a : cur) {
        vector<int> v;
        for (int& i : a)
            v.push_back(i);
        ret.push_back(v);
    }
    return ret;
}