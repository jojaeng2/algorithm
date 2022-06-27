#include <iostream>
#define NUM 1000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
int n, m, k, number[NUM+10];
ll tree[4*NUM+10];

ll segment(int start, int end, int node) {
    if(start == end) return tree[node] = number[start];
    int mid = (start+end)/2;
    return tree[node] = (segment(start, mid, node*2) * segment(mid+1, end, node*2+1))%MOD;
}

ll update(int start, int end, int node, int idx) {
    if(start>idx || end<idx) return tree[node];
    if(start == end) return tree[node] = number[start];
    int mid = (start+end)/2;
    return tree[node] = (update(start, mid, node*2, idx) * update(mid+1, end, node*2+1, idx))%MOD;
}

ll sum(int start, int end, int node, int left, int right) {
    if(right<start || end<left) return 1;
    if(left<=start && end<=right) return tree[node];
    int mid = (start+end)/2;
    return (sum(start, mid, node*2, left, right) * sum(mid+1, end, node*2+1, left, right)) % MOD;
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) cin >> number[i];
    segment(1, n, 1);
    for(int i=0; i<m+k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) {
            number[b] = c;
            update(1, n, 1, b);
        }
        else {
            cout << sum(1, n, 1, b, c) << '\n';
        }
    }
}

int main() {
    init();
}