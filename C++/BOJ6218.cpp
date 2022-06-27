#include <bits/stdc++.h>
#define NUM 200010
#define INF 1e9
using namespace std;
int arr[NUM], N, Q, maxi[4*NUM], mini[4*NUM];

void init_tree(int s, int e, int node) {
    if(s == e) {
        mini[node] = arr[s];
        maxi[node] = arr[s];
        return;
    }
    int mid = (s+e)/2;
    init_tree(s, mid, node*2);
    init_tree(mid+1, e, node*2+1);
    mini[node] = min(mini[node*2], mini[node*2+1]);
    maxi[node] = max(maxi[node*2], maxi[node*2+1]);
}

int max_query(int s, int e, int node, int left, int right) {
    if(s > right || e < left) return -1;
    if(left <= s && e <= right) return maxi[node];
    int mid = (s+e)/2;
    return max(max_query(s, mid, node*2, left, right), max_query(mid+1, e, node*2+1, left, right));
}

int min_query(int s, int e, int node, int left, int right) {
    if(s > right || e < left) return 1e9;
    if(left <= s && e <= right) return mini[node];
    int mid = (s+e)/2;
    return min(min_query(s, mid, node*2, left, right), min_query(mid+1, e, node*2+1, left, right));
}

void init() {
    cin >> N >> Q;
    for(int i=0; i<N; i++) cin >> arr[i+1];
    init_tree(1, N, 1);
    for(int i=0; i<Q; i++) {
        int l, r;
        cin >> l >> r;
        int mx = max_query(1, N, 1, l, r);
        int mn = min_query(1, N, 1, l, r);
        cout << mx - mn << '\n';
    }
}   

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    init();
}