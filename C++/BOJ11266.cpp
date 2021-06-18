#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, cnt=1, dfsn[10001];
vector<int> graph[10001];
bool visit[10001] = {false}, cp[10001] = {false};


void print() {
    int res = 0;
    for(int i=1; i<=n; i++) {
        if(cp[i]) res++;
    }
    cout << res << '\n';
    for(int i=1; i<=n; i++){
        if(cp[i]) cout << i << " ";
    }
}

int dfs(int s, int r) {
    dfsn[s] = cnt++;
    int res = dfsn[s], conn = 0;
    for(int i=0; i<graph[s].size(); i++) {
        int next = graph[s][i];
        if(dfsn[next] == 0) {
            conn++;
            int before = min(dfsn[s]+1, dfs(next, r));
            if(s != r && before>=dfsn[s]) cp[s] = true;
            res = min(res, before);
        }
        else res = min(res, dfsn[next]);
    }
    if(s == r && conn > 1) cp[s] = true; 
    cout << s << " " << res << " " << dfsn[s] << '\n';
    return res;
}

void init() {
    ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    memset(dfsn, 0, sizeof(dfsn));
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i=1; i<=n; i++) {
        if(dfsn[i] == 0) dfs(i, i);
    }
}

int main() {
    init();
    print();
}