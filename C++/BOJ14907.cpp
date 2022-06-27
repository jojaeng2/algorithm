#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <iomanip>
#include <string>
#include <sstream>
#define X first
#define Y second
#define NUM 200010
#define INF 1e15
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
int dp[30], cost[30], in[30], cnt = 1, maxi = 0;
map<char, int> m;
string s;
vector<int> graph[30];
queue<int> q;

void init() {
	memset(dp, 0, sizeof(dp));
	memset(cost, 0, sizeof(cost));
	memset(in, 0, sizeof(in));
	while(getline(cin, s)) {
		stringstream ss(s);
		char a; int b; string c;
		ss >> a >> b >> c;
		if(m.find(a) == m.end()) {
			m.insert({a, cnt++});
		}
		cost[m[a]] = b;
		for(int i=0; i<c.size(); i++) {
			in[m[a]]++;
			if(m.find(c[i]) == m.end()) {
				m.insert({m[c[i]], cnt++});
			}
			graph[m[c[i]]].push_back(m[a]);
		}
	}
	for(int i=1; i<cnt; i++) if(!in[i]) {
		q.push(i);
		dp[i] = cost[i];
		maxi = max(maxi, dp[i]);
	}
	while(!q.empty()) {
		int t = q.front();
		q.pop();
		for(int i=0; i<graph[t].size(); i++) {
			int next = graph[t][i];
			dp[next] = max(dp[next], dp[t] + cost[next]);
			maxi = max(dp[next], maxi);
			if(!--in[next]) q.push(next);
		}
	}
	cout << maxi << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}