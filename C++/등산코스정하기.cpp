#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <iostream>
#define MINF 0x7f7f7f7f7f7f7f
#define NUM 50010
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;
int visit[NUM], node, res = 1e9;
bool sv[NUM];
vector<pii> adj[NUM];
priority_queue<pii> pq;

void dijkstra() {
    while(!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        if(sv[curr.Y]) continue;
        int dist = -curr.X, no = curr.Y;

        if(visit[no] < dist) continue;
        for(auto next : adj[no]) {
            int maxi = max(dist, next.Y);
            if(visit[next.X] <= maxi) continue;
            visit[next.X] = maxi;
            pq.push({-maxi, next.X});
        }
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    memset(visit, MINF, sizeof(visit));
    memset(sv, false, sizeof(sv));
    for(auto path : paths) {
        adj[path[0]].push_back({path[1], path[2]});
        adj[path[1]].push_back({path[0], path[2]});
    }
    for(auto summit : summits) {
        sv[summit] = true;
    }
    for(auto gate : gates) pq.push({0, gate}), visit[gate] = 1e9;
    dijkstra();
    sort(summits.begin(), summits.end());
    for(auto summit : summits) {
        if(visit[summit] < res) {
            res = visit[summit];
            node = summit;
        }
    }

    return {node, res};
}
