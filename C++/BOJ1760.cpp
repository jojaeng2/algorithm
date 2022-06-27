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
#define NUM 230000
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
typedef pair<ll, ll> pll;
int n, m, graph[110][110], rr[110][110], cc[110][110], rcnt = 1, ccnt = 1, f[5010];
bool conn[5010][5010], visit[5010];
vector<int> adj[5010];

bool dfs(int curr) {
	visit[curr] = true;
	for(int next : adj[curr]) {
		if(f[next] == -1 || (!visit[f[next]] && dfs(f[next]))) {
			f[next] = curr;
			return true;
		}
	}
	return false;
}

void make_map() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(graph[i][j] == 2 || rr[i][j] != 0) continue;
			for(int k=j; k<=m; k++) {
				if(graph[i][k] == 2) break;
				rr[i][k] = rcnt;
			}
			rcnt++;
		}
	}
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			if(graph[j][i] == 2 || cc[j][i] != 0) continue;
			for(int k=j; k<=n; k++) {
				if(graph[k][i] == 2) break;
				cc[k][i] = ccnt;
			}
			ccnt++;
		}
	}
}

void init() {
	memset(graph, 0, sizeof(graph));
	memset(rr, 0, sizeof(rr));
	memset(cc, 0, sizeof(cc));
	memset(conn, false, sizeof(conn));
	memset(visit, false, sizeof(visit));
	memset(f, -1, sizeof(f));
	cin >> n >> m;
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin >> graph[i][j];
	make_map();
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(graph[i][j] == 1 || graph[i][j] == 2) continue;
			int row = rr[i][j], col = cc[i][j];
			if(conn[row][col]) continue;
			conn[row][col] = true;
			adj[row].push_back(col);
		}
	}	
	int match = 0;
	for(int i=1; i<rcnt; i++) {
		memset(visit, false, sizeof(visit));
		if(dfs(i)) match++;
	}
	cout << match << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}