/**********************************************************************
작성일 : 2022-6-28
문제 :
	어떤 두 수의 최대공약수와 최대공배수가 주어질 때, 두 수를 구하라.
	답이 여러개만 합이 최소인 값을 구하라.
풀이 :
	유클리드 호제법을 활용하여 gcd를 구하고, gcd * lcm = a * b의 성질을 활용하였다.
	이때, 두 수의 곱이 int값의 범위를 벗어나기 때문에 overflow를 조심해야한다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O()
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define INF 1000000000
typedef long long ll;

ll GCD, LCM;
vector<ll> cand;

ll gcd(ll a, ll b) {
	int r;
	while (b > 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

pair<ll, ll> solve() {
	ll a = INF;
	ll b = INF;
	int len = (int)cand.size();

	for (int i = 0; i < len; i++) {
		for (int j = i; j < len; j++) {
			if (cand[i] + cand[j] < a + b) {
				if (gcd(cand[i], cand[j]) == GCD && cand[i] * cand[j] == GCD * LCM) {
					a = cand[i];
					b = cand[j];
				}
			}
		}
	}

	return { a, b };
}

void init() {
	cin >> GCD >> LCM;

	for (ll i = 1; i * i <= LCM; i++) {
		if (LCM % i == 0) {
			cand.push_back(i);
			if (i != LCM / i)
				cand.push_back(LCM / i);
		}
	}
	sort(cand.begin(), cand.end());
}

int main(void) {
	fastio;
	init();

	pair<int, int> ans = solve();

	cout << ans.first << ' ' << ans.second;
}