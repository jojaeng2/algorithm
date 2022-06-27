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
#define NUM 300010
#define INF 1000000
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, int> pli;
int v, e, cnt = 1, dfsn[NUM], bccnt[NUM];
ll answer = 0;
vector<int> adj[NUM];
stack<pii> s;
vector<vector<pii>> bcc;
set<int> st;

int dfs(int curr, int prev = -1) {
	dfsn[curr] = cnt++;
	int res = dfsn[curr];
	for(int next:adj[curr]) {
		if(next == prev) continue;
		if(dfsn[curr] > dfsn[next]) s.push({curr, next});
		if(dfsn[next] > 0) res = min(res, dfsn[next]);
		else {
			int temp = dfs(next, curr);
			res = min(res, temp);
			if(temp >= dfsn[curr]) {
				vector<pii> currBCC;
				while(!s.empty()) {
					if(s.top() == pii(curr, next)) break;
					currBCC.push_back(s.top());
					s.pop();
				}
				currBCC.push_back(s.top());
				s.pop();
				bcc.push_back(currBCC);
			}
		}
	}
	return res;
}

void init() {
	memset(bccnt, 0, sizeof(bccnt));
	memset(dfsn, 0, sizeof(dfsn));
	cin >> v >> e;
	for(int i=0; i<e; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i=1; i<v; i++) {
		if(dfsn[i] == 0) dfs(i);
	} 
	for(auto a:bcc) {
		st.clear();
		for(auto b:a) {
			st.insert(b.X);
			st.insert(b.Y);
		}
		for(auto next:st) bccnt[next]++;
	}
	for(int i=1; i<=v; i++) {
		if(e-adj[i].size()+bccnt[i]-1 <= v-1) answer += (ll)i;
	}
	cout << answer << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}