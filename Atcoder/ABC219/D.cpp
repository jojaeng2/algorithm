#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <bitset>
#include <set>
#include <map>
#define X first
#define Y second
#define NUM 200010
#define MOD 1000000007
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int t, x, y;
ll dp[310][310][310], mini = 1e9;
vector<pii> v;

void init() {
	memset(dp, 1e4, sizeof(dp));
	cin >> t >> x >> y;
	v.push_back({0, 0});
	for(int i=0; i<t; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}
	dp[0][0][0] = 0;
	for(int i=1; i<=t; i++) {
		int a = v[i].X, b = v[i].Y;
		for(int j=0; j<=300; j++) {
			for(int k=0; k<=300; k++) {
				dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k]);
				dp[i][min(j+a, 300)][min(k+b, 300)] = min({dp[i][min(j+a, 300)][min(k+b, 300)], dp[i-1][min(300, j+a)][min(300, k+b)], dp[i-1][j][k]+1});
			}
		}
	}
	for(int i=x; i<=300; i++) for(int j=y; j<=300; j++) mini = min(mini, dp[t][i][j]);
	if(mini > t) mini = -1;
	cout << mini << '\n';
}
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}
