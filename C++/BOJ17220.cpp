#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,k,par[27], root, ans = 0;
bool visit[27] = {false};
map<char, int> mp;
vector<int> graph[27], parent;

void dfs(int s) {
    for(int i=0; i<graph[s].size(); i++) {
        int next = graph[s][i];
        if(visit[next]) continue;
        ans++;
        dfs(next);
    }
}

void init() {
    memset(par, 0, sizeof(par));
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        char x='A';
        mp.insert(make_pair((char)(x+(i-1)), i));
    }
    for(int i=0; i<m; i++) {
        char x, y;
        cin >> x >> y;
        graph[mp[x]].push_back(mp[y]);
        par[mp[y]]++;
    }
    for(int i=1; i<=n; i++) {
        if(par[i]==0) parent.push_back(i);
    }
    cin >> k;
    for(int i=0; i<k; i++) {
        char x;
        cin >> x;
        visit[mp[x]] = true;
    }
    for(int i=0; i<parent.size(); i++) {
        int root = parent[i];       
        if(!visit[root]) {
            visit[root] = true;
            dfs(root);
        }
    }
}

int main() {
    init();
    cout << ans << '\n';
}