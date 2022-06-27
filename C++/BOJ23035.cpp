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
ll n, m, t;
vector<pll> pos;
vector<ll> v;

bool compare(pll a, pll b) {
	if(a.X == b.X) return a.Y < b.Y;
	return a.X < b.X;
}

void init() {
	cin >> n >> m >> t;
	for(int i=0; i<t; i++) {
		ll x, y;
		cin >> x >> y;
		pos.push_back({x, y});
	}
	sort(pos.begin(), pos.end(), compare);
	v.push_back(-1);
	for(auto p : pos) {
		if(p.X > n) continue;
		if(p.Y > m) continue;
		if(v.back() <= p.Y) v.push_back(p.Y);
		else {
			ll idx = upper_bound(v.begin(), v.end(), p.Y) - v.begin();
			v[idx] = p.Y;
		}
	}
	cout << v.size() - 1 << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}