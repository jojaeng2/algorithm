#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int n, par;
ll dp[10001];
vector<pii> v;

void solve() {
    dp[0] = 0;
    for(int i=1; i<=n; i++) {
        ll maxi = 0;
        for(int j=i; j>=1; j--) {
            maxi = max(maxi, abs(v[j-1].second));
            dp[i] = min(dp[i], dp[j-1] + max(v[i-1].first-v[j-1].first, 2*maxi));
        }
    }
    cout << dp[n] << '\n';
}

bool compare(pii a, pii b) {
    return a.first < b.first;
}

void init() {
    fill(dp, dp+10001, 1e9);
    cin >> n;
    for(int i=0; i<n; i++) {
        ll x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end(), compare);
}

int main() {
    init();
    solve();
}