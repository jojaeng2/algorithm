#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
int n, k;
ll psum[100001], DP[100001];

void dynamic() {
    int l = 1, r = 1;
    while(r <= n) {
        ll sum = psum[r] - psum[l-1];
        DP[r] = max(DP[r], DP[r-1]);
        if(sum >= k) {
            DP[r] = max(DP[r], DP[l-1] + sum - k);
            l++;
        }
        else r++;
    }
    cout << DP[n] << '\n';
}

void init() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(psum, 0, sizeof(psum));
    memset(DP, 0, sizeof(DP));
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        cin >> psum[i];
        psum[i] += psum[i-1];
    }
}

int main() {
    init();
    dynamic();
}