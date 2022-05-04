#include <bits/stdc++.h>
#define MINF 0x7f7f7f7f7f7f7f
#define INF 1000000000
#define MOD 1000000007
#define NUM 100010
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll DP[2][NUM];
int depth[NUM], N, M, root = 1;
vector<int> adj[NUM];

void dfs(int par) {
    for(auto next : adj[par]) {
        if(depth[next] != -1) continue;
        depth[next] = depth[par] + 1;
        dfs(next);
    }
}

void dynamic(int curr, int par) {
    if(depth[curr] % 2) DP[1][curr]++;
    else DP[0][curr]++;
    for(int next : adj[curr]) {
        if(next == par) continue;
        dynamic(next, curr);
        DP[0][curr] += DP[0][next];
        DP[1][curr] += DP[1][next];
    }
}

void init() {
    memset(depth, -1, sizeof(depth));
    memset(DP, 0, sizeof(DP));
    cin >> N >> M;
    for(int i=1; i<N; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    depth[root] = 0;
    dfs(root);
    dynamic(root, 0);
    for(int i=0; i<M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if(depth[x] > depth[y]) swap(x, y);
        if(!z) {
            cout << ((DP[0][y] * (DP[0][root] - DP[0][y])) + (DP[1][y] * (DP[1][root] - DP[1][y]))) << '\n';
        }
        else {
            cout << ((DP[0][y] * (DP[1][root] - DP[1][y])) + (DP[1][y] * (DP[0][root] - DP[0][y]))) << '\n';
        }   
    }
}


int main() {    
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}