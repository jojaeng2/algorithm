#include <bits/stdc++.h>
#define X first
#define Y second
#define NUM 100010
#define INF 1e9
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
int n, m, snow[110], answer = 0;

void dfs(int s, int cnt, int psum) {
	answer = max(answer, psum);
	if(s >= n || cnt == m) return;
	dfs(s+1, cnt+1, psum + snow[s+1]);
	dfs(s+2, cnt+1, (psum/2) + snow[s+2]);
}

void init() {
	memset(snow, 0, sizeof(snow));
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> snow[i];
	dfs(0, 0, 1);
	cout << answer << '\n';
}		

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}