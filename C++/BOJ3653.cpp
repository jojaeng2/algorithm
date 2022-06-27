#include <iostream>
#include <vector>
#include <cstring>
#define NUM 200000
using namespace std;

int t, n, m, idx[NUM/2 + 10], tree[4*NUM+10];

int segment(int start, int end, int node, int left, int right) {
    if(left > end || right < start) return 0;
    if(start == end) return tree[node] = 1;
    int mid = (start+end)/2;
    return tree[node] = segment(start, mid, node*2, left, right) + segment(mid+1, end, node*2+1, left, right);
}

int sum(int start, int end, int node, int left, int right) {
    if(left > end || right < start) return 0;
    if(left<=start && end<=right) return tree[node];
    int mid = (start+end)/2;
    return sum(start, mid, node*2, left, right) + sum(mid+1, end, node*2+1, left, right);
}

void update(int start, int end, int node, int index, int dif) {
    if(index>end || index<start) return;
    tree[node] += dif;
    if(start == end) return;
    int mid = (start+end)/2;
    update(start, mid, node*2, index, dif);
    update(mid+1, end, node*2+1, index, dif);
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        memset(tree, 0, sizeof(tree));
        cin >> n >> m;
        for(int i=1; i<=n; i++) {
            idx[i] = m+i;
        }
        segment(1, m+n, 1, m+1, m+n);
        for(int i=0; i<m; i++) {
            int finding;
            cin >> finding;
            cout << sum(1, m+n, 1, 1, idx[finding]-1) << " ";
            update(1, m+n, 1, idx[finding], -1);
            idx[finding] = m-i;
            update(1, m+n, 1, idx[finding], 1);
        }
        cout << '\n';
    }
}

int main() {
    init();
}