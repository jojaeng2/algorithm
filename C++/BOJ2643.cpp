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
int dp[2][110], t;
vector<pii> v;


bool compare(pii a, pii b) {
	return a.X*a.Y > b.X*b.Y;
}

int dfs(int now, int x, int y, int s) {
	if(dp[s][now] != -1) return dp[s][now];
	dp[s][now] = 0;
	if(now == t) return dp[s][now];
	int nx = v[now+1].X, ny = v[now+1].Y;
	if(nx<=x && ny<=y) {
		dp[s][now] = max(dp[s][now], dfs(now+1, nx, ny, 1)+1);
		dp[s][now] = max(dp[s][now], dfs(now+1, x, y, 0));	
	}
	if(ny<=x && nx<=y) {
		dp[s][now] = max(dp[s][now], dfs(now+1, ny, nx, 1)+1);
		dp[s][now] = max(dp[s][now], dfs(now+1, x, y, 0));	
	}
	return dp[s][now];
}

void init() {
	memset(dp, -1, sizeof(dp));
	cin >> t;
	v.push_back(make_pair(1000, 1000));
	for(int i=0; i<t; i++) {
		int x, y;
		cin >> x >> y;
		if(x<y)swap(x, y);
		v.push_back(make_pair(x, y));
	}
	sort(v.begin(), v.end(), compare);
	cout << dfs(0, 1000, 1000, 1) << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
