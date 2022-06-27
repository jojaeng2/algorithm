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
#define INF 1000000000
#define MOD 998244353
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, int> pli;
int N, M, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
ll answer = 0, DP[5][510][510];

char graph[510][510];

ll dfs(int x, int y, int dir) {
	if(x < 1 || y < 1 || x > N || y > M) return 1;
	if(DP[dir][x][y] != -1) return DP[dir][x][y];
	DP[dir][x][y] = 0;
	if(graph[x][y] == 'D') DP[dir][x][y] += dfs(x+1, y, 0);
	if(graph[x][y] == 'U') DP[dir][x][y] += dfs(x-1, y, 1);
	if(graph[x][y] == 'L') DP[dir][x][y] += dfs(x, y-1, 3);
	if(graph[x][y] == 'R') DP[dir][x][y] += dfs(x, y+1, 2);
	return DP[dir][x][y];
}

void init() {
	memset(DP, -1, sizeof(DP));
	cin >> N >> M;
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) cin >> graph[i][j];
	for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) {
		answer += dfs(i, j, 0);
	}
	cout << answer << '\n';
}	

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}