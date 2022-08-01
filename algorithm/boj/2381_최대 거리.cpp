/**********************************************************************
작성일 : 2022-08-01
작성자 : 윤연상
문제 :
	N(1 ≤ N ≤ 50,000)개의 점들이 있을 때, 최대 L1-metric 거리를 찾으시오.
	두 점의 좌표가 (a, b), (c, d)일 때, 두 점의 L1-metric 거리는 |a-c|+|b-d|이다.
풀이 :
	만약 a < c && b < d이면 거리는 (c + d ) - (a + b)이다.
	이와 다른 경우는 (c - d) - (a - b)이다.
	따라서 x좌표와 y좌표의 합과 차이를 통해 최대 거리를 구할 수 있다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(nlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
int sum[50001], diff[50001];

void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		sum[i] = x + y;
		diff[i] = x - y;
	}
	sort(sum, sum + n);
	sort(diff, diff + n);
}

int main(void) {
	fastio;
	init();

	cout << max(sum[n - 1] - sum[0], diff[n - 1] - diff[0]);
}