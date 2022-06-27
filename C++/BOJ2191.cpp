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
#define INF 1e14
#define NUM 1010
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
int n, m, s, v, c[110], f[110];
bool visit[110];
vector<int> adj[110];
vector<pdd> mo;

bool dfs(int s) {
	visit[s] = true;
	for(int e:adj[s]) {
		if(f[e] == -1 || (!visit[f[e]] && dfs(f[e]))) {
			c[s] = e;
			f[e] = s;
			return true;
		}
	}
	return false;
}

double POW2(double x) {
	return x*x;
}

void init() {
	memset(c, -1, sizeof(c));
	memset(f, -1, sizeof(f));
	cin >> n >> m >> s >> v;
	for(int i=0; i<n; i++) {
		double x, y;
		cin >> x >> y;
		mo.push_back({x, y});
	}
	for(int i=1; i<=m; i++) {
		double x, y;
		cin >> x >> y;
		for(int j=0; j<n; j++) {
			double xx = mo[j].X, yy = mo[j].Y;
			if(POW2(xx-x)+POW2(yy-y)>POW2(s*v)) continue;
			adj[j].push_back(i);
		}	
	}
	int match = 0;
	for(int i=0; i<n; i++) {
		if(c[i]==-1) {
			memset(visit, false, sizeof(visit));
			if(dfs(i)) match++;
		}
	}
	cout << n-match << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}