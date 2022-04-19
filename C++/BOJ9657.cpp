#include <bits/stdc++.h>
#define NUM 300010
#define INF 1e9
using namespace std;
typedef long long ll;
int dp[1010], N;

int solve(int curr) {
    int& ret = dp[curr];
    if (ret != -1) return ret;
    if (curr == 0) return ret = 0;

    if (curr - 1 >= 0) {
        if (solve(curr - 1) == 0) return ret = 1;
    }
    if (curr - 3 >= 0) {
        if (solve(curr - 3) == 0) return ret = 1;
    }
    if (curr - 4 >= 0) {
        if (solve(curr - 4) == 0) return ret = 1;
    }
    return ret = 0;
}

void init() {
    memset(dp, -1, sizeof(dp));
    cin >> N;
    if(solve(N)) cout << "SK" << '\n';
    else cout << "CY" << '\n';
}   

int main() {
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    init();
}