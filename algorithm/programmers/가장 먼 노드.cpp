/**********************************************************************
작성일 : 2022-01-19
문제 :
    시작 노드로부터 가장 먼 노드들의 개수를 구하라
풀이 :
    단순한 인접리스트와 BFS를 구현하는 문제
예상 시간복잡도 : O(v+e) (정점과 간선의 개수)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>

using namespace std;

int maxDist = 0;
int dist[20001];
vector<int> adjlist[20001];

int solution(int n, vector<vector<int>> edge) {
    // 초기화
    for(vector<int> v : edge) {
        adjlist[v[0]].push_back(v[1]);
        adjlist[v[1]].push_back(v[0]);
    }
    for(int i=1;i<=n;i++){
        dist[i] = INT_MAX;
    }
    dist[1] = 0;
    
    // BFS
    queue<int> q;
    q.push(1);
    
    while(!q.empty()){
        int now = q.front(); q.pop();
        
        for(int &next : adjlist[now]){
            if(dist[next] > dist[now] + 1){
                dist[next] = dist[now] + 1;
                q.push(next);
                maxDist = max(maxDist, dist[next]);
            }
        }
    }
    // 먼 노드 체크
    int ret = 0;
    for(int i=1;i<=n;i++){
        if(dist[i] == maxDist)
            ret++;
    }
    return ret;
}