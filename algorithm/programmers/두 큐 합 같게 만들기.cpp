#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int solution(vector<int> q1, vector<int> q2) {
	int n = q1.size();
	ll sum = 0, total = 0;
	vector<int> q(n * 2);

	for (int i = 0; i < n; i++) {
		q[i] = q1[i];
		sum += q1[i];
		total += q1[i];
	}
	for (int i = 0; i < n; i++) {
		q[i + n] = q2[i];
		total += q2[i];
	}

	if (total % 2)
		return -1;
	else
		total /= 2;

	int ret = 0;
	int l = 0, r = n - 1;
	while (l <= r && r < 2 * n) {
		if (sum == total)
			return ret;
		else if (sum > total) {
			sum -= q[l++];
			ret++;
		}
		else if (r < 2 * n) {
			sum += q[++r];
			ret++;
		}
		else 
			break;
	}
	return -1;
}