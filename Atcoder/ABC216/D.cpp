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
#define INF 1000000
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, int> pli;
int n, m, idx[NUM];
queue<int> q[NUM];

void dfs(int start) {
	while(!q[start].empty()) {
		int f = q[start].front();
		if(idx[f] == -1) {
			idx[f] = start;
			break;
		}
		else if(idx[f] == start) break;
		else {
			q[idx[f]].pop();
			q[start].pop();
			if(!q[idx[f]].empty()) dfs(idx[f]);
		}
	}
}

void init() {
	memset(idx, -1, sizeof(idx));
	cin >> n >> m;
	for(int i=1; i<=m; i++) {
		int k;
		cin >> k;
		for(int j=0; j<k; j++) {
			int x;
			cin >> x;
			q[i].push(x);
		}
		dfs(i);
	}
	bool flag = false;
	for(int i=1; i<=m; i++) {
		if(!q[i].empty()) flag = true;
	}
	if(flag) cout << "No" << '\n';
	else cout << "Yes" << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}