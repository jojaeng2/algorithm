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
#define INF 987654321
#define MOD 1000000007
#define POW2(x) x*x
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, double> piib;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;
ll answer = 0;
int n, w;
priority_queue<pll> pq;

void init() {
	cin >> n >> w;
	for(int i=0; i<n; i++) {
		ll x, y;
		cin >> x >> y;
		pq.push({x, y});
	}
	ll cnt = 0;
	while(!pq.empty()) {
		if(cnt >= w) break;
		auto tp = pq.top();
		pq.pop();
		if(cnt + tp.Y <= w) {
			answer += tp.X * tp.Y;
			cnt += tp.Y;
		}
		else {
			answer += (w - cnt) * tp.X;
			cnt += tp.Y;
		}
	}
	cout << answer << '\n';

}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}