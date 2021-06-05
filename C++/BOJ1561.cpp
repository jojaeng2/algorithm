#include <iostream>
using namespace std;
typedef long long ll;
ll n, m, num[10001];

void binary() {
    ll ans, psum;
    ll left = 0, right = 6*10e10;
    while(left<=right) {
        ll mid = (left+right)/2, cnt = 0;
        for(int i=1; i<=m; i++) {
            if(mid%num[i] == 0) cnt += mid/num[i];
            else cnt += mid/num[i] + 1;
        }
        if(cnt<n) {
            ans = mid, psum = cnt, left = mid+1;
        }
        else right = mid-1;
    }
    for(int i=1; i<=m; i++) {
        if(ans%num[i] == 0) psum++;
        if(psum == n) {
            cout << i << '\n';
            break;
        }
    }
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i=1; i<=m; i++) cin >> num[i];
}

int main() {
    init();
    binary();
}