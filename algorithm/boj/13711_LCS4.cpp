#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
vector<int> arr1, arr2;

void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		arr1.push_back(num);
	}
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		arr2.push_back(num);
	}
}

int main(void){
	fastio;
	init();
}