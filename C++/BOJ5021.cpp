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
#define NUM 200010
#define INF 2000000000
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;
map<string, int> mp;
int n, m, cnt = 1, maxi = -1;
bool visit[51];
string king, answer;
vector<int> adj[51];

double dfs(int curr) {
	if(curr == mp[king]) return 1;
	if(adj[curr].size() == 0) return 0;
	if(visit[adj[curr]][0])
	return (dfs(adj[curr][0]) + dfs(adj[curr][1]))/2;
	
}

void init() {
	cin >> n >> m >> king;
	mp.insert({king, cnt++});
	for(int i=0; i<n; i++) {
		string son, fa, mo;
		cin >> son >> fa >> mo;
		if(mp.find(son) == mp.end()) mp.insert({son, cnt++});
		if(mp.find(fa) == mp.end()) mp.insert({fa, cnt++});
		if(mp.find(mo) == mp.end()) mp.insert({mo, cnt++});
		adj[mp[son]].push_back(mp[fa]);
		adj[mp[son]].push_back(mp[mo]);
	}
	for(int i=0; i<m; i++) {
		string s;
		cin >> s;
		memset(visit, false, sizeof(visit));
		double psum = dfs(mp[s]);
		if(psum > maxi) {
			maxi = psum;
			answer = s;
		}
	}
	cout << answer << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}