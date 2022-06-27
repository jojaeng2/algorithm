#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define NUM 75000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll t, n, tree[4*NUM+10], answer;
vector<pll> v;
vector<ll> x_pos;

void update(int start, int end, int node, int idx) {
    if(idx<start || idx>end) return;
    tree[node]++;
    if(start==end) return;
    int mid = (start+end)/2;
    update(start, mid, node*2, idx);
    update(mid+1, end, node*2+1, idx);
}


ll sum(int start, int end, int node, int left, int right) {
    if(right<start || end<left) return 0;
    if(left<=start && end<=right) return tree[node];
    int mid = (start+end)/2;
    return sum(start, mid, node*2, left, right) + sum(mid+1, end, node*2+1, left, right);
}


bool ASC(pll a, pll b) {
    if(a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        memset(tree, 0, sizeof(tree));
        x_pos.clear();
        v.clear();
        answer = 0;
        cin >> n;
        for(int i=1; i<=n; i++) {
            ll x, y;
            cin >> x >> y;
            v.push_back(make_pair(y, x));
            x_pos.push_back(x);
        }
        sort(v.begin(), v.end(), ASC);
        sort(x_pos.begin(), x_pos.end());
        for(int i=0; i<n; i++) {
            ll next = lower_bound(x_pos.begin(), x_pos.end(), v[i].second) - x_pos.begin()+1;
            answer += sum(1, n, 1, next, n);
            update(1, n, 1, next);
        }
        cout << answer << '\n';
    }
}

int main() {
    init();
}