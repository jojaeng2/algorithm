#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
ll t, k, n;
ll ans, num[5][1001];
vector<ll> psum1, psum2;

void two_pointer() {
    ans = psum1[0] + psum2[0];
    for(int i=0; i<psum1.size(); i++) {
        int idx = lower_bound(psum2.begin(), psum2.end(), abs(k - psum1[i])) - psum2.begin();
        if(idx == psum2.size()) idx = psum2.size()-1;
        ll x = psum1[i] + psum2[idx], y; 
        if(idx != 0) y = psum1[i] + psum2[idx-1];
        else y = 1e9;
        if(abs(x - k) < abs(k-ans)) ans = x;
        else if(abs(x - k) == abs(k-ans)) ans = min(ans, x);
        if(abs(y-k) < abs(k-ans)) ans = y;
        else if(abs(y-k) == abs(k-ans)) ans = min(ans, y);
    }
    cout << ans << '\n';
}

void make_psum() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            psum1.push_back(num[1][i] + num[2][j]);
            psum2.push_back(num[3][i] + num[4][j]);
        }
    }
    sort(psum1.begin(), psum1.end());
    sort(psum2.begin(), psum2.end());
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while(t--) {
        memset(num, 0, sizeof(num));
        psum1.clear(), psum2.clear();
        cin >> k >> n;
        for(int i=1; i<=4; i++) for(int j=1; j<=n; j++) cin >> num[i][j];
        make_psum();
        two_pointer();
    }
}

int main() {
    init();
}