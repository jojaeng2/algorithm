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
#define NUM 1010
#define INF 987654321
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, double> piib;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;
int n, par[NUM];
ll answer;
double p[NUM], c[NUM];
vector<piib> v;
vector<int> adj[NUM];

bool compare(piib a, piib b) {
	return a.Y > b.Y;
}

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

void dfs(int curr, int prev) {
	for(int next : adj[curr]) {
		if(next == prev) continue;
		dfs(next, curr);
		cout << curr << " " << next << '\n';
	}
}

void init() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> p[i] >> c[i];
		par[i] = i;
	}
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			v.push_back({{i, j}, round(((c[i]+c[j])/abs(p[i]-p[j])) - 0.5)});
		}
	}
	sort(v.begin(), v.end(), compare);
	for(int i=0; i<v.size(); i++) {
		int x = v[i].X.X, y = v[i].X.Y;
		if(uni(x, y)) {
			answer += (ll)round(v[i].Y);
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
	}
	cout << answer << '\n';
	dfs(1, -1);
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}