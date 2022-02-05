#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <iostream>
#define X first
#define Y second
#define MINF 0x7f7f7f7f
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
int visit[(1<<11)+10][1010], trap[1010];
vector<pii> adj[1010];
priority_queue<piii> pq;

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = 1e9;
    memset(visit, MINF, sizeof(visit));
    memset(trap, 0, sizeof(trap));
    for(auto road : roads) {
        int x = road[0], y = road[1], z = road[2];
        adj[x].push_back({y, z});
        adj[y].push_back({x, -z});
    }
    for(int i=0; i<traps.size(); i++) trap[traps[i]] = (1<<(i+1));
    pq.push({{0, start}, (trap[start])});
    visit[(trap[start])][start] = 0;
    while(!pq.empty()) {
        int dist = -pq.top().X.X, curr = pq.top().X.Y, psum = pq.top().Y;
        pq.pop();
        if(visit[psum][curr] < dist) continue;
        for(int i=0; i<adj[curr].size(); i++) {
            int next = adj[curr][i].X, cost = adj[curr][i].Y;
            if(!trap[curr] && !trap[next]) {
                if(cost < 0) continue;
                int nsum = psum | (trap[next]);
                if(visit[nsum][next] <= dist + cost) continue;
                visit[nsum][next] = dist + cost;
                pq.push({{-(dist + cost), next}, nsum});
            }
            else if(!trap[curr] && trap[next]) {
                if(cost < 0) {
                    if((psum & (trap[next])) == 0) continue;
                    int nsum = (psum & (~(trap[next])));
                    if(visit[nsum][next] <= dist - cost) continue;
                    visit[nsum][next] = dist - cost;
                    pq.push({{-(dist-cost), next}, nsum});
                }
                else {
                    if((psum & (trap[next])) != 0) continue;
                    int nsum = (psum | (trap[next]));
                    
                    if(visit[nsum][next] <= dist + cost) continue;
                    visit[nsum][next] = dist + cost;
                    pq.push({{-(dist + cost), next}, nsum});
                }
            }
            else if(trap[curr] && !trap[next]) {
                if(cost < 0) {
                    if((psum & (trap[curr])) == 0) continue;
                    if(visit[psum][next] <= dist - cost) continue;
                    visit[psum][next] = dist - cost;
                    pq.push({{-(dist-cost), next}, psum});
                }
                else {
                    if((psum & (trap[curr])) != 0) continue;
                    if(visit[psum][next] <= dist + cost) continue;
                    visit[psum][next] = dist + cost;
                    pq.push({{-(dist+cost), next}, psum});
                }
            }
            else if(trap[curr] && trap[next]) {
                if(cost < 0) {
                    if(((psum & (trap[curr])) != 0) && ((psum & (trap[next])) == 0)) {
                        int nsum = (psum | (trap[next]));
                        if(visit[nsum][next] <= dist - cost) continue;
                        visit[nsum][next] = dist - cost;
                        pq.push({{-(dist-cost), next}, nsum});
                    }
                    else if(((psum & (trap[curr])) == 0) && ((psum & (trap[next])) != 0)) {
                        int nsum = (psum & (~(trap[next])));
                        if(visit[nsum][next] <= dist - cost) continue;
                        visit[nsum][next] = dist - cost;
                        pq.push({{-(dist-cost), next}, nsum});
                    }
                }
                else {
                    if(((psum & (trap[curr])) == 0) && ((psum & (trap[next])) == 0)) {
                        int nsum = (psum | (trap[next]));
                        if(visit[nsum][next] <= dist + cost) continue;
                        visit[nsum][next] = dist + cost;
                        pq.push({{-(dist + cost), next}, nsum});
                    }
                    else if(((psum & (trap[curr])) != 0) && ((psum & (trap[next])) != 0)) {
                        int nsum = (psum & (~(trap[next])));
                        if(visit[nsum][next] <= dist + cost) continue;
                        visit[nsum][next] = dist + cost;
                        pq.push({{-(dist + cost), next}, nsum});
                    }
                }
            }
        }
    }
    for(int i=0; i<2048; i++) answer = min(answer, visit[i][end]);
    return answer;
}