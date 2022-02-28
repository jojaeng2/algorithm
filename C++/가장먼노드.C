#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int visit[20010];
vector<int> adj[20010];
queue<int> q;

int solution(int n, vector<vector<int>> edges) {
    memset(visit, -1, sizeof(visit));
    int answer = 0, maxi = 0;
    for(auto edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    visit[1] = 0;
    q.push(1);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(int next : adj[curr]) {
            if(visit[next] != -1) continue;
            visit[next] = visit[curr] + 1;
            q.push(next);
            maxi = max(maxi, visit[next]);
        }
    }
    for(int i=1; i<=n; i++) if(visit[i] == maxi) answer++;
    return answer;
}