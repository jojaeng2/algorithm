#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stack>
#define X first
#define Y second
#define NUM 1010
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii,int> piii;
typedef long long ll;
int n, psum[NUM+10][NUM+10], answer = NUM;
vector<pii> v;
vector<int> xx, yy;

void solve() {
	for(int i=1; i<NUM; i++) {
		for(int j=1; j<NUM; j++) {
			int maxi = max({psum[NUM][NUM]-psum[NUM][j-1]-psum[i-1][NUM]+psum[i-1][j-1], psum[i-1][j-1], psum[NUM][j-1]-psum[i-1][j-1], psum[i-1][NUM]-psum[i-1][j-1]});
			answer = min(answer, maxi);
		}
	}
}

void init() {
	memset(psum, 0, sizeof(psum));
	cin >> n;
	xx.push_back(-1), yy.push_back(-1);
	for(int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		xx.push_back(x);
		yy.push_back(y);
		v.push_back({x, y});
	}
	sort(xx.begin(), xx.end());
	sort(yy.begin(), yy.end());
	for(int i=0; i<n; i++) {
		int x = v[i].X, y = v[i].Y;
		int nx = lower_bound(xx.begin(), xx.end(), x) - xx.begin();
		int ny = lower_bound(yy.begin(), yy.end(), y) - yy.begin();
		psum[nx][ny] = 1;
	}
	for(int i=1; i<=NUM; i++) for(int j=1; j<=NUM; j++) psum[i][j] +=(psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1]);
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
	solve();
	cout << answer << '\n';
}