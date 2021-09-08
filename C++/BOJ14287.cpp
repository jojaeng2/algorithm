#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define NUM 100001
using namespace std;
typedef long long ll;
int n, m, cnt = 1, in[NUM], out[NUM];
ll lazy[4*NUM], tree[4*NUM];
vector<int> graph[NUM];

ll sum(int s, int e, int node, int l, int r) {
    if(lazy[node] != 0) {
        tree[node] += lazy[node];
        if(s != e) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(s>r || e<l) return 0;
    if(l<=s && e<=r) return tree[node];
    int mid = (s+e)/2;
    return sum(s, mid, node*2, l, r) + sum(mid+1, e, node*2+1, l, r);
}

void update(int s, int e, int node, int l, int r, int diff) {
    if(lazy[node] != 0) {
        tree[node] += lazy[node];
        if(s != e) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(s>r || e<l) return;
    if(l<=s && e<=r) {
        tree[node] += diff;
        if(s != e) {
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
        return;
    }
    int mid = (s+e)/2;
    update(s, mid, node*2, l, r, diff);
    update(mid+1, e, node*2+1, l, r, diff);
    tree[node] = tree[node*2] + tree[node*2+1];
}

int dfs(int s) {
    in[s] = cnt++;
    int res = in[s];
    for(int i=0; i<graph[s].size(); i++) {
        int next = graph[s][i];
        res = max(res, dfs(next));
    }
    out[s] = res;
    return res;
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(tree, 0, sizeof(tree));
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        int x;
        cin >> x;
        if(x == -1) continue;
        graph[x].push_back(i);
    }
    dfs(1);
    for(int i=0; i<m; i++) {
        int x, y, z;
        cin >> x;
        if(x == 1) {
            cin >> y >> z;
            update(1, n, 1, in[y], in[y], z);
        }
        else {
            cin >> y;
            cout << sum(1, n, 1, in[y], out[y]) << '\n';
        }
    }
}

int main() {
    init();
}