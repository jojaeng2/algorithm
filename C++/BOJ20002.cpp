#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, psum[301][301], answer;

void solve() {
    answer = psum[1][1];
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=min(i,j); k++) {
                answer = max(answer, psum[i][j] - (psum[i-k][j] + psum[i][j-k] - psum[i-k][j-k]));
            }
        }
    }
    cout << answer << '\n';
}

void init() {
    memset(psum, 0, sizeof(psum));
    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> psum[i][j];
            psum[i][j] += (psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1]);
        }
    }
}

int main() {
    init();
    solve();
}