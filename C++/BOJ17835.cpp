#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 1e9
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int n, m, k, start = 100001;
ll visit[100010];
vector<pii> graph[100010];

void print() {
    int mini = 0, idx = 0;
    for(int i=1; i<=n; i++) {
        if(visit[i] > mini) {
            mini = visit[i];
            idx = i;
        }
    }
    cout << idx << '\n' << mini << '\n';
}

void dijkstra(int s) {
    priority_queue<pii> pq;
    pq.push(make_pair(0, s));
    while(!pq.empty()) {
        int dist = -pq.top().first, now = pq.top().second;
        pq.pop();
        if(visit[now] < dist) continue;
        for(int i=0; i<graph[now].size(); i++) {
            int next = graph[now][i].first, cost = dist + graph[now][i].second;
            if(visit[next] <= cost) continue;
            visit[next] = cost;
            pq.push(make_pair(-cost, next));
        }
    }
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill(visit, visit+100010, INF);
    cin >> n >> m >> k;
    for(int i=0; i<m; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        graph[y].push_back(make_pair(x, d));
    }
    for(int i=0; i<k; i++) {
        int x;
        cin >> x;
        graph[start].push_back(make_pair(x, 0));
    }   
    dijkstra(start);
}

int main() {
    init();
    print();
}