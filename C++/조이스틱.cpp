#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
#include <queue>
#define X first
#define Y second
using namespace std;
int visit[(1<<21)][21], psum = 0;
set<int> s;
vector<pair<int, int>> adj[21];
int answer = 0;
priority_queue<pair<pair<int, int>, int>> pq;

int solution(string name) {
    memset(visit, 0x7f7f7f7f, sizeof(visit));
    for(int i=0; i<name.size(); i++) {
        char alpha = name[i];
        if(alpha == 'A') continue;
        answer += min((alpha - 'A'), (26 - (alpha-'A')));
    }
    for(int i=0; i<name.size(); i++) {
        char alpha = name[i];
        if(alpha == 'A') {
            psum |= (1<<i);
            continue;
        }
        s.insert(i);
    }
    for(auto num : s) {
        if(num == 0) continue;
        for(auto nn : s) {
            if(num == nn || nn == 0) continue;
            adj[num].push_back({nn, min(abs(num - nn), int(name.size()) - abs(num-nn))});
        }
    }
    for(auto num : s) {
        if(num == 0) continue;
        adj[0].push_back({num, min(num, int(name.size()) - num)});
    }
    visit[(psum | (1<<0))][0] = 0;
    pq.push({{0, (psum | (1<<0))}, 0});
    while(!pq.empty()) {
        int dist = -pq.top().X.X, sum = pq.top().X.Y, curr = pq.top().Y;
        pq.pop();
        if(visit[sum][curr] < dist) continue;
        for(auto next : adj[curr]) {
            if(visit[sum | (1<<next.X)][next.X] <= dist + next.Y) continue;
            visit[sum | (1<<next.X)][next.X] = dist + next.Y;
            pq.push({{-(dist + next.Y), sum | (1<<next.X)}, next.X});
        }
    }
    int mini = 1e9;
    for(int i=0; i<name.size(); i++) mini = min(visit[(1<<name.size())-1][i], mini);
    answer += mini;
    return answer;
}