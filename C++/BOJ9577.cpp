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
#define NUM 110
#define INF 1000000000
#define MOD 1000000007
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, int> pli;
int t, N, M, c[NUM], f[NUM], answer;
bool visit[NUM];
vector<int> adj[NUM], v;

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
	cin >> t;
	while(t--) {
		memset(c, -1, sizeof(c));
		memset(f, -1, sizeof(f));
		for(int i=0; i<NUM; i++) adj[i].clear();
		answer = -1;
		cin >> N >> M;
		for(int i=0; i<M; i++) {
			v.clear();
			int s, e, k;
			cin >> s >> e >> k;
			for(int j=0; j<k; j++) {
				int x;
				cin >> x;
				v.push_back(x);
			}
			for(int j=s; j<e; j++) for(auto next : v) adj[j].push_back(next);
		}
		
		int match = 0;
		for(int i=0; i<=100; i++) {
			memset(visit, false, sizeof(visit));
			if(dfs(i)) match++;
			if(match == N) {
				answer = i+1;
				break;
			}
		}
		cout << answer << '\n';
	}
}	

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}