#include <bits/stdc++.h>
#define X first
#define Y second
#define NUM 100010
#define INF 1e18
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
int n, par[310], answer = 0;
vector<piii> v;

bool compare(piii a, piii b) {
	return a.Y < b.Y;
}

int find(int start) {
	if(start == par[start]) return start;
	return par[start] = find(par[start]);
}

bool uni(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return false;
	if(x < y) par[y] = x;
	else par[x] = y;
	return true;
}

void init() {
	for(int i=0; i<=300; i++) par[i] = i;
	cin >> n;
	for(int i=1; i<=n; i++) {
		int x;
		cin >> x;
		v.push_back(make_pair(make_pair(0, i), x));
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			int x;
			cin >> x;
			v.push_back(make_pair(make_pair(i, j), x));
		}
	}
	sort(v.begin(), v.end(), compare);
	for(int i=0; i<v.size(); i++) {
		int x = v[i].X.X, y = v[i].X.Y, r = v[i].Y;
		if(uni(x, y)) answer += r;
	}
	cout << answer << '\n';
}		

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}