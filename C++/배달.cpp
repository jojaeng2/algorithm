#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define X first
#define Y second
using namespace std;
int visit[51];
vector<pair<int, int>> adj[51];
priority_queue<pair<int, int>> pq;


int solution(int N, vector<vector<int> > road, int K) {
    memset(visit, 1e4, sizeof(visit));
    for(auto ro : road) {
        adj[ro[0]].push_back({ro[1], ro[2]});
        adj[ro[1]].push_back({ro[0], ro[2]});
    }
    int answer = 0;
    visit[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()) {
        int dist = -pq.top().X, curr = pq.top().Y;
        pq.pop();
        if(visit[curr] < dist) continue;
        for(auto next : adj[curr]) {
            if(visit[next.X] <= dist + next.Y) continue;
            visit[next.X] = dist + next.Y;
            pq.push({-visit[next.X], next.X});
        }
    }
    for(int i=1; i<=N; i++) {
        if(visit[i] <= K) answer++;
    }
    return answer;
}