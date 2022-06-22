/**********************************************************************
작성일 : 2022-6-22
문제 :
	백준 문제 7612번 SSSP의 입력 데이터를 만드는 문제이다.
	이때 사용할 코드는 A, B이며 A는 플로이드-워셜 알고리즘, B는 벨만-포드 알고리즘을 사용하였다.

	만들고자 하는 데이터는 A 코드에서는 TLE가 발생하지 않고 B 코드에서는 TLE가 발생하도록 해야한다.
	이러한 데이터를 출력하는 코드를 구현해라.
	(TLE가 발생하는 조건 = counter변수가 1,000,000을 넘을 시)
풀이 :
	코드 A(플로이드)의 연산 횟수 = V^3
	코드 B(벨만포드)의 연산 횟수 = Q x V x E

	=> 코드 A가 TLE가 되지 않기 위해서는 V가 100이하이여야 한다.
	=> 코드 B가 TLE 되도록 하기 위해 Q를 최대값 10으로 설정해야한다.

	입력데이터의 개수 = (1 + V + 2E) + (1 + 2Q) <= 2222
	따라서 E는 최대 1050개 만들 수 있다.

	또한, 벨만 포드 알고리즘은 dist배열이 바뀌지 않을 경우 알고리즘을 바로 종료하도록 최적화 했기 때문에
	V-1번 모두 수행하도록 그래프를 형성해줘야한다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : 
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define V 100
#define Q 10
#define E 1050

struct edge {
	int u, cost;
};
vector<edge> adjlist[V];

void make_data() {
	for (int s = 0; s < V; s++) {
		int e = (s + 99) % 100;
		adjlist[s].push_back({ e, 1 });
	}

	for (int i = 0; i < E - V; i++) {
		int s, e;
		while (1) {
			s = rand() % 100;
			e = rand() % 100;
			if (s != e) break;
		}
		adjlist[s].push_back({ e, 1000 });
	}
}

int main(void) {
	fastio;
	srand(time(NULL));
	make_data();

	// block 1
	cout << V << '\n';
	for (int s = 0; s < V; s++) {
		cout << (int)adjlist[s].size() << ' ';
		for (edge& e : adjlist[s]) {
			cout << e.u << ' ' << e.cost << ' ';
		}
		cout << '\n';
	}

	// block 2
	cout << Q << '\n';
	for (int i = 0; i < Q; i++) {
		cout << "0 1\n";
	}
}