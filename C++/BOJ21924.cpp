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
int n, m, par[100010];
ll psum = 0;
vector<piii> v;

bool compare(piii a, piii b) {
	return a.Y < b.Y;
}

int find(int start) {
	if(start == par[start]) return start;
	return par[start] = find(par[start]);
}

bool uni(int x, int y) {
	int xx = find(x), yy = find(y);
	if(xx == yy) return false;
	if(xx < yy) par[yy] = xx;
	else par[xx] = yy;
	return true;
}

void init() {

	cin >> n >> m;
	for(int i=0; i<=n; i++) par[i] = i;
	for(int i=0; i<m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		psum += (ll)z;
		v.push_back({{x, y}, z});
	}
	sort(v.begin(), v.end(), compare);
	ll sum = 0;
	for(auto q : v) {
		if(uni(q.X.X, q.X.Y)) {
			sum += (ll)q.Y;
		}
	}
	ll answer = psum - sum;
	int cnt = 0;
	for(int i=1; i<=n; i++) {
		if(par[i] == i) cnt++;
	}
	if(cnt > 1) answer = -1;
	cout << answer << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}