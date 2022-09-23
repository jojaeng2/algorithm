#include <bits/stdc++.h>
#define MINF 0x7f7f7f7f
#define INF 1000000000
#define MOD 1000000009
#define NUM 1010
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<char, int> pci;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
struct st {
    int x, y, z;
};
int N, M, K, par[NUM];
bool visited[NUM];
vector<pii> adj[NUM];
vector<st> v;

int find(int start) {
    if(start == par[start]) return start;
    return par[start] = find(par[start]);
}

bool uni(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return false;
    if(x < y) par[y] = x;
    else par[x] = y;
    return true;
}

bool compare(st a, st b) {
    return a.z > b.z;
}

void dfs(int s, int e, int mini) {
    if(s == e) {
        cout << mini << '\n';
        return;
    }
    for(auto next : adj[s]) {
        if(visited[next.X]) continue;
        visited[next.X] = true;
        dfs(next.X, e, min(mini, next.Y));
    }
}

void init(){
    for(int i=0; i<NUM; i++) par[i] = i;
    cin >> N >> M >> K;

    for(int i=0; i<M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        st s;
        s.x = x, s.y = y, s.z = z;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), compare);

    for(auto curr : v) {
        int x = curr.x, y = curr.y, z = curr.z;
        if(uni(x, y)) {
            adj[x].push_back(pii(y, z));
            adj[y].push_back(pii(x, z));
        }
    }
    for(int i=0; i<K; i++) {
        memset(visited, false, sizeof(visited));
        int x,  y;
        cin >> x >> y;
        dfs(x, y, INF);
    }
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
}
