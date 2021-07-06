#include <iostream>
#include <cstring>
#include <algorithm>
#define NUM 100001
using namespace std;
int n, m, psum[NUM], DP[NUM], answer = 0;

void init() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    memset(psum, 0, sizeof(psum));
    memset(DP, 0, sizeof(DP));
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> psum[i];
        psum[i] += psum[i-1];
    }
    for(int i=1; i<=n; i++) {
        if(i>=m) {
            DP[i] = max(DP[i-1]+(psum[i]-psum[i-1]), psum[i] - psum[i-m]);
            answer = max(answer, DP[i]);
        }
        else DP[i] = DP[i-1] + (psum[i]-psum[i-1]);

    }
    cout << answer << '\n';
}

int main() {
    init();
}