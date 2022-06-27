#include <iostream>
#include <queue>
#include <vector>
#define INF 1e10
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int v, e, p;
ll svisit[5001], nvisit[5001];
vector<pii> graph[5001];

void dijkstra(int start, ll visit[5001]) {
    priority_queue<pii> pq;
    pq.push(make_pair(0, start));
    visit[start] = 0;
    while(!pq.empty()) {
        int dist = -pq.top().X, now = pq.top().Y;
        pq.pop();
        if(visit[now] < dist) continue;
        for(int i=0; i<graph[now].size(); i++) {
            int next = graph[now][i].X, cost = dist + graph[now][i].Y;
            if(cost >= visit[next]) continue;
            visit[next] = cost;
            pq.push(make_pair(-cost, next));
        }
    }
}

void init() {
    fill(svisit, svisit+5001, INF);
    fill(nvisit, nvisit+5001, INF);
    cin >> v >> e >> p;
    for(int i=0; i<e; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        graph[x].push_back(make_pair(y, d));
        graph[y].push_back(make_pair(x, d));
    }
    dijkstra(1, svisit);
    dijkstra(p, nvisit);
    cout << svisit[v] << " " << svisit[p] << " " << nvisit[v] << '\n';
    if(svisit[v] == svisit[p] + nvisit[v]) {
        cout << "SAVE HIM" << '\n';
    }
    else {
        cout << "GOOD BYE" << '\n';
    }
}

int main() {
    init();
}