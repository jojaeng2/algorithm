#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <vector>
#define NUM 500010
using namespace std;
typedef long long ll;
ll number[NUM], tree[4*NUM], lazy[4*NUM];
int n, m, in[NUM], out[NUM], cnt = 1;
vector<int> graph[NUM];

void reset() {
    memset(lazy, 0, sizeof(lazy));
    memset(tree, 0, sizeof(tree));
    memset(number, 0, sizeof(number));
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
}

void update(int s, int e, int node, int l, int r, int diff) {
    if(lazy[node] != 0) {
        tree[node] += lazy[node] * (e-s+1);
        if(s != e) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(s>r || e<l) return;
    if(l<=s && e<=r) {
        tree[node] += diff * (e-s+1);
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

ll sum(int s, int e, int node, int l, int r) {
    if(lazy[node] != 0) {
        tree[node] += lazy[node] * (e-s+1);
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

void init_tree(int s, int e, int node) {
    if(s == e) {
        tree[node] = number[s];
        return;
    }
    int mid = (s+e)/2;
    init_tree(s, mid, node*2);
    init_tree(mid+1, e, node*2+1);
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
    reset();
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        int x, y;
        if(i == 1) {
            cin >> x;
            number[i] = x;
        }   
        else {
            cin >> x >> y;
            number[i] = x;
            graph[y].push_back(i);
        }
    }
    dfs(1);
    for(int i=1; i<=n; i++) {
        update(1, n, 1, in[i], in[i], number[i]);
    }
    for(int i=1; i<=m; i++) {
        char x;
        int y, z;
        cin >> x;
        if(x == 'p') {
            cin >> y >> z;
            update(1, n, 1, in[y]+1, out[y], z);
        }
        else {
            cin >> y;
            cout << sum(1, n, 1, in[y], in[y]) << '\n';
        }
    }
}

int main() {
    init();
}