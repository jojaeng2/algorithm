#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int dp[1010], t, num[1010], maxi = 0;

void init() {
	memset(dp, 0, sizeof(dp));
	memset(num, 0, sizeof(num));
	cin >> t;
	for(int i=1; i<=t; i++) cin >> num[i];
	for(int i=1; i<=t; i++) {
		dp[i] = num[i];
		for(int j=1; j<i; j++) {
			if(num[i]<num[j]) dp[i] = max(dp[i], dp[j]+num[i]);
		}
		maxi = max(maxi, dp[i]);
	}
	cout << maxi << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
