#include <bits/stdc++.h>
#define MINF 0x7f7f7f7f
#define INF 1000000000
#define MOD 10000
#define NUM 1000010
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
bool flag = false;
int visited[NUM], N, M;
bool checked[NUM];
queue<int> q;
vector<int> adj[NUM];

void dfs(int curr, int isOdd) {
    for(int next : adj[curr]) {
        if(visited[next] == -1) {
            visited[next] = (isOdd+1) % 2;
            dfs(next, (isOdd + 1) % 2);
        }
    }
}

void init() {
    memset(visited, -1, sizeof(visited));
    memset(checked, false, sizeof(checked));
    cin >> N >> M;
    for(int i=0; i<M; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1; i<=N; i++) {
        if(visited[i] != -1) continue;
        visited[i] = 0;
        dfs(i, 0);
    }

    for(int i=1; i<=N; i++) {
        if(checked[i]) continue;
        checked[i] = true;
        q.push(i);
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            for(int next : adj[curr]) {
                if(checked[next]) continue;
                checked[next] = true;
                q.push(next);
                if(visited[curr] == visited[next]) flag = true;
            }
        }
    }
    if(flag) cout << "IMPOSSIBLE" << '\n';
    else cout << "POSSIBLE" << '\n';
}


int main() {    
    ios_base :: sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   init();
}