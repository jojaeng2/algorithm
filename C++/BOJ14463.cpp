#include <iostream>
#include <cstring>
#include <algorithm>
#define NUM 100010
using namespace std;
typedef long long ll;
int n, pos[NUM], tree[4*NUM];
ll answer = 0;

ll sum(int s, int e, int node, int left, int right) {
    if(right < s || e < left) return 0;
    if(left<=s && e<=right) return tree[node];
    int mid = (s+e)/2;
    return sum(s, mid, node*2, left, right) + sum(mid+1, e, node*2+1, left, right);
}

void update(int s, int e, int node, int idx, int diff) {
    if(idx < s || idx > e) return;
    tree[node] += diff;
    if(s == e) return;
    int mid = (s+e)/2;
    update(s, mid, node*2, idx, diff);
    update(mid+1, e, node*2+1, idx, diff);
} 

void init() {
    ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    memset(pos, 0, sizeof(pos));
    memset(tree, 0, sizeof(tree));
    cin >> n;
    for(int i=1; i<=2*n; i++) {
        int x;
        cin >> x;
        if(pos[x] == 0) {
            pos[x] = i;
            update(1, 2*n, 1, i, 1);
        }
        else {
            answer += sum(1, 2*n, 1, pos[x]+1, i);
            update(1, 2*n, 1, pos[x], -1);
        }
    }
    cout << answer << '\n';
}

int main() {
    init();
}