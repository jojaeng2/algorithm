#include <iostream>
#include <cstring>
#define NUM 100010
using namespace std;
typedef long long ll;
ll n, m, num[NUM], tree[4*NUM], lazy[4*NUM];

ll sum(ll s, ll e, ll node, ll idx) {
    if(lazy[node] != 0) {
        tree[node] += (e-s+1) * lazy[node];
        if(s != e) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(e<idx || idx<s) return 0;
    if(s == e) return tree[node];
    ll mid = (s+e)/2;
    return sum(s, mid, node*2, idx) + sum(mid+1, e, node*2+1, idx);
}

void update(ll s, ll e, ll node, ll l, ll r, ll diff) {
    if(lazy[node] != 0) {
        tree[node] += (e-s+1) * lazy[node];
        if(s != e) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(r<s || e<l) return;
    if(l<=s && e<=r) {
        tree[node] += (e-s+1) * diff;
        if(s != e) {
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
        return;
    }
    ll mid = (s+e)/2;
    update(s, mid, node*2, l, r, diff);
    update(mid+1, e, node*2+1, l, r, diff);
    tree[node] = tree[node*2] + tree[node*2+1];
}

ll make_segment(ll s, ll e, ll node) {
    if(s == e) return tree[node] = num[s];
    ll mid = (s+e)/2;
    return tree[node] = make_segment(s, mid, node*2) + make_segment(mid+1, e, node*2+1);
}

void init() {
    ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    memset(lazy, 0, sizeof(lazy));
    cin >> n;
    for(int i=1; i<=n; i++) cin >> num[i];
    make_segment(1, n, 1);
    cin >> m;
    for(int i=0; i<m; i++) {
        int order;
        cin >> order;
        if(order == 1) {
            ll x, y, d;
            cin >> x >> y >> d;
            update(1, n, 1, x, y, d);
        }
        else {
            ll x;
            cin >> x;
            cout << sum(1, n, 1, x) << '\n';
        }
    }
}

int main() {
    init();
}