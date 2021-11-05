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
#define NUM 1010
#define INF 1000000000
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, int> pli;
int N, M, DP[210][110];
bool visit[110];

int dfs(int s, int t) {
	if(s > N) return 0;
	if(DP[t][s] != -1) return DP[t][s];
	DP[t][s] = 1e9;
	if(visit[s]) return DP[t][s] = dfs(s+1, t);
	else {
		if(t >= 3) DP[t][s] = dfs(s+1, t-3);
		DP[t][s] = min(DP[t][s], dfs(s+1, t)+10000);
		DP[t][s] = min(DP[t][s], dfs(s+3, t+1)+25000);
		DP[t][s] = min(DP[t][s], dfs(s+5, t+2)+37000);
	}
	return DP[t][s];
}

void init() {
	memset(DP, -1, sizeof(DP));
	memset(visit, false, sizeof(visit));
	cin >> N >> M;
	for(int i=0; i<M; i++) {
		int x;
		cin >> x;
		visit[x] = true;
	}
	dfs(1, 0);
	cout << DP[0][1] << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}