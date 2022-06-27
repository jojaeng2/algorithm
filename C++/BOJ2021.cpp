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
typedef pair<piii, int> piiii;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;
int n, m, visit[NUM], s, e, answer = INF;
vector<int> adj[NUM], station[NUM];
queue<int> q;

void init() {
	memset(visit, -1, sizeof(visit));
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		while(true) {
			int x;
			cin >> x;
			if(x == -1) break;
			adj[i].push_back(x);
			station[x].push_back(i);
		}
	}
	cin >> s >> e;
	for(int start : station[s]) {
		visit[start] = 0;
		q.push(start);
	}
	while(!q.empty()) {
		int curr = q.front();
		q.pop();
		for(int next : adj[curr]) {
			for(int stat : station[next]) {
				if(visit[stat] != -1) continue;
				visit[stat] = visit[curr] + 1;
				q.push(stat);
			}
		}
	}
	for(int ans : station[e]) {
		if(visit[ans] == -1) continue;
		answer = min(answer, visit[ans]);
	}
	if(answer == INF) answer = -1;
	cout << answer << '\n';
}	

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}