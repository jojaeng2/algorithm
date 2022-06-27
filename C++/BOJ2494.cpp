#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stack>
#define X first
#define Y second
#define NUM 100010
#define INF 1e9
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii,int> piii;
typedef long long ll;
int n, dp[11][10010], num[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, par[11][10010];
string s1, s2;
vector<pii> v;

int dfs(int s, int l) {
	if(dp[l][s] != -1) return dp[l][s];
	if(s == n) return 0;
	dp[l][s] = 0;
	int c1 = s1[s]-'0', c2 = s2[s]-'0';
	c1 = (c1+l)%10;
	if(c1 < c2) {
		dp[l][s] = dfs(s+1, (l+c2-c1)%10) + c2-c1;
		par[l][s] = (c2-c1);
		int res2 = dfs(s+1, l) + (10-(c2-c1));
		if(res2 < dp[l][s]) {
			dp[l][s] = res2;
			par[l][s] = -(10-(c2-c1));
		} 
	}
	else {
		dp[l][s] = dfs(s+1, l) + c1-c2;
		par[l][s] = -(c1-c2);
		int res2 = dfs(s+1, (l+(10-(c1-c2)))%10) + (10-(c1-c2));
		if(res2 < dp[l][s]) {
			dp[l][s] = res2;
			par[l][s] = (10-(c1-c2));
		}
	}
	return dp[l][s];
}

void trace(int s, int psum) {
	if(s == n) return;
	cout << s+1 << " " << par[psum%10][s] << '\n';
	trace(s+1, psum + (par[psum%10][s] >= 0 ? par[psum%10][s] : 0));
}

void init() {
	memset(dp, -1, sizeof(dp));
	cin >> n >> s1 >> s2;
	dfs(0, 0);
	cout << dp[0][0] << '\n';
	trace(0, 0);
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}