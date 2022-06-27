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
#define NUM 2010
#define INF 987654321
#define MOD 1000000007
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n;
ll num[NUM], DP[NUM][NUM];

ll dfs(int x, int y, int idx) {
	if(idx > n) return 0;
	if(DP[x][y] != -1) return DP[x][y];
	DP[x][y] = INF;
	if(x == 0) DP[x][y] = min(DP[x][y], dfs(idx, y, idx+1));
	else DP[x][y] = min(DP[x][y], dfs(idx, y, idx+1) + abs(num[x] - num[idx]));
	if(y == 0) DP[x][y] = min(DP[x][y], dfs(x, idx, idx+1));
	else DP[x][y] = min(DP[x][y], dfs(x, idx, idx+1) + abs(num[y] - num[idx]));
	return DP[x][y];
	
}

void init() {
	memset(num, 0, sizeof(num));
	memset(DP, -1, sizeof(DP));
	cin >> n;
	for(int i=1; i<=n; i++) cin >> num[i];
	num[0] = num[1];
	dfs(0, 0, 1);
	cout << DP[0][0] << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}