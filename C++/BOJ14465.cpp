#include <iostream>
#include <cstring>
using namespace std;
int n, m, k, psum[100010], mini = 1e9;

void solve() {
    for(int i=m; i<=n; i++) {
        mini = min(mini, m-(psum[i] - psum[i-m]));
    }
    cout << mini << '\n';
}

void init() {
    fill(psum, psum+100001, 1);
    cin >> n >> m >> k;
    for(int i=0; i<k; i++) {
        int x;
        cin >> x;
        psum[x]--;
    }

    for(int i=1; i<=n; i++) {
        psum[i] += psum[i-1];
    }
}


int main() {
    init();
    solve();
}