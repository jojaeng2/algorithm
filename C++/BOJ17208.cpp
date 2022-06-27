#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <cmath>
#include <deque>
#include <list>
#define X first
#define Y second
#define NUM 230000
#define INF 2000000000
#define MOD 1000000007
#define LOG 22
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
int n, m, k, dp[310][310][310], answer = 0;
vector<pii> v;

void init() {
	memset(dp, 0, sizeof(dp));
	cin >> n >> m >> k;
	v.push_back({0, 0});
	for(int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({x, y});
	}
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=m; j++) for(int p=0; p<=k; p++) dp[i][j][p] = dp[i-1][j][p];
		for(int j=v[i].X; j<=m; j++) {
			for(int p=v[i].Y; p<=k; p++) {
				dp[i][j][p] = max(dp[i][j][p], dp[i-1][j-v[i].X][p-v[i].Y] + 1);
				answer = max(answer, dp[i][j][p]);
			}
		}
	}
	cout << answer << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}