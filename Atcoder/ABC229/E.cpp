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
#define INF 987654321
#define MOD 1000000007
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, double> piib;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;
int n, m, par[200010];
vector<int> adj[200010], answer;

int find(int start) {
	if(start == par[start]) return start;
	return par[start] = find(par[start]);
}

bool uni(int x, int y) {
	int xx = find(x), yy = find(y);
	if(xx == yy) return false;
	if(xx < yy) par[yy] = xx;
	else par[xx] = yy;

	return true;
}

void init() {
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		if(x > y) swap(x, y);
		adj[x].push_back(y);
	}
	for(int i=0; i<=n; i++) par[i] = i;
	int node = 0;
	answer.push_back(0);
	for(int i=n; i>1; i--) {
		node++;
		for(int next : adj[i]) {
			if(uni(next, i)) {
				node--;
			}
		}
		answer.push_back(node);
	}
	reverse(answer.begin(), answer.end());
	for(auto ans : answer) {
		cout << ans << '\n';
	}

}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}