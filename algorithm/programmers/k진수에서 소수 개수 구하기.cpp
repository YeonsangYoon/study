#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k, len;
bool mark[100][100];
string s;

bool is_prime(ll num) {
    if (num <= 1)
        return false;
    for (ll i = 2; (i * i) <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

ll stringToInt(string num) {
    ll ret = 0;
    for (char& c : num) {
        ll cur = (ll)c - '0';
        ret = 10 * ret + cur;
    }
    return ret;
}

void init(int N, int K) {
    n = N; k = K;

    stack<char> st;
    while (N > 0) {
        st.push('0' + N % K);
        N /= K;
    }
    while (!st.empty()) {
        s.push_back(st.top());
        st.pop();
    }
    len = (int)s.size();
}

void dnq(int l, int r) {
    if (l > r) return;

    bool flag = true;
    string tmp;
    for (int i = l; i <= r; i++) {
        if (s[i] == '0')
            flag = false;
        tmp.push_back(s[i]);
    }
    if (is_prime(stringToInt(tmp)) && flag)
        mark[l][r] = true;

    for (int i = l; i <= r; i++) {
        if (s[i] == '0') {
            dnq(l, i - 1);
            dnq(i + 1, r);
        }
    }
}

int solution(int N, int K) {
    init(N, K);
    dnq(0, len - 1);

    int ans = 0;
    for (int i = 0; i <= len; i++) {
        for (int j = 0; j <= len; j++) {
            if (mark[i][j])
                ans++;
        }
    }
    return ans;
}