#include <iostream>
#include <cstring>
using namespace std;
int n, l[1001], r[1001], psum[1001][1001], answer = 0;

void solve() {
    memset(psum, 0, sizeof(psum));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            psum[i][j] = psum[i-1][j];
            if(abs(r[j] - l[i]) <= 4) psum[i][j] = max(psum[i][j], psum[i-1][j-1] + 1);
            else psum[i][j] = max(psum[i][j], psum[i][j-1]);
        }
    }
    int maxi = 0;
    for(int i=1; i<=n; i++) maxi = max(maxi, psum[n][i]);
    cout << maxi << '\n';
}

void init() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> l[i];
    for(int i=1; i<=n; i++) cin >> r[i];
}

int main() {
    init();
    solve();
}