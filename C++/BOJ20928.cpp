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
#define NUM 10000
#define INF 1000000000010
#define MOD 1000000007
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
int n, m, pos[1000010], mov[1000010], idx[1000010];
int answer = 0, maxi, now;

void init() {
	memset(pos, 0, sizeof(pos));
	memset(idx, 0, sizeof(idx));
	memset(mov, 0, sizeof(mov));
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		int x;
		cin >> x;
		pos[x] = i;
		idx[i] = x;
	}
	for(int i=1; i<=n; i++) {
		int x;
		cin >> x;
		mov[idx[i]] = x;
	}
	maxi = idx[1] + mov[idx[1]];
	now = maxi;
	bool flag = false;
	for(int i=idx[1]; i<=m; i++) {
		if(i > now) {
			if(maxi < i) break;
			now = maxi;
			if(flag) {
				answer++;
				flag = false;
			}
		}
		if(maxi < i + mov[i] && pos[i] != 0) {
			maxi = i + mov[i];
			flag = true;
		}
	}
	if(maxi < m) answer = -1;
	cout << answer << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}