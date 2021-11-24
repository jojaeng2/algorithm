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
int n, m, psum = 0, score[200010];
priority_queue<pii> pq;

void init() {
	cin >> n >> m;
	for(int i=1; i<=m; i++) {
		cin >> score[i];
		psum += score[i];
	}
	for(int i=1; i<=m; i++) {
		int x;
		cin >> x;
		pq.push({min(100-score[i], x), i});
	}
	int t = 0;
	while(!pq.empty()) {
		if(t == n*24) break;
		t++;
		int x = pq.top().X, idx = pq.top().Y;
		pq.pop();
		if(score[idx] >= 100 || x == 0) continue;
		score[idx] += x;
		psum += x;
		pq.push({min(100-score[idx], x), idx});
	}
	cout << psum << '\n';
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
}