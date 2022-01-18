/**********************************************************************
작성일 : 2022-1-18
문제 :
    주어진 수가 4개의 소수들의 합으로 만들 수 있는 지 확인하고 소수들을 출력하는 문제
풀이 :
    정수론 문제로 '골드바흐의 추측'을 알면 쉽게 풀 수 있는 문제이다. 
    - 골드바흐의 추측 : 4 이상의 모든 짝수는 두 소수의 합으로 표현할 수 있다.
    아직 미해결 문제이지만 10^18 이하의 짝수에서는 참이라는 것을 수치적으로 확인했다.
시간 제한 : 2초
메모리 제한 : 512MB
예상 시간복잡도 : O(n*m) (n:최대 입력값, m:쿼리수)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int maxNum = 0;
bool isPrime[100000001];
vector<int> input;

void init() {
    // 입력
    while (1) {
        int n; cin >> n;
        if (cin.eof()) break; 
        input.push_back(n);
        maxNum = max(maxNum, n);
    }
}
void eratos() {
    // 에라토스테네스의 체
    for (int i = 2; i <= maxNum; i++) {
        isPrime[i] = true;
    }

    for (int i = 2; i <= maxNum; i++) {
        if (isPrime[i]) {
            for (int j = i * 2; j <= maxNum; j += i) {
                isPrime[j] = false;
            }
        }
    }
}
void solve() {
    for (int& num : input) {
        if (num < 8) {  // 8보다 작으면 무조건 불가능
            cout << "Impossible.\n";
        }
        else if (num % 2) { // 홀수(2, 3은 무조건 포함)
            num -= 5;
            for (int i = 2; i <= maxNum; i++) {
                if (isPrime[i] && isPrime[num - i]) {
                    cout << "2 3 " << i << " " << num - i << '\n';
                    break;
                }
            }
        }
        else {              // 짝수(2, 2는 무조건 포함)
            num -= 4;
            for (int i = 2; i <= maxNum; i++) {
                if (isPrime[i] && isPrime[num - i]) {
                    cout << "2 2 " << i << " " << num - i << '\n';
                    break;
                }
            }
        }
    }
}


int main() {
	fastio;

	init();
    eratos();
    solve();

    return 0;
}