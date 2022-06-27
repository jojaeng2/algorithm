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
#define NUM 100100
#define INF 1000000000
#define MOD 1000000007
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, int> pli;
int n, dfsn[110], cnt = 1, c[110], f[110];
bool visit[110];
vector<piii> v;
vector<int> adj[110];

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
	memset(dfsn, -1, sizeof(dfsn));
	memset(c, -1, sizeof(c));
	memset(f, -1, sizeof(f));
	cin >> n;
	for(int i=0; i<n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v.push_back({{x, y}, z});
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(i == j) continue;
			if(v[i].X.X == v[j].X.X && v[i].X.Y == v[j].X.Y && v[i].Y == v[j].Y) {
				if(i < j) {
					adj[i].push_back(j);
					adj[i+50].push_back(j);
				}
			}
			else if(v[i].X.X >= v[j].X.X && v[i].X.Y >= v[j].X.Y && v[i].Y >= v[j].Y) {
				adj[i].push_back(j);
				adj[i+50].push_back(j);
			}
		}
	}
	int match = 0;
	for(int i=0; i<=n+50; i++) {
		if(c[i] == -1) {
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