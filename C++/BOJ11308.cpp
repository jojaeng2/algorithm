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
#define X first
#define Y second
#define NUM 100
#define INF 1000000
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, int> pli;
int t, v, e, cnt, dfsn[NUM];
vector<int> adj[NUM];
vector<pii> answer;
set<pii> s, dat;

void print() {
	if(s.size() != 0) cout << "NO" << '\n';
	else {
		cout << "YES" << '\n';
		for(auto ans:answer) {
			int x = ans.X, y = ans.Y;
			cout << x << " " << y << '\n';
		}
	}
}

int dfs(int curr, int prev) {
	dfsn[curr] = cnt++;
	int res = dfsn[curr];
	for(int next:adj[curr]) {
		if(next == prev) continue;
		if(dfsn[next]) {
			res = min(res, dfsn[next]);
			if(dat.find(pii(curr, next)) == dat.end() && dat.find(pii(next, curr)) == dat.end()) {
				dat.insert({curr, next});
				answer.push_back({curr, next});
			}
		}
		else {
			int par = dfs(next, curr);
			if(par > dfsn[curr]) s.insert({curr, next});
			else {
				if(dat.find(pii(curr, next)) == dat.end() && dat.find(pii(next, curr)) == dat.end()) {
					dat.insert({curr, next});
					answer.push_back({curr, next});
				}
			}
			res = min(res, par);
		}
	}
	return res;
}

void init() {
	cin >> t;
	while(t--) {
		s.clear();
		dat.clear();
		answer.clear();
		for(int i=0; i<NUM; i++) adj[i].clear();
		memset(dfsn, 0, sizeof(dfsn));
		cnt = 1;
		cin >> v >> e;
		for(int i=0; i<e; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		for(int i=1; i<=v; i++) {
			if(!dfsn[i]) dfs(i, 0);
		}
		print();
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}