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
#define INF 1000000000
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, int> pli;
int t, n, num[1010], cnt = 0;
bool visit[1010];

void dfs(int start) {
	if(visit[num[start]]) return;
	visit[num[start]] = true;
	dfs(num[start]);
}

void init() {
	cin >> t;
	while(t--) {
		cnt = 0;
		memset(num, 0, sizeof(num));
		memset(visit, false, sizeof(visit));
		cin >> n;
		for(int i=1; i<=n; i++) cin >> num[i];
		for(int i=1; i<=n; i++) {
			if(visit[i]) continue;
			cnt++;
			dfs(i);
		}
		cout << cnt << '\n';
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}