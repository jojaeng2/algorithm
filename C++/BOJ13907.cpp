#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
#define INF 1e9
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pair<ll, int>,int> pli;
int n, m, k, s, e;
ll ans[1001][1001];
vector<pii> graph[1001];

void print() {
    ll zero = INF;
    for(int i=0; i<1001; i++) {
        zero = min(zero, ans[i][e]);
    }
    cout << zero << '\n';
    int psum = 0;
    for(int i=0; i<k; i++) {
        int pos;
        cin >> pos;
        psum += pos;
        ll mini = 1e9;
        for(int j=0; j<1001; j++) {
            mini = min(mini, ans[j][e] + (psum*j));
        }
        cout << mini << '\n';
    }
}

void dijkstra() {
    priority_queue<pli> pq;
    pq.push(make_pair(make_pair(-0, s), 0));
    while(!pq.empty()) {
        ll dist = -pq.top().X.X;
        int now = pq.top().X.Y, cnt = pq.top().Y;
        pq.pop();
        if(ans[cnt][now] < dist || cnt>=n) continue;
        for(int i=0; i<graph[now].size(); i++) {
            int next = graph[now][i].X, cost = graph[now][i].Y;
            if(ans[cnt+1][next] <= dist + cost) continue;
            ans[cnt+1][next] = dist + cost;
            pq.push(make_pair(make_pair(-(dist+cost), next), cnt+1));
        }
    }
}

void init() {
    ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    memset(ans, 1e4, sizeof(ans));
    cin >> n >> m >> k;
    cin >> s >> e;
    for(int i=0; i<m; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        graph[x].push_back(make_pair(y, d));
        graph[y].push_back(make_pair(x, d));
    }
}

int main() {
    init();
    dijkstra();
    print();
}