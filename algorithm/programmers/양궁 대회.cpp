#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, scoreDiff;
int score[11], info[11], ans[11];
bool canWin = false;

void change() {
    ll s = 0, a = 0;
    for (int i = 0; i <= 10; i++) {
        s = s * 10 + (ll)score[i];
        a = a * 10 + (ll)ans[i];
    }

    if (s > a) {
        for (int i = 0; i <= 10; i++)
            ans[i] = score[i];
    }
}

void compare_score() {
    int u = 0, l = 0;
    for (int i = 0; i <= 10; i++) {
        if (score[i] == 0 && info[i] == 0) continue;
        else if (score[i] > info[i]) l += i;
        else u += i;
    }

    if (l > u) {
        canWin = true;
        if (scoreDiff < l - u) {
            scoreDiff = l - u;
            for (int i = 0; i <= 10; i++)
                ans[i] = score[i];
        }
        else if (scoreDiff == l - u) {
            change();
        }
    }
}

void combination(int cnt, int cur) {
    if (cnt == n) {
        compare_score();
        return;
    }

    for (int i = cur; i <= 10; i++) {
        score[i]++;
        combination(cnt + 1, i);
        score[i]--;
    }
}

void init(int N, vector<int> Info) {
    n = N;
    for (int i = 0; i <= 10; i++)
        info[i] = Info[10 - i];
}

vector<int> solution(int N, vector<int> Info) {
    init(N, Info);
    
    combination(0, 0);

    vector<int> ret;
    if (canWin) {
        for (int i = 0; i <= 10; i++)
            ret.push_back(ans[10 - i]);
    }
    else {
        ret.push_back(-1);
    }
    return ret;
}