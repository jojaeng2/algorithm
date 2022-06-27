#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define X first
#define Y second
#define INF 1e9
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll visit[21];
int t, n, m, psum, c=0, par[21];
vector<pii> graph[21];
vector<int> ans;

void print() {
    cout << "Case #" << c << ": ";
    if(visit[m-1]==INF) cout << -1 << '\n';
    else {
        for(int i=m-1; i!=0; i=par[i]) {
            ans.push_back(i);
        }
        ans.push_back(0);
        for(int i=ans.size()-1; i>=0; i--) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}

void dijkstra(int s) {
    priority_queue<pii> pq;
    visit[s] = 0;
    pq.push(make_pair(0, s));
    while(!pq.empty()) {
        int dist = -pq.top().X, now = pq.top().Y;
        pq.pop();
        if(visit[now] < dist) continue;
        for(int i=0; i<graph[now].size(); i++) {
            int next = graph[now][i].X, cost = graph[now][i].Y;
            if(visit[next]<=dist+cost) continue;
            visit[next] = dist+cost;
            par[next] = now;
            pq.push(make_pair(-(dist+cost), next));
        }
    }
}

void init() {
    cin >> t;
    while(t--) {
        c++;
        for(int i=0; i<21; i++) graph[i].clear();
        ans.clear();
        fill(visit, visit+21, INF);
        memset(par, 0, sizeof(par));
        psum = INF;
        cin >> n >> m;
        for(int i=0; i<n; i++) {
            int x, y, d;
            cin >> x >> y >> d;
            graph[x].push_back(make_pair(y, d));
            graph[y].push_back(make_pair(x, d));
        }
        dijkstra(0);
        print();
    }
}

int main() {
    init();
}
