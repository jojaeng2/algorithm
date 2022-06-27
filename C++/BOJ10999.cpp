#include <iostream>
#include <cstring>
#define NUM 1000001
using namespace std;
typedef long long ll;
ll num[NUM], tree[4*NUM], lazy[4*NUM], n, m, k;

ll sum(ll s, ll e, ll node, ll l, ll r) {
    if(lazy[node] != 0) {
        tree[node] += (e-s+1) * lazy[node];
        if(s != e) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(s>r || e<l) return 0;
    if(l<=s && e<=r) return tree[node];
    ll mid = (s+e)/2;
    return sum(s, mid, node*2, l, r) + sum(mid+1, e, node*2+1, l, r);
}

void update(ll s, ll e, ll node, ll l, ll r, ll dif) {
    if(lazy[node] != 0) {
        tree[node] += (e-s+1) * lazy[node];
        if(s != e) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(l>e || r<s) return;
    if(l<=s && e<=r) {
        tree[node] += (e-s+1) * dif;
        if(s != e) {
            lazy[node*2] += dif;
            lazy[node*2+1] += dif;
        }
        return;
    }
    ll mid = (s+e)/2;
    update(s, mid, node*2, l, r, dif);
    update(mid+1, e, node*2+1, l, r, dif);
    tree[node] = tree[node*2] + tree[node*2+1];
}

ll make_tree(ll s, ll e, ll node) {
    if(s == e) return tree[node] = num[s];
    ll mid = (s+e)/2;
    return tree[node] = make_tree(s, mid, node*2) + make_tree(mid+1, e, node*2+1);
}

void init() {
    ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    memset(lazy, 0, sizeof(lazy));
    memset(tree, 0, sizeof(tree));
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) cin >> num[i];
    make_tree(1, n, 1);
    for(int i=0; i<m+k; i++) {
        int ord;
        cin >> ord;
        if(ord == 1) {
            ll s, e, d;
            cin >> s >> e >> d;
            update(1, n, 1, s, e, d);
        }
        else {
            ll s, e;
            cin >> s >> e;
            cout << sum(1, n, 1, s, e) << '\n';
        }
    }
}

int main() {
    init();
}