#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, m;
ll mid = -1, leaf=0;
bool flag = false;
vector<pii> graph[200001];

void dfs(int s, int e, ll psum) {
    leaf = max(leaf, psum);
    if(graph[s].size()>=2 && mid == -1) {
        if(graph[s].size() == 2 && m == s) {
            mid = psum;
            flag = true;
        }
        if(graph[s].size() > 2) {
            mid = psum;
            flag = true;
        }
    }
    for(int i=0; i<graph[s].size(); i++) {
        int next = graph[s][i].first, dist = graph[s][i].second;
        if(next == e) continue;
        dfs(next, s, psum+dist);
    }
}

void init() {
    cin >> n >> m;
    for(int i=1; i<n; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        graph[x].push_back(make_pair(y, d));
        graph[y].push_back(make_pair(x, d));
    }
    dfs(m, -1, 0);
    if(mid == -1) cout << leaf << " " << 0 << '\n';
    else if(mid == 0 && !flag) cout << leaf << " " << mid << '\n';
    else cout << mid << " " << leaf-mid << '\n';
}

int main() {
    init();   
}