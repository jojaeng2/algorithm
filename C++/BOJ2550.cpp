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
int n, idx[10100], par[10100];
vector<int> v, pos, ans, res;

void init() {
	memset(idx, 0, sizeof(idx));
	memset(par, -1, sizeof(par));
	cin >> n;
	for(int i=0; i<n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	for(int i=1; i<=n; i++) {
		int x;
		cin >> x;
		idx[x] = i;
	}
	ans.push_back(-1);
	pos.push_back(-1);
	for(int now:v) {
		if(idx[now] > pos.back()) {
			pos.push_back(idx[now]);
			par[now] = ans.back();
			ans.push_back(now);
		}
		else {
			int in = lower_bound(pos.begin(), pos.end(), idx[now]) - pos.begin();
			pos[in] = idx[now];
			ans[in] = now;
			if(in == 0) par[now] = -1;
			else par[now] = ans[in-1];
		}
	}
	for(int i=ans.back(); i!=-1; i=par[i]) {
		res.push_back(i);
	}
	sort(res.begin(), res.end());
	cout << res.size() << '\n';
	for(int i=0; i<res.size(); i++) {
		cout << res[i] << " ";
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}