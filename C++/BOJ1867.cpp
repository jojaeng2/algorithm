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
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, double> piib;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;
int n, m, f[NUM], c[NUM];
char t[NUM];
bool visit[NUM];
vector<int> adj[NUM];

bool dfs(int curr) {
	visit[curr] = true;
	for(int next : adj[curr]) {
		if(f[next] == -1 || (!visit[f[next]] && dfs(f[next]))) {
			c[curr] = next;
			f[next] = curr;
			return true;
		}
	}
	return false;
}

void init() {
	memset(f, -1, sizeof(f));
	memset(c, -1, sizeof(c));
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		int x;
		char y;
		cin >> x >> y;
		t[x] = y;
	}
	for(int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		if(t[x] == 'c') adj[x].push_back(y);
		else adj[y].push_back(x);
	}
	int match = 0;
	for(int i=1; i<=n; i++) {
		if(c[i] == -1) {
			memset(visit, false, sizeof(visit));
			if(dfs(i)) match++;
		} 
	}
	cout << n - match << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}