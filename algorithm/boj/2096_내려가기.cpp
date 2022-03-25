/**********************************************************************
작성일 : 2022-03-25
문제 :
	n개의 줄에 각각 세개의 수가 적혀있다. 
	1줄부터 n번째 줄까지 내려갈때 얻을 수 있는 점수의 최솟값과 최댓값을 구하라.
	내려가는 규칙은 다음과 같다.
	left -> left or mid
	mid -> left or mid or right
	right -> mid or right
풀이 :
	dp와 슬라이딩 윈도우를 활용하였다.
	메모리 제한이 4mb이기 때문에 dp배열을 선언하지 않고 슬라이딩 윈도우를 
	활용했다.
시간 제한 : 1초
메모리 제한 : 4MB
예상 시간복잡도 : O(n)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
int l, m, r;

int main() {
	fastio;

	cin >> n;
	cin >> l >> m >> r;

	int tmpL, tmpM, tmpR;
	int minL = l, minM = m, minR = r;
	int maxL = l, maxM = m, maxR = r;

	for (int i = 0; i < n - 1; i++) {
		int l, m, r;
		cin >> l >> m >> r;

		tmpL = min(minL, minM) + l;
		tmpM = min(min(minL, minM), minR) + m;
		tmpR = min(minM, minR) + r;
		minL = tmpL; minM = tmpM; minR = tmpR;

		tmpL = max(maxL, maxM) + l;
		tmpM = max(max(maxL, maxM), maxR) + m;
		tmpR = max(maxM, maxR) + r;
		maxL = tmpL; maxM = tmpM; maxR = tmpR;
	}

	cout << max(max(maxL, maxM), maxR) << ' ' << min(min(minL, minM), minR);
}