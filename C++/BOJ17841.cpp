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
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
int n, m, cnt = 1001, c[2010], f[2010];
bool visit[2010];
map<string, int> mp;
vector<int> adj[2001];

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
	memset(c, -1, sizeof(c));
	memset(f, -1, sizeof(f));
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		string s;
		cin >> s;
		mp.insert({s, cnt++});
	}
	for(int i=1; i<=n; i++) {
		int x;
		cin >> x;
		for(int j=0; j<x; j++) {
			string s;
			cin >> s;
			adj[i].push_back(mp[s]);
			adj[mp[s]].push_back(i);
		}
	}
	int match = 0;
	for(int i=1; i<=n; i++) {
		memset(visit, false, sizeof(visit));
		if(dfs(i)) match++;
	}
	if(match == n) cout << "YES" << '\n';
	else {
		cout << "NO" << '\n';
		cout << match << '\n';
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}