#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int n;
ll d;
vector<pll> v;

void solve() {
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    int ans = 0;
    for(int i=0; i<v.size(); i++) {
        ll s = v[i].X, e = v[i].Y;
        if(e-s > d) continue;
        pq.push(s);
        while(!pq.empty()) {
            ll fs = pq.top();
            if(fs < e-d) pq.pop();
            else break;
        }
        ans = max(ans, (int)pq.size());
    }
    cout << ans << '\n';
}

bool compare(pll a, pll b) {
    if(a.Y == b.Y) return a.X < b.X;
    return a.Y < b.Y;
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) {
        ll x, y;
        cin >> x >> y;
        if(x > y) swap(x, y);
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end(), compare);
    cin >> d;
}

int main() {
    init();
    solve();
}