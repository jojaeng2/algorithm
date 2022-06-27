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
#define NUM 100010
#define INF 2000000000
#define MOD 1000000007
#define LOG 22
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, ll> pil;
typedef pair<pii, int> piii;
typedef pair<piii, int> piiii;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;
int n, m, dp[11][100010], answer = 0, num[11][100010];


void init() {
	memset(dp, 0, sizeof(dp));
	cin >> n >> m;
	for(int i=1; i<=m; i++) for(int j=1; j<=n; j++) cin >> num[i][j];
	for(int i=1; i<=m; i++) dp[i][1] = num[i][1], answer = max(answer, dp[i][1]);
	for(int i=2; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			for(int k=1; k<=m; k++) {
				if(j == k) dp[j][i] = max(dp[j][i], dp[k][i-1] + num[j][i]/2);
				else dp[j][i] = max(dp[j][i], dp[k][i-1] + num[j][i]);

			}
			answer = max(answer, dp[j][i]);
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