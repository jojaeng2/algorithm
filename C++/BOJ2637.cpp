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
#include <cmath>
#define X first
#define Y second
#define NUM 100010
#define INF 1000000000
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, int> pli;
int N, M, in[110], dp[110], stin[110];
bool start[110];
vector<pii> adj[110];
queue<int> q;

void topo() {
	q.push(N);
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		for(auto next : adj[now]) {
			int node = next.X, cost = next.Y;
			dp[node] += (cost * dp[now]);
			if(!--in[node]) {
				q.push(node);
			}
		}
	}
}

void init() {
	memset(in, 0, sizeof(in));
	memset(start, false, sizeof(start));
	memset(dp, 0, sizeof(dp));
	memset(stin, 0, sizeof(stin));
	cin >> N >> M;
	for(int i=0; i<M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		in[y]++;
		stin[x]++;
		adj[x].push_back({y, z});
	}
	dp[N] = 1;
	topo();
	for(int i=1; i<=N; i++) {
		if(!stin[i]) {
			cout << i << " " << dp[i] << '\n';
		}
 	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}