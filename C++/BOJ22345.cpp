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
#define INF 1000000010
#define MOD 1000000007
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
int n, q;
ll a[200010], ax[200010];
map<ll, ll> mp;
vector<ll> v;

void init() {
	memset(a, 0, sizeof(a));
	memset(ax, 0, sizeof(ax));
	cin >> n >> q;
	for(int i=0; i<n; i++) {
		ll a, x;
		cin >> a >> x;
		v.push_back(x);
		mp.insert({x, a});
	}
	v.push_back(-INF);
	sort(v.begin(), v.end());
	for(int i=1; i<v.size(); i++) {
		ll aa = mp[v[i]], idx = v[i];
		a[i] = a[i-1] + aa;
		ax[i] = ax[i-1] + aa*idx;
	}
	for(int i=0; i<q; i++) {
		ll x;
		cin >> x;
		int lidx = lower_bound(v.begin(), v.end(), x) - v.begin();
		int ridx = upper_bound(v.begin(), v.end(), x) - v.begin();
		ll answer = x * a[lidx-1] - ax[lidx-1] + (ax[n] - ax[ridx-1]) - (x * (a[n] - a[ridx-1]));
		cout << answer << '\n';
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}