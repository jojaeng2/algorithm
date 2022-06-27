#include <iostream>
#include <cstring>
#define NUM 200000
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll n, psum_tree[4*NUM+10], cnt_tree[4*NUM+10];
ll answer = 1;

void update(int start, int end, int node, int idx) {
    if(idx<start || idx>end) return;
    psum_tree[node] += idx;
    cnt_tree[node]++;
    if(start == end) return;
    int mid = (start+end)/2;
    update(start, mid, node*2, idx);
    update(mid+1, end, node*2+1, idx);
}

ll sum(int start, int end, int node, int left, int right, ll tree[4*NUM+10]) {
    if(start>right || end<left) return 0;
    if(left<=start && end<=right) return tree[node];
    int mid = (start+end)/2;
    return sum(start, mid, node*2, left, right, tree) + sum(mid+1, end, node*2+1, left, right, tree);
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1; i<=n; i++) {
        int a;
        cin >> a;
        update(0, NUM, 1, a);
        if(i==1) continue;
        ll left_tree = sum(0, NUM, 1, 0, a-1, cnt_tree), right_tree = sum(0, NUM, 1, a+1, NUM, cnt_tree);
        ll left_psum = sum(0, NUM, 1, 0, a-1, psum_tree), right_psum = sum(0, NUM, 1, a+1, NUM, psum_tree);
        ll l = (left_tree * a - left_psum)%MOD, r = (right_psum - right_tree*a)%MOD;
        answer *= ((l+r)%MOD);
        answer %= MOD;
    }
}


void reset() {
    memset(psum_tree, 0, sizeof(psum_tree));
    memset(cnt_tree, 0, sizeof(cnt_tree));
}

int main() {
    reset();
    init();
    cout << answer << '\n';
}