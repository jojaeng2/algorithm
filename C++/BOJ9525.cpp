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
int n, graph[110][110], rr[110][110], cc[110][110], hcnt = 0, cnt = 0, f[5010], c[5010];
bool visit[5010], conn[5010][5010];
vector<int> adj[5010];

bool dfs(int curr) {
	visit[curr] = true;
	for(auto next : adj[curr]) {
		if(f[next] == -1 || (!visit[f[next]] && dfs(f[next]))) {
			c[curr] = next;
			f[next] = curr;
			return true;
		}
	}
	return false;
}

void init() {
	memset(graph, 0, sizeof(-1));
	memset(conn, false, sizeof(conn));
	memset(f, -1, sizeof(f));
	memset(c, -1, sizeof(c));
	memset(rr, -1, sizeof(rr));
	memset(cc, -1, sizeof(cc));
	cin >> n;
	for(int i=0; i<n; i++) {
		string s;
		cin >> s;
		for(int j=0; j<s.size(); j++) {
			if(s[j] == '.') graph[i][j] = 0;
			else graph[i][j] = 1;
		}
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(graph[i][j] == 1 || rr[i][j] != -1) continue;
			cnt++;
			for(int k=j; k<n; k++) {
				if(graph[i][k] == 1) break;
				rr[i][k] = cnt;
			}
		}	
	}	

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(graph[j][i] == 1 || cc[j][i] != -1) continue;
			hcnt++;
			for(int k=j; k<n; k++) {
				if(graph[k][i] == 1) break;
				cc[k][i] = hcnt;
			}
		}
	}	

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(graph[i][j] == 1) continue;
			int row = rr[i][j], col = cc[i][j];
			if(conn[row][col]) continue;
			conn[row][col] = true;
			adj[row].push_back(col);
		}
	}
	int match = 0;
	for(int i=1; i<=cnt; i++) {
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